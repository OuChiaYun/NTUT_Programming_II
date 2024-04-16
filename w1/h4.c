#include <stdio.h>

int main()
{
    int s1, s2 = 0;
    int add[] = {0, 0, 0};
    int rm[] = {0, 0, 0};
    int s2_U, s2_N = 0;
    scanf("%d%d", &s1, &s2);
    scanf("%d%d%d", &add[0], &add[1], &add[2]);
    scanf("%d%d%d", &rm[0], &rm[1], &rm[2]);

    s2_U = s2;
    s2_N = s2;

    for (int i = 0; i < 3; i++)
    {
        s2 = s2 | (1 << (add[i]));
    }


    for (int i = 0; i < 3; i++)
    {
        s2 = s2 & ~(1 << (rm[i]));
    }

    char flag = 'Y';

    s2_U = s2_U & s2;
    s2_N = s2_N | s2;
    for (int i = 0; i < 8; i++)
    {
        if( (s1 & 1) < (s2 & 1) )
        {
            flag = 'N';
            break;
        }
        s1 = s1 >>1;
        s2 = s2 >>1;
    }
    printf("%c\n",flag);
    printf("%d\n", s2_U);
    printf("%d\n", s2_N);
}