#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <math.h>

void print_n(int n[], int k)
{
    int maxi = 0;

    for (int i = k - 1; i >= 0; i--)
    {
        if (n[i] != 0)
        {
            maxi = i;
            break;
        }
    }

    for (int i = maxi; i >= 0; i--)
    {
        printf("%d", n[i]);
    }
}

int isL(int a[], int b[])
{
    for (int i = 50 - 1; i >= 0; i--)
    {
        if (a[i] > b[i])
        {
            // printf("%d %d ",a[i],b[i]);
            return 1;
        }
        else if (a[i] < b[i])
        {
            return 0;
        }
        else
        {
            continue;
        }
    }

    return 2;
}

void reset(int n[], int k)
{
    for (int u = 0; u < k; u++)
    {
        n[u] = 0;
    }
}

void deal(char str[], int n[])
{

    for (int i = 0; i < 50; i++)
    {
        n[i] = 0;
    }
    int j = 0;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        n[j] = (str[i] - '0');
        j++;
    }
}

void add(int a[], int b[], int sum[])
{
    int carry = 0;

    for (int i = 0; i < 50; i++)
    {
        sum[i] = a[i] + b[i] + carry;
        carry = sum[i] / 10;
        sum[i] = sum[i] % 10;
    }
}

void sub(int a[], int b[], int sum[])
{
    int borrow = 0;

    for (int i = 0; i < 50; i++)
    {
        sum[i] = a[i] - b[i] - borrow;
        if (sum[i] < 0)
        {
            borrow = 1;
            sum[i] += 10;
        }
        else
        {
            borrow = 0;
        }
    }
}

int getN(int a[])
{
    int count = 0;
    for (int i = 49; i >= 0; i--)
    {
        if (a[i] == 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    return 50 - count;
}

void mul(int a[], int b[], int sum[])
{
    for (int i = 0; i < 50 - 1; i++)
    {
        if (b[i] == 0)
        {
            continue;
        }
        for (int j = 0; j < 50 - 1; j++)
        {
            sum[i + j] += a[j] * b[i];
            // printf("%d ",sum[i]);
        }
    }

    int carry = 0;

    for (int i = 0; i < 100; i++)
    {
        sum[i] = sum[i] + carry;
        carry = sum[i] / 10;
        sum[i] = sum[i] % 10;
    }
}

void dive(int a[], int b[])
{
    int na = getN(a);
    int nb = getN(b);
    int nn = na - nb;
    int q = 0; //quote

    if (isL(a, b) == 2)
    {
        printf("0\n");
    }
    else if (isL(a, b) == 0)
    {
        print_n(a, 50);
        printf("\n");
    }

    while (isL(a, b) == 1 && nn >= 0)
    {
        int i = 1;
        for (i = 1; i <= 10; i++) //try 1-10
        {

            int may[50] = {0}; //need to mul, a temp array
            int sum[50] = {0}; //sum of mul i
            int sum_shift[100] = {0}; //sum of mul 1*10^nn

            may[0] = i;
            mul(b, may, sum);

            reset(may, 50);

            may[nn] = 1;
            mul(sum, may, sum_shift);

            if (isL(sum_shift, a) == 1)
            {
                reset(sum, 50);
                reset(may, 50);
                reset(sum_shift, 50);

                may[0] = i - 1;
                mul(b, may, sum);

                reset(may, 50);
                
                may[nn] = 1;
                mul(sum, may, sum_shift);

                sub(a, sum_shift, a);

                break;
            }
        }
        q = q * 10 + (i - 1);

        nn -= 1;
    }

    if (nn >= 0)
    {
        q = q * (int)pow(10, nn + 1);
    }
    printf("q:%d\n", q);
}

int main()
{

    char str1[50] = {' '};
    char str2[50] = {' '};
    int n1[50] = {0};
    int n2[50] = {0};
    int sum[100] = {0};
    scanf("%s", str1);
    scanf("%s", str2);
    reset(n1, 50);
    reset(n2, 50);
    reset(sum, 100);
    deal(str1, n1);
    deal(str2, n2);

    dive(n1, n2);

    printf("\n");
}