#include <stdio.h>

int main()
{

    int s = 0;
    int player[] = {0, 0, 0};
    scanf("%d%d%d", &player[0], &player[1], &player[2]);

    for (int i = 0; i < 3; i++)
    {

        if (i != 0)
        {

            if (player[i] == 4)
            {
                s = 0;
            }
            else
            {
                s = s << player[i];
            }
        }
        // 1100
        // 100 100 110 -> 4 4 6
        // 110 -> 6
        // 0 x,1 0 , 2 1 , 3 2, 4 x
        if (player[i] != 0 && player[i] != 4)
        {
            s = s | (1 << player[i]-1);
        }
        // printf("%d ", s);
    }


    for(int i = 0;i<3;i++){
        printf("%d ",s & 1);
        s = s >> 1;
    }
    // printf("%d", s);
}