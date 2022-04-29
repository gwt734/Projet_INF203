#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void affiche_vache(int argc, char *argv[]){
    char yeux[3] = "OO\0";
    char langue[2] = " \0";
    char vache[1000] = "        \\ ^ __ ^\n         \\ (%s)\\_______\n           (__)\\       )\\/\\\n             %s ||----w |\n               ||     ||\n ";
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i],"-T")==0 && argc > i+1){
            langue[0] = argv[i + 1][0];
        }
        if (strcmp(argv[i],"-e")==0 && argc > i+1){
            yeux[0] = argv[i + 1][0];
            yeux[1] = argv[i + 1][1]; 
        }
        
    }
    for (int i = 0; i <argc; i++){
        if (strcmp(argv[i],"-tournevache")==0 && argc > i+1){
            int nombre_tours = atoi(argv[i+1]);
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
    printf(vache, yeux, langue);
}
void update() { printf(" \033[ H \033[ J"); }
void gotoxy(x, y) { printf(" \033[%d;%dH", x, y); }


int main(int argc,char *argv[]){
    affiche_vache(argc, argv);
    /*
    printf("ligne 1\nligne 2\n");
    
 
    printf("\033");
    gotoxy(1, 7);
    printf("ligne 3\n");
    update();
    */
}