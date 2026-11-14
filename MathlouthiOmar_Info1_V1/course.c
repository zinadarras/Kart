#include <stdio.h>
#include <string.h>
#include "course.h"

void ajouterCourse(Course tab[], int *nb, Pilote tabPil[], int nbPil, Categorie tabCat[], int nbCat) {
    if (*nb >= MAX_COURSES) {
        printf("Erreur : Tableau des courses plein !\n");
        return;
    }
    if (nbPil == 0 || nbCat == 0) {
        printf("Erreur : Il faut au moins un pilote et une categorie pour creer une course !\n");
        return;
    }

    afficherPilotes(tabPil, nbPil);
    int mat;
    printf("\nEntrez le matricule du pilote : ");
    scanf("%d", &mat);
    if (chercherPiloteParMatricule(tabPil, nbPil, mat) == -1) {
        printf("Pilote introuvable !\n");
        return;
    }

    afficherCategories(tabCat, nbCat);
    int idCat;
    printf("\nEntrez l'ID de la categorie choisie : ");
    scanf("%d", &idCat);
    if (chercherCategorieParId(tabCat, nbCat, idCat) == -1) {
        printf("Categorie introuvable !\n");
        return;
    }

    Course c;
    c.identifiant = (*nb == 0) ? 1 : tab[*nb - 1].identifiant + 1;
    c.matricule_pilote = mat;
    c.id_categorie = idCat;
    strcpy(c.etat, "en_attente");

    tab[*nb] = c;
    (*nb)++;
    printf("Inscription/Course #%d enregistree (Etat : en_attente) !\n", c.identifiant);
}

void afficherCourses(Course tab[], int nb) {
    if (nb == 0) {
        printf("Aucune course enregistree.\n");
        return;
    }
    printf("\n--- LISTE DES COURSES ---\n");
    for (int i = 0; i < nb; i++) {
        printf("Course #%d | Pilote Mat: %d | Cat ID: %d | Etat: %s\n",
               tab[i].identifiant, tab[i].matricule_pilote, tab[i].id_categorie, tab[i].etat);
    }
}

void modifierCourse(Course tab[], int nb) {
    if (nb == 0) {
        printf("Aucune course a modifier.\n");
        return;
    }
    afficherCourses(tab, nb);
    int id, pos = -1;
    printf("\nEntrez l'ID de la course a modifier : ");
    scanf("%d", &id);

    for (int i = 0; i < nb; i++) {
        if (tab[i].identifiant == id) { pos = i; break; }
    }
    if (pos == -1) {
        printf("Course introuvable !\n");
        return;
    }

    printf("Nouvel etat (en_attente / en_cours / realisee) : ");
    scanf("%s", tab[pos].etat);
    printf("Course modifiee avec succes !\n");
}

void supprimerCourse(Course tab[], int *nb) {
    if (*nb == 0) {
        printf("Aucune course a supprimer.\n");
        return;
    }
    afficherCourses(tab, *nb);
    int id, pos = -1;
    printf("\nEntrez l'ID de la course a supprimer : ");
    scanf("%d", &id);

    for (int i = 0; i < *nb; i++) {
        if (tab[i].identifiant == id) { pos = i; break; }
    }
    if (pos == -1) {
        printf("Course introuvable !\n");
        return;
    }

    for (int i = pos; i < *nb - 1; i++) {
        tab[i] = tab[i + 1];
    }
    (*nb)--;
    printf("Course supprimee avec succes !\n");
}
