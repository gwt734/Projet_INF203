# Projet_INF203

## 1 - Préliminaires

## 2 - Bash

## 3 - C

## 4 - Automates

### Automate

image

1. Fonction affiche :
```c
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
```





