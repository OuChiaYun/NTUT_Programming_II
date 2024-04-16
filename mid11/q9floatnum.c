#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_a(int n[])
{
    int max = 0;
    for (int i = 99; i >= 0; i--)
    {
        if (n[i] != 0)
        {
            max = i;
            break;
        }
    }

    for (int i = max; i >= 0; i--)
    {
        printf("%d", n[i]);
    }
}

void print_b(int n[])
{
    int index = 0;
    for (int i = 0; i < 69; i++)
    {
        if (n[i] != 0)
        {
            index = i;
            break;
        }
    }
    for (int i = 69; i >= index; i--)
    {
        printf("%d", n[i]);
    }
}

int isL(int a[], int b[])
{

    for (int i = 69; i >= 0; i--)
    {
        if (a[i] > b[i])
        {
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
    for (int i = 0; i < k; i++)
    {
        n[i] = 0;
    }
}

int deal(char str[], int np, int na1[], int nb1[])
{

    int index = 0;

    reset(na1, 100);
    reset(nb1, 100);

    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] == '.')
        {
            index = i;
            break;
        }
    }
    int j = 0;
    for (int i = index - 1; i >= 0; i--)
    {
        if (str[0] == '-')
        {
            np = -1;
            continue;
        }
        na1[j] = (str[i] - '0');
        j++;
    }

    j = 69;

    for (int i = index + 1; i < strlen(str); i++)
    {
        nb1[j] = str[i] - '0';
        j--;
    }

    return strlen(str) - index - 1;
};

int add(int a[], int b[], int cin, int sum[])
{
    int carry = cin;
    for (int i = 0; i < 70; i++)
    {
        sum[i] = a[i] + b[i] + carry;
        carry = sum[i] / 10;
        sum[i] %= 10;
    }
    return carry;
}

int sub(int a[], int b[], int bin, int sum[])
{
    int borrow = bin;
    for (int i = 0; i < 70; i++)
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
    return borrow;
}
int mul2(int a[], int b[], int local1, int local2, int shift1, int shift2, int sum[])
{

    for (int i = local2; i < 70; i++)
    {
        if (b[i] == 0)
        {
            continue;
        }

        for (int j = local1; j < 70; j++)
        {
            sum[i - local2 + j - local1 + shift1 + shift2] += a[j] * b[i];
        }
    }
    int carry = 0;
    for (int i = 0; i < 200; i++)
    {
        sum[i] += carry;
        carry = sum[i] / 10;
        sum[i] %= 10;
    }
}

void case1(char str1[], char str2[])
{
    int na1[100] = {0};
    int nb1[100] = {0};
    int na2[100] = {0};
    int nb2[100] = {0};
    int suma[200] = {0};
    int sumb[200] = {0};
    int np1 = 1;
    int np2 = 1;
    int npsize1 = deal(str1, np1, na1, nb1);
    int npsize2 = deal(str2, np2, na2, nb2);

    int carry = add(nb1, nb2, 0, sumb);
    add(na1, na2, carry, suma);

    print_a(suma);
    printf(".");
    print_b(sumb);
    printf("\n");
}

void case2(char str1[], char str2[])
{
    int na1[100] = {0};
    int nb1[100] = {0};
    int na2[100] = {0};
    int nb2[100] = {0};
    int suma[200] = {0};
    int sumb[200] = {0};
    int np1 = 1;
    int np2 = 1;
    int npsize1 = deal(str1, np1, na1, nb1);
    int npsize2 = deal(str2, np2, na2, nb2);

    if (isL(na1, na2) == 1)
    {

        int borrow = sub(nb1, nb2, 0, sumb);
        sub(na1, na2, borrow, suma);
    }
    else if (isL(na1, na2) == 0)
    {

        int borrow = sub(nb2, nb1, 0, sumb);
        sub(na2, na1, borrow, suma);
        printf("-");
    }

    print_a(suma);
    printf(".");
    print_b(sumb);
    printf("\n");
}

void case3(char str1[], char str2[])
{
    int na1[100] = {0};
    int nb1[100] = {0};
    int na2[100] = {0};
    int nb2[100] = {0};
    int suma[200] = {0};
    int sumb[200] = {0};
    int np1 = 1;
    int np2 = 1;
    int pro1[200] = {0};
    int pro2[200] = {0};
    int prosum[200] = {0};

    int npsize1 = deal(str1, np1, na1, nb1);
    int npsize2 = deal(str2, np2, na2, nb2);
    // a1*a2 a1*b2 a2*b1 a2*b2
    mul2(nb1, nb2, 70 - npsize1, 70 - npsize2, 0      ,0       ,prosum);
    mul2(na1, nb2, 0           , 70 - npsize2, npsize1,0       , prosum);
    mul2(nb1, na2, 70 - npsize1, 0           , 0      , npsize2, prosum);
    mul2(na1, na2, 0           , 0           , npsize1, npsize2, prosum);
    //a[] b[] locata locateb shifta shiftb sum

    int j = 0;
    for (int i = (npsize1 + npsize2); i < 200; i++)
    {
        suma[j] = prosum[i];
        j++;
    }
    print_a(suma);
    printf(".");
    j = 69;
    for (int i = (npsize1 + npsize2) - 1; i >= 0; i--)
    {
        sumb[i] = prosum[i];
    }
    print_a(sumb);
}
int main()
{
    char str1[100] = {' '};
    char str2[100] = {' '};
    memset(str1, ' ', 100);
    memset(str2, ' ', 100);
    scanf("%s", str1);
    scanf("%s", str2);
    case1(str1, str2);
    case2(str1, str2);
    case3(str1, str2);
}