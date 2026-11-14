#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include "pilote.h"
#include "categorie.h"
#include "kart.h"

#define MAX_COURSES 200

typedef struct {
    int identifiant;
    int matricule_pilote;   // Lien avec Pilote
    int id_categorie;       // Lien avec Categorie
    char etat[20];          // "en_attente", "en_cours", "realisee"
} Course;

// Fonctions CRUD
void ajouterCourse(Course tab[], int *nb, Pilote tabPil[], int nbPil, Categorie tabCat[], int nbCat);
void afficherCourses(Course tab[], int nb);
void modifierCourse(Course tab[], int nb);
void supprimerCourse(Course tab[], int *nb);

#endif // COURSE_H_INCLUDED
