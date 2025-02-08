#ifndef HEAD_H
#define HEAD_H

typedef struct{
char id[20];
char nom[20];
char adr[20];
int nbr_tot;
}voyageur;

int menu();
int nbrVoyageurs(char file[]);
void saisirVoyageurs(voyageur *e);
voyageur *charger_donnees(char file[], int *n);
void sauvegarder_donnees(char file[], voyageur *tab, int n);
int trouver(voyageur * tab, char id[], int n);
voyageur *ajouter(voyageur v, voyageur *tab, int *n);
void supprimer(voyageur *tab, char id[], int *n);
void afficher(voyageur *tab, int n);
void liberer(voyageur *tab);


#endif // HEAD_


