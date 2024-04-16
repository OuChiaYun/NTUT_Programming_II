#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE
{
    char name[100];
    char age[100];
    char birth[100];
    struct _NODE *next;

} NODE;

typedef struct _QUEUE
{
    NODE *frontp;
    NODE *tailp;
} QUEUE;

NODE *create_node(char name[], char age[1], char birth[])
{

    NODE *node = (NODE *)malloc(sizeof(NODE));

    strcpy(node->name, name);
    strcpy(node->age, age);
    strcpy(node->birth, birth);
    node->next = NULL;
    return node;
}

void enqueue(QUEUE *qp, NODE *node)
{

    if (qp->frontp == NULL)
    {

        qp->frontp = node;
        qp->tailp = node;
    }
    else
    {
        qp->tailp->next = node;
        qp->tailp = node;
    }
}

NODE *dequeue(QUEUE *qp)
{

    if (qp->frontp == NULL)
    {
        return NULL;
    }
    else
    {
        NODE *current = qp->frontp;

        if (qp->frontp == qp->tailp)
        {
            qp->frontp = NULL;
            qp->tailp = NULL;
            return current;
        };
        qp->frontp = current->next;
        return current;
    }
}

void show_list(NODE *root)
{
    NODE *current = root;

    while (current != NULL)
    {
        printf("%s %s %s\n", current->name, current->age, current->birth);
        current = current->next;
    }
}

int main()
{

    QUEUE qp = {NULL, NULL};
    NODE *root = NULL;

    char name[100] = {"Marry"};
    char age[100] = {"19"};
    char day[100] = {"1989_7_16"};

    NODE *n = create_node(name, age, day);

    enqueue(&(qp), n);

    char name2[100] = {"Maqweijoy"};
    char age2[100] = {"qe"};
    char day2[100] = {"198jqwpie_16"};

    NODE *n2 = create_node(name2, age2, day2);

    NODE *de = dequeue(&(qp));

    printf("%s %s %s\n", current->name, current->age, current->birth);

    printf("%");

    // show_list
    show_list(qp.frontp);
}
