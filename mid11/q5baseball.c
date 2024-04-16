#include <stdio.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int main()
{

    char map[100][100][4] = {"  "};

    int n = 0;
    int count = 0;

    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &n);
        count += n;

        for (int j = 0; j < n; j++)
        {
            scanf("%s", map[i][j]);
        }
    }
    int out = 0;
    int score = 0;
    int s = 0;
    int n0 = 0;
    int mm[9][3] = {0, 0, 0};
    for (int i = 1; i < 10; i++)
    {
        mm[i - 1][0] = i;
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            // printf("co %d \n", count);
            if (count <= 0)
            {
                break;
            }
            count--;
            // printf("%s ", map[j][i]);
            char a = map[j][i][0];
            char a2 = map[j][i][1];
            int an = map[j][i][0] - '0';

            if (a2 == 'O')
            {
                out++;
                // printf("\n");
                if (out == 3)
                {
                    s = 0;
                    out = 0;
                    n0 = 1;
                    continue;
                }

                continue;
            }

            if (a == 'H')
            {
                score++;
                an = 4;
                mm[j][2]++;
            }

            if (n0==0)
            {
                
                for (int k = 0; k < an; k++)
                {
                    s = s << 1;
                    if ((s & 8) == 8)
                    {
                        score++;

                        mm[j][2]++;
                    }
                }
            }
            n0=0;
            mm[j][1] += 1;
            s = s | 1 << (an - 1);
           
        }
    }


    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            if (mm[i][2] > mm[j][2])
            {
                swap(&mm[i][0], &mm[j][0]);
                swap(&mm[i][1], &mm[j][1]);
                swap(&mm[i][2], &mm[j][2]);
            }

            else if (mm[i][2] == mm[j][2] && mm[i][1] > mm[j][1])
            {
                swap(&mm[i][0], &mm[j][0]);
                swap(&mm[i][1], &mm[j][1]);
                swap(&mm[i][2], &mm[j][2]);
            }

            else if (mm[i][2] == mm[j][2] && mm[i][1] == mm[j][1] && mm[i][0] < mm[j][0])
            {
                swap(&mm[i][0], &mm[j][0]);
                swap(&mm[i][1], &mm[j][1]);
                swap(&mm[i][2], &mm[j][2]);
            }
        }
    }
    printf("%d\n", score);
    for (int i = 0; i < 9; i++)
    {
        printf("%d %d %d\n", mm[i][0], mm[i][1], mm[i][2]);
    }
}