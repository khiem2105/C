#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct element {
    float x,y;
    int num;
    struct element *suivant;
};
//prototype init
void init(struct element **);
//prototype afficher
void afficher(const struct element *);
//prototype supprimer_dernier_element
void supprimer_dernier_element(struct element *);
//Prototype liberer_liste
void liberer_liste(struct element *);
//Prototype save
int save(struct element *);
//Prototype restore
int restore(struct element **);

//Définition de init
void init(struct element **adebut) {
    *adebut = NULL;
    float x,y;
    int num;
    struct element *courant;
    while(1) {
        puts("Saisir num, x et y (0=num pour quitter)");
        scanf("%d %f %f", &num, &x, &y);
        if(num == 0) break;
        courant = (struct element*)malloc(sizeof(struct element));
        courant->num = num;
        courant->x = x; courant->y = y;
        courant->suivant = *adebut;
        *adebut = courant;
    }
}

//D éfintion de afficher
void afficher(const struct element *debut) {
    while(debut != NULL) {
        printf("Cellule(%d,%.2f,%.2f)->", debut->num, debut->x, debut->y);
        debut = debut->suivant;
    }
    puts("NULL");
}

//Définition de supprimer dernier element
void supprimer_dernier_element(struct element *debut) {
    struct element *pre;

    while(debut->suivant != NULL) {
        pre = debut;
        debut = debut->suivant;
    }
    pre->suivant = NULL;
    free(debut);
}

void liberer_liste(struct element *debut) {
    if(debut->suivant == NULL) free(debut);
    else {
        liberer_liste(debut->suivant);
        free(debut);
    }
}

int save(struct element *debut) {
    FILE *out = fopen("list.bin", "wb");

    if(!out) {
        printf("Can not open file");
        return -1;
    }
    else {
        while(debut != NULL) {
            int result = fwrite(debut, sizeof(struct element), 1, out);
            if(result == -1) {
                printf("Error");
                return -1;
            }
            debut = debut->suivant;
        }
        fclose(out);
        return 0;
    }
}

int restore(struct element **adebut) {
    FILE *in = fopen("list.bin", "rb");

    if(!in) {
        printf("Can not open file");
        return -1;
    }
    *adebut = NULL;
    while(1) {
        struct element *new = malloc(sizeof(struct element));
        int result = fread(new, sizeof(struct element), 1, in);
        if(feof(in)) break;
        if(result == -1) {
            printf("Error");
            return -1;
        }
        if(*adebut == NULL) {
            *adebut = new;
            (*adebut)->suivant = NULL;
        }
        else {
            struct element *temp = *adebut;
            while(temp->suivant != NULL) temp = temp->suivant;
            temp->suivant = new;
            temp->suivant->suivant = NULL;
        }
        // printf("%d %f %f\n", new->num, new->x, new->y);
    }
    fclose(in);
    return 0;
}

int main() {
    struct element *debut;

    printf("Initialiser la liste:\n");
    init(&debut);
    printf("Apres l'initialisation:\n");
    afficher(debut);
    // supprimer_dernier_element(debut);
    // printf("Apres avoir supprime le dernier element:\n");
    // afficher(debut);
    // liberer_liste(debut);
    // debut = NULL;
    // afficher(debut);
    save(debut);
    struct element *new_liste;
    restore(&new_liste);
    afficher(new_liste);
}
