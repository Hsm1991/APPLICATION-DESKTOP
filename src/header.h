#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
typedef struct menu{
    int id,date ;
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
}menu;

void ajouter(menu m);
void modifier(int identif,menu m);
void supprimer(int iden);
void cherche2r(GtkWidget *liste,int ident);
void afficher(GtkWidget *liste);
void nbEtudiant(int *n1, int *n2, int *n3, int *n4, int *n5);

#endif // HEADER_H_INCLUDED
