#include <stdio.h>
#define PI 3
typedef struct
{
    int area, radius;
} circle_t;
typedef struct
{
    int area, width, height;
} rect_t;
typedef union
{
    circle_t circle;
    rect_t rect;
} figure_data_t;
typedef struct
{
    figure_data_t fig;
    char shap;
} figure_t;