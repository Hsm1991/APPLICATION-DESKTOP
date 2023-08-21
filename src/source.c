
#include "header.h"
#include <stdio.h>
#include <stdlib.h>



enum{
  IDE,
  NOM,
  TYPE,
  DATE,
  ENTREE,
  SUITE,
  DESSERT,
  COLUMNS
};


void ajouter(menu m)
{
  FILE* f;
  f=fopen("menu.txt","ab+");
  fprintf(f,"%d %s %s %s %s %s %d\n",m.id,m.nom,m.type,m.entree,m.suite,m.dessert,m.date);
  fclose(f);
}

void supprimer(int iden){
FILE* f;
FILE* ft;
f=fopen("menu.txt","r");
ft=fopen("tmp.txt","ab+");
    int id,date;
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
    char str[25];
while(fscanf(f,"%d %s %s %s %s %s %d\n",&id,nom,type,entree,suite,dessert,&date)!=EOF){
if (id!=iden){fprintf(ft,"%d %s %s %s %s %s %d\n",id,nom,type,entree,suite,dessert,date);}
}

fclose(f);
fclose(ft);
remove("menu.txt");
rename("tmp.txt","menu.txt");
}


void afficher(GtkWidget *liste){  //pointeur 3la treeview de type gtkwidget
    
    GtkCellRenderer *renderer; 
    GtkTreeViewColumn *column; 
    GtkTreeIter iter; 
    GtkListStore *store;
    int datee,id;
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
    
    store = NULL; 
    FILE *f;

    store = gtk_tree_view_get_model(liste);
    if(store == NULL){ 
    renderer = gtk_cell_renderer_text_new(); 
    column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",IDE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer =gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer =gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer =gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
  
    renderer =gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("entree",renderer,"text",ENTREE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
  
    renderer =gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("suite",renderer,"text",SUITE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer =gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("dessert",renderer,"text",DESSERT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    }
    store = gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    f=fopen("menu.txt","r");
  while(fscanf(f,"%d %s %s %s %s %s %d\n",&id,nom,type,entree,suite,dessert,&datee)!=EOF){
    printf("%d %s %s %s %s %s %d\n",id,nom,type,entree,suite,dessert,datee );
    gtk_list_store_append(store,&iter);
  gtk_list_store_set(store,&iter,IDE,id,TYPE,type,NOM,nom,DATE,datee,ENTREE,entree,SUITE,suite,DESSERT,dessert,-1);
}                
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
    g_object_unref(store);
        
}

void modifier(int identif,menu m){
  printf("%d\n",m.id );
FILE* f;
FILE* ft;
    int id,date;
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
    char str[25];
f=fopen("menu.txt","r");
ft=fopen("tmp.txt","ab+");

while(fscanf(f,"%d %s %s %s %s %s %d\n",&id,nom,type,entree,suite,dessert,&date)!=EOF)
{
  if (identif==id ) {fprintf(ft,"%d %s %s %s %s %s %d\n",m.id,m.nom,m.type,m.entree,m.suite,m.dessert,m.date);}
  else {fprintf(ft,"%d %s %s %s %s %s %d\n",id,nom,type,entree,suite,dessert,date);}
}

fclose(f);
fclose(ft);
remove("menu.txt");
rename("tmp.txt","menu.txt");
}


void  chercher2(GtkWidget *liste,int ident)
{
  
    GtkCellRenderer *renderer; 
    GtkTreeViewColumn *column; 
    GtkTreeIter iter; 
    GtkListStore *store;
    int datee,id;
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
    
    store = NULL; 
    FILE *f;

    store = gtk_tree_view_get_model(liste);
    if(store == NULL){ 
    renderer = gtk_cell_renderer_text_new(); 
    column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",IDE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer =gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer =gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer =gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
  
    renderer =gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("entree",renderer,"text",ENTREE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
  
    renderer =gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("suite",renderer,"text",SUITE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer =gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("dessert",renderer,"text",DESSERT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    }
    store = gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    f=fopen("menu.txt","r");
  while(fscanf(f,"%d %s %s %s %s %s %d\n",&id,nom,type,entree,suite,dessert,&datee)!=EOF){
    if (id==ident){
    printf("%d %s %s %s %s %s %d\n",id,nom,type,entree,suite,dessert,datee );
    gtk_list_store_append(store,&iter);
  gtk_list_store_set(store,&iter,IDE,id,TYPE,type,NOM,nom,DATE,datee,ENTREE,entree,SUITE,suite,DESSERT,dessert,-1);
} 
}               
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
    g_object_unref(store);
}


void nbEtudiant(int *n1, int *n2, int *n3, int *n4, int *n5){
  printf("7\n");
  FILE *f=NULL;
  char cin[20];
  int niveau;
  f=fopen("etudiants.txt","r");
   while(fscanf(f,"%s %d\n",cin,&niveau)!=EOF){
    if (niveau==1){
      (*n1)++;  
    }
    else if (niveau==2){
      (*n2)++;  
    }
    else if (niveau==3){
      (*n3)++;  
    }
    else if (niveau==4){
      (*n4)++;  
    }
    else if (niveau==5){
      (*n5)++;  
    }
  }
  printf("%d %d %d %d %d",*n1,*n2,*n3,*n4,*n5);
}
