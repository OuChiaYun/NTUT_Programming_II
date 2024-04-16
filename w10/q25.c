#include <stdio.h>
#include <math.h>

double f1(double a, double x)
{

    double fx;

    fx = pow((a - x * x), (0.5));
    return fx;
}
double f2(double a, double x)
{

    double fx;

    fx = (a * (x * x * x) + 7 * x) / (pow((a + x), 0.5));
    return fabs(fx);
}
double A(double a, double p, double q, int n, int err, double (*f)(double, double))
{

    double x = (q - p) / n;         //-6-4/1
    double ans = (*f)(a, p) + f(a, q); //-1 // 1
    double a_ = (q - p) / (2 * n);
   
    for (double i = p + x; i < q; i += x)
    {
       
        ans += 2 * f(a, i);
    }
    ans *= a_;

    return ans;
}

int main()
{

    int ch = -1;
    double a = 0, p = 0, q = 0;
    int err = 0;
    double err_n = 1;
    double (*f)(double, double) = f1;

    while (ch != 0)
    {
        scanf("%d", &ch);
        if (ch == 0)
        {
            break;
        }
        scanf("%lf%lf%lf%d", &a, &p, &q, &err);
        // printf("a%f",a);
        err_n = 1.0 / pow(10, err);

        if (ch == 1)
        {
            f = f1;
        }
        else if (ch == 2)
        {
            f = f2;
        }
        int j = 1;
        double a1 = A(a, p, q, j, err, f);
        j *= 2;
        double a2 = A(a, p, q, j, err, f);
        while (fabs(a1 - a2) > err_n)
        {

            // printf("j : %d ",j);
            a1 = A(a, p, q, j, err, f);
            j *= 2;
            a2 = A(a, p, q, j, err, f);
        }

        printf("%.12f\n", a2);
    }
}