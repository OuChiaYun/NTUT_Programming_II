#include <stdio.h>
#include <string.h>

int main()
{

    char map[10][6] = {{' '}};
    int x = 0;
    char c = ' ';

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &x);
        // printf("%d\n", x);
        for (int j = 0; j < x; j++)
        {
            scanf(" %c %c", &map[i][j], &c);
            // printf("\n%s\n", map[i][j]);
        }
    }
    int s = 0;
    int out = 0;
    int n = 0;
    int score = 0;
    int player_n = 0;
    int flag = 0;
    int round = 1;

    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            if (map[j][i] == ' ')
            {
                continue;
            }
            // printf("%c ", map[j][i]);

            int player_n = (map[j][i]) - '0';
            // printf("%d %d \n", player_n, out);
            if (player_n == 24)
            {
                player_n = 4;
                score++;
            }

            if (player_n == 35 || player_n == 22 || player_n == 23)
            {
                out++;
                if (out == 3 && round < 3)
                {
                    // printf("\n");
                    // // printf("s : %d\n", score);
                    // for (int i = 0; i < 3; i++)
                    // {
                    //     printf("%d ", s & 1);
                    //     s = s >> 1;
                    // }
                    // printf("\n");
                    round++;
                    s = 0;
                    out = 0;
                    flag = 1;
                    // n = i + 1;
                    // continue;
                }

                continue;
            }

            if (flag != 1)
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
            flag = 0;
        }
        // printf("\n");
    }
    printf("%d\n", score);
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", s & 1);
        s = s >> 1;
    }
    printf("\n");
    s = 0;
    out = 0;
    n = 0;
    int scoreB = 0;
    player_n = 0;
    flag = 0;
    round = 1;

    for (int i = 0; i < 5; i++)
    {

        for (int j = 5; j < 10; j++)
        {
            if (map[j][i] == ' ')
            {
                continue;
            }
            // printf("%c ", map[j][i]);

            int player_n = (map[j][i]) - '0';
            // printf("%d %d \n", player_n, out);
            if (player_n == 24)
            {
                player_n = 4;
                scoreB++;
            }

            if (player_n == 35 || player_n == 22 || player_n == 23)
            {
                out++;
                if (out == 3 && round < 3)
                {
                    // printf("\n");
                    // // printf("s : %d\n", score);
                    // for (int i = 0; i < 3; i++)
                    // {
                    //     printf("%d ", s & 1);
                    //     s = s >> 1;
                    // }
                    // printf("\n");
                    round++;
                    s = 0;
                    out = 0;
                    flag = 1;
                    // n = i + 1;
                    // continue;
                }

                continue;
            }

            if (flag != 1)
            {

                for (int k = 0; k < player_n; k++)
                {
                    if ((s & 4) >= 4)
                    {
                        scoreB++;
                    }

                    s = s << 1;
                }
            }

            if (player_n != 0 && player_n != 4)
            {
                s = s | (1 << player_n - 1);
            }
            flag = 0;
        }
        // printf("\n");
    }
    printf("%d\n", scoreB);
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", s & 1);
        s = s >> 1;
    }
    printf("\n");

    if(score > scoreB){
        printf("A");
    }else if(score < scoreB){
        printf("B");
    }else{
        printf("Tie");
    }
    // printf("\n");

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 6; j++)
    //     {
    //         printf("%c ", map[i][j]);
    //     }
    //     printf("\n");
    // }
}