#ifndef AF_H_INCLUDED
#define AF_H_INCLUDED

#include <gtk/gtk.h>
typedef struct
{
  int jour;
  int mois;
  int annee;
}date;
typedef struct
{
  char spec[30];
  int niv;
}classe;
typedef struct
{
  char nom[30];
  char prenom[30];
  date naissance;
  classe niveau;
  int chambre;
  int CIN;
  int tel;
}Etudiant;
typedef struct mesure
{
    int jour;
    int heure;
    int id;
    int valeur;
}mesure;
void ajouter2(Etudiant E,char txt[]);
Etudiant rechercher(int cn);
void modifier2(char id[20],Etudiant e);
void supprimer2(char id[20]);
void afficher2(GtkWidget *liste);
void niveau();

#endif // AF_H_INCLUDED
