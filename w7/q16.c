#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swab_his(int a[], int b[])
{
    int temp0 = a[0];
    int temp1 = a[1];
    int temp2 = a[2];

    a[0] = b[0];
    a[1] = b[1];
    a[2] = b[2];

    b[0] = temp0;
    b[1] = temp1;
    b[2] = temp2;
}

void print_s(int u)
{
    for (int f = 0; f < 3; f++)
    {
        printf("%d ", u & 1);
        u = u >> 1;
    }
    printf("\n");
}
int main()
{

    char map[10][10][3] = {{"  "}};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            map[i][j][2] = '\0';
            map[i][j][1] = '\0';
            map[i][j][0] = '\0';
        }
    }
    int n = 0;
    int num[10][10] = {{0}};
    int his[10][4] = {{0}};
    // int k = 0;
    int o_num = 0;
    int map_n = 0;
    int round = 0;
    int s = 0;
    int score = 0;
    int all_score = 0;
    for (int i = 0; i < 9; i++)
    {
        his[i][0] = i + 1;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%s", map[i][j]);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // printf("%s ",map[i][j]);
            if (map[j][i][0] == '\0')
            {
                break;
            }
            if ((strcmp(map[j][i], "FO") == 0 || strcmp(map[j][i], "FO") == 0 || strcmp(map[j][i], "GO") == 0 || strcmp(map[j][i], "SO") == 0))
            {
           
                o_num++;
                if (o_num == 3)
                {
                    round = 0;
                    o_num = 0;
                    s = 0;
                }
        
            }
            else
            {
                score = 0;
                if (strcmp(map[j][i], "HR") == 0)
                {
                    map_n = 4;
                    score++;
                    all_score++;
                }
                else
                {

                    map_n = map[j][i][0] - '0';
                }
                if (round != 0)
                {

                    for (int h = 0; h < map_n; h++)
                    {
                        // printf("hh %d hh",s);
                        s = s << 1;
                        // printf("hh %d hh",s);
                        if ((s & 8) == 8)
                        {
                            score++;
                            all_score++;
                        }
                    }
                }
                his[j][2] += score;
                his[j][1] += 1;
                // printf("gycdu %d %skd",map_n,map[j][i]);
                s = s | 1 << (map_n - 1);
                // printf("i: %d %s %d\n", j + 1, map[j][i], score);
                // print_s(s);
                round++;
            }
        }
    }

    // for (int i = 0; i < 9; i++)
    // {
    //     printf("%d, %d, %d ", his[i][0], his[i][1], his[i][2]);
    //     printf("\n");
    // }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            if (his[i][2] > his[j][2])
            {
                swab_his(his[i], his[j]);
            }

            else if ( (his[i][2] == his[j][2]) && (his[i][1] > his[j][1]))
            {
                swab_his(his[i], his[j]);
            }
            else if  ((his[i][2] == his[j][2]) && (his[i][1] == his[j][1]) && (his[i][0] < his[j][0]) )
            {
                swab_his(his[i], his[j]);
            }
        }
    }
    // printf("=================\n");
    printf("%d\n", all_score);
    for (int i = 0; i < 9; i++)
    {
        printf("%d %d %d ", his[i][0], his[i][1], his[i][2]);
        printf("\n");
    }
}