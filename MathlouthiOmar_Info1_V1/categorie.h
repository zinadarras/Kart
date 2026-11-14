#ifndef CATEGORIE_H_INCLUDED
#define CATEGORIE_H_INCLUDED

#define MAX_CATEGORIES 50

typedef struct {
    int identifiant;
    char nom[30];
    float prix_inscription;
    int duree_reservation; // en minutes
    char niveau[20];       // Debutant, Intermediaire, Expert
} Categorie;

// Fonctions CRUD
void ajouterCategorie(Categorie tab[], int *nb);
void afficherCategories(Categorie tab[], int nb);
void modifierCategorie(Categorie tab[], int nb);
void supprimerCategorie(Categorie tab[], int *nb);

// Fonction utilitaire (utile pour verifier si un ID existe lors de l'ajout d'un kart)
int chercherCategorieParId(Categorie tab[], int nb, int id);

#endif // CATEGORIE_H_INCLUDED
