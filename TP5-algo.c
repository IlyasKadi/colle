#include<stdlib.h>
#include<stdio.h>


typedef struct concours{
    char filier;
    int seuil;
    LISTE L_Principal;
    FILE* L_Attente;
}CONCOURS;

typedef struct maillon{
    CANDIDAT candidat;
    struct liste *suivant;
}MAILLON;

typedef MAILLON* LISTE;

typedef struct candidat{
    char nom[20];
    int note;
    int cne;
}CANDIDAT;

typedef struct file{
    MAILLON *tete;
    MAILLON *queue;
}FILE;

// initFile 
FILE* initFile(){
    FILE *f = malloc(sizeof(FILE));
    f->tete = NULL;
    f->queue = NULL;
    return f;
}

// initMaillon
MAILLON *initMaillon(){
    MAILLON *m = malloc(sizeof(MAILLON));
    m->suivant = NULL;
    return m;
}

// Maillonvide
int MaillonVide(MAILLON *m){
    return m == NULL;
}

// FileVide
int FileVide(FILE *f){
    if(f->tete == NULL && f->queue == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// creercandidat
CANDIDAT *creercandidat(CANDIDAT c){
    CANDIDAT *candidat = malloc(sizeof(CANDIDAT));
    candidat->note = c.note;
    candidat->cne = c.cne;
    return candidat;
}

// initconcours
CONCOURS *initconcours(){
    CONCOURS *c = malloc(sizeof(CONCOURS));
    c->filier = ' ';
    c->seuil = 0;
    c->L_Principal = initMaillon();
    c->L_Attente = initFile();;
    return c;
}

// enfiler
void enfiler(FILE *f, MAILLON *m){
    if(FileVide(f)){
        f->tete = m;
        f->queue = m;
    }
    else{
        f->queue->suivant = m;
        f->queue = m;
    }
}

// defiler
void *defiler(FILE *f){
    MAILLON *m = f->tete;
    if(f->tete == f->queue){
        f->tete = NULL;
        f->queue = NULL;
    }
    else{
        f->tete = f->tete->suivant;
    }
    return m;
}

// tailleFile
int tailleFile(FILE *f){
    int i = 0;
    MAILLON *m = f->tete;
    while(m != NULL){
        i++;
        m = m->suivant;
    }
    return i;
}


// tailleListe
int tailleListe(MAILLON *m){
    int count = 0;
    while(m != NULL){
        count++;
        m = m->suivant;
    }
    return count;
}

float moyenneListe(MAILLON *m){
    int i = 0;
    int sum = 0;
    while(m != NULL){
        sum += m->candidat.note;
        m = m->suivant;
    }
    return sum/i;
}

float moyenneFile(FILE *f){
    int i = 0;
    int sum = 0;
    MAILLON *m = f->tete;
    while(m != NULL){
        sum += m->candidat.note;
        m = m->suivant;
    }
    return sum/i;
}

// file copy
FILE *filecopy(FILE *f){
    FILE *f2 = initFile();
    MAILLON *m = f->tete;
    while(m != NULL){
        enfiler(f2, m);
        m = m->suivant;
    }
    return f2;
}

// Nous souhaitons gérer les inscriptions aux concours de plusieurs filières à l’aide des listes chainées et les files. Réaliser un programme qui :
// • Ajoute les candidats ayant une note supérieure ou égale au seuil fixé de la filière dans la liste principale, et les autres dans la liste d’attentes.
void ajouterCandidat(CONCOURS *c, CANDIDAT cnd){
    if(cnd.note >= c->seuil){
        MAILLON *m = creercandidat(cnd);
        MAILLON *tmp = c->L_Principal;
        while (tmp->suivant != NULL){
            tmp = tmp->suivant;
        }
        tmp->suivant = m;
        m->suivant = NULL;
    }
    else{
        enfiler(c->L_Attente, creercandidat(cnd));
    }
}

// • Affiche le nombre des candidats dans les deux listes, et la moyenne générale de chaque liste.
void affichernbCandidats(CONCOURS *c){
    printf("Nombre de candidats dans la liste principale : %d\n", tailleListe(c->L_Principal));
    printf("Nombre de candidats dans la liste d'attente : %d\n", tailleFile(c->L_Attente));
    printf("Moyenne générale de la liste principale : %.2f\n", moyenneListe(c->L_Principal));
    printf("Moyenne générale de la liste d'attente : %.2f\n", moyenneFile(c->L_Attente));
}
// • Supprime un candidat de la liste principale et le remplace par un candidat de la liste d’attente.

void supprimerCandidate(CONCOURS *c){
    MAILLON *m = c->L_Principal;
    c->L_Principal = c->L_Principal->suivant;
    free(m);
    
    MAILLON *tmp = c->L_Attente->tete;
    defiler(c->L_Attente);

    MAILLON *tmp2 = c->L_Principal;
    while (tmp2->suivant != NULL){
        tmp2 = tmp2->suivant;
    }
    tmp2->suivant = tmp;
    tmp->suivant = NULL;
}


int main(){
// tester le programme pour 2 filières :
// • Filière A : seuil = 10
// • Filière B : seuil = 15
    CONCOURS *c1 = initconcours();
    c1->filier = 'A';
    c1->seuil = 10;
    CANDIDAT* cnd1 = creercandidat(*cnd1);
    *cnd1->nom = "toto";
    cnd1->note = 5;
    ajouterCandidat(c1, *cnd1);
    CANDIDAT* cnd2 = creercandidat(*cnd2);
    *cnd2->nom = "titi";
    cnd2->note = 15;
    ajouterCandidat(c1, *cnd2);
    return 0;
}


