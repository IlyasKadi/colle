#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char content;
    struct Node *suivant;
} Node;

typedef struct
{
    Node *head;
    int size;
} Pile;

Pile *init_pile()
{
    Pile *pile = malloc(sizeof(Pile));
    pile->head = NULL;
    pile->size = 0;
    return pile;
}

int isEmpty(Pile *F)
{
    return F->head == NULL;
}

int getHead(Pile *F)
{
    if (!isEmpty(F))
    {
        return (int)F->head->content;
    }
    return 0;
}

void empiler(Pile *F, char c)
{
    Node *n = malloc(sizeof(Node));
    n->content = c;
    n->suivant = F->head;
    F->head = n;
    F->size++;
}

void depiler(Pile *F)
{
    if (!isEmpty(F))
    {
        Node *n = F->head;
        F->head = F->head->suivant;
        F->size--;
        free(n);
    }
}

int evaluate(char *s)
{
    Pile *F = init_pile();
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(')
        {
            empiler(F, s[i]);
        }
        else if (s[i] == ')')
        {
            depiler(F);
        }
        else if (s[i] == '+')
        {
            int a = getHead(F);
            depiler(F);
            int b = getHead(F);
            depiler(F);
            empiler(F, a + b);
        }
        else if (s[i] == '*')
        {
            int a = getHead(F);
            depiler(F);
            int b = getHead(F);
            depiler(F);
            empiler(F, a * b);
        }
        else if (s[i] == '-')
        {
            int a = getHead(F);
            depiler(F);
            int b = getHead(F);
            depiler(F);
            empiler(F, b - a);
        }
        else if (s[i] == '/')
        {
            int a = getHead(F);
            depiler(F);
            int b = getHead(F);
            depiler(F);
            empiler(F, b / a);
        }
        i++;
    }
    return getHead(F);
}



int main()
{
    char *s = "(1+2)*3";
    printf("%d\n", evaluate(s));
    return 0;
}