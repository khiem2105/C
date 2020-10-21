#include <stdio.h>
#include <stdlib.h>
int main(){
    struct point{
        char nom; // caractère
        int x, y;
    };
    struct point bloc;
    char nomfich[81];
    FILE *in;
    /* ouvrir le fichier à lire */
    printf("nom du fichier:");
    scanf("%80s", nomfich);
    in = fopen(nomfich, "rb");//mode d’accès
    if (!in){
        printf("Impossible d'ouvrir ce fichier");
        exit(-1);
    }
    printf("lire le nom et les coordonnées des points \n");
    while (1){
        fread(&bloc, sizeof(struct point), 1, in);// 1 bloc de sizeof(struct point) octets
        if (feof(in))
            break;
        printf("%c %d %d\n", bloc.nom, bloc.x, bloc.y);
    }
    fclose(in);
}