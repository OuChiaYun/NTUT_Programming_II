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

NODE *creatnode(char name[], char age[], char birth[])
{

    NODE *node = (NODE *)malloc(sizeof(NODE));
    strcpy(node->name, name);
    strcpy(node->age, age);
    strcpy(node->birth, birth);
    node->next = NULL;

    return node;
}

void show_link(NODE *root)
{
    NODE *current = root;
    while (current != NULL)
    {
        printf("%s %s %s\n", current->name, current->age, current->birth);
        current = current->next;
    }
}

int show_size(NODE *root)
{
    int n = 0;
    NODE *current = root;
    while (current != NULL)
    {
        current = current->next;
        n++;
    }
    return n;
}

void show_rev_link(NODE *root)
{
    NODE *current = root;
    if (current != NULL)
    {
        show_rev_link(current->next);
        printf("%s %s %s\n", current->name, current->age, current->birth);
    }
    else
    {
        return;
    }
}

void push(NODE **root, NODE *node)
{
    // printf("%s %s %s", node.name, node.age, node.birth);

    if (*root == NULL)
    {
        *root = node;
    }
    else
    {

        NODE *current = *root;

        while (current->next != NULL)
        {

            current = current->next;
        }

        current->next = node;
    }
}

NODE *pop(NODE **root)
{

    if (*root != NULL)
    {

        NODE *current = *root;

        if (current->next == NULL)
        {
            *root = NULL;
            return current;
        }

        NODE *pre = *root;
        while (current->next != NULL)
        {
            pre = current;
            current = current->next;
        }

        pre->next = NULL;
        // free(current);
        return current;
    }
    else
    {

        return creatnode("The Stack is empty", "The Stack is empty", "The Stack is empty");
    }
}

int main()
{

    NODE *root = NULL;

    int cmd = 0;
    while (cmd != 5)
    {
        int cmd_2 = 0;

        char str[100] = {' '};
        char str_map[10][100] = {{' '}};
        int k = 0;
        scanf("%d", &cmd);

        if (cmd == 5)
        {
            break;
        }
        else if (cmd == 1)
        {
            scanf(" %[^\n]", str);

            const char del[2] = {' '};
            char *p = strtok(str, del);

            while (p != NULL)
            {
                // printf("%s\n", p);

                strcpy(str_map[k], p);
                k++;

                p = strtok(NULL, del);
            }

            char day[100] = {""};

            strcat(day, str_map[2]);
            strcat(day, "_");
            strcat(day, str_map[3]);
            strcat(day, "_");
            strcat(day, str_map[4]);
            strcat(day, "\0");
            // printf("cjwior %s\n",day);

            NODE *n = creatnode(str_map[0], str_map[1], day);
            push(&root, n);
            // printf("%s %s %s\n",root->name,root->age,root->birth);
        }
        else if (cmd == 2)
        {
            scanf("%d", &cmd_2);

            if (cmd_2 == 1)
            {

                NODE *c = pop(&root);
                printf("%s\n", c->name);
                free(c);
            }
            if (cmd_2 == 2)
            {

                NODE *c = pop(&root);
                printf("%s\n", c->age);
                free(c);
            }
            if (cmd_2 == 3)
            {

                NODE *c = pop(&root);
                printf("%s\n", c->birth);
                free(c);
            }
        }
        else if (cmd == 3)
        {
            NODE *c = pop(&root);
            if (strcmp("The Stack is empty", c->birth) == 0)
            {
                printf("%s %s %s\n", c->name, c->age, c->birth);

                continue;
            }
            else
            {
                printf("%s %s %s\n", c->name, c->age, c->birth);
            }
            while (1)
            {

                NODE *c = pop(&root);

                if (strcmp("The Stack is empty", c->birth) == 0)
                {
                    break;
                }
                else
                {
                    printf("%s %s %s\n", c->name, c->age, c->birth);
                }
            }
        }
        else if (cmd == 4)
        {
            show_rev_link(root);
            if (root == NULL)
            {
                printf("The Stack is empty\n");
            }
        }
    }
    
    printf("%d\n", show_size(root));
}