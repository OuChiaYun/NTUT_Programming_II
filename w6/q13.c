#include <stdio.h>
#include <math.h>

int c_calculate(int M)
{
    int m = M;

    int n = 0;

    while (m != -1)
    {
        if ((m == 0) || (m == 1))
        {
            m = -1;
        }
        else if ((m % 2) == 0)
        {
            m = (m / 2);
            if (n == 0)
            {
                M = M / 2;
            }
            n++;
        }
        else if (((m) % 2) == 1)
        {
            m = ((m + 1) / 2);
            if (n == 0)
            {
                M = (M + 1) / 2;
            }
            n++;
        }
    }
 
    return n;
    // printf("\n");
}

int main()
{

    // int M = 10;
    char M[190] = {'0'};
    int n = 0;
    while (1)
    {
        scanf("%s", M);
        n = 0;

        if ((M[0] == '-') && (M[1] == '1'))
        {
            break;
        }
        for (int i = 10; i--; i >= 0)
        {
            // printf("LL %c LL\n",M[i]);
            n = n + (M[i] - '0') * (pow(2, 9 - i));
            // printf("%d ",n);
        }
        // printf("\nmm %d\n",n);

        int result = 0;
        for (int i = 0; i <= n; i++)
        {
            result += c_calculate(i);
        }
        // printf("%d\n", result);
        for (int i = 0; i < 14; i++)
        {
            printf("%d", (result & 8192) / 8192);
            result = result << 1;
        }
        printf("\n");

    }
    // printf("%d\n",n);
}