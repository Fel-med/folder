#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

int menu(){
    int choix;
    do{
        printf("\nDonner votre choix\n 1-nombre de voyageur\n 2-saisir un voyageur\n 3-afficher\n 4-supprimer le voyageur dont l'id\n 0-Quitter\n-->");
        scanf("%d",&choix);
    }while(choix<0 || choix>4);
    return choix;
}


int nbrVoyageurs(char file[]){
    int n=0;
    voyageur e;
    FILE *f = fopen(file, "rb");
    if (f == NULL){
            printf("\nError 1");
            return NULL;
    }
    while (fread(&e, sizeof(voyageur), 1, f)==1) n++;
    fclose(f);
    return n;
}


void saisirVoyageurs(voyageur *e){
    printf("\nsaisir: id nom adr nbr_total\n-->");
    scanf("%s %s %s %d", e->id, e->nom, e->adr, &(e->nbr_tot));
}


voyageur* charger_donner(char file[], int *n){
    voyageur *tab = malloc(sizeof(voyageur)*50);
    FILE *f = fopen(file, "rb");
    if (f == NULL){
            printf("\nError 2");
            return NULL;
    }
    *n = nbrVoyageurs(file);
    int i;
    for (i=0 ; i<n ; i++){
        fread(tab + i, sizeof(voyageur), 1, f);
    }
    fclose(f);
    return tab;
}


void sauvegarder_donnees(char file[], voyageur *tab, int n){
    FILE *f = fopen(file, "wb");
    if (f == NULL){
            printf("\nError 3");
            return NULL;
    }
    int i;
    for (i=0 ; i<n ; i++){
        fwrite(tab+i , sizeof(voyageur), 1, f);
    }
    fclose(f);
}


int trouver(voyageur * tab, char id[], int n){
    int i=0;
    while(i<n && strcmp(tab[i].id, id)!=0) i++;
    if (i<n) return i;
    else return -1;
}


voyageur *ajouter(voyageur v, voyageur *tab, int *n){
    int i = trouver(tab, v.id, *n);
    if (i>=0) tab[i].nbr_tot--;
    else tab[(*n)++] = v;
    return tab;
}


void supprimer(voyageur *tab, char id[], int *n){
    int j, i = trouver(tab, id, n);
    if (i>=0){
        for (j=i+1 ; j<*n ; j++){
            tab[j-1]=tab[j];
        }
        (*n)--;
    }
}


void afficher(voyageur *tab, int n){
    int i;
    for (i=0 ; i<n ; i++)
        printf("\n%s %s %s %d", tab[i].adr, tab[i].id, tab[i].nom, tab[i].nbr_tot);
}


void liberer(voyageur *tab){
    free(tab);
}


