#include <stdio.h>
#include <math.h>

int lcd(int a, int b)
{
    int beggest = 0;
    int _lcd = 0;
    if (a < b)
    {
        beggest = a;
    }
    else
    {
        beggest = b;
    }

    for (int i = 1; i <= beggest; i++)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            _lcd = i;
        }
    }

    return _lcd;
}

void N1(int n)
{
    int k = 0;

    int map[10][4] = {0}; 
    int flag = 0;

    scanf("%d", &k);


    if (n == 1)
    {
        for (int i = 0; i < k; i++)
        {
            flag = 0;
            int _lcd = 0;
            scanf("%d%d%d%d", &map[i][0], &map[i][1], &map[i][2], &map[i][3]);
            // x1,y1,x2,y2
            // m = (y1 - y2) / (x1 - x2)
            // b = (x2 * y1 - x1 * y2) / (x2 - x1)
            int m1 = (map[i][1] - map[i][3]);
            int m2 = (map[i][0] - map[i][2]);

            if (m1 < 0 && m2 < 0)
            {
                m1 = abs(m1);
                m2 = abs(m2);
            } // m1 / m2 皆正


            else if ((m2 < 0))
            {
                m2 = abs(m2);
                m1 *= -1; //m1/-m2 => -m1/m2 
            }

            if ((m1 % m2 != 0))
            {
                _lcd = lcd(abs(m1), abs(m2));
                printf("y = %d/%dx", m1 / _lcd, abs(m2 / _lcd)); // m1/m2
            }
            else
            {
                if (m1 == 0)
                {
                    printf("y ="); //m1 == 0 => y = b
                    flag = 1;
                }
                else if ((m1 / m2) == 1) // y = 1x => y = x
                {
                    printf("y = x");
                }
                else if ((m1 / m2) == -1) // y = -1x => y = -x
                {
                    printf("y = -x");
                }
                else
                {
                    printf("y = %dx", m1 / m2); // y = (m1/m2)x => y = Mx 
                }
            }

            int b1 = map[i][2] * map[i][1] - map[i][0] * map[i][3];
            int b2 = map[i][2] - map[i][0];
            // b = (x2 * y1 - x1 * y2) / (x2 - x1)



            int _lcd2 = 0;

            char np2 = '+';
            if (b1 < 0 && b2 < 0) // -b1/-b2 => b1/b2
            {
                b1 = abs(b1);
                b2 = abs(b2);
            }

            else if (b2 < 0) // b1/-b2 => -b1/b2
            {
                b2 = abs(b2);
                b1 *= -1;
            }
            
            if (b1< 0 || b2 < 0) // take the '-' out of b
            {
                np2 = '-';
            }

            if ((b1 != 0) && (b1 % b2 != 0)) // b1%b2 == 0 is show B
            {
                _lcd2 = lcd(abs(b1), abs(b2)); // take lcd
                if (flag == 1)
                {
                    printf(" %d/%d\n", b1 / _lcd2, abs(b2 / _lcd2)); // b1/b2
                }
                else
                {

                    printf(" %c %d/%d\n", np2, abs(b1 / _lcd2), abs(b2 / _lcd2)); //y = mx - b1/b2
                }
            }
            else
            {
                if (b1 == 0)
                {
                    if(flag == 0){

                        printf("\n"); // y = mx
                    }else{
                        printf(" 0\n"); // y = 0
                    }
                   
                }
                else if (flag == 1)
                {
                    printf(" %d\n", b1 / b2); // y = b1/b2
                }
                else
                {
                    printf(" %c %d\n", np2, abs(b1 / b2)); // y = mx - (b1/b2) => y = mx - B
                }
            }
        }
    }
}

void N2(int n)
{

    int a1 = 0, a2 = 0, a3 = 0;
    int b1 = 0, b2 = 0, b3 = 0;
    int c1 = 0, c2 = 0, c3 = 0;

    // float x1 =0 ,x2 = 0,x3 = 0;
    float x[3] = {0};
    // float y1 =0 ,y2 = 0,y3 = 0;
    float y[3] = {0};

    scanf("%d%d%d", &a1, &b1, &c1);
    scanf("%d%d%d", &a2, &b2, &c2);
    scanf("%d%d%d", &a3, &b3, &c3);
    /// L1 * L2
    x[0] = (float)(a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);
    y[0] = (float)(b1 * x[0] + c1) / a1;
    /// L2 * L3
    x[1] = (float)(a3 * c2 - a2 * c3) / (a2 * b3 - a3 * b2);
    y[1] = (float)(b2 * x[1] + c2) / a2;
    /// L1 * L3
    x[2] = (float)(a3 * c1 - a1 * c3) / (a1 * b3 - a3 * b1);
    y[2] = (float)(b3 * x[2] + c3) / a3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((x[i] < x[j]))
            {

                float temp = x[i];
                x[i] = x[j];
                x[j] = temp;

                float temp2 = y[i];
                y[i] = y[j];
                y[j] = temp2;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((x[i] == x[j]) && (y[i] < y[j]))
            {

                float temp = x[i];
                x[i] = x[j];
                x[j] = temp;

                float temp2 = y[i];
                y[i] = y[j];
                y[j] = temp2;
            }
        }
    }
    // L1L2
    // L1L3
    // L2L3
    printf("(%.2f, %.2f)\n(%.2f, %.2f)\n(%.2f, %.2f)", x[0], y[0], x[1], y[1], x[2], y[2]);
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    if (n == 1)
    {
        N1(n);
    }
    else if (n == 2)
    {
        N2(n);
    }
}