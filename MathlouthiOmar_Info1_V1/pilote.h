#ifndef PILOTE_H_INCLUDED
#define PILOTE_H_INCLUDED

#define MAX_PILOTES 100

typedef struct {
    int matricule;
    char nom[50];
    char niveau[20]; // Debutant, Intermediaire, Expert
} Pilote;

// Fonctions CRUD
void ajouterPilote(Pilote tab[], int *nb);
void afficherPilotes(Pilote tab[], int nb);
void modifierPilote(Pilote tab[], int nb);
void supprimerPilote(Pilote tab[], int *nb);

// Fonction utilitaire (utile lors de l'inscription a une course)
int chercherPiloteParMatricule(Pilote tab[], int nb, int matricule);

#endif // PILOTE_H_INCLUDED
