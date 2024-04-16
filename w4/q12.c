#include <stdio.h>
#include <string.h>
void print(int sum[])
{
    int start = 0;

    for (int i = 99; i >= 0; i--)
    {
        if (sum[i] != 0)
        {
            start = i;
            break;
        }
    }
    // printf("now");
    for (int i = start; i >= 0; i--)
    {
        printf("%d", sum[i]);
    }
}

void mul(int a1_n[], int a2_n[])
{

    int sum[100] = {0};
    int carry = 0;
    for (int i = 0; i < 100; i++)
    {
        if (a1_n[i] == 0)
        {
            continue;
        }

        for (int j = 0; (i + j) < 100; j++)
        {
            sum[i + j] += a1_n[i] * a2_n[j];
        }
    }
    for (int i = 0; i < 100; ++i)
    {
        sum[i] += carry;
        carry = sum[i] / 10;
        sum[i] %= 10;
    }
    print(sum);
}

void sub(int a1_n[], int a2_n[], char sign)
{

    int sum[100] = {0};
    int borrow = 0;
    for (int i = 0; i < 100; i++)
    {
        sum[i] = a1_n[i] - a2_n[i] - borrow;
        if (sum[i] < 0)
        {
            borrow = 1;
            sum[i] += 10;
        }
        else
            borrow = 0;
    }
    if (sign == '-')
    {
        printf("%c", sign);
    }

    print(sum);
}

void add(int a1_n[], int a2_n[])
{

    int sum[100] = {0};
    int carry = 0;
    for (int i = 0; i < 100; i++)
    {
        sum[i] = a1_n[i] + a2_n[i] + carry;
        carry = sum[i] / 10;
        sum[i] %= 10;
    }

    print(sum);
}

void deal(char a1[], char a2[], char op)
{

    char a1_re[100] = {'0'};
    char a2_re[100] = {'0'};
    int j = 0;
    int a1_n[100] = {0};
    int a2_n[100] = {0};

    for (int i = strlen(a1) - 1; i >= 0; i--)
    {

        a1_re[i] = a1[j];
        j++;
    }

    // printf("%s\n", a1_re);

    j = 0;
    for (int i = strlen(a2) - 1; i >= 0; i--)
    {

        a2_re[i] = a2[j];
        j++;
    }

    for (int i = 0; i < strlen(a1_re); i++)
    {
        a1_n[i] = a1_re[i] - '0';
    }

    for (int i = 0; i < strlen(a2_re); i++)
    {
        a2_n[i] = a2_re[i] - '0';
    }
    if (op == '+')
    {
        add(a1_n, a2_n);
    }

    else if (op == '-')
    {
        if ((strlen(a1) < strlen(a2)) || ((strlen(a1) == strlen(a2)) && ( (a1[0]-'0') < (a2[0]-'0') )))
        {
            sub(a2_n, a1_n, '-');
        }
        else
        {
            sub(a1_n, a2_n, '+');
        }
    }
    else if (op == '*')
    {
        mul(a1_n, a2_n);
    }
}

int main()
{
    char arr1[100] = {'0'};
    char arr2[100] = {'0'};
    char op = '+';
    scanf(" %c",&op);
    scanf("%s", arr1);
    scanf("%s", arr2);

    deal(arr1, arr2, op);
}