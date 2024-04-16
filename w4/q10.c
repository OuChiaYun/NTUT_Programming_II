#include <stdio.h>
#include <string.h>

int main()
{

    char ans[5] = {' '};
    char gues[5] = {' '};
    int A = 0,B=0;
    int i = 0;

   
    scanf(" %s", ans);
   
    for (i = 0; i < 6; i++)
    {
        A=0;
        B=0;
        scanf(" %s", gues);
        

        if (strcmp(ans, gues) == 0)
        {
            printf("win");
            break;
        }
        else
        {
        
            for (int j = 0; j < 4; j++)
            {
                for (int h = 0; h < 4; h++)
                {

                    if (gues[j] == ans[h] && (j == h))
                    {
                        
                        A++;
                    }
                    else if (gues[j] == ans[h] && (j != h))
                    {
                        B++;
                    }
                }
            }

            printf("%dA%dB\n",A,B);
        }
    }

    if(i == 6){
        printf("loss");
    }
}