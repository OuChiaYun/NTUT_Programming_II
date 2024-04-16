#include <stdio.h>

int main()
{
    int op = 0;
    int n = 0;

    scanf("%d", &op);
    scanf("%d", &n);

    if (op == 1)
    {
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                printf("%d", j);
            }
            printf("\n");
        }

        for (int i = n; i >= 1; i--)
        {
            for (int j = i; j >= 1; j--)
            {
                printf("%d", j);
            }
            printf("\n");
        }
    }

    if (op == 2)
    {

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n - i; j++)
            {
                printf("_");
            }
            for (int j = i; j >= 1; j--)
            {
                printf("%d", j);
            }
            for (int j = 2; j <= i; j++)
            {
                printf("%d", j);
            }
            for (int j = 1; j < n - i; j++)
            {
                printf("_");
            }
            printf("\n");
        }
        // printf("\n");

        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = 1; j < n - i; j++)
            {
                printf("_");
            }
            for (int j = i; j >= 1; j--)
            {
                printf("%d", j);
            }
            for (int j = 2; j <= i; j++)
            {
                printf("%d", j);
            }
            for (int j = 1; j < n - i; j++)
            {
                printf("_");
            }
            printf("\n");
        }
    }

    if (op == 3)
    {

        int k = 1;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            k = 1;
            flag = 0;
            for (int j = 0; j < (2 * i + 1); j++)
            {
                // printf("0");
                if (k == i + 1)
                {
                    flag = 1;
                }

                if (flag == 0)
                {
                    printf("%d", k++);
                }
                else
                {
                    printf("%d", k--);
                }
            }
            printf("\n");
        }
    }
}