#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include "fonction2.c"
#include "stock.h"
#include "stock.c"
#include "header.h"
#include  "AF.h"
char user_id[20],mot_pass[20];
void
on_button1_login_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *entry,*eye;
	entry=lookup_widget(button,"entry1_login");
	
	GtkWidget *image1,*image2;
	image1=lookup_widget(button,"image2_login");
	image2=lookup_widget(button,"image3_login");
	eye=lookup_widget(button,"button259_login");
	
	GtkWidget *label1,*label2;
	label1=lookup_widget(button,"label3_login");
	label2=lookup_widget(button,"label4_login");

	GtkWidget *window1,*window2;
	window1=lookup_widget(button,"Login");
	if (gtk_widget_get_visible(image1)){
		gtk_widget_set_visible(label1,FALSE);
		gtk_widget_set_visible(image1,FALSE);
		gtk_widget_set_visible(eye,TRUE);
		gtk_entry_set_visibility (GTK_ENTRY (entry), FALSE);
		gtk_widget_set_visible(label2,TRUE);
		gtk_widget_set_visible(image2,TRUE);
		gtk_widget_set_visible(image2,TRUE);
		strcpy(user_id,gtk_entry_get_text(entry));
		gtk_entry_set_text(entry,"");
	}
	else {
		strcpy(mot_pass,gtk_entry_get_text(entry));
		g_print("%s %s",user_id,mot_pass);
		if (strcmp(user_id,"admin")==0 & strcmp(mot_pass,"admin")==0){
			window2=create_afficher_user();
			gtk_widget_show(window2);
			gtk_widget_destroy(window1);
		}
		else if (strcmp(user_id,"ahmed")==0 & strcmp(mot_pass,"1234")==0){
		window2=create_Page_accueil();
		gtk_widget_show(window2);
		gtk_widget_destroy(window1);}
	}
}



reclamation r;
int x;
int g[2]={0,0};
char h[20]="hebergement";
char d[20]="restauration";
Reclamation R;


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
int a;
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* ID;
gchar* type;
gchar* numero;
gchar* text;

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{

gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&jour,1,&mois,2,&annee,3,&nom,4,&prenom,5,&ID,6,&type,7,&numero,8,&text,-1);
strcpy(R.jour1,jour);
strcpy(R.mois1,mois);
strcpy(R.annee1,annee);
strcpy(R.nom,nom);
strcpy(R.prenom,prenom);
strcpy(R.ID,ID);
strcpy(R.type_reclamation,type);
strcpy(R.numero_reclamation,numero);
strcpy(R.text_reclamation,text);

}
}


void
on_button4_mod_clicked                 (GtkButton       *button,
                                        gpointer         user_data) 
{

GtkWidget *windowmod;
windowmod=create_modification();
gtk_widget_show (windowmod);


}


void
on_button5_rech_clicked                (GtkWidget       *objet_graphique,gpointer  user_data)


{

GtkWidget *treeview11;

treeview11=lookup_widget(objet_graphique,"treeview1_reclamation");
char id[20];
char np[20];

GtkWidget *identifiant;
GtkWidget *num;

identifiant=lookup_widget(objet_graphique,"enterderecherche");
num=lookup_widget(objet_graphique,"entryderecherche2");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(identifiant)));
strcpy(np,gtk_entry_get_text(GTK_ENTRY(num)));
chercher(id,num,treeview11);



}


void
on_alignment4_check_resize             (GtkContainer    *container,
                                        gpointer         user_data)
{

}


void
on_button2_ajout_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowadd;
windowadd=create_ajoutdereclamation();
gtk_widget_show (windowadd);

}




void
on_button6_aficher_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview;

treeview=lookup_widget(objet,"treeview1_reclamation");
affich(treeview);

}


void
on_button9j_ajout_loula_clicked        (GtkWidget       *objet_graphique,gpointer  user_data)
{
Reclamations r;
int e;
char s;


GtkWidget *nom, *prenom, *id, *type, *text, *numr;
GtkWidget *jouro;
GtkWidget *moiso;
GtkWidget *annneo;
nom=lookup_widget(objet_graphique,"entry55_NOM");
prenom=lookup_widget(objet_graphique,"entryss_prenom");
id=lookup_widget(objet_graphique,"entryrr_id");
text=lookup_widget(objet_graphique,"entry_textq");
numr=lookup_widget(objet_graphique,"entreyomyheart");
jouro=lookup_widget(objet_graphique,"spinbutton101");
moiso=lookup_widget(objet_graphique,"spinbutton233");
annneo=lookup_widget(objet_graphique,"comboboxentry101");




r.jour1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jouro));
r.mois1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moiso));
if(strcmp("2021",gtk_combo_box_get_active_text(GTK_COMBO_BOX(annneo)))==0)
r.annee1=2021;
else
r.annee1=2022;






strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(r.ID,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(r.text_reclamation,gtk_entry_get_text(GTK_ENTRY(text)));
strcpy(r.numero_reclamation,gtk_entry_get_text(GTK_ENTRY(numr)));
if(x==1)

{
strcpy(r.type_reclamation,h);
}
else if(x==2)
{
strcpy(r.type_reclamation,d);
}

ajouter_reclam(r);



}


void
on_radiobutton3_hebergement_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
x=1;

}


void
on_radiobutton1_restauration_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
x=2;

}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_checkbutton1_yess_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
g[1]=2;

}


void
on_checkbutton2_ssa_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
g[0]=1;

}


void
on_modification23_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{










Reclamations r1;
int t;
int x=1 ;
char z[20] ;



GtkWidget *jour,*mois,*annee,*nom, *prenom, *id, *type, *text,*numc;

nom=lookup_widget(objet,"entry1nomh");
prenom=lookup_widget(objet,"entry2prenom");
id=lookup_widget(objet,"entrydeid2");
text=lookup_widget(objet,"entrykiko");
numc=lookup_widget(objet,"entrydenumdereclam");
jour=lookup_widget(objet,"spinbutton235JOUR");
mois=lookup_widget(objet,"spinbutton234MOIS");
annee=lookup_widget(objet,"comboboxentry102999");
r1.jour1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
r1.mois1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
if(strcmp("2021",gtk_combo_box_get_active_text(GTK_COMBO_BOX(annee)))==0)
r1.annee1=2021;
else
r1.annee1=2022;


       
strcpy(r1.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(r1.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(r1.ID,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(r1.text_reclamation,gtk_entry_get_text(GTK_ENTRY(text)));
strcpy(r1.numero_reclamation,gtk_entry_get_text(GTK_ENTRY(numc)));
if(x==1)
{
strcpy(r.type_reclamation,h);
}
else if(x==2)
{
strcpy(r.type_reclamation,d);
}

modifier_reclam(R,r1);
}





void
on_buttonbaby44_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget *windore;
windore=create_CONFIRMATION();
gtk_widget_show (windore);



}


void
on_button7_confirmer_desuprimer_clicked

                                        
                                        (GtkWidget  *objet,
                                        gpointer         user_data)
{


if(g[1]==2)

supprimer_reclam(R);








}




void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}



void
on_button5_accueil_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1=lookup_widget(button,"Page_accueil");
	gtk_widget_destroy(window1);
	
	window2=create_gestion_de_reclamation();
	gtk_widget_show(window2);
}




void
on_serviceleplusreclamer_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview;

treeview=lookup_widget(button,"treeview2_reclamation");
 leplusreclamer(treeview);
}

user o;
char id111[4];
char sexe1[10]="Homme";
int cnf1=0;
char sexe2[10]="Homme";
int cnf2=0;
void
on_button102_hsm_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *label55_hsm;

label55_hsm = lookup_widget(button,"label6_sexe");
//sexe (s,msg);

gtk_label_set_text(GTK_LABEL(label55_hsm),sexe1);
}


void
on_retour_ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_user;
ajouter_user=lookup_widget(button,"ajouter_user");
gtk_widget_destroy(ajouter_user);
GtkWidget *afficher_user;
afficher_user = create_afficher_user ();
  gtk_widget_show (afficher_user);
}


void
on_ajouter_user_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";

user p;

GtkWidget *nom_user,*prenom_user,*cin_user,*tel_user,*email_user,*comboboxentry1_user,*calendar1_user;
GtkWidget *spinbutton1_user;

nom_user=lookup_widget(button,"nom_user");
prenom_user=lookup_widget(button,"prenom_user");
cin_user=lookup_widget(button,"cin_user");
tel_user=lookup_widget(button,"tel_user");
email_user=lookup_widget(button,"email_user");
comboboxentry1_user=lookup_widget(button,"comboboxentry1_user");
calendar1_user=lookup_widget(button,"calendar1_user");
spinbutton1_user=lookup_widget(button,"spinbutton1_user");

GtkWidget *ecin_us;
ecin_us = lookup_widget (button ,"ecin_us");
GtkWidget *etel_us;
etel_us = lookup_widget (button ,"etel_us");
GtkWidget *eemail_us;
eemail_us = lookup_widget (button ,"eemail_us");
GtkWidget *enom_us;
enom_us = lookup_widget (button ,"enom_us");
GtkWidget *eprenom_us;
eprenom_us = lookup_widget (button ,"eprenom_us");
GtkWidget *eposte_us;
eposte_us = lookup_widget (button ,"eposte_us");
GtkWidget *econf_us;
econf_us = lookup_widget (button ,"econf_us");


int bbb=0;
gtk_calendar_get_date (GTK_CALENDAR(calendar1_user),
                       &aa,
                       &mm,
                       &jj);

mm=mm+1;
sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,a);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,c);

p.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1_user));
strcpy(p.date_naissance,y);
strcpy(p.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1_user)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom_user)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_user)));
strcpy(p.CIN,gtk_entry_get_text(GTK_ENTRY(cin_user)));
strcpy(p.sexe,sexe1);
strcpy(p.num,gtk_entry_get_text(GTK_ENTRY(tel_user)));
strcpy(p.email,gtk_entry_get_text(GTK_ENTRY(email_user)));



if (verifier_cin (p.CIN)==0 || (strcmp(p.CIN,"")==0)){bbb=1;
	          gtk_widget_show (ecin_us);
}
else {
		  gtk_widget_hide(ecin_us);
}
if (verifier_cin (p.num)==0 || (strcmp(p.num,"")==0)){bbb=1;
	          gtk_widget_show (etel_us);

}
else {
		  gtk_widget_hide(etel_us);
}	

if (verifier_email (p.email)==0 || (strcmp(p.email,"")==0) ){bbb=1;
	gtk_widget_show (eemail_us);

}
else {
		  gtk_widget_hide(eemail_us);
}
if (verifier_lettre (p.nom)==0 || (strcmp(p.nom,"")==0) ){bbb=1;
	gtk_widget_show (enom_us);

}
else {
		  gtk_widget_hide(enom_us);
}
if (verifier_lettre (p.prenom)==0 || (strcmp(p.prenom,"")==0) ){bbb=1;
	gtk_widget_show (eprenom_us);

}
else {
		  gtk_widget_hide(eprenom_us);
}
if ( (strcmp(p.poste,"")==0) ){bbb=1;
	gtk_widget_show (eposte_us);

}
else {
		  gtk_widget_hide(eposte_us);
}

if ( cnf1==0) {bbb=1;
	gtk_widget_show (econf_us);

}
else {
		  gtk_widget_hide(econf_us);
}

if (bbb == 0){

ajouter_util(p);

GtkWidget *ajouter_user;
ajouter_user=lookup_widget(button,"ajouter_user");
gtk_widget_destroy(ajouter_user);
GtkWidget *afficher_user;
afficher_user = create_afficher_user ();
  gtk_widget_show (afficher_user);
}
}

void
on_radiobutton1_hsm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe1,"Homme");
}


void
on_radiobutton2_user_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe1,"Femme");
}


void
on_actualiser_user_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1_user;
GtkWidget *afficher_user;
afficher_user=lookup_widget(button,"afficher_user");
treeview1_user=lookup_widget(afficher_user,"treeview1_user");


afficher_util(treeview1_user);
}


void
on_go_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_user;
afficher_user=lookup_widget(button,"afficher_user");
gtk_widget_destroy(afficher_user);
user p;
char id1[30];
char nom1[30];
char prenom1[30];
char CIN1[30];
char sexe1[30];
char date_naissance1[30];
char poste1[30];
char num1[30];
char email1[40];
FILE *f;

f=fopen("util.txt","r");
GtkWidget *modifier1_user;
  modifier1_user = create_modifier1_user ();
  gtk_widget_show (modifier1_user);
GtkWidget *nom_user1;
nom_user1 = lookup_widget (modifier1_user ,"nom_user1");
GtkWidget *prenom_user1;
prenom_user1 = lookup_widget (modifier1_user ,"prenom_user1");
GtkWidget *cin_user1;
cin_user1 = lookup_widget (modifier1_user ,"cin_user1");
GtkWidget *tel_user1;
tel_user1 = lookup_widget (modifier1_user ,"tel_user1");
GtkWidget *email_user1;
email_user1 = lookup_widget (modifier1_user ,"email_user1");
GtkWidget *comboboxentry11_user;
comboboxentry11_user = lookup_widget (modifier1_user ,"comboboxentry11_user");

while(fscanf(f, "%s %s %s %s %s %s %s %s %s \n",id1,nom1,prenom1,CIN1,sexe1,date_naissance1,poste1,num1,email1)!=EOF){
 if (strcmp(id111,id1)==0){
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier1_user,"nom_user1")),nom1);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier1_user,"prenom_user1")),prenom1);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier1_user,"cin_user1")),CIN1);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier1_user,"tel_user1")),num1);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier1_user,"email_user1")),email1);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier1_user,"comboboxentry11_user")),poste1);

}}
}


void
on_go_supprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_user;
afficher_user=lookup_widget(button,"afficher_user");

GtkWidget *supprimer1_user;
supprimer1_user = create_supprimer1_user ();
  gtk_widget_show (supprimer1_user);
}


void
on_go_ajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_user;
afficher_user=lookup_widget(button,"afficher_user");
gtk_widget_destroy(afficher_user);
GtkWidget *ajouter_user;
ajouter_user = create_ajouter_user ();
  gtk_widget_show (ajouter_user);
}


void
on_rechercher_user_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];
GtkWidget *treeview1_user;
GtkWidget *afficher_user;
afficher_user=lookup_widget(button,"afficher_user");

treeview1_user=lookup_widget(afficher_user,"treeview1_user");
cherch = lookup_widget (button ,"entre_rechercher_user");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
 rechercher_util(treeview1_user,ch);
}


void
on_conf_aj_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
cnf1=1;
}


void
on_treeview1_user_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* genre;
	gchar* dns;
	gchar* poste;
	gchar* num;
	gchar* email;
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &id, 1, &nom,2,&prenom,3,&cin,4,&genre,5,&dns,6,&poste,7,&num,8,&email,-1);
	strcpy(id111,id);
	
	}
}


void
on_conf_supp_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
supprimer_util(id111);
GtkWidget *supprimer1_user;
supprimer1_user=lookup_widget(button,"supprimer1_user");
gtk_widget_destroy(supprimer1_user);
GtkWidget *afficher_user;

  gtk_widget_show (afficher_user);
}


void
on_annuler_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer1_user;
supprimer1_user=lookup_widget(button,"supprimer1_user");
gtk_widget_destroy(supprimer1_user);
GtkWidget *afficher_user;

  gtk_widget_show (afficher_user);
}


void
on_modifier_us_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ecin_us;
ecin_us = lookup_widget (button ,"ecin_us1");
GtkWidget *etel_us;
etel_us = lookup_widget (button ,"etel_us1");
GtkWidget *eemail_us;
eemail_us = lookup_widget (button ,"eemail_us1");
GtkWidget *enom_us;
enom_us = lookup_widget (button ,"enom_us1");
GtkWidget *eprenom_us;
eprenom_us = lookup_widget (button ,"eprenom_us1");
GtkWidget *eposte_us;
eposte_us = lookup_widget (button ,"eposte_us1");
GtkWidget *econf_us;
econf_us = lookup_widget (button ,"econf_us1");


int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
int bbb=0;
user p;

GtkWidget *nom_user,*prenom_user,*cin_user,*tel_user,*email_user,*comboboxentry1_user,*calendar1_user;
GtkWidget *spinbutton1_user;

nom_user=lookup_widget(button,"nom_user1");
prenom_user=lookup_widget(button,"prenom_user1");
cin_user=lookup_widget(button,"cin_user1");
tel_user=lookup_widget(button,"tel_user1");
email_user=lookup_widget(button,"email_user1");
comboboxentry1_user=lookup_widget(button,"comboboxentry11_user");
calendar1_user=lookup_widget(button,"calendar11_user");
spinbutton1_user=lookup_widget(button,"spinbutton11_user");



gtk_calendar_get_date (GTK_CALENDAR(calendar1_user),
                       &aa,
                       &mm,
                       &jj);

mm=mm+1;
sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,a);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,c);

p.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1_user));
strcpy(p.date_naissance,y);
strcpy(p.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1_user)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom_user)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_user)));
strcpy(p.CIN,gtk_entry_get_text(GTK_ENTRY(cin_user)));
strcpy(p.sexe,sexe2);
strcpy(p.num,gtk_entry_get_text(GTK_ENTRY(tel_user)));
strcpy(p.email,gtk_entry_get_text(GTK_ENTRY(email_user)));


if (verifier_cin (p.CIN)==0 || (strcmp(p.CIN,"")==0)){bbb=1;
	          gtk_widget_show (ecin_us);
}
else {
		  gtk_widget_hide(ecin_us);
}
if (verifier_cin (p.num)==0 || (strcmp(p.num,"")==0)){bbb=1;
	          gtk_widget_show (etel_us);

}
else {
		  gtk_widget_hide(etel_us);
}	

if (verifier_email (p.email)==0 || (strcmp(p.email,"")==0) ){bbb=1;
	gtk_widget_show (eemail_us);

}
else {
		  gtk_widget_hide(eemail_us);
}
if (verifier_lettre (p.nom)==0 || (strcmp(p.nom,"")==0) ){bbb=1;
	gtk_widget_show (enom_us);

}
else {
		  gtk_widget_hide(enom_us);
}
if (verifier_lettre (p.prenom)==0 || (strcmp(p.prenom,"")==0) ){bbb=1;
	gtk_widget_show (eprenom_us);

}
else {
		  gtk_widget_hide(eprenom_us);
}
if ( (strcmp(p.poste,"")==0) ){bbb=1;
	gtk_widget_show (eposte_us);

}
else {
		  gtk_widget_hide(eposte_us);
}
if ( cnf2==0) {bbb=1;
	gtk_widget_show (econf_us);

}
else {
		  gtk_widget_hide(econf_us);
}

if (bbb == 0){
modifier_userr(id111,p);

GtkWidget *modifier1_user;
modifier1_user=lookup_widget(button,"modifier1_user");
gtk_widget_destroy(modifier1_user);
GtkWidget *afficher_user;
afficher_user = create_afficher_user ();
  gtk_widget_show (afficher_user);
}
}

void
on_anuuler_md_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier1_user;
modifier1_user=lookup_widget(button,"modifier1_user");
gtk_widget_destroy(modifier1_user);
GtkWidget *afficher_user;
afficher_user = create_afficher_user ();
  gtk_widget_show (afficher_user);
}


void
on_button4_md_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *label33_sexe;

label33_sexe = lookup_widget(button,"label33_user");
//sexe (s,msg);

gtk_label_set_text(GTK_LABEL(label33_sexe),sexe2);
}


void
on_radiobutton11_user_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe2,"Homme");
}


void
on_radiobutton22_user_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe2,"Femme");
}


void
on_checkbutton11_user_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
cnf2=1;
}


void
on_statique_plat_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
char a3[10];
char b3[10];
char c3[10];
char y3[40]="le jour : ";


char a1[10];
char b1[10];
char c1[10];
char y1[40]="le jour : ";

char a2[10];
char b2[10];
char c2[10];
char y2[40]="le jour : ";

char num[3];

GtkWidget *spinbutton1_semaine;

spinbutton1_semaine = lookup_widget(button,"spinbutton1_semaine");

int z=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1_semaine));

sprintf(num,"%d",z);

GtkWidget *num_semaine;
num_semaine = lookup_widget(button,"num_semaine");
gtk_label_set_text(GTK_LABEL(num_semaine),num);

dechet pl1 = plat1(z);
dechet pl2 = plat2(z);
dechet pl3 = plat3(z);

sprintf(a1,"%d",pl1.x1);sprintf(b1,"%d",pl1.x2);sprintf(c1,"%f",pl1.x3);
strcat(y1,a1);strcat(y1," qui contient ");strcat(y1,c1);(y1," de dechets");strcat(y1," %");

sprintf(a2,"%d",pl2.x1);sprintf(b2,"%d",pl2.x2);sprintf(c2,"%f",pl2.x3);
strcat(y2,a2);strcat(y2," qui contient ");strcat(y2,c2);(y2," de dechets");strcat(y2," %");

sprintf(a3,"%d",pl3.x1);sprintf(b3,"%d",pl3.x2);sprintf(c3,"%f",pl3.x3);
strcat(y3,a3);strcat(y3," qui contient ");strcat(y3,c3);(y3," de dechets");strcat(y3," %");


GtkWidget *plat1;
plat1 = lookup_widget(button,"plat1");
gtk_label_set_text(GTK_LABEL(plat1),y1);
GtkWidget *plat2;
plat2 = lookup_widget(button,"plat2");
gtk_label_set_text(GTK_LABEL(plat2),y2);
GtkWidget *plat3;
plat3 = lookup_widget(button,"plat3");
gtk_label_set_text(GTK_LABEL(plat3),y3);
}


void
on_login_user_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *erreur_pass;

erreur_pass = lookup_widget(button,"erreur_pass");

GtkWidget *username, *password, *windowAcceuil_hsm;
char user[20];
char passw[20];
int trouve;
username = lookup_widget (button, "entry1_user");
password = lookup_widget (button, "entry2_pass");
strcpy(user ,gtk_entry_get_text ( GTK_ENTRY(username)));
strcpy(passw ,gtk_entry_get_text ( GTK_ENTRY(password)));
trouve=verif_pass(user,passw);
if (trouve==1)
{

GtkWidget *auth_user;
auth_user=lookup_widget(button,"auth_user");
gtk_widget_destroy(auth_user);
GtkWidget *afficher_user;
afficher_user = create_afficher_user ();
  gtk_widget_show (afficher_user);
}
else if (trouve==-1){gtk_widget_show (erreur_pass);}
}


void
on_inscri_user_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *auth_user;
auth_user=lookup_widget(button,"auth_user");
gtk_widget_destroy(auth_user);
GtkWidget *inscri_user;
inscri_user = create_inscri_user ();
  gtk_widget_show (inscri_user);
}



void
on_inscri_us_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *login, *pw;
char login1[40];
char passw[40];
login = lookup_widget(button,"entre_username");
pw = lookup_widget(button,"entre_password");
strcpy(login1,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));
f=fopen("utilisateur.txt","a+");
if (f != NULL)
{
fprintf(f,"%s %s \n",login1,passw);

}
fclose(f);
GtkWidget *inscri_user;
inscri_user=lookup_widget(button,"inscri_user");
gtk_widget_destroy(inscri_user);
GtkWidget *auth_user;
auth_user = create_auth_user ();
  gtk_widget_show (auth_user);


}
void
on_annuler_ins_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *inscri_user;
inscri_user=lookup_widget(button,"inscri_user");
gtk_widget_destroy(inscri_user);
GtkWidget *auth_user;
auth_user = create_auth_user ();
  gtk_widget_show (auth_user);
}


void
on_deconn_user_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_user;
afficher_user=lookup_widget(button,"afficher_user");
gtk_widget_destroy(afficher_user);
GtkWidget *auth_user;
auth_user = create_auth_user ();
  gtk_widget_show (auth_user);
}
produit o2;
char tyy[20]="froid";
int choix=0;
char tyy1[20]="froid";
int x1=0;int x2=0;
void
on_modifier_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
gtk_widget_destroy(afiicher_st);
produit p;
FILE *f;
f=fopen("produit.txt","r");
GtkWidget *modifier_st;
  modifier_st = create_modifier_st ();
  gtk_widget_show (modifier_st);
GtkWidget *Mprod_id_st;
Mprod_id_st = lookup_widget (modifier_st ,"Mprod_id_st");
GtkWidget *Mnom_st;
Mnom_st = lookup_widget (modifier_st ,"Mnom_st");
GtkWidget *combobox2_st;
combobox2_st = lookup_widget (modifier_st ,"combobox2_st");
GtkWidget *spinbutton11_st;
spinbutton11_st = lookup_widget (modifier_st ,"spinbutton11_st");
GtkWidget *spinbutton22_st;
spinbutton22_st = lookup_widget (modifier_st ,"spinbutton22_st");

while(fscanf(f,"%s %s %s %d %s %s %d\n",p.prod_id,p.nom,p.nature,&p.quant,p.type,p.date,&p.lieu)!=-1){
 if (strcmp(p.prod_id,o2.prod_id)==0){
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_st,"Mprod_id_st")),p.prod_id);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_st,"Mnom_st")),p.nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_st,"combobox2_st")),p.nature);
                gtk_range_set_value(GTK_ENTRY(lookup_widget(modifier_st,"spinbutton11_st")),p.quant);
                gtk_range_set_value(GTK_ENTRY(lookup_widget(modifier_st,"spinbutton22_st")),p.lieu);

}}
GtkWidget *erreur_nom2,*erreur_prod_id2,*erreur_conf2;

erreur_nom2=lookup_widget(modifier_st,"erreur_nom2");
erreur_prod_id2=lookup_widget(modifier_st,"erreur_prod_id2");
erreur_conf2=lookup_widget(modifier_st,"erreur_conf2");
 
gtk_widget_hide(erreur_nom2);  
gtk_widget_hide(erreur_prod_id2);  
gtk_widget_hide(erreur_conf2);
}


void
on_ajouter_st_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
gtk_widget_destroy(afiicher_st);
GtkWidget *ajouter_st;
ajouter_st = create_ajouter_st ();
  gtk_widget_show (ajouter_st);


GtkWidget *erreur_nom1,*erreur_prod_id1,*erreur_nature1,*erreur_conf1;

erreur_nom1=lookup_widget(ajouter_st,"erreur_nom1");
erreur_prod_id1=lookup_widget(ajouter_st,"erreurprod_id_1");
erreur_nature1=lookup_widget(ajouter_st,"erreur_nature1");
erreur_nature1=lookup_widget(ajouter_st,"erreur_conf1");

gtk_widget_hide(erreur_nom1);  
gtk_widget_hide(erreur_prod_id1);  
gtk_widget_hide(erreur_nature1);
gtk_widget_hide(erreur_conf1);



}


void
on_actualiser_st_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1_st;
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
treeview1_st=lookup_widget(afiicher_st,"treeview1_st");

afficher_st(treeview1_st);


}


void
on_chercher_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];
GtkWidget *treeview1_st;
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");

treeview1_st=lookup_widget(afiicher_st,"treeview1_st");
cherch = lookup_widget (button ,"entre_rechercher_st");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
 chercher_st(treeview1_st,ch);
}


void
on_ajouterpr_st_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *prod_id;
GtkWidget *nom;
GtkWidget *nature;
GtkWidget *quant;
GtkWidget *type;

GtkWidget *lieu;
GtkWidget *ajouter_st;


produit p;
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
int o=0;
prod_id = lookup_widget (button ,"entryprod_id_st");
nom = lookup_widget (button ,"entrynom_st");
nature = lookup_widget (button ,"combobox1_nature");
quant = lookup_widget (button ,"spinbutton1_qt_st");
type = lookup_widget (button ,"radiobutton1_fr");
lieu = lookup_widget (button ,"spinbutton1_lieu");


GtkWidget *erreur_nom1,*erreur_prod_id1,*erreur_nature1,*erreur_conf1;
ajouter_st=lookup_widget(button,"ajouter_st");
erreur_nom1=lookup_widget(ajouter_st,"erreur_nom1");
erreur_prod_id1=lookup_widget(ajouter_st,"erreurprod_id_1");
erreur_nature1=lookup_widget(ajouter_st,"erreur_catg1");
erreur_conf1=lookup_widget(ajouter_st,"erreur_conf1");
gtk_widget_hide(erreur_nom1);  
gtk_widget_hide(erreur_prod_id1);  
gtk_widget_hide(erreur_nature1);

gtk_widget_hide(erreur_conf1);





GtkWidget *calendar;
calendar=lookup_widget(button,"calendar1_st");
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);
mm=mm+1;


p.quant=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quant));
p.lieu=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lieu));

strcpy(p.prod_id, gtk_entry_get_text(GTK_ENTRY(prod_id)));
strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.nature, gtk_combo_box_get_active_text(GTK_COMBO_BOX(nature)));


sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,c);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,a);


strcpy(p.date,y);
strcpy(p.type,tyy);

if (strcmp(p.prod_id,"")==0)
{o=1;
gtk_widget_show(erreur_prod_id1);
}
else o=0;
 if (strcmp(p.nom,"")==0)
{o=1;
gtk_widget_show(erreur_nom1);
}
else o=0;

 if (x1==0)
{
gtk_widget_show(erreur_conf1);
}
if (strcmp(p.nature,"")==0)
{o=1;
gtk_widget_show(erreur_nature1);
}else o=0;



 if(o==0 && x1==1){
ajouter_produit(p);



gtk_widget_destroy(ajouter_st);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
x1=0;


}

}


void
on_anuulerajout_st_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_st;
ajouter_st=lookup_widget(button,"ajouter_st");
gtk_widget_destroy(ajouter_st);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
GtkWidget* resultat_st;

}


void
on_annulersupp_st_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer_st;
supprimer_st=lookup_widget(button,"supprimer_st");
gtk_widget_destroy(supprimer_st);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
  gtk_widget_show (afiicher_st);



}


void
on_confirmersupp_st_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
 supprimer_st(o2.prod_id);
GtkWidget *supprimer_st;
supprimer_st=lookup_widget(button,"supprimer_st");
gtk_widget_destroy(supprimer_st);
GtkWidget *afiicher_st;

  gtk_widget_show (afiicher_st);

}


void
on_treeview1_st_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
                                    
{GtkTreeIter iter;
	gchar* prod_id;
	gchar* nom;
	gchar* nature;
	gchar* type;
	gchar* quant;
	gchar* date;
	gchar* lieu;
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &prod_id, 1 , &nom, 2 , &nature, 3 , &quant, 4 , &type, 5 , &date, 6 , &lieu,-1);
	strcpy(o2.prod_id,prod_id);
	o2.quant=atoi(quant); 
	}

}


void
on_supprimer_st_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");

GtkWidget *supprimer_st;
supprimer_st = create_supprimer_st ();
  gtk_widget_show (supprimer_st);
}


void
on_annulerM_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier_st;
modifier_st=lookup_widget(button,"modifier_st");
gtk_widget_destroy(modifier_st);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);


}


void
on_modifier1_st_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *prod_id;
GtkWidget *nom;
GtkWidget *nature;
GtkWidget *quant;
GtkWidget *type;

GtkWidget *lieu;



produit p;
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
int x=0;
GtkWidget *modifier_st;
modifier_st=lookup_widget(button,"modifier_st");
prod_id = lookup_widget (button ,"Mprod_id_st");
nom = lookup_widget (button ,"Mnom_st");
nature = lookup_widget (button ,"combobox2_st");
quant = lookup_widget (button ,"spinbutton11_st");
type = lookup_widget (button ,"radiobutton11_st");
lieu = lookup_widget (button ,"spinbutton22_st");

GtkWidget *erreur_nom2,*erreur_prod_id2,*erreur_conf2,*erreur_nature1;
erreur_nature1=lookup_widget(modifier_st,"erreur_catg2");
erreur_nom2=lookup_widget(modifier_st,"erreur_nom2");
erreur_prod_id2=lookup_widget(modifier_st,"erreur_prod_id2");
erreur_conf2=lookup_widget(modifier_st,"erreur_conf2");

 
gtk_widget_hide(erreur_nom2);  
gtk_widget_hide(erreur_prod_id2);  
gtk_widget_hide(erreur_conf2);
gtk_widget_hide(erreur_nature1);
GtkWidget *calendar;
calendar=lookup_widget(button,"calendar1_dateM");
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);
mm=mm+1;


p.quant=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quant));
p.lieu=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lieu));

strcpy(p.prod_id, gtk_entry_get_text(GTK_ENTRY(prod_id)));
strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.nature, gtk_combo_box_get_active_text(GTK_COMBO_BOX(nature)));


sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,c);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,a);


strcpy(p.date,y);
strcpy(p.type,tyy1);
if (strcmp(p.prod_id,"")==0)
{x=1;
gtk_widget_show(erreur_prod_id2);
}else x=0;
 if (strcmp(p.nom,"")==0)
{x=1;
gtk_widget_show(erreur_nom2);
}else x=0;
if (strcmp(p.nature,"")==0)
{x=1;
gtk_widget_show(erreur_nature1);
}else x=0;

 if (x2==0)
{
gtk_widget_show(erreur_conf2);
}

 if(x==0 && x2 ==1){
modifier_stt(o2.prod_id,p);

gtk_widget_destroy(modifier_st);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
x2=0;
}}


void
on_radiobutton1_fr_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy,"froid");
}


void
on_radiobutton2_nr_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy,"normal");
}


void
on_radiobutton11_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy1,"froid");
}


void
on_radiobutton22_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy1,"normal");
}


void
on_checkbutton1_st_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x1=1;
}


void
on_checkbutton11_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x2=1;
}


void
on_retire_st_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"tache2");

GtkWidget *tache2;
tache2 = create_tache2 ();
  gtk_widget_show (tache2);
}


void
on_treeview2_st_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_afficher_tache2_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *spinbutton1_mn;
spinbutton1_mn = lookup_widget (button ,"spinbutton1_mn");
int mn=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1_mn));
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
GtkWidget *calendar;
calendar=lookup_widget(button,"calendar3_st");
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);
mm=mm+1;

sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,c);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,a);

GtkWidget *treeview2_st;
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
treeview2_st=lookup_widget(afiicher_st,"treeview2_st");
stoq_ep(treeview2_st,y,mn,choix);
}


void
on_confirme_ut_st_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *quant1;
GtkWidget *tache2;
GtkWidget *erreur_qnt;
int x;
int y=0;
int bb=0;
quant1 = lookup_widget (button ,"spinbutton111_st");

tache2=lookup_widget(button,"tache2");

erreur_qnt=lookup_widget(tache2,"erreur_qnt");
y=0;
 
gtk_widget_hide(erreur_qnt);  


x=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quant1));



bb = ret_qp( o2);

if (x >bb)
{y=1;
gtk_widget_show(erreur_qnt);
}
if (x <= bb){
utiliser_stt(o2.prod_id,x);

gtk_widget_destroy(tache2);
GtkWidget *afiicher_st;
afiicher_st = create_afiicher_st ();
  gtk_widget_show (afiicher_st);
}



}


void
on_annuler_ut_st_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tache2;
tache2=lookup_widget(button,"tache2");
gtk_widget_destroy(tache2);
GtkWidget *afiicher_st;
afiicher_st=lookup_widget(button,"afiicher_st");
  gtk_widget_show (afiicher_st);
}


void
on_Date_expir___toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
choix=1;
}


void
on_Stock_epuis___toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
choix=0;
}


void
on_button4_accueil_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1=lookup_widget(button,"Page_accueil");
	gtk_widget_destroy(window1);
	
	window2=create_afiicher_st();
	gtk_widget_show(window2);
}

int typemenu=0;
int typemenu2=0;
void sendmail(char body[])
{
        char cmd[200];
        FILE *fp = fopen("mail.txt","w+"); // open it for writing.
        fprintf(fp,"%s\n",body);        // write body to it.
        fclose(fp);             // close it.

        sprintf(cmd,"curl smtps://smtp.gmail.com:465 -v --mail-from \"niveau.etudiant@gmail.com:A123456789+\" --mail-rcpt \"mohaned.zidi@esprit.tn\" --ssl -u niveau.etudiant@gmail.com:A123456789+ -T mail.txt -k --anyauth"); // prepare command.
        system(cmd);     // execute it.
}
void
on_ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *addmenu;
    addmenu = create_addmenu ();
    gtk_widget_show (addmenu);
}

void on_afficher_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data){

  	GtkWidget *liste;
    GtkWidget *browsemenu;
    browsemenu= create_browsemenu();
    gtk_widget_show (browsemenu);
    liste=lookup_widget(browsemenu,"treeview1_menu");
    afficher(liste);



}
void on_supprimer_clicked (GtkButton       *button,
                                        gpointer         user_data){
    GtkWidget *deletemenu;
    
    deletemenu= create_deletemenu();
    gtk_widget_show (deletemenu);



}
void on_button_ajout_clicked(GtkButton       *button,
                                        gpointer         user_data){
   
    GtkWidget *id,*nom, *addmenu,*date,*type,*entree,*suite,*dessert;
    id=NULL;
    menu m; 
    char id1[20];

    id = lookup_widget(button,"entry4_id");
    nom = lookup_widget(button,"entry9_nom");
    date = lookup_widget (button,"spinbutton5_menu");
    entree = lookup_widget (button,"entry10_entree");
    suite = lookup_widget (button,"entry11_suite");
    dessert = lookup_widget (button,"entry12_dessert");

    strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
    m.id= atoi(id1);

    if (typemenu==1){
         strcpy(m.type,"petitdejeuner");
    }
    if (typemenu==2){
     strcpy(m.type, "Dejeuner");   
    }
    if (typemenu==3){
        strcpy(m.type, "Dinner");
    }

    strcpy(m.nom, gtk_entry_get_text(GTK_ENTRY(nom))); 
    m.date=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (date)) ;

    strcpy(m.entree, gtk_entry_get_text(GTK_ENTRY(entree))); 
    strcpy(m.suite, gtk_entry_get_text(GTK_ENTRY(suite )));
    strcpy(m.dessert, gtk_entry_get_text(GTK_ENTRY(dessert))); 
    
    ajouter(m);
    sendmail("Un menu a ete ajoute avec succes.");
	

}

void on_button_supprimer_clicked (GtkButton       *button,
                                        gpointer         user_data){

}
void
on_modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *updatemenu;
    updatemenu= create_updatemenu();
    gtk_widget_show (updatemenu);
}


void
on_chercher_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *id;
    GtkWidget *liste;
    char id1[20];
    id = lookup_widget(button,"entry8_menu");
    strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id))); 
    liste=lookup_widget(button,"treeview1_menu");
    chercher2(liste,atoi(id1));
}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	

}


void
on_button2_modifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
      printf("1\n" );
    GtkWidget *id,*nom, *addmenu,*date,*type,*entree,*suite,*dessert;
    id=NULL;
    menu m; 
    char id1[20];
    id = lookup_widget(button,"entry13_menu");
    nom = lookup_widget(button,"entry14_menu");
    date = lookup_widget (button,"spinbutton16_menu");
    entree = lookup_widget (button,"entry15_menu");
    suite = lookup_widget (button,"entry16_menu");
    dessert = lookup_widget (button,"entry16_menu");

    strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
    m.id= atoi(id1);
    if (typemenu2==1){
         strcpy(m.type,"petitdejeuner");
    }
    if (typemenu2==2){
     strcpy(m.type, "Dejeuner");   
    }
    if (typemenu2==3){
        strcpy(m.type, "Dinner");
    }
    strcpy(m.nom, gtk_entry_get_text(GTK_ENTRY(nom))); 
    m.date=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (date)) ;
    strcpy(m.entree, gtk_entry_get_text(GTK_ENTRY(entree))); 
    strcpy(m.suite, gtk_entry_get_text(GTK_ENTRY(suite )));
    strcpy(m.dessert, gtk_entry_get_text(GTK_ENTRY(dessert))); 
    modifier(m.id,m);
}


void
on_petitdej_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    typemenu=1;
}


void
on_dejeuner_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    typemenu=2;
}


void
on_dinner_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    typemenu=3;
}

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 typemenu2=1;
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   typemenu2=2;
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
       typemenu2=3;
}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	 GtkWidget *id;
	GtkWidget *liste;
 	char id1[20];
  	id = lookup_widget(button,"entry8_menu");
  	strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id))); 
  	supprimer(atoi(id1));
	liste=lookup_widget(button,"treeview1_menu");
    afficher(liste);
	
}


void
on_nbetudiants_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *meilleure;
    meilleure= create_window1();
    gtk_widget_show (meilleure);

    GtkWidget *label1,*label2,*label3,*label4,*label5 ;

    int n1=0,n2=0,n3=0,n4=0,n5=0;
    char fichierEtud[20];
    char niveau[5];
    nbEtudiant(&n1,&n2,&n3,&n4,&n5);
    label1 = lookup_widget(meilleure,"label36_menu");
    label2 = lookup_widget(meilleure,"label37_menu");
    label3 = lookup_widget(meilleure,"label42_menu");
    label4 = lookup_widget(meilleure,"label44_menu");
    label5 = lookup_widget(meilleure,"label46_menu");

    
    sprintf(niveau, "%d", n1);
    gtk_label_set_text(label1,niveau);

    sprintf(niveau, "%d", n2);
    gtk_label_set_text(label2,niveau);
    
    sprintf(niveau, "%d", n3);
    gtk_label_set_text(label3,niveau);

    sprintf(niveau, "%d", n4);
    gtk_label_set_text(label4,niveau);
    
    sprintf(niveau, "%d", n5);
    gtk_label_set_text(label5,niveau);

}


void
on_button6_accueil_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1=lookup_widget(button,"Page_accueil");
	gtk_widget_destroy(window1);
	
	window2=create_choices();
	gtk_widget_show(window2);
}


void
on_button259_login_pressed             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *entry;
  entry=lookup_widget(button,"entry1_login");
  gtk_entry_set_visibility (GTK_ENTRY (entry), TRUE);
  return FALSE;
}


void
on_button259_login_released            (GtkButton       *button,
                                        gpointer         user_data)
{
	 GtkWidget *entry;
  entry=lookup_widget(button,"entry1_login");
  gtk_entry_set_visibility (GTK_ENTRY (entry), FALSE);
  return FALSE;
}


void
on_deconnection_accueil_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1=lookup_widget(button,"Page_accueil");
	gtk_widget_destroy(window1);
	
	window2=create_Login();
	gtk_widget_show(window2);
}


void
on_retour_stock_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1=lookup_widget(button,"afiicher_st");
	gtk_widget_destroy(window1);
	
	window2=create_Page_accueil();
	gtk_widget_show(window2);
}


void
on_retour_menu_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1=lookup_widget(button,"choices");
	gtk_widget_destroy(window1);
	
	window2=create_Page_accueil();
	gtk_widget_show(window2);
}


void
on_retour_user_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1=lookup_widget(button,"afficher_user");
	gtk_widget_destroy(window1);
	
	window2=create_Page_accueil();
	gtk_widget_show(window2);
}


void
on_retour_reclamation_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1=lookup_widget(button,"gestion_de_reclamation");
	gtk_widget_destroy(window1);
	
	window2=create_Page_accueil();
	gtk_widget_show(window2);
}


int choix2[]={0,0,0,0,0};
Etudiant E;
Etudiant ET;
char sup[100],id[10];
void
on_button_ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
   
//Déclaration
GtkWidget *nom,*prenom,*chambre,*cin,*tel,*jour,*mois,*annee,*niveau,*spc,*invalid;
char x[10];


nom = lookup_widget(button, "entry_nom") ;
strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

prenom = lookup_widget(button, "entry_prenom") ;
strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

jour= lookup_widget(button, "spinbutton_jour");
E.naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));


mois= lookup_widget(button, "spinbutton_mois");
E.naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));


annee= lookup_widget(button, "spinbutton_annee");
E.naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));



niveau= lookup_widget(button, "combobox_niveau");
strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau)));
E.niveau.niv=atoi(x);

spc= lookup_widget(button, "combobox_spc");
strcpy(E.niveau.spec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(spc)));



chambre= lookup_widget(button, "entry_chambre");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(chambre)));
E.chambre=atoi(x);

tel= lookup_widget(button, "entry_tel");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(tel)));
E.tel=atoi(x);


cin= lookup_widget(button, "entry_cin");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(cin)));
E.CIN=atoi(x);
invalid = lookup_widget(button, "label_invalid") ; 
if ((strlen(x)!=8) && (strlen(x)!=7))
{
gtk_label_set_text(GTK_LABEL(invalid),"invalide");}
else {
gtk_label_set_text(GTK_LABEL(invalid),"valide");
ajouter2(E,"etudiant.txt");
}

}


void
on_button_ajouter_tab_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*principale;
window1 = create_window1_foyer ();
gtk_widget_show (window1);
principale=lookup_widget(button,"principale");
gtk_widget_destroy(principale);


}


void
on_button_modifier_tab_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier,*principale;
principale=lookup_widget(button,"principale");
gtk_widget_destroy(principale);
modifier = create_modifier ();
gtk_widget_show (modifier);

}


void
on_button_return_ajouter_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *principale,*window1;
principale = create_principale ();
gtk_widget_show (principale);
window1=lookup_widget(button,"window1_foyer");
gtk_widget_destroy(window1);
}




void
on_button_return_modifier_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *principale,*modifier;
principale = create_principale ();
gtk_widget_show (principale);
modifier=lookup_widget(button,"modifier");
gtk_widget_destroy(modifier);
}


void
on_button_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entry1,*entry2,*entry3,*entry4,*entry5;
entry1=lookup_widget(button,"entry_modif_nom");
entry2=lookup_widget(button,"entry_modif_prenom");
entry3=lookup_widget(button,"entry_modif_niveau");
entry4=lookup_widget(button,"entry_modif_chambre");
entry5=lookup_widget(button,"entry_modif_tel");

Etudiant e;
strcpy(e.nom,gtk_entry_get_text(entry1));
strcpy(e.prenom,gtk_entry_get_text(entry2));
e.chambre=atoi(gtk_entry_get_text(entry4));
e.tel=atoi(gtk_entry_get_text(entry5));
e.niveau.niv=atoi(gtk_entry_get_text(entry3));
g_print("nom=%s    prenom=%s     chambre=%d     tel=%d      niveau=%d\n",e.nom,e.prenom,e.chambre,e.tel,e.niveau.niv);
modifier2(id,e);

}


void
on_button_chercher_tab_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *carte;
int cn;
char c[10]; 
carte= lookup_widget(button, "entry_chercher_tab");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(carte)));
GtkWidget *treeview;

treeview=lookup_widget(button,"treeview_foyer");

afficher3(treeview,c);
}


void
on_checkbutton_nom_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix2[0]=1;}
else
{choix2[0]=0;}
}


void
on_checkbutton_prenom_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton_niveau_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton_chambre_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton_tel_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button_affich_tab_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview,*principale;
principale=lookup_widget(button,"principale");
principale = create_principale ();
gtk_widget_show (principale);
gtk_widget_destroy(principale);

treeview=lookup_widget(button,"treeview_foyer");

afficher2(treeview);
}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* ch1;
gchar* ch2;
gchar* nai;
gchar* cat;
gchar* e;
gchar* g;
gchar* h;
char gstr[20];

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path));
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&ch1,1,&ch2,2,&nai,3,&cat,4,&e,5,&g,6,&h,-1);
sprintf(gstr,"%d",g);
strcpy(id,gstr);
afficher2(treeview);
}
}


void
on_button_supprim_tab_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
supprimer2(id);
}



void
on_button3_accueil_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1=lookup_widget(button,"Page_accueil");
	gtk_widget_destroy(window1);
	
	window2=create_principale();
	gtk_widget_show(window2);
}


void
on_button1_cap_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1=lookup_widget(button,"principale");
	gtk_widget_destroy(window1);
	
	window2=create_window2();
	gtk_widget_show(window2);
}


void
on_button2_cap_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview;
treeview=lookup_widget(button,"treeview1");
alarme(treeview,"mouvement.txt","fumee.txt");
}


void
on_retour_foyer_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1=lookup_widget(button,"principale");
	gtk_widget_destroy(window1);
	
	window2=create_Page_accueil();
	gtk_widget_show(window2);
}


void
on_retour2_foyer_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1=lookup_widget(button,"window2");
	gtk_widget_destroy(window1);
	
	window2=create_principale();
	gtk_widget_show(window2);
}

