#ifndef KART_H_INCLUDED
#define KART_H_INCLUDED

#include <time.h>
#include "categorie.h"

#define MAX_KARTS 50

typedef struct {
    int identifiant;
    int id_categorie;       // Lien avec Categorie
    int max_courses;
    int compteur_courses;
    float prix;
    float cout_revision;
    char etat[20];          // "LIBRE", "EN_COURSE", "EN_ATTENTE", "REVISION"
    int course_en_cours;    // -1 si aucune
    time_t date_disponibilite;
} Kart;

// Fonctions CRUD (on passe aussi tabCat et *caisse car l'achat d'un kart deduit son prix de la caisse)
void ajouterKart(Kart tab[], int *nb, Categorie tabCat[], int nbCat, float *caisse);
void afficherKarts(Kart tab[], int nb);
void modifierKart(Kart tab[], int nb, Categorie tabCat[], int nbCat);
void supprimerKart(Kart tab[], int *nb);

// Fonctions de maintenance (pour le menu Revisions)
void afficherKartsEnAttente(Kart tab[], int nb);
void reviserKart(Kart tab[], int nb, float *caisse);

#endif // KART_H_INCLUDED
