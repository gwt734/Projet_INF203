#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void affiche_vache(int argc, char *argv[]){
    /*On initialise les yeux et la langue en des caractères spécifiques ainsi qu'une vache */
    char yeux[3] = "OO\0";
    char langue[2] = " \0";
    char vache[1000] = "        \\ ^ __ ^\n         \\ (%s)\\_______\n           (__)\\       )\\/\\\n             %s ||----w |\n               ||     ||\n";
    
    /*Cette boucle va permettre de modifier la langue et les yeux en rentrant une option comme -T en argument
    avec le caractère par lequel on veut le remplacer on peut aussi le faire avec les yeux en suivant le même fonctionnement 
    mais à la place de -T on met -e*/
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i],"-T")==0){
            if (argc > i){
                langue[0] = argv[i + 1][0];
            }else{
                printf("Il manque un argument après l'option -T.\n");
                exit(EXIT_FAILURE);
            }
        }
        if (strcmp(argv[i],"-e")==0){
            if (argc > i){
                yeux[0] = argv[i + 1][0];
                yeux[1] = argv[i + 1][1];
            }else{
                printf("Il manque un argument après l'option -e.\n");
                exit(EXIT_FAILURE);
            }
             
        }
        /*Et lorsqu'on lui donne -parle ainsi qu'un autre argument, alors la vache va dire l'argument apres -parle*/
        if (strcmp(argv[i],"-parle")==0){
            if (argc > i){
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
    /*Cette boucle nous permet de faire danser notre vache et en reprenant la même 
    logique que précédemment, pour qu'elle danse il faut lui rentrer l'argument -danse 
    ainsi que le nombre de fois qu'elle effectura cette danse*/
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

void cligne2(){
    /*On fait un premier update pour effacer ce qu'il y a dans le terminal*/
    update();
    char *argv[2];
    argv[0] = "-e";
    argv[1] = "-O";
    /*On affiche la vache une fois avec les yeux ouverts ou refais un update puis avec les yeux fermés ...*/
    affiche_vache(0, argv);
    sleep(1);
    update();
    affiche_vache(2, argv);
    sleep(1);
    update();
    affiche_vache(0,argv);
}


int main(int argc,char *argv[]){
    cligne2();
}