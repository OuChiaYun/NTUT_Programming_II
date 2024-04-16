#include <stdio.h>
#include <string.h>
void swap(char **str1, char **str2)
{
    // printf("%s %s\n",str1,str2);
    char *t = *str1;
    *str1 = *str2;
    *str2 = t;
    // printf("%s %s\n",str1,str2);
}

void swap_int(int *n1, int *n2)
{
    // printf("%s %s\n",str1,str2);
    int t = *n1;
    *n1 = *n2;
    *n2 = t;
    // printf("%s %s\n",str1,str2);
}

int myStrcmp(char *s1, char *s2)
{
    for (; (*s1 != '\0') && (*s2 != '\0'); s1++, s2++)
    {
        if (*s1 > *s2)
            return 1;
        else if (*s1 < *s2)
            return -1;
    }
    if (*s1 != '\0')
        return 1;
    else if (*s2 != '\0')
        return -1;
    return 0;
}
void case1(char *A, char *n1, char *n2)
{
    // printf("%s", A);
    char *delim = " ";
    char *pch = NULL;
    pch = strtok(A, delim);
    while (pch != NULL)
    {
        if (strcmp(pch, n1) == 0)
        {
            printf("%s", n2);
        }
        else
        {
            printf("%s", pch);
        }

        pch = strtok(NULL, delim);
        if (pch != NULL)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void case2(char *A, char *n1, char *n2)
{
    // printf("%s", A);
    char *delim = " ";
    char *pch = NULL;
    pch = strtok(A, delim);
    while (pch != NULL)
    {
        if (strcmp(pch, n1) == 0)
        {
            printf("%s ", n2);
            printf("%s", pch);
        }
        else
        {
            printf("%s", pch);
        }

        pch = strtok(NULL, delim);
        if (pch != NULL)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void case3(char *A, char *n1, char *n2)
{
    // printf("%s", A);
    char *delim = " ";
    char *pch = NULL;
    pch = strtok(A, delim);
    while (pch != NULL)
    {
        if (strcmp(pch, n1) == 0)
        {
            printf("%s ", pch);
            printf("%s", n2);
        }
        else
        {
            printf("%s", pch);
        }

        pch = strtok(NULL, delim);
        if (pch != NULL)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void case4(char *A, char *n1, char *n2)
{
    // printf("%s", A);
    char *delim = " ";
    char *pch = NULL;
    pch = strtok(A, delim);
    while (pch != NULL)
    {
        if (strcmp(pch, n1) != 0)
        {
            printf("%s", pch);
            // printf("%s ", n2);
            pch = strtok(NULL, delim);
            if (pch != NULL)
            {
                printf(" ");
            }
        }
        else
        {

            pch = strtok(NULL, delim);
        }
    }
    printf("\n");
}

void case5(char *A, char *n1, char *n2)
{
    // printf("%s", A);
    char *str[100] = {" "};
    char *str2[100] = {" "};
    char *delim = " ";
    char *pch;
    pch = strtok(A, delim);
    int n = 0;
    int str2n[100] = {0};
    while (pch != NULL)
    {

        // printf("%s ", pch);
        str[n] = pch;
        n++;
        pch = strtok(NULL, delim);
    }
    // printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (myStrcmp(str[i], str[j]) == 1)
            {
                swap(&str[i], &str[j]);
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%s ", str[i]);
    // }
    // printf("\n");
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < k; j++)
        {
            if (myStrcmp(str[i], str2[j]) == 0)
            {
                flag++;
                str2n[j] += 1;
                break;
            }
        }
        if (flag == 0)
        {
            str2[k] = str[i];
            str2n[k] = 1;
            k++;
        }
        // printf("%s ", str[i]);
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {

            if (str2n[i] > str2n[j])
            {
                swap_int(&str2n[i], &str2n[j]);
                swap(&str2[i], &str2[j]);
            }
            else if ((str2n[i] == str2n[j]) && (myStrcmp(str2[i], str2[j]) == -1))
            {
                swap_int(&str2n[i], &str2n[j]);
                swap(&str2[i], &str2[j]);
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        printf("%s,", str2[i]);
        printf("%d\n", str2n[i]);
    }
    // printf("\n");
}

int main()
{

    char n[200] = {' '};
    char n1[200] = {' '};
    char n2[200] = {' '};
    char nn[200] = {' '};
    char nnn[200] = {' '};
    char nnnn[200] = {' '};
    char nnnnn[200] = {' '};
    scanf(" %[^\n]", n);
    scanf(" %[^\n]", n1);
    scanf(" %[^\n]", n2);
    // printf("%s",n);
    strcpy(nn, n);
    strcpy(nnn, n);
    strcpy(nnnn, n);
    strcpy(nnnnn, n);
    case1(n, n1, n2);
    case2(nn, n1, n2);
    case3(nnn, n1, n2);
    case4(nnnn, n1, n2);
    case5(nnnnn, n1, n2);
}