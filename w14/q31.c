#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
    int n;
    int coef;
    struct NODE *next;
} Node;

void print_link(Node *node)
{
    Node *current = node;
    int a = 0;
    while (current != NULL)
    {
        if (current->n != 0)
        {

            if (a == 0)
            {
                if (current->coef == 0)
                {

                    printf("%d", current->n);
                }
                else if (current->n < 0)
                {
                    if (current->n == -1)
                    {
                        printf("-x^%d", current->coef);
                    }
                    else
                    {
                        printf("-%dx^%d", abs(current->n), current->coef);
                    }
                }
                else
                {
                    if (current->n == 1)
                    {
                        printf("x^%d", current->coef);
                    }
                    else
                    {

                        printf("%dx^%d", current->n, current->coef);
                    }
                }
            }
            else
            {

                if (current->coef == 0)
                {

                    if (current->n > 0)
                    {
                        printf("+");
                    }
                    printf("%d", current->n);
                    
                }
                else
                {
                    if (current->n < 0)
                    {
                        if (current->n == -1)
                        {
                            printf("-x");
                        }
                        else
                        {
                            printf("-%dx", abs(current->n));
                        }
                        if (current->coef > 1)
                        {
                            printf("^%d", current->coef);
                        }
                    }
                    else
                    {
                        if (current->n == 1)
                        {
                            printf("+x");
                        }
                        else
                        {
                            printf("+%dx", current->n);
                        }

                        if (current->coef > 1)
                        {
                            printf("^%d", current->coef);
                        }
                    }
                }
            }
            // printf("%d X^%d ", current->n, current->coef);
            a++;
        }

        if (current->next == NULL && current->coef == 0 && current->n == 0 && a == 0)
        {
            printf("0");
        }
        current = current->next;
    }
    // printf("%d X^%d ", current->n, current->coef);
}

void insert(Node **node, int n, int coefficient)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->n = n;
    new_node->coef = coefficient;
    new_node->next = NULL;

    if (*node == NULL)
    {
        *node = new_node;
        new_node->next = NULL;
        (*node)->next = NULL;
    }
    else
    {
        Node *current = *node;
        while (current->next != NULL)
        {
            current->coef += 1;
            current = current->next;
        }
        current->coef += 1;
        current->next = new_node;
    }
}

void insert_front(Node **node, int n, int coefficient)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->n = n;
    new_node->coef = coefficient;
    new_node->next = NULL;

    if (*node == NULL)
    {
        *node = new_node;
        new_node->next = NULL;
        (*node)->next = NULL;
    }
    else
    {
        Node *current = (*node);
        *node = new_node;
        new_node->next = current;
        new_node->coef = (current->coef) + 1;
        while (current->next != NULL)
        {
            current = current->next;
        }
    }
}

Node *add_link(Node *node1, Node *node2, int n)
{
    Node *current1 = node1;
    Node *current2 = node2;

    Node *result = NULL;

    for (int i = 0; i < n; i++)
    {
        insert(&result, 0, 0);
    }

    Node *res = result;
    while (current1 != NULL)
    {
        res->n = current1->n + current2->n;
        res = res->next;
        current1 = current1->next;
        current2 = current2->next;
    }

    return result;
}

Node *sub_link(Node *node1, Node *node2, int n)
{
    Node *current1 = node1;
    Node *current2 = node2;

    Node *result = NULL;

    for (int i = 0; i < n; i++)
    {
        insert(&result, 0, 0);
    }
    Node *res = result;
    while (current1 != NULL)
    {
        res->n = current1->n - current2->n;
        res = res->next;
        current1 = current1->next;
        current2 = current2->next;
    }

    return result;
}

Node *mux_link(Node *node1, Node *node2, int n1, int n2)
{
    Node *res = NULL;
    for (int i = 0; i < n1 + n2 - 1; i++)
    {
        insert(&res, 0, 0);
    }
    Node *no1 = node1;
    Node *no2 = node2;

    while (no1 != NULL)
    {
        int tmp_n = 0;
        int tmp_co = 0;
        no2 = node2;
        while (no2 != NULL)
        {
            tmp_n = no1->n * no2->n;
            tmp_co = no1->coef + no2->coef;

            Node *res_c = res;
            while (res_c != NULL)
            {
                if (tmp_co == res_c->coef)
                {
                    res_c->n += tmp_n;

                    break;
                }
                res_c = res_c->next;
            }

            no2 = no2->next;
        }
        no1 = no1->next;
    }
    // printf("\njiowfe");
    return res;
}

int main()
{

    Node *root[2] = {NULL, NULL};
    int n[2] = {0, 0};
    for (int i = 0; i < 2; i++)
    {
        char line1[100] = {' '};

        scanf(" %[^\n]", line1);
        const char del[] = " ";
        char *ptr = strtok(line1, del);

        while (ptr != NULL)
        {
            n[i] += 1;
            insert(&root[i], atoi(ptr), 0);
            ptr = strtok(NULL, del);
        }

    }

    Node **smlst;

    smlst = (n[0] < n[1]) ? &root[0] : &root[1];
    int max = (n[0] > n[1]) ? n[0] : n[1];
    int sml = (n[0] < n[1]) ? n[0] : n[1];

    Node *new1 = mux_link(root[0], root[1], n[0], n[1]);


    for (int i = sml; i < max; i++)
    {
        insert_front(&(*smlst), 0, 0);
    }

    Node *new;
    new = add_link(root[0], root[1], max);
    print_link(new);
    printf("\n");
    new = sub_link(root[0], root[1], max);
    print_link(new);
    printf("\n");
    print_link(new1);
    printf("\n");
}