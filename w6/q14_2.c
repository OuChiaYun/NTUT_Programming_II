#include <stdio.h>
#include <string.h>
#include<math.h>
void print(int sum[100])
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
    // printf("now %d\n", start);
    for (int i = start; i >= 0; i--)
    {
        printf("%d", sum[i]);
    }
}

int isLarger(int a1_n[], int a2_n[])
{

    int num2 = 100;
    int num1 = 100;
    for (int i = 99; i >= 0; i--)
    {
        // printf("%d",a1_n[i]);
        if (a1_n[i] == 0)
        {
            num1 -= 1;
        }
        else
        {
            break;
        }
    }

    for (int i = 99; i >= 0; i--)
    {
        // printf("%d",a1_n[i]);
        if (a1_n[i] == 0)
        {
            num2 -= 1;
        }
        else
        {
            break;
        }
    }

    if (num1 > num2)
    {
        return 1;
    }
    else if (num1 < num2)
    {
        return 0;
    }

    int a = 0;
    for (int i = num1; i >= 0; i--)
    {

        if (a1_n[i] < a2_n[i])
        {
            a = 1;
            // printf("hhhh");
            break;
        }
        else if (a1_n[i] > a2_n[i])
        {
            a = 0;
            break;
        }else{
            a = 2;
        }
    }
    if(a == 2){
        return 2;
    }

    if (a == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int getNum(int a[])
{

    int num = 100;
    for (int i = 99; i >= 0; i--)
    {
        // printf("%d",a1_n[i]);
        if (a[i] == 0)
        {
            num -= 1;
        }
        else
        {
            break;
        }
    }


    return num;
}

void mul(int a1_n[], int a2_n[], int sum[])
{

    // int sum[100] = {0};
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
    // print(sum);
}

void sub(int a1_n[100], int a2_n[100], int sum[100])
{

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

}


void div(int a1_n[100], int a2_n[100])
{

    int sum[100] = {0};
    int now[100] = {0};
    int n1 = getNum(a1_n);
    int n2 = getNum(a2_n);
    int nn = n1 - n2;
    unsigned long long int count =0;
 
    int flag = 0;
    int jdg = isLarger(a1_n, a2_n);
    while (isLarger(a1_n, a2_n) == 1)
    {
        flag = 0;
        for (int i = 1; i < 11; i++)
        {

            for (int k = 0; k < 100; k++)
            {
                sum[k] = 0;
                now[k] = 0;
            }

            now[0] = i;//try to mul 1-10
           
            mul(a2_n, now, sum);
       
            int n = getNum(sum); // long ,the length
           

            now[0] = 0;
            now[nn] = 1;//the  位數
            // print(now);
            int k[100] = {0};
            // printf("\n");
            // printf("jh %d\n", nn);
            mul(sum, now, k);

          
            if (isLarger(k, a1_n)==1)
            {

                now[nn] = 0;
                now[0] = i - 1; // 將now 歸零，然改為剛剛try 的大於的數
                int gg[100] = {0};

                mul(a2_n, now, gg); // 乘出來是 gg
                
                now[0] = 0;
                now[nn] = 1;    // 再乘上位數
                int gg2[100] = {0};
                mul(gg, now, gg2); // 乘出來是 gg2
        
                sub(a1_n, gg2, a1_n); //與乘數相減
                
                flag = i-1; 
                break;
            };
            // while()
        }

        count = count * 10 + flag;

        nn -= 1;
    }

    count = count*pow(10,nn+1);

    if(jdg == 2){
        printf("1\n0\n");
    }else{
        printf("%lld\n",count);
        print(a1_n);
        printf("\n");
    }
}

void deal(char a1[], char a2[])
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

    // printf("%d\n",isLarger(a1_n,a2_n));

    if (isLarger(a1_n, a2_n) == 0)
    {
        printf("0\n");
        print(a1_n);
    }
    else
    {

        // printf("ds");
        div(a1_n, a2_n);
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