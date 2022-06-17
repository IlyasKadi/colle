#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int valeur;
	struct node *left;
	struct node *right;
}node;

typedef node *arbre;

arbre initArbre(){
	arbre racine;
	racine=NULL;
	return racine;
}
int taillearbre(arbre racine){
	int count=0;
	if(racine==NULL){
		return 0;
	}
}
arbre creerArbre( int v, arbre g, arbre d){
    arbre racine;
    racine = malloc(sizeof(node));
    racine->valeur = v;
    racine->left = g;
    racine->right = d;
    return racine;
}

// On considère cet arbre binaire de recherche, écrivez un programme qui permet de :
	// 1. Insérer toutes les valeurs d'un tableau dans l'arbre binaire de recherche.
	void inserer(arbre *racine, int valeur){
		if(*racine == NULL){
			*racine = (arbre)malloc(sizeof(node));
			(*racine)->valeur = valeur;
			(*racine)->left = NULL;
			(*racine)->right = NULL;
		}
		else if(valeur < (*racine)->valeur){
			inserer(&(*racine)->left, valeur);
		}
		else if(valeur > (*racine)->valeur){
			inserer(&(*racine)->right, valeur);
		}
	}
	// 2. Parcourir l’arbres à l’aide des 3 méthodes : inFixe, PostFixe et prefixe.
	
	void parcourirInFixe(arbre racine){
		if(racine != NULL){
			printf("%d ", racine->valeur);
			parcourirInFixe(racine->left);
			parcourirInFixe(racine->right);
		}
	}
	void parcourirPostFixe(arbre racine){
		if(racine != NULL){
			parcourirPostFixe(racine->left);
			parcourirPostFixe(racine->right);
			printf("%d ", racine->valeur);
		}
	}
	void parcourirPrefixe(arbre racine){
		if(racine != NULL){
			printf("%d ", racine->valeur);
			parcourirPrefixe(racine->left);
			parcourirPrefixe(racine->right);
		}
	}
	// 3. Calculer le nombre des nœuds et des feuilles.
	int nombrenodes(arbre racine){
		if(racine == NULL){
			return 0;
		}
		else{
			return 1 + nombrenodes(racine->left) + nombrenodes(racine->right);
		}
	}

	int nombreFeuilles(arbre racine){
		if(racine == NULL){
			return 0;
		}
		else if(racine->left == NULL && racine->right == NULL){
			return 1;
		}
		else{
			return nombreFeuilles(racine->left) + nombreFeuilles(racine->right);
		}
	}

	// 5. Créer une copie de l’arbre.
	arbre copieArbre(arbre racine){
		arbre copie = initArbre();
		if(racine != NULL){
			copie = creerArbre(racine->valeur, copieArbre(racine->left), copieArbre(racine->right));
		}
		return copie;
	}

	// 6. Tester si un élément est dans l’arbre.
	int estDansArbre(arbre racine, int valeur){
		if(racine == NULL){
			return 0;
		}
		else if(valeur == racine->valeur){
			return 1;
		}
		else if(valeur < racine->valeur){
			return estDansArbre(racine->left, valeur);
		}
		else{
			return estDansArbre(racine->right, valeur);
		}
	}

	// 7. Renvoyer le minimum de l’arbre.
	int minimum(arbre racine){
		if(racine->left == NULL){
			return racine->valeur;
		}
		else{
			return minimum(racine->left);
		}
	}

	int main(){
		arbre racine = initArbre();
    // 1. Insérer toutes les valeurs de l'arbre.
		int tab[8] = {50, 38, 33, 34, 55, 53, 51, 68, 69};
		int i;
		for(i=0; i<8; i++){
			inserer(&racine, tab[i]);
		}
	// 4. Insérer les valeurs : 32,20,70,66.
		inserer(&racine, 32);
		inserer(&racine, 20);
		inserer(&racine, 70);
		inserer(&racine, 66);
		printf("Infixe : ");
		parcourirInFixe(racine);
		printf("\nPostFixe : ");
		parcourirPostFixe(racine);
		printf("\nPrefixe : ");
		parcourirPrefixe(racine);
		printf("\nNombre de nodes : %d\n", nombrenodes(racine));
		printf("Nombre de feuilles : %d\n", nombreFeuilles(racine));
		// tester cest 70 est dans l'arbre
		printf("Tester si 70 est dans larbre : %d\n", estDansArbre(racine, 70));
		// renvoye le minimum de l'arbre
		printf("le minimum de larbre : %d\n", minimum(racine));
		return 0;
	}

