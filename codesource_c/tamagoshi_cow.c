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

void update() { printf("\033[H\033[J"); }

void affiche_vache(int etat, int dureedevie, int stock, char *nom_vache){
    /*On nettoie le terminal*/
    update();

    /*On initialise la vache*/
    char vache[1000];

    /* On initialise la liste qui défini l'ordre dans lequel remplir les bottes de foins et la liste qui contient la chaine a afficher à l'endroit de chaque bottes ("  " si pas de botte et "##" si oui). */
    int ordre_bottes_de_foin[10] = {8, 9, 5, 7, 4, 2, 10, 6, 3, 1};
    char *bottes_de_foins[10];

    /* dépendamment du niveau du stock on "active" les bottes de foin correspondantes */
    for (int i = 0; i < 10; i++){
        if (stock>=i+1){
            bottes_de_foins[ordre_bottes_de_foin[i]-1] = "##";
        }else{
            bottes_de_foins[ordre_bottes_de_foin[i]-1] = "  ";
        }
    }

    /* On ajoute des espaces autour du nom pour pouvoir l'afficher correctement*/
    char nom_vache_formatte[100];
    int len_nom_vache = strlen(nom_vache);
    int espaces_pour_nom = (11 - len_nom_vache) / 2;
    int i;
    for (i = 0; i < espaces_pour_nom; i++)
    {
        nom_vache_formatte[i] = ' ';
    }
    for (int j = 0; j < len_nom_vache; j++)
    {
        nom_vache_formatte[espaces_pour_nom+j] = nom_vache[j];
    }
    for (int k = 0; k < espaces_pour_nom + 1; k++)
    {
        nom_vache_formatte[espaces_pour_nom + len_nom_vache + k]=' ';
    }
    if (len_nom_vache % 2 == 1)
    {
        nom_vache_formatte[espaces_pour_nom + len_nom_vache + espaces_pour_nom] = '\0';
    }
    else
    {
        nom_vache_formatte[espaces_pour_nom + len_nom_vache + espaces_pour_nom] = ' ';
        nom_vache_formatte[espaces_pour_nom + len_nom_vache + espaces_pour_nom + 1] = '\0';
    }

    /* Dépendamment de l'état actuel on modifie le dessin de la vache puis on l'affiche*/
    switch (etat)
    {
    case byebyelife:
        if (dureedevie < 10)
        {
            strcpy(vache, "                                                                               +&-\n                                                                            _.-^-._    .--.\n                                                                         .-'   _   '-. |__|\n                                                                        /     |_|     \\|  |\n                                                                       /_____STOCK_____\\  |\n _____________                                                        /|       %s      |\\ |\n |    RIP    | - __ -________                                          |     %s %s     |  |\n |%s|  (XX)_\\       )\\/\\                  |---|---|---|---|---|    %s %s %s   |  |\n |  0%d jours |  (__)==\\----w/===     \\|/           |---|---|---|---|---|  %s %s %s %s  |  |\n^^^^^^^^^^^^^^^^^^U^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf(vache, bottes_de_foins[0], bottes_de_foins[1], bottes_de_foins[2], nom_vache_formatte, bottes_de_foins[3], bottes_de_foins[4], bottes_de_foins[5], dureedevie, bottes_de_foins[6], bottes_de_foins[7], bottes_de_foins[8], bottes_de_foins[9]);
        }
        else if (dureedevie < 100)
        {
            strcpy(vache, "                                                                               +&-\n                                                                            _.-^-._    .--.\n                                                                         .-'   _   '-. |__|\n                                                                        /     |_|     \\|  |\n                                                                       /_____STOCK_____\\  |\n _____________                                                        /|       %s      |\\ |\n |    RIP    | - __ -________                                          |     %s %s     |  |\n |%s|  (XX)_\\       )\\/\\                  |---|---|---|---|---|    %s %s %s   |  |\n |  %d jours |  (__)==\\----w/===     \\|/           |---|---|---|---|---|  %s %s %s %s  |  |\n^^^^^^^^^^^^^^^^^^U^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf(vache, bottes_de_foins[0], bottes_de_foins[1], bottes_de_foins[2], nom_vache_formatte, bottes_de_foins[3], bottes_de_foins[4], bottes_de_foins[5], dureedevie, bottes_de_foins[6], bottes_de_foins[7], bottes_de_foins[8], bottes_de_foins[9]);
        }
        else
        {
            strcpy(vache, "                                                                               +&-\n                                                                            _.-^-._    .--.\n                                                                         .-'   _   '-. |__|\n                                                                        /     |_|     \\|  |\n                                                                       /_____STOCK_____\\  |\n _____________                                                        /|       %s      |\\ |\n |    RIP    | - __ -________                                          |     %s %s     |  |\n |%s|  (XX)_\\       )\\/\\                  |---|---|---|---|---|    %s %s %s   |  |\n | Trop agée |  (__)==\\----w/===     \\|/           |---|---|---|---|---|  %s %s %s %s  |  |\n^^^^^^^^^^^^^^^^^^U^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf(vache, bottes_de_foins[0], bottes_de_foins[1], bottes_de_foins[2], nom_vache_formatte, bottes_de_foins[3], bottes_de_foins[4], bottes_de_foins[5], bottes_de_foins[6], bottes_de_foins[7], bottes_de_foins[8], bottes_de_foins[9]);
        }
        break;
    case lifesucks:
        //strcpy(vache, "          ^ __ ^\n           (--)\\_______\n           (__)\\       )\\/\\\n   O           ||----w |\n  \\|/          ||     ||             \\|/\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        strcpy(vache, "                                                                               +&-\n                                                                            _.-^-._    .--.\n                                                                         .-'   _   '-. |__|\n                                                                        /     |_|     \\|  |\n          ~ __ ~                                                       /_____STOCK_____\\  |\n           (--)\\_______                                               /|       %s      |\\ |\n           (__)\\       )\\/\\                                            |     %s %s     |  |\n   O           ||----w |                           |---|---|---|---|---|    %s %s %s   |  |\n  \\|/          ||     ||             \\|/           |---|---|---|---|---|  %s %s %s %s  |  |\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        printf(vache, bottes_de_foins[0], bottes_de_foins[1], bottes_de_foins[2], bottes_de_foins[3], bottes_de_foins[4], bottes_de_foins[5], bottes_de_foins[6], bottes_de_foins[7], bottes_de_foins[8], bottes_de_foins[9]);
        break;
    case liferocks:
        // strcpy(vache,"           ^ __ ^\n            (OO)\n           ~(o_)\\\n           \\\\//  \\\n            ~  \\  \\/\\/\n   0            ||\n  \\|/           ||                   \\|/\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        strcpy(vache, "                                                                               +&-\n                                                                            _.-^-._    .--.\n           ^ __ ^                                                        .-'   _   '-. |__|\n            (OO)                                                        /     |_|     \\|  |\n           ~(o_)\\                                                      /_____STOCK_____\\  |\n           \\\\//  \\                                                    /|       %s      |\\ |\n            ~  \\  \\/\\/                                                 |     %s %s     |  |\n   0            ||                                 |---|---|---|---|---|    %s %s %s   |  |\n  \\|/           ||                   \\|/           |---|---|---|---|---|  %s %s %s %s  |  |\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        printf(vache, bottes_de_foins[0], bottes_de_foins[1], bottes_de_foins[2], bottes_de_foins[3], bottes_de_foins[4], bottes_de_foins[5], bottes_de_foins[6], bottes_de_foins[7], bottes_de_foins[8], bottes_de_foins[9]);
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
    /*On nettoie le terminal*/
    update();

    /*Initialisation de variable */
    int lunchfood;
    int dureedevie = 0;
    int etat = 2;

    /*On demande de rentrer le nom de la vache dont la longueur doit etre comprise entre 1 et 11 compris la boucle permet de redmander tant que la condition n'est pas vérifiée*/ 
    char nom_vache[100];
    printf("Comment voulez-vous nommer votre vache ? ");
    scanf("%s", nom_vache);
    while (strlen(nom_vache) > 11 || strlen(nom_vache) < 1)
    {
        printf("Veuillez entrer un nom d'au moins un caractère et au plus 11.\n");
        scanf("%s",nom_vache);
    }

    /*Boucle qui va vérifier que la vache n'est pas morte et qui compte sa durée de vie*/
    while (etat != byebyelife)
    {
        /*affiche l'état courant de la vache en la dessinant*/
        affiche_vache(etat, dureedevie, stock, nom_vache);

        /*On demande de rentrer une valeur de lunchfood qui doit être compris entre le stock et 0 compris la boucle permet de redmander tant que la condition n'est pas vérifiée*/ 
        printf("Combien voulez vous donner de bottes de foin à %s? : ", nom_vache);
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
    }
    /*Lorsque la partie est finie, on affiche la vache morte et on conclu avec une phrase et son age*/
    affiche_vache(etat, dureedevie, stock, nom_vache);
    return 0;
}