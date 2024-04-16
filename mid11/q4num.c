#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a % b);
    //最大公因數
}

int lcd(int a, int b)
{
    return (a * b) / gcd(a, b);
    //最小公倍數
}

int swap(float *a, float *b)
{
    float t = *a;
    *a = *b;
    *b = t;
}

void n1()
{

    int m[10] = {0, 0, 0};
    int b[10] = {0, 0, 0};

    int x1[10] = {0};
    int x2[10] = {0};
    int y1[10] = {0};
    int y2[10] = {0};
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int mup = y1[i] - y2[i];
        int mdo = x1[i] - x2[i];

        int bup = (x2[i] * y1[i] - x1[i] * y2[i]);
        int bdo = x2[i] - x1[i];
        int np1 = (mup * mdo) / abs(mup * mdo);
        int np2 = (bup * bdo) / abs(bup * bdo);
        // printf("y = %d/%d %d/%d\n", mup, mdo, bup, bdo);
        int k = gcd(mup, mdo);
        mup = mup / k;
        mdo = mdo / k;
        k = gcd(bup, bdo);
        bup = bup / k;
        bdo = bdo / k;
        int flag = 0;
        printf("y = ");

        if (mup == 0)
        {
            if (bup % bdo == 0)
            {
                printf("%d", bup);
            }
            else
            {
                printf("%d/%d", bup, abs(bdo));
            }
        }
        else
        {

            if (mup % mdo == 0)
            {
                if (abs(mup / mdo) == 1)
                {

                    if (np1 < 0)
                    {
                        printf("-x");
                    }
                    else
                    {
                        printf("x");
                    }
                }
                else if (abs(mup / mdo) != 1)
                {

                    printf("%dx", mup / mdo);
                }
            }
            else
            {
                printf("%d/%dx", np1*(abs(mup)), abs(mdo));
            }

            if (bup != 0)
            {
                if (np2 < 0)
                {
                    if (bup % bdo == 0)
                    {
                        if (abs(bup) / abs(bdo) != 1)
                        {
                            printf(" - %d", abs(bup) / abs(bdo));
                        }
                    }
                    else
                    {
                        printf(" - %d/%d", abs(bup), abs(bdo));
                    }
                }
                else
                {
                    if (bup % bdo == 0)
                    {
                        printf(" + %d", abs(bup) / abs(bdo));
                    }
                    else
                    {
                        printf(" + %d/%d", abs(bup), abs(bdo));
                    }
                }
            }
        }
        printf("\n");
        // printf("y = %d/%d %d/%d\n", mup, mdo, bup, bdo);
    }
}

void n2()
{
    int a[10] = {0};
    int b[10] = {0};
    int c[10] = {0};

    for (int i = 0; i < 3; i++)
    {

        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }

    float y[10] = {0};
    float x[10] = {0};

    // y = b1/a1x + c1/a1
    // y = b2/a2x + c2/a2
    //-1*(c1/a1-c1/a2)= (b1/a1 - b2/a2) x
    // x = (c1/a1-c2/a2)/ (b1/a1 - b2/a2)
    x[0] = -1 * ((float)c[0] / a[0] - (float)c[1] / a[1]) / ((float)b[0] / a[0] - (float)b[1] / a[1]);
    x[1] = -1 * ((float)c[1] / a[1] - (float)c[2] / a[2]) / ((float)b[1] / a[1] - (float)b[2] / a[2]);
    x[2] = -1 * ((float)c[2] / a[2] - (float)c[0] / a[0]) / ((float)b[2] / a[2] - (float)b[0] / a[0]);
    // printf("%.2f %.2f %.2f\n", x[0], x[1], x[2]);

    y[0] = ((float)b[0] / a[0]) * x[0] + ((float)c[0] / a[0]);
    y[1] = ((float)b[1] / a[1]) * x[1] + ((float)c[1] / a[1]);
    y[2] = ((float)b[2] / a[2]) * x[2] + ((float)c[2] / a[2]);
    // printf("%.2f %.2f %.2f\n", y[0], y[1], y[2]);
    // x b to s
    // y s to b
    //  printf()

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (x[i] < x[j])
            {
                swap(&x[i], &x[j]);
                swap(&y[i], &y[j]);
                //
            }
            else if ((x[i] == x[j]) && (y[i] > y[j]))
            {
                swap(&x[i], &x[j]);
                swap(&y[i], &y[j]);
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("(%.2f, %.2f)\n", x[i], y[i]);
    }//(-1.00, 2.00)
}

int main()
{
    int op = 0;
    int n = 0;

    scanf("%d", &n);
    if (n ==1)
    {
        n1();
    }else{
        n2();
    }
}