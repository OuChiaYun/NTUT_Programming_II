#include <stdio.h>

int main()
{

    int out = 0;
    int score = 0;
    int n = 0;
    int s = 0;
    char player[] = {'0', '0', '0', '0', '0'};
    scanf(" %c %c %c %c %c", &player[0], &player[1], &player[2], &player[3], &player[4]);

    for (int i = 0; i < 5; i++)
    {
        int player_n = player[i] - '0';
        // printf("%d %d \n", player_n, out);
        if (player_n == 24)
        {
            player_n = 4;
            score++;
        }

        if (player_n == 31)
        {
            out++;
            if (out == 3)
            {
                s = 0;
                out = 0;
                n = i + 1;
                // continue;
            }
            continue;
        }

        if (i != n)
        {

            for (int k = 0; k < player_n; k++)
            {
                if ((s & 4) >= 4)
                {
                    score++;
                }

                s = s << 1;
            }
        }

        if (player_n != 0 && player_n != 4)
        {
            s = s | (1 << player_n - 1);
        }
    }

    printf("%d\n", score);
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", s & 1);
        s = s >> 1;
    }
    // printf("%d", s);
}