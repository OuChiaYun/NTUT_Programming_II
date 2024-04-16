#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}

int lcd(int a, int b)
{
    return ((a * b) / gcd(a, b));
}

void deal(char p[], int p_n[])
{

    int p_op = 1;
    int p_a = 0;
    int p_b = 0;
    int p_k = 0; // => k(a/b)
    int p_flag = 0;

    for (int i = 0; i < strlen(p); i++)
    {
        if (p[i] == '-')
        {
            p_op = -1;
            continue;
        }

        if (p[i] == '(')
        {
            p_k = p_a;
            p_a = 0;
            continue;
        }
        else if (p[i] == ')')
        {
            continue;
        }

        if (p[i] == '/')
        {
            p_flag = 1;
        }
        else if (p_flag == 0)
        {
            p_a = p_a * 10 + p[i] - '0';
        }
        else if (p_flag == 1)
        {
            p_b = p_b * 10 + p[i] - '0';
        }
    }

    // printf("%d %d %d %d\n", p_op, p_k, p_a, p_b);
    p_n[0] = p_op;
    p_n[1] = p_k;
    p_n[2] = p_a;
    p_n[3] = p_b;
}

void add(int p1[], int p2[], int sum[])
{
    int s_op;
    int s_k;
    int s_a;
    int s_b;
    int _lcd = lcd(p1[3], p2[3]);

    int p1_a = p1[0] * (p1[2] + p1[1] * p1[3]) * (_lcd / p1[3]);
    int p2_a = p2[0] * (p2[2] + p2[1] * p2[3]) * (_lcd / p2[3]);

    int p1_b = _lcd;
    int p2_b = _lcd;

    // printf("%d /%d , %d /%d", p1_a, p1_b, p2_a, p2_b);

    int _gcd = gcd(abs(p1_a + p2_a), _lcd);
    s_k = abs((p1_a + p2_a) / _lcd);
    s_a = ((p1_a + p2_a) % _lcd) / _gcd;
    s_b = abs(_lcd / _gcd);
    s_op = s_a / abs(s_a);
    s_a = abs(s_a);

    sum[0] = s_op;
    sum[1] = s_k;
    sum[2] = s_a;
    sum[3] = s_b;
    // printf("\n%d %d %d %d\n", s_op, s_k, s_a, s_b);
}

void mul(int p1[], int p2[], int sum[])
{
    int s_op;
    int s_k;
    int s_a;
    int s_b;

    int p1_a = (p1[2] + p1[1] * p1[3]);
    int p2_a = (p2[2] + p2[1] * p2[3]);
    int p1_b = p1[3];
    int p2_b = p2[3];

    // printf("%d /%d * %d /%d", p1_a, p1_b, p2_a, p2_b);

    s_op = p1[0] * p2[0];
    s_a = p1_a * p2_a;
    s_b = p1_b * p2_b;

    s_k = s_a / s_b;
    s_a = s_a % s_b;

    int _gcd = gcd(s_a, s_b);

    s_a = s_a / _gcd;
    s_b = s_b / _gcd;

    sum[0] = s_op;
    sum[1] = s_k;
    sum[2] = s_a;
    sum[3] = s_b;
    // printf("\n%d %d %d %d\n", s_op, s_k, s_a, s_b);
}

int main()
{
    char p1[100] = {" "};
    char p2[100] = {" "};
    char op = ' ';
    char contin = 'y';

    while (contin == 'y')
    {
        int p1_n[5] = {0, 0, 0, 0};
        int p2_n[5] = {0, 0, 0, 0};
        int sum[5] = {0, 0, 0, 0};

        scanf("%s", p1);
        scanf("%s", p2);
        scanf(" %c", &op);
        scanf(" %c", &contin);

        deal(p1, p1_n);
        deal(p2, p2_n);

        if (p1_n[3] == 0 || p2_n[3] == 0)
        {
            printf("ERROR\n");
        }
        else
        {

            if (op == '+')
            {
                add(p1_n, p2_n, sum);
            }
            else if (op == '-')
            {
                p2_n[0] *= -1;
                add(p1_n, p2_n, sum);
            }
            else if (op == '*')
            {
                mul(p1_n, p2_n, sum);
            }
            else if (op == '/')
            {
                p2_n[2] = p2_n[1] * p2_n[3] + p2_n[2];
                int temp = p2_n[2];
                p2_n[2] = p2_n[3];
                p2_n[3] = temp;
                p2_n[1] = 0;

                mul(p1_n, p2_n, sum);
            }

            // printf("ans\n");

            if (sum[0] == -1)
            {
                printf("-");
            }

            if (sum[2] == 0)
            {
                printf("0");
            }
            else if (sum[1] != 0)
            {
                printf("%d(%d/%d)\n", sum[1], sum[2], sum[3]);
            }
            else if (sum[1] == 0)
            {
                printf("%d/%d\n", sum[2], sum[3]);
            }
        }
    }
}