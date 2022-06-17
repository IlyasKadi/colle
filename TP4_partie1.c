#include<stdlib.h>
#include<stdio.h>

// Partie 1 : implémentation d'une pile d'entiers à l'aide d'une liste chaînée.
// 1. Définir la structure PILE.

typedef struct maillon {
    char *donnee;
    struct maillon *suivant;
}Maillon;

typedef struct pile{
    Maillon *front;
    int taille;
} Pile;

//2. Écrire les fonctions suivantes :
// initPile qui retourne un pointeur sur une pile initialisée à vide

Pile *initPile(){
    Pile *p = malloc(sizeof(Pile));
    p->front = NULL;
    p->taille = 0;
    return p;
}

// pileVide qui retourne 0 si la pile contient au moins un élément, et 1 si la pile est vide.
int pileVide(Pile *p){
    return p->taille == 0;
}


// sommet qui permet de récupérer la valeur du sommet de la pile, la fonction retourne 1 si tout se passe bien, retourne 0 si la pile est vide.
int sommet(Pile *p, char *s){
    if(pileVide(p)){
        return 0;
    }
    else{
        *s = p->front->donnee;
        return 1;
    }
}

// empiler qui empile un entier dans une pile.
void empiler(Pile *p, char *s){
    Maillon *m = malloc(sizeof(Maillon));
    m->donnee = s;
    m->suivant = p->front;
    p->front = m;
    p->taille++;
}

// depiler qui supprime le sommet de la pile p. La mémoire occupée par ce sommet doit être libérée.
void depiler(Pile *p){
    if(pileVide(p)){
        return;
    }
    else{
        Maillon *m = p->front;
        p->front = m->suivant;
        free(m);
        p->taille--;
    }
}


int main(int argc, char const *argv[])
{
// 3. Écrire le programme principal qui réalise le scénario suivant :
// - Créer une pile vide.
// - Empiler la liste (1, 2, 15, -5, 7).
// - Afficher le sommet de la pile.
Pile *p = initPile();
int L[5] = {1, 2, 15, -5, 7};
for (int i = 0; i < 5; i++)
{
    empiler(p, L[i]);
    
}

char s;
while(!pileVide(p)){
    sommet(p, &s);
    printf("%d\n", s);
    depiler(p);
}
return 0;
}
