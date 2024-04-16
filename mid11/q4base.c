#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{

    char map[15][15] = {' '};

    int count = 0;
    int out_n = 0;

    for (int i = 0; i < 9; i++)
    {
        int n = 0;
        scanf("%d", &n);
        count += n;
        for (int j = 0; j < n; j++)
        {
            scanf(" %c", &map[i][j]);
        }
    }

    scanf("%d", &out_n);

    int out = 0;
    int allout = 0;

    int s = 0;
    int score = 0;

    int me[9][3] = {0};
    int round = 0;
    int an = 0;
    int a[80] = {-1};
    int k = 0;
    for (int f = 0; f < 80; f++)
    {

        a[f] = -1;
    }

    for (int i = 0; i < 9; i++)
    {
        me[i][0] = i + 1;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            if (count < 0)
            {
                continue;
            }
            count--;

            if (map[j][i] == 'O')
            {
                out++;
                allout++;
                if (out == 3)
                {
                    s = 0;
                    out = 0;
                    round = 0;
                    for (int f = 0; f < 80; f++)
                    {

                        a[f] = -1;
                    }
                    k = 0;
                    continue;
                }
                continue;
            }

            an = (map[j][i] - '0');
            a[k] = j;
            k++;

            if (map[j][i] == 'H')
            {
                an = 4;

                a[k - 1] = -1;
                if (allout < out_n)
                {
                    score++;

                    me[j][2] += 1;
                }
            }

            if (round != 0)
            {
                for (int k = 0; k < an; k++)
                {
                    s = s << 1;

                    if ((s & 8) == 8)
                    {

                        if (allout < out_n)
                        {
                            score++;
                        }

                        for (int p = 0; p < 80; p++)
                        {
                            if (a[p] != -1 && allout < out_n)
                            {
                                me[a[p]][2] += 1;

                                a[p] = -1;
                                break;
                            }
                        }
                    }
                }
            }

            round++;
            s = s | 1 << (an - 1);
            if (allout < out_n)
            {
                me[j][1] += 1;
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (me[i][2] > me[j][2])
            {
                swap(&me[i][0], &me[j][0]);
                swap(&me[i][1], &me[j][1]);
                swap(&me[i][2], &me[j][2]);
            }
            else if ((me[i][2] == me[j][2]) && (me[i][0] < me[j][0]))
            {
                swap(&me[i][0], &me[j][0]);
                swap(&me[i][1], &me[j][1]);
                swap(&me[i][2], &me[j][2]);
            }
        }
    }

    printf("%d\n", score);
    for (int i = 0; i < 3; i++)
    {
        printf("%d %d %d\n", me[i][0], me[i][1], me[i][2]);
    }
}