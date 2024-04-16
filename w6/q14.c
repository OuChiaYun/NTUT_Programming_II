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
    for (int i = start; i >= 0; i--)
    {
        printf("%d", sum[i]);
    }
}

void sub(int a1_n[], int a2_n[])
{

    // int sum[100] = {0};
    int borrow = 0;
    // int *sum_ptr=sum;
    for (int i = 0; i < 100; i++)
    {
        a1_n[i] = a1_n[i] - a2_n[i] - borrow;
        if (a1_n[i] < 0)
        {
            borrow = 1;
            a1_n[i] += 10;
        }
        else
            borrow = 0;
    }
    // printf("sub\n");
    // print(sum);
    // return sum;
}

void deal(char a1[], char a2[])
{

    char a1_re[100] = {'0'};
    char a2_re[100] = {'0'};
    int j = 0;
    int a1_n[100] = {0};
    int a2_n[100] = {0};
    for (int i = 0; i < 100; i++)
    {
        a1_n[i] = 0;
    }

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

    unsigned long long int k = 0;
    int num = strlen(a1);
    while (1)
    {

        if ((num < strlen(a2)))
        {
            printf("%lld\n", k);
            print(a1_n);
            break;
        }
        if (num == strlen(a2))
        {
            int a = 0;
            for (int i = num; i >= 0; i--)
            {

                if (a1_n[i] < a2_n[i])
                {
                    a = 1;
                    // printf("hhhh");
                    break;
                }
                else
                {
                    a = 0;
                    break;
                }
            }

            if (a == 1)
            {
                printf("%lld\n", k);
                print(a1_n);
                break;
            }
        }

        k++;
        sub(a1_n, a2_n);
        if (k == 10000000)
        {
            printf("now");
            print(a1_n);
            break;
        }
        num = 100;
        for (int i = 99; i >= 0; i--)
        {
            // printf("%d",a1_n[i]);
            if (a1_n[i] == 0)
            {
                num -= 1;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    char arr1[100] = {'0'};
    char arr2[100] = {'0'};
    scanf("%s", arr1);
    scanf("%s", arr2);

    deal(arr1, arr2);
}