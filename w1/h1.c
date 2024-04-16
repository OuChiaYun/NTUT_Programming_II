#include <stdio.h>
#include <math.h>

int main()
{

    int a = 0, b = 0, c = 0;
    float x1;
    float x2;

    scanf("%d%d%d",&a,&b,&c);
    x1 = ((-b) + sqrt(b * b - 4 * a * c)) / (2 * a);
    x2 = ((-b) - sqrt(b * b - 4 * a * c)) / (2 * a);
    
    printf("%.1f\n%.1f",x1,x2);
}