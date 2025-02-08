#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "fonction.c"

int choix;
int n, x;
char file[] = "file.bin";
voyageur *tab;
voyageur e;
char id[];


int main(){
    tab = charger_donner(file, &n);
    do{
    choix = menu();
    switch(choix){
        case 1:
            x = nbrVoyageurs(file);
            printf("\nnbr de voy : %d",x);
            break;
        case 2:
            saisirVoyageurs(&e);
            tab = ajouter(e, tab, &n);
            break;
        case 3:
            afficher(tab,n);
            break;
        case 4:
            printf("saisir un id : ");
            scanf("%s",id);
            supprimer(tab,id,&n);
    }

    }while(choix!=0);

sauvegarder_donnees (file, tab, n);
liberer(tab);

return 0;

}
