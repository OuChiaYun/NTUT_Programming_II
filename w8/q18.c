#include <stdio.h>
#include <string.h>
#include <math.h>

void DF_expression(int n, int ni, int nj, int *k, char s[], char res[][100], int id)
{
    // locate point for s[]
    if (n > 1)
    {
        if (s[*k] == '2')
        {
            *k = *k + 1;
            // sum = sum - 1;
            // DF_expression(n / 2,n*(id/2)+(n/2)*(0/2),n*(id%2)+(n/2)*(0%2), k, s, res, sum - 1,0,id);
            DF_expression(n / 2, ni + (n / 2) * (0 / 2), nj + (n / 2) * (0 % 2), k, s, res, id);
            DF_expression(n / 2, ni + (n / 2) * (1 / 2), nj + (n / 2) * (1 % 2), k, s, res, id);
            DF_expression(n / 2, ni + (n / 2) * (2 / 2), nj + (n / 2) * (2 % 2), k, s, res, id);
            DF_expression(n / 2, ni + (n / 2) * (3 / 2), nj + (n / 2) * (3 % 2), k, s, res, id);
            // printf("kk %d %d %d %d %d %d %d\n", n, ni, nj, *k, sum,id,_id);

        } // 寬    i       j  sk    res
        else
        {
            // printf("%d %d %d %d|%d\n", n, ni, nj, *k, id);
            // printf("%d %d %d %d %d %d|%d\n", n,(int)pow(2,n)*(_id/2)+n*(id/2),(int)pow(2,n)*(_id%2)+n*(id%2), *k, sum,id,_id);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    res[ni + i][nj + j] = s[*k];
                }
            }

            *k = *k + 1;
        }
    }
    else
    {
        // printf("%d %d %d %d %d\n", n, ni, nj, *k, id);
        res[ni][nj] = s[*k];
        *k = *k + 1;
    }
}

int main()
{
    int n = 0;
    char s[100];
    char res[100][100] = {{'0'}};
    int count[100][5] = {{0}};
    memset(s, ' ', 99);

    scanf("%s", s);
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            res[i][j] = '0';
        }
    }
    int k = 0;
    int sum = 3;
    // printf("%d \n", strlen(s));
    DF_expression(n, 0, 0, &k, s, res, 0);

    int u = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // printf("%c ",res[i][j]);
            if(res[i][j] == '1'){
                count[u][0] = i;
                count[u][1] = j;
                count[u][2] = res[i][j] -'0';
                u++;
            }
        }
        // printf("count \n");
    }

    for(int i = 0;i<u;i++){
        
        printf("%d,%d\n",count[i][0],count[i][1]);

    }

    if(u == 0){
        printf("all white\n");
    }
}