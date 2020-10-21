#include <stdio.h>
#include <stdlib.h>

int main(){
    struct point{
        char nom;
        int x, y;
    };
    struct point bloc;

    char nomFichier[81];
    FILE *out;

    printf("Nom du fichier:");
    scanf("%80s", nomFichier);
    out = fopen(nomFichier, "wb");
    if(!out){
        printf("Can not open file");
        exit(-1);
    }
    while(1){
        printf("Point:");
        scanf(" %c %d %d", &bloc.nom, &bloc.x, &bloc.y);
        if(bloc.nom == '*'){
            exit(1);
        }
        fwrite(&bloc, sizeof(struct point), 1, out);
    }
    fclose(out);

}