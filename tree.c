/**************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

***************************/

#include <stdio.h>



typedef struct maillon {
    int value;
    maillon * right;
    maillon * left ;
}MAILLON;

MAILLON * initarbre()
{
    MAILLON *racine;
    racine=NULL;
    return racine;
}


int istreeempty(MAILLON * racine)
{
    if(racine==NULL)
    return 1;
    
    else
    retun 0;
}

MAILLON * createtree(int v, MAILLON * subtreel,MAILLON * subtreer)
{
    
    MAILLON * racine = (MAILLON *) malloc(sizeof(MAILLON));
    racine->value=v;
    racine->left=subtreel;
    racine->right=subtreer;
    return racine;
}

// MAILLON * a1,a2,a3,a4,a5,a6;
// a6=createtree(6,NULL,NULL);
// a8=createtree(8,NULL,NULL);
// a3=createtree(3,NULL,NULL);
// a5=createtree(5,NULL,a6);
// a4=createtree(4,a3,a5);
// a9=createtree(4,a8,NULL);
// a7=createtree(7,a4,a9);

void deletetree (MAILLON * tree)
{
    if(tree!=NULL)
    {
        deletetree(tree->right);
        deletetree(tree->left);
    free(tree);
    tree=NULL;
    }

    
    
}

void infinpr (MAILLON * tree)
{
    if(tree!=NULL)
    {
    infinpr (tree->left);
    printf("%d",tree->value);
    infinpr (tree->right);
    }
}
void postfinpr (MAILLON * tree)
{
    if(tree!=NULL)
    {
    postfinpr (tree->left);
    postfinpr (tree->right);
    printf("%d",tree->value);
    }
}
void prefinpr (MAILLON * tree)
{
    if(tree!=NULL)
    {
    printf("%d",tree->value);
    prefinpr (tree->left);
    prefinpr (tree->right);
    }
}

MAILLON * findnode (MAILLON * tree,int v)
{
    
    MAILLON * m ; ptr=NULL;
    
    if (tree!=NULL)
    {
        if(tree->value==v)
        ptr = tree;
        else
        {
            ptr= findnode(tree->right,v);
            
            if(ptr == NULL)
            ptr= findnode(tree->left,v);
        }
    }
    
    return ptr;
}

MAILLON * findnodebinary (MAILLON * tree,int v)
{
    
 
    
    if (istreeempty(tree)) return NULL;
    
        if(tree->value==v)
        return tree;
        
        if(tree->value < v)
        {
          return findnodebinary(tree->right,v);
        }  
           
           return findnodebinary(tree->left,v);
       
}

int exist (MAILLON * tree,int v)
{
    
    if(istreeempty(tree))
    return 0;
    
    if(tree->value==v)
    return 1;
    
        return  exist (tree->left, v) ||(tree->right, v);
}



MAILLON * minimum (MAILLON * tree)
{
    
    MAILLON * curr = tree;
    
    while( curr && curr->left!=NULL)
    curr=curr->left;
    
    return curr;
}

void insertelm (MAILLON * tree,int v)
{
    
    MAILLON * newn = createtree( v, NULL,NULL);
    
    
    if(istreeempty(tree))
    {
        tree=newn;
    }
    
    else
    {
        if(tree->value < v)
        {
            insertelm (tree->right, v);
        }
        else
        {
             insertelm (tree->left, v);
        }
    }
    return tree;
}


int numsofnodes (MAILLON * tree)
{
    
    if(istreeempty(tree))
    return 0;
    
        else if(tree->left==NULL&& tree->right==NULL)
    return 1;
    
    else 
    {
        return numsofnodes(tree->right)+numsofnodes(tree->right);
    }
    
    
    
}

MAILLON * CREATECLONE_(MAILLON * racine )
{
    if(racine==NULL)
    return NULL;

    MAILLON * node = createtree(racine->value,NULL,NULL);

    node->left = CREATECLONE_(racine->left);
    node->right = CREATECLONE_(racine->right);

    return node;

}





int main()
{
    printf("Hello World");

    return 0;
}