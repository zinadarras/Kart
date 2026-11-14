#include <stdio.h>
#include <string.h>
#include "kart.h"

void ajouterKart(Kart tab[], int *nb, Categorie tabCat[], int nbCat, float *caisse) {
    if (*nb >= MAX_KARTS) {
        printf("Erreur : Parc de karts plein !\n");
        return;
    }
    if (nbCat == 0) {
        printf("Impossible d'ajouter un kart : creez d'abord au moins une categorie !\n");
        return;
    }

    afficherCategories(tabCat, nbCat);
    int idCat;
    printf("\nChoisissez l'ID de la categorie pour ce kart : ");
    scanf("%d", &idCat);

    if (chercherCategorieParId(tabCat, nbCat, idCat) == -1) {
        printf("Erreur : Categorie invalide !\n");
        return;
    }

    Kart k;
    k.identifiant = (*nb == 0) ? 1 : tab[*nb - 1].identifiant + 1;
    k.id_categorie = idCat;

    printf("Prix d'achat du kart : ");
    scanf("%f", &k.prix);

    if (*caisse < k.prix) {
        printf("Fonds insuffisants dans la caisse (Solde actuel : %.2f) !\n", *caisse);
        return;
    }

    printf("Nombre MAX de courses avant revision : ");
    scanf("%d", &k.max_courses);
    printf("Cout d'une revision : ");
    scanf("%f", &k.cout_revision);

    k.compteur_courses = 0;
    strcpy(k.etat, "LIBRE");
    k.course_en_cours = -1;
    k.date_disponibilite = time(NULL);

    *caisse -= k.prix; // Deduction du prix d'achat
    tab[*nb] = k;
    (*nb)++;

    printf("Kart K%d achete et ajoute avec succes ! Nouveau solde caisse : %.2f\n", k.identifiant, *caisse);
}

void afficherKarts(Kart tab[], int nb) {
    if (nb == 0) {
        printf("Aucun kart dans l'ecurie.\n");
        return;
    }
    printf("\n--- LISTE DES KARTS ---\n");
    for (int i = 0; i < nb; i++) {
        printf("Kart K%d | Cat ID: %d | Etat: %s | Courses: %d/%d | Revision: %.2f\n",
               tab[i].identifiant, tab[i].id_categorie, tab[i].etat,
               tab[i].compteur_courses, tab[i].max_courses, tab[i].cout_revision);
    }
}

void modifierKart(Kart tab[], int nb, Categorie tabCat[], int nbCat) {
    if (nb == 0) {
        printf("Aucun kart a modifier.\n");
        return;
    }
    afficherKarts(tab, nb);
    int id, pos = -1;
    printf("\nEntrez l'ID du kart a modifier : ");
    scanf("%d", &id);

    for (int i = 0; i < nb; i++) {
        if (tab[i].identifiant == id) { pos = i; break; }
    }
    if (pos == -1) {
        printf("Kart introuvable !\n");
        return;
    }

    afficherCategories(tabCat, nbCat);
    printf("Nouvel ID categorie : ");
    scanf("%d", &tab[pos].id_categorie);
    printf("Nouveau MAX courses : ");
    scanf("%d", &tab[pos].max_courses);
    printf("Nouveau cout revision : ");
    scanf("%f", &tab[pos].cout_revision);

    printf("Kart modifie avec succes !\n");
}

void supprimerKart(Kart tab[], int *nb) {
    if (*nb == 0) {
        printf("Aucun kart a supprimer.\n");
        return;
    }
    afficherKarts(tab, *nb);
    int id, pos = -1;
    printf("\nEntrez l'ID du kart a supprimer : ");
    scanf("%d", &id);

    for (int i = 0; i < *nb; i++) {
        if (tab[i].identifiant == id) { pos = i; break; }
    }
    if (pos == -1) {
        printf("Kart introuvable !\n");
        return;
    }

    for (int i = pos; i < *nb - 1; i++) {
        tab[i] = tab[i + 1];
    }
    (*nb)--;
    printf("Kart supprime avec succes !\n");
}

void afficherKartsEnAttente(Kart tab[], int nb) {
    int trouve = 0;
    printf("\n--- KARTS EN ATTENTE DE REVISION ---\n");
    for (int i = 0; i < nb; i++) {
        if (strcmp(tab[i].etat, "EN_ATTENTE") == 0 || tab[i].compteur_courses >= tab[i].max_courses) {
            printf("Kart K%d | Courses: %d/%d | Cout revision: %.2f\n",
                   tab[i].identifiant, tab[i].compteur_courses, tab[i].max_courses, tab[i].cout_revision);
            trouve = 1;
        }
    }
    if (!trouve) printf("Aucun kart n'a besoin de revision pour le moment.\n");
}

void reviserKart(Kart tab[], int nb, float *caisse) {
    afficherKartsEnAttente(tab, nb);
    int id, pos = -1;
    printf("\nEntrez l'ID du kart a reviser (0 pour annuler) : ");
    scanf("%d", &id);
    if (id == 0) return;

    for (int i = 0; i < nb; i++) {
        if (tab[i].identifiant == id) { pos = i; break; }
    }
    if (pos == -1) {
        printf("Kart introuvable !\n");
        return;
    }

    if (*caisse < tab[pos].cout_revision) {
        printf("Fonds insuffisants dans la caisse pour payer la revision !\n");
        return;
    }

    *caisse -= tab[pos].cout_revision;
    tab[pos].compteur_courses = 0;
    strcpy(tab[pos].etat, "LIBRE");
    printf("Revision terminee ! Le Kart K%d est de nouveau LIBRE. Nouveau solde : %.2f\n", id, *caisse);
}
