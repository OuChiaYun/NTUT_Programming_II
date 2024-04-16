#include <stdio.h>
#include <string.h>
void case1(char *n1, int nu, int *i, char r[200][200])
{
    int s = 0;
    int u = nu;
    char *p = &n1[0];

    while (s < strlen(n1))
    {
        strncpy(r[*i], n1 + s, u);
        s += u;
        (*i)++;
    }
}

char *caseCount(char *n1, char a[100])
{

    int s = 0;
    int k = 0;

    for (int i = 0; i < strlen(n1); i++)
    {
        int flag = 0;
        for (int j = 0; j < k; j++)
        {
            if (n1[i] == a[j])
            {

                flag = 1;
            }
        }

        if (flag == 0)
        {

            a[k] = n1[i];
            k++;
        }
    }
}
int main()
{

    char n[200] = {' '};
    char m[200] = {' '};
    int nu = 0;
    int acout = 0;
    char r[200][200] = {' '};
    char a[100] = {' '};
    scanf(" %[^\n]", n);
    scanf("%d", &nu);
    scanf(" %[^\n]", m);
    caseCount(n, a);

    case1(m, nu, &acout, r);

    int s = 0;
    int q = 0;

    char set[100][100] = {' '};
    for (int i = 0; i < acout - 1; i++)
    {

        for (int g = i + 1; g < acout; g++)
        {

            if (i != g)
            {
                int flag2 = 0;
                for (int f = 0; f < nu; f++)
                {

                    for (int d = 0; d < nu; d++)
                    {

                        if (r[i][f] == r[g][d])
                        {

                            int flag = 0;
                            for (int u = 0; u < s; u++)
                            {
                                if (set[q][u] == r[i][f])
                                {

                                    flag = 1;
                                }
                            }

                            if (flag == 0)
                            {

                                set[q][s] = r[i][f];
                                flag2 = 1;
                                s++;
                            }
                        }
                    }
                }
                if (flag2 == 1)
                {
                    q++;
                }
                s = 0;
            }
        }
    }

    int count = 0;

    for (int j = 0; j < q; j++)
    {
        int flag = 0;
        for (int h = 0; h < strlen(set[j]); h++)
        {

            for (int f = 0; f < strlen(a); f++)
            {

                if (set[j][h] == a[f])
                {
                    flag += 1;
                }
            }
        }
        if ((flag != strlen(a)) || (strlen(set[j]) != strlen(a)))
        {
            memset(set[j], '\0', 100);
            count++;
        }
    }

    int all_set = 0;

    printf("%d", q - count);
}