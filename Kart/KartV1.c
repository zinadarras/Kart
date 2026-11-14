#include <stdio.h>
#include <time.h>
#define MAX_CATEGORIES 50
#define MAX_KARTS 50
#define MAX_PILOTES 100
#define MAX_COURSES 500

typedef enum {
    DEBUTANT,
    INTERMEDIAIRE,
    EXPERT
} Niveau;

typedef enum {
    LIBRE,
    EN_COURSE,
    ATTENTE_REVISION,
    REVISION
} EtatKart;

typedef enum {
    EN_ATTENTE,
    COURSE_EN_COURS,
    REALISEE
} EtatCourse;


typedef struct {
    int identifiant;
    char nom[30];
    float prix_inscription;
    int duree_reservation;
    Niveau niveau;
} Categorie;

typedef struct {
    int identifiant;
    int id_categorie;
    int max_courses;
    int compteur_courses;
    float prix;
    float cout_revision;
    EtatKart etat;
    int course_en_cours;
    time_t date_disponibilite;
} Kart;

typedef struct {
    int matricule;
    char nom[50];
    Niveau niveau;
} Pilote;

typedef struct {
    int identifiant;
    int matricule_pilote;
    int id_categorie;
    EtatCourse etat;
} Course;

typedef struct {
    Categorie categories[MAX_CATEGORIES];
    Kart karts[MAX_KARTS];
    Pilote pilotes[MAX_PILOTES];
    Course courses[MAX_COURSES];
    int nb_categories;
    int nb_karts;
    int nb_pilotes;
    int nb_courses;
    float caisse;
} Ecurie;

Ecurie ecurie;

void menuCategories() {
    int choix;

    do {
        printf("\n===== GESTION DES CATEGORIES =====\n");
        printf("1. Ajouter une categorie\n");
        printf("2. Modifier une categorie\n");
        printf("3. Afficher les categories\n");
        printf("4. Supprimer une categorie\n");
        printf("0. Retour\n");

        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1) {
            printf("\nChoix invalide !\n");
            while (getchar() != '\n');
            choix = -1;
            continue;
        }

        switch (choix) {
            case 1:
                printf("\nAjouter une categorie\n");
                break;

            case 2:
                printf("\nModifier une categorie\n");
                break;

            case 3:
                printf("\nAfficher les categories\n");
                break;

            case 4:
                printf("\nSupprimer une categorie\n");
                break;

            case 0:
                printf("\nRetour au menu principal\n");
                break;

            default:
                printf("\nChoix invalide !\n");
        }

    } while (choix != 0);
}


void menuKarts() {
    int choix;

    do {
        printf("\n===== GESTION DES KARTS =====\n");
        printf("1. Ajouter un kart\n");
        printf("2. Modifier un kart\n");
        printf("3. Afficher les karts\n");
        printf("4. Supprimer un kart\n");
        printf("0. Retour\n");

        printf("\nVotre choix : ");

        if (scanf("%d", &choix) != 1) {
            printf("\nChoix invalide !\n");
            while (getchar() != '\n');
            choix = -1;
            continue;
        }

        switch (choix) {
            case 1:
                printf("\nAjouter un kart\n");
                break;

            case 2:
                printf("\nModifier un kart\n");
                break;

            case 3:
                printf("\nAfficher les karts\n");
                break;

            case 4:
                printf("\nSupprimer un kart\n");
                break;

            case 0:
                printf("\nRetour au menu principal\n");
                break;

            default:
                printf("\nChoix invalide !\n");
        }

    } while (choix != 0);
}


void menuPilotes() {
    int choix;

    do {
        printf("\n===== GESTION DES PILOTES =====\n");
        printf("1. Ajouter un pilote\n");
        printf("2. Modifier un pilote\n");
        printf("3. Afficher les pilotes\n");
        printf("4. Supprimer un pilote\n");
        printf("0. Retour\n");

        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1) {
            printf("\nChoix invalide !\n");
            while (getchar() != '\n');
            choix = -1;
            continue;
        }

        switch (choix) {
            case 1:
                printf("\nAjouter un pilote\n");
                break;

            case 2:
                printf("\nModifier un pilote\n");
                break;

            case 3:
                printf("\nAfficher les pilotes\n");
                break;

            case 4:
                printf("\nSupprimer un pilote\n");
                break;

            case 0:
                printf("\nRetour au menu principal\n");
                break;

            default:
                printf("\nChoix invalide !\n");
        }

    } while (choix != 0);
}


void menuCourses() {
    int choix;

    do {
        printf("\n===== GESTION DES COURSES =====\n");
        printf("1. Ajouter une course\n");
        printf("2. Modifier une course\n");
        printf("3. Afficher les courses\n");
        printf("4. Supprimer une course\n");
        printf("0. Retour\n");

        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1) {
            printf("\nChoix invalide !\n");
            while (getchar() != '\n');
            choix = -1;
            continue;
        }

        switch (choix) {
            case 1:
                printf("\nAjouter une course\n");
                break;

            case 2:
                printf("\nModifier une course\n");
                break;

            case 3:
                printf("\nAfficher les courses\n");
                break;

            case 4:
                printf("\nSupprimer une course\n");
                break;

            case 0:
                printf("\nRetour au menu principal\n");
                break;

            default:
                printf("\nChoix invalide !\n");
        }

    } while (choix != 0);
}


void menuPrincipal() {
    int choix;

    do {
        printf("\n========== GESTION KARTING ==========\n");
        printf("1. Gestion des categories\n");
        printf("2. Gestion des karts\n");
        printf("3. Gestion des pilotes\n");
        printf("4. Gestion des courses\n");
        printf("5. Afficher la caisse\n");
        printf("0. Quitter\n");

        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1) {
            printf("\nChoix invalide !\n");
            while (getchar() != '\n');
            choix = -1;
            continue;
        }

        switch (choix) {
            case 1:
                menuCategories();
                break;

            case 2:
                menuKarts();
                break;

            case 3:
                menuPilotes();
                break;

            case 4:
                menuCourses();
                break;

            case 5:
                printf("\nSolde de la caisse : %.2f DT\n", ecurie.caisse);
                break;

            case 0:
                printf("\nAu revoir !\n");
                break;

            default:
                printf("\nChoix invalide !\n");
        }

    } while (choix != 0);
}

int main() {
    ecurie.nb_categories = 0;
    ecurie.nb_karts = 0;
    ecurie.nb_pilotes = 0;
    ecurie.nb_courses = 0;
    ecurie.caisse = 2000.0;
    menuPrincipal();
    return 0;
}
