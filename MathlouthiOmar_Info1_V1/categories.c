#include <stdio.h>
#include <string.h>
#include "categorie.h"

int chercherCategorieParId(Categorie tab[], int nb, int id) {
    for (int i = 0; i < nb; i++) {
        if (tab[i].identifiant == id) {
            return i;
        }
    }
    return -1;
}

void ajouterCategorie(Categorie tab[], int *nb) {
    if (*nb >= MAX_CATEGORIES) {
        printf("Erreur : Tableau des categories plein !\n");
        return;
    }
    Categorie c;
    // Auto-generation de l'ID (max ID existant + 1)
    c.identifiant = (*nb == 0) ? 1 : tab[*nb - 1].identifiant + 1;

    printf("Nom de la categorie (ex: Sprint, Endurance) : ");
    scanf("%s", c.nom);
    printf("Prix d'inscription (en pieces) : ");
    scanf("%f", &c.prix_inscription);
    printf("Duree de reservation (en minutes) : ");
    scanf("%d", &c.duree_reservation);
    printf("Niveau (Debutant / Intermediaire / Expert) : ");
    scanf("%s", c.niveau);

    tab[*nb] = c;
    (*nb)++;
    printf("Categorie '%s' ajoutee avec succes (ID: %d) !\n", c.nom, c.identifiant);
}

void afficherCategories(Categorie tab[], int nb) {
    if (nb == 0) {
        printf("Aucune categorie enregistree.\n");
        return;
    }
    printf("\n--- LISTE DES CATEGORIES ---\n");
    for (int i = 0; i < nb; i++) {
        printf("ID: %d | Nom: %s | Prix: %.2f | Duree: %d min | Niveau: %s\n",
               tab[i].identifiant, tab[i].nom, tab[i].prix_inscription,
               tab[i].duree_reservation, tab[i].niveau);
    }
}

void modifierCategorie(Categorie tab[], int nb) {
    if (nb == 0) {
        printf("Aucune categorie a modifier.\n");
        return;
    }
    afficherCategories(tab, nb);
    int id;
    printf("\nEntrez l'ID de la categorie a modifier : ");
    scanf("%d", &id);

    int pos = chercherCategorieParId(tab, nb, id);
    if (pos == -1) {
        printf("Categorie introuvable !\n");
        return;
    }

    printf("Nouveau nom : ");
    scanf("%s", tab[pos].nom);
    printf("Nouveau prix d'inscription : ");
    scanf("%f", &tab[pos].prix_inscription);
    printf("Nouvelle duree (min) : ");
    scanf("%d", &tab[pos].duree_reservation);
    printf("Nouveau niveau : ");
    scanf("%s", tab[pos].niveau);

    printf("Categorie modifiee avec succes !\n");
}

void supprimerCategorie(Categorie tab[], int *nb) {
    if (*nb == 0) {
        printf("Aucune categorie a supprimer.\n");
        return;
    }
    afficherCategories(tab, *nb);
    int id;
    printf("\nEntrez l'ID de la categorie a supprimer : ");
    scanf("%d", &id);

    int pos = chercherCategorieParId(tab, *nb, id);
    if (pos == -1) {
        printf("Categorie introuvable !\n");
        return;
    }

    for (int i = pos; i < *nb - 1; i++) {
        tab[i] = tab[i + 1];
    }
    (*nb)--;
    printf("Categorie supprimee avec succes !\n");
}
