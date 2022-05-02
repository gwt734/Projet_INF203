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
        if (strcmp(argv[i],"-T")==0 && argc > i+1){
            langue[0] = argv[i + 1][0];
        }
        if (strcmp(argv[i],"-e")==0 && argc > i+1){
            yeux[0] = argv[i + 1][0];
            yeux[1] = argv[i + 1][1]; 
        }
        if (strcmp(argv[i],"-parle")==0 && argc > i+1){
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
        }
    }
    printf(vache, yeux, langue);
}
void update() { printf(" \033[ H \033[ J"); }
void gotoxy(x, y) { printf(" \033[%d;%dH", x, y); }

void cligne(){
    gotoxy(4, 0);
    char *argv[2];
    argv[0] = "-e";
    argv[1] = "-O";
    affiche_vache(2, argv);
    gotoxy(4, 0);
    sleep(1);
    affiche_vache(0,argv);
    gotoxy(9, 0);
}


int main(int argc,char *argv[]){
    FILE *f=fopen(argv[1], "r");
    char fichier[100];
    char c;
    fscanf(f, "%c", &c);
    for(int i = 0; !feof(f); i++){
        char *argw[4];
        argw[0] = "-T";
        char str_c[1];
        str_c[0] = c;
        argw[1] = str_c;
        argw[2] = "-parle";
        argw[3] = fichier;
        affiche_vache(4, argw);
        fichier[i]=c;
        fscanf(f, "%c", &c);
    }
    char *argw[2];
    argw[0] = "-parle";
    argw[1] = fichier;
    affiche_vache(2, argw);
}