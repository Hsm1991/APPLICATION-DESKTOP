#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include "fonction.h"
typedef struct
{
    int jour;
    int mois;
    int annee;
}Date;
typedef struct
{
    Date date;
    char nom[20];
    char prenom[20];
    char ID[20];
    char type_reclamation[20];
    int numero_reclamation;
    char text_reclamation[1000];
}reclamation;
typedef struct
{
    int jour1;
    int mois1;
    int annee1;
    char nom[20];
    char prenom[20];
    char ID[20];
    char type_reclamation[20];
    char numero_reclamation[20];
    char text_reclamation[1000];
}Reclamations;
typedef struct
{
    char jour1[20];
    char mois1[20];
    char annee1[20];
    char nom[20];
    char prenom[20];
    char ID[20];
    char type_reclamation[20];
    char numero_reclamation[20];
    char text_reclamation[1000];
}Reclamation;

void ajouter_reclam(Reclamations r);
void modifier_reclam(Reclamation p ,Reclamations r);
void afficher_reclam(void);
void supprimer_reclam(Reclamation p);
void chercher(char n[20],char p[20],GtkWidget *liste);
void test(reclamation r);
void affich(GtkWidget *liste);
void leplusreclamer(GtkWidget *liste);


#endif // FONCTION_H_INCLUDED

