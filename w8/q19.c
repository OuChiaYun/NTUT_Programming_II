#include <stdio.h>

int C(int n, int r)
{
    if (n < r || r < 0)
        return -1;
    if (n == r || r == 0)
        return 1;
    return C(n - 1, r) + C(n - 1, r - 1);
}
int queen(int n, int arr[][30])
{
    int ans = 0;
    // horizon
    int count = 0;
    // printf("hor\n");
    for (int i = 0; i < n; i++)
    {

        count = 0;
        for (int j = 0; j < n; j++)
        {
            count += arr[i][j];
        }

        // printf("%d\n", count);
        if (count > 1)
        {
            ans += C(count, 2);
        }
    }

    // printf("vert\n");
    for (int i = 0; i < n; i++)
    {

        count = 0;
        for (int j = 0; j < n; j++)
        {
            count += arr[j][i];
        }

        // printf("%d\n", count);
        if (count > 1)
        {
            ans += C(count, 2);
        }
    }

    // printf("left span 1\n");

    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j <= i; j++)
        {
            count += arr[i - j][j];
            // printf("%d,%d\n", i-j, j);
        }
        // printf("%d\n", count);
        if (count > 1)
        {
            ans += C(count, 2);
        }
    }

    // printf("left span 2\n");

    for (int i = 1; i < n; i++)
    {
        count = 0;
        for (int j = i; j < n; j++)
        {
            count += arr[j][n - (j - i) - 1];
            // printf("%d,%d\n",j,n-(j-i)-1);
        }
        // printf("%d\n", count);

        if (count > 1)
        {
            ans += C(count, 2);
        }
    }

    // printf("right span 1\n");

    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = i; j >= 0; j--)
        {
            count += arr[j][n - 1 - (i - j)];
            // printf("%d,%d\n", j,n-1-(i-j));
        }
        // printf("%d\n", count);
        if (count > 1)
        {
            ans += C(count, 2);
        }
    }

    // printf("right span 2\n");

    for (int i = n - 1; i >= 1; i--)
    {
        count = 0;
        for (int j = 1; j <= i; j++)
        {
            count += arr[n - j][i - j];
            // printf("%d,%d\n",n-j,i-j);
        }
        // printf("%d\n", count);
        if (count > 1)
        {
            ans += C(count, 2);
        }
    }

    return ans;
    // printf("ans %d",ans);
}

int main()
{

    int n = 0;
    int arr[30][30] = {{0}};

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%d", arr[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("%d",C(5,2));
    int ans= queen(n, arr);

    if(ans == 0){
        printf("There is no attack.\n");
    }else{
        printf("%d\n",ans);
    }
}