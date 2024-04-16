#include <stdio.h>
#include <math.h>
#include <string.h>

void DEcconvertToOther(unsigned long long int n, int num)
{

    if (n == 0)
    {
        printf("stop\n");
    }
    else
    {
        DEcconvertToOther(n / num, num);
        printf("%X", n % num);
    }
}

unsigned long long int convertToDec(int n[], int num, int length)
{
    // num進制轉10進制
    // 傳入的字串 num 字串進制
    // length 長度
    unsigned long long int count = 0;
    int i = 0;
     unsigned long long int rem = 0;
    int j = length - 1;
    while (length > 0)
    {
        // printf("|%d ", i);
        rem = n[j];
        // unsigned long long int u = 1;
        // for(int k =0;k<i;k++){
        //     u *= 10;
        // }

        count += rem * (unsigned long long int)pow(num, i);
        // count += rem *u;
        i++;
        j--;
        length--;
        // printf("%lld|", count);
    }

    return count;
}

int main()
{

    char st[20] = {' '};
    int nt[20] = {0};
    int n1 = 0;
    int n2 = 0;

    scanf("%s", st);
    scanf("%d", &n1);
    scanf("%d", &n2);

    for (int i = 0; i < strlen(st); i++)
    {
        if (st[i] == 'A')
        {
            nt[i] = 10;
        }
        else if (st[i] == 'B')
        {
            nt[i] = 11;
        }
        else if (st[i] == 'C')
        {
            nt[i] = 12;
        }
        else if (st[i] == 'D')
        {
            nt[i] = 13;
        }
        else if (st[i] == 'E')
        {
            nt[i] = 14;
        }
        else if (st[i] == 'F')
        {
            nt[i] = 15;
        }
        else
        {

            nt[i] = st[i] - '0';
        }
    }

    // for (int i = 0; i < strlen(st); i++)
    // {
    //     printf("%d ", nt[i]);
    // }
    unsigned long long int n = convertToDec(nt, n1, strlen(st));
    printf("now: %lld\n", convertToDec(nt, n1, strlen(st)));
    printf("\n");
    DEcconvertToOther(n, n2);
}