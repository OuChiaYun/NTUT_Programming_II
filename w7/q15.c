#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swab_k(int a[], int b[], int m)
{
    int temp = 0;
    for (int i = 0; i < m; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

int main()
{
    int m = 0;
    char n[50] = {' '};
    int n_n[25] = {0};
    int k_k[25][25] = {{0}};
    int point = 0;
    int point_k = 0;
    int point_num = 0;

    scanf("%d", &m);
    scanf(" %[^\n]", n);

    for (int i = 0; i < strlen(n); i++)
    {

        if (n[i] != ' ')
        {
            n_n[point] = n[i] - '0';
            point++;
        }
    }

    for (int i = 0; i < (point - m + 1); i++)
    {

        int flag = 0;
        for (int j = i; j < i + m; j++)
        {
            for (int k = j + 1; k < i + m; k++)
            {
                if (n_n[j] == n_n[k])
                {
                    flag = 1;

                    break;
                }
            }
            if (flag == 1)
            {
                break;
            }
        }

        if (flag == 0)
        {
            point_num ++;

            int flag_k = 0;
            for (int k = 0; k < point_k; k++)
            {
                flag_k = 0;
                for (int j = 0; j < m; j++)
                {
                    if (k_k[k][j] != n_n[i + j])
                    {

                        flag_k = 1;
                    }
                }

                if (flag_k == 0)
                {

                    break;
                }
            }

            int h = 0;
            if (flag_k != 0 || point_k == 0)
            {
                for (int j = i; j < i + m; j++)
                {
                    k_k[point_k][h] = n_n[j];
                    // printf("%d ", n_n[j]);
                    h++;
                }
                point_k++;
                // printf("\n");
            }
        }
    }
    // printf("\n\n");

    for (int i = 0; i < point_k; i++) // row1
    {
        for (int h = 0; h < point_k; h++) // row2
        {
            for (int j = 0; j < m; j++) // col
            {
                // printf("udich %d___%djdip",k_k[i][j],k_k[h][j]);
                if (k_k[i][j] < k_k[h][j])
                {
                    // printf("_ %d___%d _|",k_k[i][j],k_k[h][j]);
                    swab_k(k_k[i], k_k[h], m);

                    break;
                }else if (k_k[i][j] > k_k[h][j])
                {
                    break;
                }
                
            }
        }
    }
    printf("%d\n",point_num);
    for (int i = 0; i < point_k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", k_k[i][j]);
        }
        printf("\n");
    }
}