#include <stdio.h>
#include <stdlib.h>
#include "ecurie.h"

void menuCategories(Categorie tabCat[], int *nbCat) {
    int choix;
    do {
        system("cls");
        printf("=========== GERER LES CATEGORIES ===========\n");
        printf("1) Ajouter une categorie\n");
        printf("2) Afficher les categories\n");
        printf("3) Modifier une categorie\n");
        printf("4) Supprimer une categorie\n");
        printf("5) Retour menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: ajouterCategorie(tabCat, nbCat); break;
            case 2: afficherCategories(tabCat, *nbCat); break;
            case 3: modifierCategorie(tabCat, *nbCat); break;
            case 4: supprimerCategorie(tabCat, nbCat); break;
            case 5: break;
            default: printf("Choix invalide!\n");
        }
        if (choix != 5) {
            printf("\nAppuyez sur Entree pour continuer...");
            getchar(); getchar();
        }
    } while(choix != 5);
}

void menuKarts(Kart tabKarts[], int *nbKarts, Categorie tabCat[], int nbCat, float *caisse) {
    int choix;
    do {
        system("cls");
        printf("=========== GERER LES KARTS ===========\n");
        printf("1) Ajouter (acheter) un kart\n");
        printf("2) Afficher tous les karts\n");
        printf("3) Modifier un kart\n");
        printf("4) Supprimer un kart\n");
        printf("5) Retour menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: ajouterKart(tabKarts, nbKarts, tabCat, nbCat, caisse); break;
            case 2: afficherKarts(tabKarts, *nbKarts); break;
            case 3: modifierKart(tabKarts, *nbKarts, tabCat, nbCat); break;
            case 4: supprimerKart(tabKarts, nbKarts); break;
            case 5: break;
            default: printf("Choix invalide!\n");
        }
        if (choix != 5) {
            printf("\nAppuyez sur Entree pour continuer...");
            getchar(); getchar();
        }
    } while(choix != 5);
}

void menuPilotes(Pilote tabPil[], int *nbPil) {
    int choix;
    do {
        system("cls");
        printf("=========== GERER LES PILOTES ===========\n");
        printf("1) Inscrire un pilote\n");
        printf("2) Afficher les pilotes\n");
        printf("3) Modifier un pilote\n");
        printf("4) Supprimer un pilote\n");
        printf("5) Retour menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: ajouterPilote(tabPil, nbPil); break;
            case 2: afficherPilotes(tabPil, *nbPil); break;
            case 3: modifierPilote(tabPil, *nbPil); break;
            case 4: supprimerPilote(tabPil, nbPil); break;
            case 5: break;
            default: printf("Choix invalide!\n");
        }
        if (choix != 5) {
            printf("\nAppuyez sur Entree pour continuer...");
            getchar(); getchar();
        }
    } while(choix != 5);
}

void menuCourses(Course tabCourses[], int *nbCourses, Pilote tabPil[], int nbPil, Categorie tabCat[], int nbCat) {
    int choix;
    do {
        system("cls");
        printf("=========== GERER LES COURSES ===========\n");
        printf("1) Ajouter une inscription / course\n");
        printf("2) Afficher les courses\n");
        printf("3) Modifier une course\n");
        printf("4) Supprimer une course\n");
        printf("5) Retour menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: ajouterCourse(tabCourses, nbCourses, tabPil, nbPil, tabCat, nbCat); break;
            case 2: afficherCourses(tabCourses, *nbCourses); break;
            case 3: modifierCourse(tabCourses, *nbCourses); break;
            case 4: supprimerCourse(tabCourses, nbCourses); break;
            case 5: break;
            default: printf("Choix invalide!\n");
        }
        if (choix != 5) {
            printf("\nAppuyez sur Entree pour continuer...");
            getchar(); getchar();
        }
    } while(choix != 5);
}

void menuEcurie(float caisse, int nbKarts, int nbPilotes, int nbCourses) {
    system("cls");
    printf("=========== ETAT DE L'ECURIE ===========\n");
    printf("Solde actuel de la caisse : %.2f pieces\n", caisse);
    printf("Nombre de karts dans la flotte : %d\n", nbKarts);
    printf("Nombre de pilotes inscrits : %d\n", nbPilotes);
    printf("Nombre total de courses enregistrees : %d\n", nbCourses);
    printf("========================================\n");
    printf("\nAppuyez sur Entree pour revenir au menu principal...");
    getchar(); getchar();
}

void menuRevisions(Kart tabKarts[], int nbKarts, float *caisse) {
    int choix;
    do {
        system("cls");
        printf("=========== MAINTENANCE & REVISIONS ===========\n");
        printf("1) Karts en attente de revision\n");
        printf("2) Effectuer la revision d'un kart\n");
        printf("3) Retour menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: afficherKartsEnAttente(tabKarts, nbKarts); break;
            case 2: reviserKart(tabKarts, nbKarts, caisse); break;
            case 3: break;
            default: printf("Choix invalide!\n");
        }
        if (choix != 3) {
            printf("\nAppuyez sur Entree pour continuer...");
            getchar(); getchar();
        }
    } while(choix != 3);
}
