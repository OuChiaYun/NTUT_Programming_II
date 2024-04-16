#include <stdio.h>
#include <stdlib.h>

typedef struct node_s
{
    int data;
    struct node_s *next;
} node_t;

void print_link(node_t *root)
{

    node_t *cur = root;
    int k = 0;
    while (cur != NULL)
    {
        k++;
        printf("%d ", cur->data);
        cur = cur->next;
    }

    if (k == 0)
    {
        printf("None");
    }
}

void reverse_link(node_t *root)
{

    node_t *cur = root;

    if (cur->next != NULL)
    {
        reverse_link(root->next);
        printf("%d->", cur->data);
    }
    else
    {
        printf("%d->", cur->data);
    }
}

void insert_last(node_t **root, int data)
{

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->next = NULL;

    new_node->data = data;

    if (*root == NULL)
    {
        *root = new_node;
    }
    else
    {
        node_t *cur = *root;

        while (cur->next != NULL)
        {
            cur = cur->next;
        }

        cur->next = new_node;
    }
}

void pop_head(node_t **root)
{

    if (*root == NULL)
    {
        return;
    }

    node_t *tmp = *root;

    *root = tmp->next;

    free(tmp);
}

void pop_tail(node_t **root)
{

    if (*root == NULL)
    {
        return;
    }

    node_t *cur = *root;
    node_t *pre_cur = *root;

    if (cur->next == NULL)
    {

        *root = NULL;
        free(cur);
        return;
    }

    while (cur->next != NULL)
    {
        pre_cur = cur;
        cur = cur->next;
    }

    pre_cur->next = NULL;

    free(cur);
}

void delete_node(node_t **root, int data)
{

    if (*root == NULL)
    {
        return;
    }

    node_t *cur = *root;
    node_t *pre_cur = *root;

    if (cur->next == NULL)
    {

        *root = NULL;
        free(cur);
        return;
    }

    while (cur->data != data && cur != NULL)
    {
        pre_cur = cur;
        cur = cur->next;
        if (cur == NULL)
        {
            break;
        }
    }

    if (cur == NULL)
    {
        return;
    }

    if (cur == *root)
    {
        *root = cur->next;
        free(cur);
        return;
    }
    pre_cur->next = cur->next;
    free(cur);
}

void search_node(node_t **root, int data_x, int data_y)
{

    if (*root == NULL)
    {
        return;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    new_node->data = data_y;
    new_node->next = NULL;

    node_t *cur = *root;
    node_t *pre = *root;

    while (cur->data != data_x && cur != NULL)
    {
        pre = cur;
        cur = cur->next;

        if (cur == NULL)
        {
            return;
        }
    }

    if (cur == NULL)
    {
        return;
    }
    else
    {

        new_node->next = cur->next;
        cur->next = new_node;
    }
}

void swab_node(node_t **root, int data_x, int data_y)
{

    if (*root == NULL)
    {
        return;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    new_node->data = data_y;
    new_node->next = NULL;

    node_t *cur = *root;

    while (cur != NULL)
    {
        if (cur->data == data_x)
        {
            cur->data = data_y;
        }

        else if (cur->data == data_y)
        {
            cur->data = data_x;
        }
        cur = cur->next;
    }

    if (cur == NULL)
    {
        return;
    }
}

int main()
{

    node_t *root = NULL;

    // int data[] = {1, 4, 2, 5, 7};

    int data_n = 0;
    int data = 0;

    int c = 0;
    int op[3] = {0};
    int r_count = 0;

    scanf("%d", &data_n);
    for (int i = 0; i < data_n; i++)
    {
        scanf("%d", &data);

        insert_last(&root, data);
    }

    scanf("%d", &c);

    for (int i = 0; i < c; i++)
    {

        scanf("%d", &op[0]);

        if (op[0] == 1)
        {
            scanf("%d", &op[1]);
            insert_last(&root, op[1]);
        }

        if (op[0] == 2)
        {
            pop_head(&root);
        }
        if (op[0] == 3)
        {
            pop_tail(&root);
        }

        if (op[0] == 4)
        {

            scanf("%d", &op[1]);
            delete_node(&root, op[1]);
        }

        if (op[0] == 5)
        {

            scanf("%d%d", &op[1], &op[2]);
            search_node(&root, op[1], op[2]);
        }

        if (op[0] == 6)
        {

            r_count++;
        }

        if (op[0] == 7)
        {
            scanf("%d%d", &op[1], &op[2]);
            swab_node(&root, op[1], op[2]);
        }
    }

    if (r_count % 2 == 1)
    {
        reverse_link(root);
        printf("\n");
    }
    else
    {
        print_link(root);
        printf("\n");
    }
    // print_link(root);
    // pop_head(&root);
    // printf("\n");
    // print_link(root);
    // pop_tail(&root);
    // printf("\n");
    // print_link(root);
    // delete_node(&root, 2);
    // printf("\n");
    // search_node(&root, 5, 6);
    // search_node(&root, 4, 2);
    // print_link(root);

    // swab_node(&root, 2, 5);
    // printf("\n");
    // print_link(root);
    // printf("\n");
    // reverse_link(root);
}