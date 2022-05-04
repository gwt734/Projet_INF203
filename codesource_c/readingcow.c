#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void affiche_vache(int argc, char *argv[]){
    char yeux[3] = "OO\0";
    char langue[2] = " \0";
    char vache[1000] = "        \\ ^ __ ^\n         \\ (%s)\\_______\n           (__)\\       )\\/\\\n             %s ||----w |\n               ||     ||\n";
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i],"-T")==0){
            if (argc > i+1){
                langue[0] = argv[i + 1][0];
            }else{
                printf("Il manque un argument après l'option -T.\n");
                exit(EXIT_FAILURE);
            }
        }
        if (strcmp(argv[i],"-e")==0){
            if (argc > i+1){
                yeux[0] = argv[i + 1][0];
                yeux[1] = argv[i + 1][1];
            }else{
                printf("Il manque un argument après l'option -e.\n");
                exit(EXIT_FAILURE);
            }
             
        }

        if (strcmp(argv[i],"-parle")==0){
            if (argc > i+1){
                printf(" ");
                for (int j = 0; j < 2+strlen(argv[i+1]); j++){
                    printf("-");
                }
                printf("\n< ");
                for (int j = 0;argv[i+1][j] != '\0'; j++){
                    printf("%c", argv[i+1][j]);
                }
                printf(" >\n ");
                for (int j = 0; j < 2+strlen(argv[i+1]); j++){
                    printf("-");
                }
                printf("\n");
            }else{
                printf("Il manque un argument après l'option -parle.\n");
                exit(EXIT_FAILURE);
            }
        }
    for (int i = 0; i <argc; i++){
        if (strcmp(argv[i], "-danse") == 0)
        {
            int nombre_tours = atoi(argv[i + 1]);
            for (int j = 0; j < nombre_tours-1; j++)
            {
                strcpy(vache, "                 /)  (\\\n            .~._((,\"\".))_.~,\n             `~.   %s   ,~'\n               / ,n~~n. \\\n              { { .__. } }\n               ) `~ %s~' (\n              /`-._  _.-'\\\n             /            \\\n           ,-X            X-.\n          /   \\          /   \\\n         (     )| |  | |(     )\n          \\   / | |  | | \\   /\n           \\_(.-( )--( )-.)_/\n           /_,\\ ) /  \\ ( /._\\\n               /_,\\  /._\\\n");
                printf(vache, yeux, langue);
                sleep(1);
                printf("\n");
                strcpy(vache, "                 /)  (\\\n            .-._((,~~.))_.-,\n             `-.   %s   ,-'\n               / ,n--n. \\\n       (`'\\   ( ( .__. ) )  /`')\n        `.'\"._ ) `- %s-' (_,\"`.'\n          \"._             _,\"\n             /            \\\n            (              )\n            (`-.__    __.-')\n             \\   /`--'\\   /\n              ) /      \\ (\n             /._\\      /_,\\\n");
                printf(vache, yeux, langue);
                printf("\n");
                sleep(1);
            }
            strcpy(vache, "                 /)  (\\\n            .~._((,\"\".))_.~,\n             `~.   %s   ,~'\n               / ,n~~n. \\\n              { { .__. } }\n               ) `~ %s~' (\n              /`-._  _.-'\\\n             /            \\\n           ,-X            X-.\n          /   \\          /   \\\n         (     )| |  | |(     )\n          \\   / | |  | | \\   /\n           \\_(.-( )--( )-.)_/\n           /_,\\ ) /  \\ ( /._\\\n               /_,\\  /._\\\n");
        }
    }
    }
    printf(vache, yeux, langue);
}
void update() { printf("\033[H\033[J"); }
void gotoxy(x, y) { printf(" \033[%d;%dH", x, y); }


int main(int argc,char *argv[]){
    /*On ouvre le fichier que l'on va vouloir lui faire manger*/
    FILE *f=fopen(argv[1], "r");
    char fichier[100];
    char c;
    /*On va prendre toutes les caractères du fichier un a un et grâce au for 
    d'abord ils vont passé au niveau de la langue de la vache grâce à l'option -T 
    expliqué auparavant puis grâce à l'option -T, la lettre va ensuite s'afficher dans la bulle.
    On update à chaque itérattion pour que cela soit animé.*/
    fscanf(f, "%c", &c);
    for(int i = 0; !feof(f); i++){
        update();
        char *argw[4];
        argw[0] = "-T";
        char str_c[1];
        str_c[0] = c;
        argw[1] = str_c;
        argw[2] = "-parle";
        argw[3] = fichier;
        affiche_vache(4, argw);
        sleep(1);
        fichier[i]=c;
        fscanf(f, "%c", &c);
    }
    update();
    char *argw[2];
    argw[0] = "-parle";
    argw[1] = fichier;
    affiche_vache(2, argw);
}