#include <stdio.h>
#include <stdlib.h>

typedef struct node_s
{
    int coef;
    int exp;
    struct node_s *next;
} node_t;
typedef node_t *nodep_t;

typedef struct pol_s
{
    nodep_t root;
} pol_t;

void print_link(node_t *root)
{

    node_t *cur = root;
    int k = 0;
    while (cur != NULL)
    {
        k++;
        printf("%d %d ", cur->coef, cur->exp);
        cur = cur->next;
    }

    if (k == 0)
    {
        printf("None");
    }
}

void insert_last(node_t **root, int coef)
{

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->coef = coef;
    new_node->exp = 0;
    new_node->next = NULL;

    if (*root == NULL)
    {
        *root = new_node;
    }
    else
    {
        node_t *cur = *root;
        int count = 0;

        while (cur->next != NULL)
        {
            cur->exp += 1;
            cur = cur->next;
        }
        cur->exp += 1;
        cur->next = new_node;
    }
}

void insert_head(node_t **root, int coef)
{

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->coef = coef;
    new_node->exp = 0;
    new_node->next = NULL;

    if (*root == NULL)
    {
        *root = new_node;
    }
    else
    {
        node_t *cur = *root;

        *root = new_node;
        new_node->next = cur;
        int count = 0;
        while (cur != NULL)
        {
            cur = cur->next;
            count++;
        }

        new_node->exp = count;
    }
}

void add_list(pol_t *t1, int p1_n, pol_t *t2, int p2_n, pol_t *t3)
{

    node_t *p1 = t1->root;
    node_t *p2 = t2->root;
    node_t *p3 = t3->root;

    int add_n = p1_n > p2_n ? p1_n : p2_n;

    for (int i = 0; i < add_n; i++)
    {

        insert_last(&p3, 0);
    }

    node_t *cur1 = p1;
    node_t *cur2 = p2;
    node_t *cur3 = p3;

    while (cur1 != NULL)
    {

        cur2 = p2;
        while (cur2 != NULL)
        {
            if (cur1->exp == cur2->exp)
            {
                cur3 = p3;
                while (cur3 != NULL)
                {
                    if (cur3->exp == cur1->exp)
                    {
                        cur3->coef += cur1->coef + cur2->coef;

                        break;
                    }

                    cur3 = cur3->next;
                }
            }

            cur2 = cur2->next;
        }
        cur1 = cur1->next;
    }

    printf("\nadd : ");
    print_link(p3);
}

void sub_list(pol_t *t1, int p1_n, pol_t *t2, int p2_n, pol_t *t3)
{

    node_t *p1 = t1->root;
    node_t *p2 = t2->root;
    node_t *p3 = t3->root;

    int add_n = p1_n > p2_n ? p1_n : p2_n;

    for (int i = 0; i < add_n; i++)
    {

        insert_last(&p3, 0);
    }

    node_t *cur1 = p1;
    node_t *cur2 = p2;
    node_t *cur3 = p3;

    while (cur1 != NULL)
    {

        cur2 = p2;
        while (cur2 != NULL)
        {
            if (cur1->exp == cur2->exp)
            {
                cur3 = p3;
                while (cur3 != NULL)
                {
                    if (cur3->exp == cur1->exp)
                    {
                        cur3->coef += cur1->coef - cur2->coef;

                        break;
                    }

                    cur3 = cur3->next;
                }
            }

            cur2 = cur2->next;
        }
        cur1 = cur1->next;
    }

    printf("\nsub : ");
    print_link(p3);
}

void mul_list(pol_t *t1, int p1_n, pol_t *t2, int p2_n, pol_t *t3)
{

    node_t *p1 = t1->root;
    node_t *p2 = t2->root;
    node_t *p3 = t3->root; //先見空的樹

    int add_n = p1_n > p2_n ? p1_n : p2_n;

    for (int i = 0; i < p1_n + p2_n-1; i++)
    {

        insert_last(&p3, 0);
    }

    node_t *cur1 = p1;
    node_t *cur2 = p2;
    node_t *cur3 = p3;

    while (cur1 != NULL)
    {

        cur2 = p2;
        while (cur2 != NULL)
        {

            cur3 = p3;
            while (cur3 != NULL)
            {
                if (cur3->exp == (cur1->exp+ cur2->exp))
                {
                    cur3->coef += cur1->coef * cur2->coef; //在把系數相加

                    break;
                }

                cur3 = cur3->next;
            }

            cur2 = cur2->next;
        }
        cur1 = cur1->next;
    }

    printf("\nmul : ");
    print_link(p3);
}

int main()
{
    pol_t pol1, pol2;

    pol_t add;
    pol_t sub;
    pol_t mul;
    add.root = NULL;
    sub.root = NULL;
    mul.root = NULL;
    pol1.root = NULL;
    pol2.root = NULL;

    int n1;
    int n2;

    int data = 0;

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {

        scanf("%d", &data);
        insert_last(&pol1.root, data);
    }

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {

        scanf("%d", &data);
        insert_last(&pol2.root, data);
    }

    if (n1 > n2)
    {
        for (int i = n2; i < n1; i++)
        {
            insert_head(&pol2.root, 0);
        }
    }
    else
    {

        for (int i = n1; i < n2; i++)
        {
            insert_head(&pol1.root, 0);
        }
    }

    print_link(pol1.root);
    printf("\n");
    print_link(pol2.root);

    add_list(&pol1, n1, &pol2, n2, &add);
    sub_list(&pol1, n1, &pol2, n2, &sub);
    mul_list(&pol1, n1, &pol2, n2, &mul);
}
