#include <stdio.h>
#include <math.h>

void c_calculate(int M)
{
    int m = M;
    // printf("%d",m);

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

    for (int i = 0; i < 4; i++)
    {
        printf("%d", (n & 8) / 8);
        n = n << 1;
    }
    printf("\n");

    m = M;
    while (m != -1)
    {
        if ((m == 0) || (m == 1))
        {
            printf("%d ",m);
            m = -1;
        }
        else if ((m % 2) == 0)
        {
            printf("%d ", m);
            m = (m / 2);
        }
        else if (((m) % 2) == 1)
        {
            printf("%d ", m);
            m = ((m + 1) / 2);
        }
    }
    printf("\n");
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
        for (int i = 12; i--; i >= 0)
        {
            // printf("LL %c LL\n",M[i]);
            n = n + (M[i] - '0') * (pow(2, 11-i));
            // printf("%d ",n);
        }
        // printf("\nmm %d\n",n);
        if (n == 0)
        {
            printf("0000\n");
            printf("No Feedback\n");
        }
        else
        {
            c_calculate(n);
            
        }
        // printf("%s", M);
        
        // printf("jj %d kk \n",(M[0] != '-') && (M[1] != '1'));
    }
    // printf("%d\n",n);
}