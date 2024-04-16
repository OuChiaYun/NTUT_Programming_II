#include <stdio.h>
#include <math.h>
#include <string.h>

#define shapeText(TYPE)              \
    char name[100];                  \
    int (*perimeter)(struct TYPE *); \
    int (*area)(struct TYPE *);

typedef struct circle_s
{
    shapeText(circle_s);
    int radius;
} circle_t;

typedef struct rectangle_s
{
    shapeText(rectangle_s);
    int width, height;
} rectangle_t;
typedef struct square_s
{
    shapeText(square_s);
    int side;
} square_t;
typedef struct triangle_s
{
    shapeText(triangle_s);
    int s1, s2, s3;
} triangle_t;

int circle_area(circle_t *obj)
{
    return obj->radius * obj->radius * 4;
}

int circle_perimeter(circle_t *obj)
{
    return obj->radius * 2 * 4;
}

int rectangle_area(rectangle_t *obj)
{

    return obj->width * obj->height;
}

int rectangle_perimeter(rectangle_t *obj)
{
    return obj->width * 2 + obj->height * 2;
}

int square_area(square_t *obj)
{
    return obj->side * obj->side;
}

int square_perimeter(square_t *obj)
{
    return obj->side * 4;
}

int triangle_area(triangle_t *obj)
{

    int s = obj->s1 + obj->s2 + obj->s3;
    s = s / 2;
    s = s * (s - obj->s1) * (s - obj->s2) * (s - obj->s3);
    return pow(s, 0.5);
}

int triangle_perimeter(triangle_t *obj)
{
    int s = obj->s1 + obj->s2 + obj->s3;
    return s;
}

void create_circle(circle_t *obj)
{
    obj->area = circle_area;
    obj->perimeter = circle_perimeter;
}

void create_triangle(triangle_t *obj)
{
    obj->area = triangle_area;
    obj->perimeter = triangle_perimeter;
}

void create_retangle(rectangle_t *obj)
{
    obj->area = rectangle_area;
    obj->perimeter = rectangle_perimeter;
}

void create_square(square_t *obj)
{
    obj->area = square_area;
    obj->perimeter = square_perimeter;
}

int main()
{

    int n = 0;
    circle_t c[100];
    triangle_t t[100];
    rectangle_t r[100];
    square_t s[100];


    square_t* ss ;
    ss = (square_t*)&c[0];

    c[0].radius = 5;

    printf("%d",ss->area);


    // int area_sum = 0;
    // int pr_sum = 0;

    // int c_t = 0, t_t = 0, r_t = 0, s_t = 0;
    // char name_t[100];

    // scanf("%d", &n);

    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &n);
    //     scanf("%s", name_t);

    //     printf("%s\n", name_t);
    //     if (strcmp(name_t, "triangle") == 0)
    //     {

    //         scanf("%d", &t[t_t].s1);
    //         scanf("%d", &t[t_t].s2);
    //         scanf("%d", &t[t_t].s3);
    //         create_triangle(&t[t_t]);

    //         printf("%d %d\n", t[t_t].perimeter(&t[t_t]), t[t_t].area(&t[t_t]));
    //         area_sum += t[t_t].area(&t[t_t]);
    //         pr_sum += t[t_t].perimeter(&t[t_t]);
    //         t_t++;
    //     }
    //     if (strcmp(name_t, "circle") == 0)
    //     {
    //         scanf("%d", &c[c_t].radius);
    //         create_circle(&c[c_t]);

    //         printf("%d %d\n", c[c_t].perimeter(&c[c_t]), c[c_t].area(&c[c_t]));
    //         area_sum += c[c_t].area(&c[c_t]);
    //         pr_sum += c[c_t].perimeter(&c[c_t]);
    //         c_t++;
    //     }
    //     if (strcmp(name_t, "rectangle") == 0)
    //     {
    //         scanf("%d", &r[r_t].height);
    //         scanf("%d", &r[r_t].width);
    //         create_retangle(&r[r_t]);
    //         printf("%d %d\n", r[r_t].perimeter(&r[r_t]), r[r_t].area(&r[r_t]));

    //         area_sum += r[r_t].area(&r[r_t]);
    //         pr_sum += r[r_t].perimeter(&r[r_t]);
    //         r_t++;
    //     }
    //     if (strcmp(name_t, "square") == 0)
    //     {
    //         scanf("%d", &s[s_t].side);
    //         create_square(&s[s_t]);
    //         printf("%d %d\n", s[s_t].perimeter(&s[s_t]), s[s_t].area(&s[s_t]));

    //         area_sum += s[s_t].area(&s[s_t]);
    //         pr_sum += s[s_t].perimeter(&s[s_t]);
    //         s_t++;
    //     }
    // }

    // printf("%d %d\n", pr_sum,area_sum);
}