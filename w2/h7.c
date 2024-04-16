#include <stdio.h>

int main()
{

    int N = 0;
    int M = 0;

    scanf("%d%d", &N, &M);
    int k = M - 1;
    int k2 = M - 1;
    int s = 1;
    int abc = -1;
    if(N <1|| N > 2||M<2||M>9)
    {
        printf("error");
    }

    else if (N == 1)
    {
        for (int i = 0; i < M; i++)
        {
            s = 1;
            for (int j = 0; j < 2 * (M - 1) + 1; j++)
            {
                if (j < k || j > k2)
                {
                    printf("#");
                }

                else
                {
                    if (s % 2 == 1)
                    {
                        printf("*");
                    }
                    else
                    {
                        if (abc % 3 == 0)
                        {
                            printf("A");
                        }
                        else if (abc % 3 == 1)
                        {
                            printf("B");
                        }
                        else
                        {
                            printf("C");
                        }
                    }
                    s++;
                }
            }
            printf("\n");
            abc++;
            k = k - 1;
            k2 = k2 + 1;
        }
    }

    /////
    else if (N == 2)
    {
        int y = 1;
        int y2 = (M + 1) * 2 - 1;
        int num = 1;
        for (int i = 0; i < M; i++)
        {
            num = 1;
            for (int j = 0; j < (M + 1) * 2; j++)
            {
                if (j >= y && j < y2)
                {
                    printf("*");
                }
                else
                {
                    if (j < y)
                    {
                        printf("%d", num);
                        num++;
                    }
                    else
                    {
                        num--;
                        printf("%d", num);
                    }
                }
            }
            printf("\n");
            y = y + 1;
            y2 = y2 - 1;
        }
    }
}