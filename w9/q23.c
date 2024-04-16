#include <stdio.h>
#include <string.h>

// int all_in(char str1[100][100], int s1, )

int cmp_rs(char str1[100][100], int s1, char str2[100][100], int s2)
{
    int x = 0;
    int flag = 0;
    for (int i = 0; i < s1; i++)
    {

        for (int j = 0; j < s2; j++)
        {
            // printf("[%s%s]",str1[i],str2[j]);
            if (strcmp(str1[i], str2[j]) == 0)
            {

                flag++;
            }
        }
    }
    // printf("ffff: %d \n",flag);

    if (flag == s1 && flag == s2)
    {
        return 1;
    }
    else
    {

        return 0;
    }
}

int cmp(char str1[100][100], int s1, char str2[100][100], int s2, char xset[100][100],int *x)
{
    *x = 0;
    for (int i = 0; i < s1; i++)
    {
        int flag = 0;

        for (int j = 0; j < s2; j++)
        {
            if (strcmp(str1[i], str2[j]) == 0)
            {

                return 0;
            }
        }
    }

    for (int i = 0; i < s1; i++)
    {
        // xset[x] = str1[i];
        // printf("%s ",str1[i]);
        strcpy(xset[*x], str1[i]);
        (*x)++;
    }
    for (int j = 0; j < s2; j++)
    {
        // printf("%s ",str2[j]);
        strcpy(xset[*x], str2[j]);
        (*x)++;
    }

    // printf(" x==x ");
    return 1;
}

void case1(char n1[100], char n2[100][100], int *r)
{
    // char str[] = "00:22:33:4B:55:5A";
    char *delim = " ";
    char *pch;
    pch = strtok(n1, delim);
    while (pch != NULL)
    {
        // printf("%s\n", pch);
        int flag = 0;
        for (int i = 0; i < *r; i++)
        {

            if (strcmp(pch, n2[i]) == 0)
            {

                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {

            strcpy(n2[*r], pch);
            // printf("%s+",n2[*r]);
            (*r)++;
        }
        pch = strtok(NULL, delim);
    }
}

int main()
{

    char s[1000] = {' '};
    char ss[100][100] = {' '};
    int rs;

    char n[100][100] = {' '};
    char nn[100][100][100] = {' '};

    char cp[100][100] = {' '};
    int cptr = 0;

    int q = 0;
    int rn[100] = {0};
    char xset[100][100][100] = {' '};
    int xn[100] = {0};

    scanf(" %[^\n]", s);
    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {

        scanf(" %[^\n]", n[i]);
    }
    printf("=================\n");

    case1(s, ss, &rs);

    for (int i = 0; i < rs; i++)
    {

        printf("%s\n", ss[i]);
    }
    printf("==================\n");

    for (int i = 0; i < q; i++)
    {
        case1(n[i], nn[i], &rn[i]);

        for (int j = 0; j < rn[i]; j++)
        {

            printf("%s_", nn[i][j]);
        }
        printf("\n");
    }

    printf("===================\n");

    // printf("%d", cmp(nn[2], rn[2], nn[3], rn[3]));
    // printf("===================\n");
    int x = 0;
    int count = 0;
    for (int i = 0; i < (q - 1); i++)
    {

        for (int j = i + 1; j < q; j++)
        {
            // s1 s2 => n[1] n[2]
            
            if (cmp(nn[i], rn[i], nn[j], rn[j], xset[x],& xn[x] ) == 1)
            {
                printf("%d %d ", i+1, j+1);
                for (int i = 0; i < xn[x]; i++)
                {
                    printf("%s,", xset[x][i]);
                }
                printf("\n");

                if ((cmp_rs(ss, rs,xset[x], xn[x]) ==1))
                {
                    printf("%d %d", i + 1, j + 1);
                    printf("yy\n");
                    count++;
                }
            }
        }
    }

    printf("%d\n",count);
}