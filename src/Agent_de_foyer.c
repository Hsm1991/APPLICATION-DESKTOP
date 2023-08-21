#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "AF.h"
#include <stdlib.h>
enum
{
	NOM,
	PRENOM,
	DATE,
	NIVEAU,
	CHAMBRE,
	CIN,
	TEL,
	COLUMNS,
};
enum
{
	JOUR,
	HEURE,
	ID1,
	VALEUR,
	COLUMNS1
};
//ajouter
void ajouter2(Etudiant E,char txt[])
{
    FILE *f;
    f=fopen(txt,"a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %d %d %d %s %d %d %d\n",E.nom,E.prenom,E.naissance.jour,E.naissance.mois,E.naissance.annee,E.niveau.niv,E.niveau.spec,E.chambre,E.CIN,E.tel);
        fclose(f);
    }
}


//chercher
Etudiant rechercher(int cn)
{
    FILE *f;
    Etudiant E;
    char ch1[30];
    char ch2[30];
    int a,b,c,d,e,g,h/*cn,tro=0*/;
    char ch3[20];
    f=fopen("etudiant.txt","r");
    /*printf("CIN de l'etudiant vollu :");
    scanf("%d",&cn);*/
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %s %d %d %d \n",ch1,ch2,&a,&b,&c,&d,ch3,&e,&g,&h)!= EOF)
        {
            if(cn==g)
            {
              strcpy(E.nom,ch1);strcpy(E.prenom,ch2);E.naissance.jour=a;E.naissance.mois=b;E.naissance.annee=c;
	      E.niveau.niv=d;strcpy(E.niveau.spec,ch3);E.chambre=e;E.CIN=g;E.tel=h;  
            }
        }
        /*if(tro==0)
        {
            printf("Etudiant n'existe pas!\n");
        }*/
    }
    fclose(f);
    return E;
}

//modifier
void modifier2(char id[30],Etudiant e)
{
    
    Etudiant e2;
	FILE *f;
	FILE *f2;
	f=fopen("etudiant.txt","r");
	f2=fopen("tmp.txt","a+");
	g_print("%s",id);
    if(f!=NULL)
    {
	while (fscanf(f,"%s %s %d %d %d %d %s %d %d %d\n", e2.nom,e2.prenom,&e2.naissance.jour,&e2.naissance.mois,&e2.naissance.annee,&e2.niveau.niv,e2.niveau.spec,&e2.chambre,&e2.CIN,&e2.tel)!= EOF){
		g_print("3");
		if (atoi(id)==e2.CIN){
			
			fprintf(f2,"%s %s %d %d %d %d %s %d %d %d \n",e.nom,e.prenom,e2.naissance.jour,e2.naissance.mois,e2.naissance.annee,e.niveau.niv,e2.niveau.spec,e.chambre,e.CIN,e.tel);}
		else 
			fprintf(f2,"%s %s %d %d %d %d %s %d %d %d \n",e2.nom,e2.prenom,e2.naissance.jour,e2.naissance.mois,e2.naissance.annee,e2.niveau.niv,e2.niveau.spec,e2.chambre,e2.CIN,e2.tel);
	}
	fclose(f);
	fclose(f2);

	remove("etudiant.txt");
	rename("tmp.txt","etudiant.txt");
    }
}


//supprimer
void supprimer2(char id[20])
{
    FILE *f,*l;
    char ch1[30];
    char ch2[30];
    int a,b,c,d,e,g,h;
    char ch3[20],gstr[10];
    f=fopen("etudiant.txt","r");
    l=fopen("tmp.txt","w");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %s %d %d %d \n",ch1,ch2,&a,&b,&c,&d,ch3,&e,&g,&h)!= EOF)
        {
	    sprintf(gstr,"%d",g);
            if ((strcmp(id,gstr)!=0))
            {
                fprintf(l,"%s %s %d %d %d %d %s %d %d %d \n",ch1,ch2,a,b,c,d,ch3,e,g,h);
            }
        }
    }
    fclose(f);
    fclose(l);
    remove("etudiant.txt");
    rename("tmp.txt","etudiant.txt");
}

//afficher
void afficher2(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    char ch1[30];
    char ch2[30];
    int a,b,c,d,e,g,h;
    char ch3[20],nai[100],cat[100];
    store=NULL;

    FILE *f;

    //
    if(store==NULL)
    {
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Date de naissance",renderer,"text",DATE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Niveau",renderer,"text",NIVEAU,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    column = gtk_tree_view_column_new_with_attributes("Chambre",renderer,"text",CHAMBRE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("N°cin",renderer,"text",CIN,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("N°tel",renderer,"text",TEL,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();

    store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

    f=fopen("etudiant.txt","r");

    if(f==NULL)
    {return;}
    else
    {
     f=fopen("etudiant.txt","a+");
     while(fscanf(f,"%s %s %d %d %d %d %s %d %d %d \n",ch1,ch2,&a,&b,&c,&d,ch3,&e,&g,&h)!= EOF)
        {
	    sprintf(cat,"%d",a);
	strcpy(nai,strcat(cat,"/"));
	sprintf(cat,"%d",b);
	strcat(nai,strcat(cat,"/"));
	sprintf(cat,"%d",c);
	strcat(nai,cat);
	sprintf(cat,"%d",d);
	strcat(cat,ch3);
	    gtk_list_store_append(store,&iter);
	    gtk_list_store_set(store,&iter,NOM,ch1,PRENOM,ch2,DATE,nai,NIVEAU,cat,CHAMBRE,e,CIN,g,TEL,h,-1);
        }
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref (store);
    }
    }   
}

void niveau()
{


 FILE *f;
    char ch1[30];
    char ch2[30];
    int a,b,c,d,e,g,h,s1=0,s2=0,s3=0,s4=0,s5=0,ni;
    char ch3[20];
    f=fopen("etudiant.txt","r");
  if(f!=NULL)
  {
        
          
		while(fscanf(f,"%s %s %d %d %d %d %s %d %d %d \n",ch1,ch2,&a,&b,&c,&d,ch3,&e,&g,&h)!= EOF)
			
        	{ 		if(d==1)

                                 {
                                  s1++;

                                 }

  				if(d==2)
                                {
                                 s2++;

                                }

 				if(d==3)
                                {
              			 s3++;

            			}

 				if(d==4)
            			{
              			s4++;

            			}

 				if(d==5)
            			{
              			s5++;

            			}
       
    		}

	do
            {
		
                printf("entrer votre choix \n");
                printf("0.Terminer \n1.1ère année \n2. 2ème année  \n3. 3e année \n4. 4e année\n5. 5e année \n");
                scanf("%d",&ni);
           
		 switch (ni)
                	{
                    

                    case 1 :    
				printf(" Le nombre d'étudiants en premiere  année est %d \n",s1);
                                break;

                    case 2 :      
                                printf(" Le nombre d'étudiants en premiere  année est %d \n",s2);
                                break;

                    case 3 :     
                                printf(" Le nombre d'étudiants en premiere  année est %d \n",s3);
                                break;

                    case 4 :     
				printf(" Le nombre d'étudiants en premiere  année est %d \n",s4);
                                break;

                    case 5 :      
				printf(" Le nombre d'étudiants en premiere  année est %d \n",s5);
                                break;
               
		}
	}while(ni>0 && ni<6);
        //}while(ni>0 && ni<6);
 }
    fclose(f);
	}


void afficher3(GtkWidget *liste,char id5[20])
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    char ch1[30];
    char ch2[30];
    int a,b,c,d,e,g,h;
    char ch3[20],nai[100],cat[100];
    store=NULL;

    FILE *f;

    //
    if(store==NULL)
    {
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Date de naissance",renderer,"text",DATE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Niveau",renderer,"text",NIVEAU,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    column = gtk_tree_view_column_new_with_attributes("Chambre",renderer,"text",CHAMBRE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("N°cin",renderer,"text",CIN,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("N°tel",renderer,"text",TEL,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();

    store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

    f=fopen("etudiant.txt","r");

    if(f==NULL)
    {return;}
    else
    {
     f=fopen("etudiant.txt","a+");
     while(fscanf(f,"%s %s %d %d %d %d %s %d %d %d \n",ch1,ch2,&a,&b,&c,&d,ch3,&e,&g,&h)!= EOF)
        {
		if (atoi(id5)==g){
			    sprintf(cat,"%d",a);
			strcpy(nai,strcat(cat,"/"));
			sprintf(cat,"%d",b);
			strcat(nai,strcat(cat,"/"));
			sprintf(cat,"%d",c);
			strcat(nai,cat);
			sprintf(cat,"%d",d);
			strcat(cat,ch3);
			    gtk_list_store_append(store,&iter);
			    gtk_list_store_set(store,&iter,NOM,ch1,PRENOM,ch2,DATE,nai,NIVEAU,cat,CHAMBRE,e,CIN,g,TEL,h,-1);
		}
        }
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref (store);
    }
    }   
}
void alarme(GtkWidget *liste, char *fname, char *fname1)
{
mesure p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar statut[20];
FILE *f, *g;


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Jour", renderer,"text",JOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Heure", renderer,"text",HEURE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID", renderer,"text",ID1, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Valeur", renderer,"text",VALEUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);



store=gtk_list_store_new(COLUMNS1, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);
f=fopen(fname,"r");
if(f!=NULL)
{
		while(fscanf(f,"%d %d %d %d\n",&(p.jour),&(p.heure),&(p.id),&(p.valeur))!=EOF)
	{
if(p.valeur==1&&p.heure>=0&&p.heure<6){
sprintf(statut,"Mouvement");
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,JOUR,p.jour,HEURE,p.heure,ID1,p.id,VALEUR,statut,-1);
}
	}
	fclose(f);
g=fopen(fname1,"r");
if(f!=NULL)
{
		while(fscanf(g,"%d %d %d %d\n",&(p.jour),&(p.heure),&(p.id),&(p.valeur))!=EOF)
	{
if(p.valeur==1&&p.heure>=0&&p.heure<6){
sprintf(statut,"Fumée");
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,JOUR,p.jour,HEURE,p.heure,ID1,p.id,VALEUR,statut,-1);
}
	}
	fclose(g);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
}


