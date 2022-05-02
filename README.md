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
    char yeux[3];
    char langue[2];
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
    char vache[1000] = "          ^ __ ^\n           (%s)\\_______\n           (__)\\       )\\/\\\n   O         %s ||----w |\n  \\|/          ||     ||             \\|/\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    printf(vache, yeux, langue);
}
```





