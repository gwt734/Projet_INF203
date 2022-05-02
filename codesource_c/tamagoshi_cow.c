#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define byebyelife 0
#define lifesucks 1
#define liferocks 2

int fitness = 5;
int stock = 5;

void affiche_vache(int etat){
    /* Déclaration des yeux et de la langue */
    char yeux[3];
    char langue[2];

    /* Dépendamment de l'état actuel on modifie les yeux et la langue*/
    switch (etat)
    {
    case byebyelife:
        strcpy(yeux,"XX\0");
        strcpy(langue,"U\0");
        break;
    case lifesucks:
        strcpy(yeux,"--\0");
        strcpy(langue," \0");
        break;
    case liferocks:
        strcpy(yeux,"OO\0");
        strcpy(langue," \0");
        break;
    }

    /* On crée la vache de base qui "prend en paramètre" les yeux et la langue*/
    char vache[1000] = "          ^ __ ^\n           (%s)\\_______\n           (__)\\       )\\/\\\n   O         %s ||----w |\n  \\|/          ||     ||             \\|/\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    
    /* On affiche la vache avec les yeux et la langue modifiés */
    printf(vache, yeux, langue);
}

void update_stock(int lunchfood){
    /* On initialise le generateur de nombres aleatoires */
    time_t t ;
    srand (( unsigned ) time (& t ) ) ;

    /*On génère un nombre entre -3 et 3 inclus*/
    int crop = (rand() % 8) - 3;
    stock = stock + crop - lunchfood;
    if (stock<0){
        stock = 0;
    }
    else if (stock>10){
        stock = 10;
    }
}

void update_fitness(int lunchfood){
    time_t t ;
    t = t + 12232;
    srand((unsigned)time(&t));
    int digestion = (rand() % 4) - 3;
    fitness = fitness + digestion + lunchfood;
    if (fitness<0){
        fitness = 0;
    }
    else if (fitness>10){
        fitness= 10;
    }
}

int main(){
    int lunchfood;
    int dureedevie = 0;
    int etat = 2;
    while (etat != byebyelife)
    {
        affiche_vache(etat);
        printf("stock : %d\n", stock);
        printf("lunchfood? : ");
        scanf("%d", &lunchfood);
        while (lunchfood>stock || lunchfood<0){
            printf("Veuillez entrer une valeur entre 0 et %d.\n    lunchfood? : ", stock);
            scanf("%d", &lunchfood);
        }
        update_stock(lunchfood);
        update_fitness(lunchfood);
        if (fitness == 0 || fitness == 10){
            etat = byebyelife;
        }else if (fitness == 1 || fitness == 2 || fitness == 3 || fitness == 7 || fitness == 8 || fitness == 9){
            etat = lifesucks;
        }else if (fitness == 4 || fitness == 5 || fitness == 6){
            etat = liferocks;
        }
        dureedevie = dureedevie + 1;
        printf("______________________________________________________________________________________________\n\n");
    }
    affiche_vache(etat);
    printf("Vous avez perdu, votre vache avait %d ans\n",dureedevie);
}