#include <stdio.h>

int main()
{

    float h, w = 0;
    float BMI = 0;

    scanf("%f%f", &w, &h);

    BMI = w / ((h / 100) * (h / 100));

    printf("%.1f\n", BMI);
    printf("jirwo");
}