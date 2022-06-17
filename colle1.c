#include<stdlib.h>
#include<stdio.h>

typedef struct maillon{
    float note;
    struct maillon *suivant;
}MAILLON;

typedef struct file{
    MAILLON *tete;
    MAILLON *queue;
}File;

typedef struct pile{
    MAILLON *tete;
}PILE;

// init maillon
MAILLON *initMaillon(){
    MAILLON *m = malloc(sizeof(MAILLON));
    m->suivant = NULL;
    return m;
}

// creer maillon
MAILLON *creerMaillon(float note){
    MAILLON *m = initMaillon();
    m->note = note;
    m->suivant = NULL;
    return m;
}

// intit File
File *initFile(){
    File *f = malloc(sizeof(File));
    f->tete = NULL;
    f->queue = NULL;
    return f;
}

// init pile
PILE *initPile(){
    PILE *p = malloc(sizeof(PILE));
    p->tete = NULL;
    return p;
}

// File vide
int FileVide(File *f){
    if(f->tete == NULL && f->queue == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// pile vide
int pileVide(PILE *p){
    if(p->tete == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// enFiler
float enFiler(File *f, float note){
    MAILLON *m = initMaillon();
    m->note = note;
    if(FileVide(f)){
        f->tete = m;
        f->queue = m;
    }
    else{
        f->queue->suivant = m;
        f->queue = m;
    }
    return note;
}

// deFiler
float deFiler(File *f){
    float note;
    if(FileVide(f)){
        printf("File vide\n");
        return 0;
    }
    else{
        note = f->tete->note;
        MAILLON *m = f->tete;
        f->tete = f->tete->suivant;
        free(m);
        return note;
    }
}


// empiler
float empiler(PILE *p, float note){
    MAILLON *m = initMaillon();
    m->note = note;
    if(pileVide(p)){
        p->tete = m;
    }
    else{
        m->suivant = p->tete;
        p->tete = m;
    }
    return note;
}


// depiler
void depiler(PILE *p){
    if(pileVide(p)){
        printf("Pile vide\n");
    }
    else{
        MAILLON *m = p->tete;
        p->tete = p->tete->suivant;
        free(m);
    }
}








int main(int argc, char const *argv[])
{
    // Créer une File qui content les notes des étudiants 
    File *f = initFile();
    FILE *copyF = initFile();

    float notes[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    // Remplissez la File avec les notes des étudiants
    for(int i = 0; i < 20; i++){
        enFiler(f, notes[i]);
    }
    // Afficher la File
    MAILLON *m = f->tete;
    while(m != NULL){
        printf("%f\n", m->note);
        m = m->suivant;
    }

    // Créer une pile a partir de la File en mettant note ‹10 en dernier puis note >=10 et note <15 et au sommet note >17
    PILE *p = initPile();
    PILE *p2 = initPile();
    PILE *p3 = initPile();
    if (FileVide(f)){
        printf("File vide\n");
    }
    else{
        while(!FileVide(f)){
            float note = deFiler(f);
            if(note < 10){
                empiler(p, note);
            }
            else if(note >= 10 && note < 15){
                empiler(p2, note);
            }
            else{
                empiler(p3, note);
            }
        }
        enfiler(copyF, p);
        defiler(p);
    }

    while (!pileVide(p2)){
        enfiler(p, p2);
        defiler(p2);
    }
    while (!pileVide(p3)){
        enfiler(p, p3);
        defiler(p3);
    }
    while (!pileVide(copyF)){
        enfiler(p, copyF);
        defiler(copyF);
    }
    
    // Afficher la pile
    m = p->tete;
    while(m != NULL){
        printf("%f\n", m->note);
        m = m->suivant;
    }

    return 0;
}
