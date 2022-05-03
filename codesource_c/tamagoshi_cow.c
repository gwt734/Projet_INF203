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

void affiche_vache(int etat, int dureedevie){
    /* Déclaration des yeux et de la langue */
    char yeux[3];
    char langue[2];

    /* On crée la vache de base qui "prend en paramètre" les yeux et la langue*/
    char vache[1000] = "          ^ __ ^\n           (%s)\\_______\n           (__)\\       )\\/\\\n   O         %s ||----w |\n  \\|/          ||     ||             \\|/\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    
    /* Dépendamment de l'état actuel on modifie les yeux et la langue*/
    switch (etat)
    {
    case byebyelife:
        if (dureedevie < 10)
        {
            strcpy(vache," _____________\n |    RIP    | - __ -_______\n |   Vache   |  (XX)_\\       )\\/\\\n |  0%d jours |  (__)==\\----w/===\n^^^^^^^^^^^^^^^^^^U^^^^^^^^^^^^^^^^\n");
            printf(vache, dureedevie);
        }
        else if (dureedevie < 100)
        {
            strcpy(vache," _____________\n |    RIP    | - __ -_______\n |   Vache   |  (XX)_\\       )\\/\\\n |  %d jours |  (__)==\\----w/===\n^^^^^^^^^^^^^^^^^^U^^^^^^^^^^^^^^^^\n");
            printf(vache, dureedevie);
        }
        else
        {
            strcpy(vache," _____________\n |    RIP    | - __ -_______\n |   Vache   |  (XX)_\\       )\\/\\\n | Trop agée |  (__)==\\----w/===\n^^^^^^^^^^^^^^^^^^U^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf(vache);
        }
        break;
    case lifesucks:
        strcpy(vache,"          ^ __ ^\n           (--)\\_______\n           (__)\\       )\\/\\\n   O           ||----w |\n  \\|/          ||     ||             \\|/\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        printf(vache);
        break;
    case liferocks:
        strcpy(vache,"           ^ __ ^\n            (OO)\n           ~(o_)\\\n           \\\\//  \\\n            ~  \\  \\/\\/\n                ||\n                ||\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        printf(vache);
        break;
    }
}

void stock_update(int lunchfood){
    /* On initialise le generateur de nombres aleatoires */
    time_t t ;
    srand (( unsigned ) time (& t ) ) ;

    /*On génère un nombre entre -3 et 3 inclus*/
    int crop = (rand() % 8) - 3;
    stock = stock + crop - lunchfood;

    /*Notre stock doit obligatoirement être en 0 et 10 inclus*/
    if (stock<0){
        stock = 0;
    }
    else if (stock>10){
        stock = 10;
    }
}

void fitness_update(int lunchfood){
    /* On initialise le generateur de nombres aleatoires */
    time_t t ;
    t = t + 12232;
    srand((unsigned)time(&t));

    /*On génère un nombre entre -3 et 0 inclus*/
    int digestion = (rand() % 4) - 3;
    fitness = fitness + digestion + lunchfood;
    
    /*Notre stock doit obligatoirement être en 0 et 10 inclus*/
    if (fitness<0){
        fitness = 0;
    }
    else if (fitness>10){
        fitness= 10;
    }
}

int main(){
    /*Initialisation de variable */
    int lunchfood;
    int dureedevie = 0;
    int etat = 2;

    /*Boucle qui va vérifier que la vache n'est pas morte et qui compte sa durée de vie*/
    while (etat != byebyelife)
    {
        /*affiche l'état courant de la vache en la dessinant*/
        affiche_vache(etat, dureedevie);

        /*On affiche le stock restant et on demande de rentrer
        une valeur de lunchfood qui doit être compris entre le stock et 0 compris*/ 
        printf("stock : %d\n", stock);
        printf("lunchfood? : ");
        scanf("%d", &lunchfood);
        while (lunchfood>stock || lunchfood<0){
            printf("Veuillez entrer une valeur entre 0 et %d.\n    lunchfood? : ", stock);
            scanf("%d", &lunchfood);
        }
        
        /* On met à jour les valeurs du stock et du fitness et selon 
        la valeur du fitness la vache change d'état et nous refaisons cette boucle 
        tant que la vache ne soit pas dans l'état byebyelife et si ce n'est pas le cas, on ajoute un à la durée de vie*/
        stock_update(lunchfood);
        fitness_update(lunchfood);
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
    /*Lorsque la partie est finie, on affiche la vache morte et on conclu avec une phrase et son age*/
    affiche_vache(etat, dureedevie);
    return 0;
}