#ifndef PROJET_H_INCLUDED
#define PROJET_H_INCLUDED
enum
{
	EPROD,
	ENOM,
	ENAT,
	EQUANT,
	ETYPE,
	EDATE,
	ELIEU,
	COLUMNS2,
};
typedef struct
{char prod_id[20];
char nom[20];
char nature[20];
int quant;
char type[20];
char date[20];
int lieu;
}produit;





#endif // PROJET_H_INCLUDED
