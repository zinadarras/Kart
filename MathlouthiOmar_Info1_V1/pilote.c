#include <stdio.h>
#include <string.h>
#include "pilote.h"

int chercherPiloteParMatricule(Pilote tab[], int nb, int matricule) {
    for (int i = 0; i < nb; i++) {
        if (tab[i].matricule == matricule) {
            return i;
        }
    }
    return -1;
}

void ajouterPilote(Pilote tab[], int *nb) {
    if (*nb >= MAX_PILOTES) {
        printf("Erreur : Tableau des pilotes plein !\n");
        return;
    }
    Pilote p;
    p.matricule = (*nb == 0) ? 100 : tab[*nb - 1].matricule + 1;

    printf("Nom du pilote (sans espaces, ex: BenAli_Sami) : ");
    scanf("%s", p.nom);
    printf("Niveau (Debutant / Intermediaire / Expert) : ");
    scanf("%s", p.niveau);

    tab[*nb] = p;
    (*nb)++;
    printf("Pilote inscrit avec succes (Matricule: %d) !\n", p.matricule);
}

void afficherPilotes(Pilote tab[], int nb) {
    if (nb == 0) {
        printf("Aucun pilote inscrit.\n");
        return;
    }
    printf("\n--- LISTE DES PILOTES ---\n");
    for (int i = 0; i < nb; i++) {
        printf("Matricule: %d | Nom: %s | Niveau: %s\n",
               tab[i].matricule, tab[i].nom, tab[i].niveau);
    }
}

void modifierPilote(Pilote tab[], int nb) {
    if (nb == 0) {
        printf("Aucun pilote a modifier.\n");
        return;
    }
    afficherPilotes(tab, nb);
    int mat;
    printf("\nEntrez le matricule du pilote a modifier : ");
    scanf("%d", &mat);

    int pos = chercherPiloteParMatricule(tab, nb, mat);
    if (pos == -1) {
        printf("Pilote introuvable !\n");
        return;
    }

    printf("Nouveau nom : ");
    scanf("%s", tab[pos].nom);
    printf("Nouveau niveau : ");
    scanf("%s", tab[pos].niveau);

    printf("Pilote modifie avec succes !\n");
}

void supprimerPilote(Pilote tab[], int *nb) {
    if (*nb == 0) {
        printf("Aucun pilote a supprimer.\n");
        return;
    }
    afficherPilotes(tab, *nb);
    int mat;
    printf("\nEntrez le matricule du pilote a supprimer : ");
    scanf("%d", &mat);

    int pos = chercherPiloteParMatricule(tab, *nb, mat);
    if (pos == -1) {
        printf("Pilote introuvable !\n");
        return;
    }

    for (int i = pos; i < *nb - 1; i++) {
        tab[i] = tab[i + 1];
    }
    (*nb)--;
    printf("Pilote supprime avec succes !\n");
}
