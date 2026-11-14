#ifndef ECURIE_H_INCLUDED
#define ECURIE_H_INCLUDED

#include "categorie.h"
#include "kart.h"
#include "pilote.h"
#include "course.h"

void menuCategories(Categorie tabCat[], int *nbCat);
void menuKarts(Kart tabKarts[], int *nbKarts, Categorie tabCat[], int nbCat, float *caisse);
void menuPilotes(Pilote tabPil[], int *nbPil);
void menuCourses(Course tabCourses[], int *nbCourses, Pilote tabPil[], int nbPil, Categorie tabCat[], int nbCat);
void menuEcurie(float caisse, int nbKarts, int nbPilotes, int nbCourses);
void menuRevisions(Kart tabKarts[], int nbKarts, float *caisse);

#endif // ECURIE_H_INCLUDED
