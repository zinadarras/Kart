#include <stdio.h>
#include <stdlib.h>
#include "categorie.h"
#include "kart.h"
#include "pilote.h"
#include "course.h"
#include "ecurie.h"

int main() {

    Categorie tabCategories[MAX_CATEGORIES];
    int nbCategories = 0;

    Kart tabKarts[MAX_KARTS];
    int nbKarts = 0;

    Pilote tabPilotes[MAX_PILOTES];
    int nbPilotes = 0;

    Course tabCourses[MAX_COURSES];
    int nbCourses = 0;

    // Caisse initiale de l'ecurie (ex: 2000 pieces selon le CDC)
    float caisse = 2000.0;

    int choix;
    do {
        system("cls");
        printf("=====================================================\n");
        printf("            GESTION D'UNE ECURIE DE KARTING          \n");
        printf("=====================================================\n");
        printf("1. Gerer les categories\n");
        printf("2. Gerer les karts\n");
        printf("3. Gerer les pilotes\n");
        printf("4. Gerer les courses\n");
        printf("5. Consulter l'etat de l'ecurie / Caisse\n");
        printf("6. Maintenance & Revisions\n");
        printf("7. Quitter\n");
        printf("=====================================================\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: menuCategories(tabCategories, &nbCategories); break;
            case 2: menuKarts(tabKarts, &nbKarts, tabCategories, nbCategories, &caisse); break;
            case 3: menuPilotes(tabPilotes, &nbPilotes); break;
            case 4: menuCourses(tabCourses, &nbCourses, tabPilotes, nbPilotes, tabCategories, nbCategories); break;
            case 5: menuEcurie(caisse, nbKarts, nbPilotes, nbCourses); break;
            case 6: menuRevisions(tabKarts, nbKarts, &caisse); break;
            case 7:
                printf("\nFermeture du programme...\n");
                break;
            default:
                printf("\nChoix invalide. Appuyez sur Entree pour reessayer...");
                getchar(); getchar();
        }
    } while (choix != 7);

    return 0;
}
