#include <stdio.h>
#include <string.h>
#include <math.h>

#define ShapeText(TYPE)                 \
    char name[10];                      \
    double (*perimeter)(struct TYPE *); \
    double (*area)(struct TYPE *);

typedef struct shape_s
{
    ShapeText(shape_s);

} shape_t;

typedef struct circle_s
{
    ShapeText(circle_s);
    double radius;
} circle_t;

typedef struct rectangle_s
{
    ShapeText(rectangle_s);
    double length;
    double width;
} rectangle_t;

typedef struct square_s
{
    ShapeText(square_s);
    double edge;
} square_t;

typedef struct triangle_s
{
    ShapeText(triangle_s);
    double edge1;
    double edge2;
    double edge3;
} triangle_t;

double ShapeArea(shape_t *obj) { return 0; }
double ShapePerimeter(shape_t *obj) { return 0; }

double circleArea(circle_t *obj) { return 3.14 * obj->radius * obj->radius; }
double circlePerimeter(circle_t *obj) { return 3.14 * 2 * obj->radius; }

double rectangleArea(rectangle_t *obj) { return obj->length * obj->width; }
double rectanglePerimeter(rectangle_t *obj) { return 2 * obj->length + 2 * obj->width; }

double squareArea(square_t *obj) { return obj->edge * obj->edge; }
double squarePerimeter(square_t *obj) { return obj->edge * 4; }

double triangleArea(triangle_t *obj)
{
    double s = (obj->edge1 + obj->edge2 + obj->edge3) / 2.0;
    double t = (s - obj->edge1) * (s - obj->edge2) * (s - obj->edge3);
    return pow(s * t, 0.5);
}
double trianglePerimeter(triangle_t *obj) { return (obj->edge1 + obj->edge2 + obj->edge3); }

void ShapeNew(shape_t *obj)
{
    strcpy(obj->name, "shape");
    obj->perimeter = ShapePerimeter;
    obj->area = ShapeArea;
}

void circleNew(circle_t *obj)
{
    strcpy(obj->name, "circle");
    obj->perimeter = circlePerimeter;
    obj->area = circleArea;
}

void rectangleNew(rectangle_t *obj)
{
    strcpy(obj->name, "rectangle");
    obj->perimeter = rectanglePerimeter;
    obj->area = rectangleArea;
}

void squareNew(square_t *obj)
{
    strcpy(obj->name, "square");
    obj->perimeter = squarePerimeter;
    obj->area = squareArea;
}

void triangleNew(triangle_t *obj)
{
    strcpy(obj->name, "triangle");
    obj->perimeter = trianglePerimeter;
    obj->area = triangleArea;
}

// C：圓形，結構內容具有 1 個 radius 屬性 (圓周率請使用3.14)
// R：矩形，結構內容具有 1 個 length、1 個 width 屬性
// S：正方形，結構內容具有 1 個 edge 屬性
// T：三角形，結構內容具有 3 個 edge 屬性

int main()
{

    int n = 0;

    circle_t c;
    rectangle_t r;
    square_t s;
    triangle_t t;
    char type = ' ';

    double p = 0;
    double a = 0;

    circleNew(&c);
    rectangleNew(&r);
    squareNew(&s);
    triangleNew(&t);

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &type);

        if (type == 'C')
        {
            scanf("%lf", &c.radius);
            printf("%.2f ", c.perimeter(&c));
            printf("%.2f\n", c.area(&c));
            p += c.perimeter(&c);
            a += c.area(&c);
        }

        if (type == 'R')
        {
            scanf("%lf", &r.length);
            scanf("%lf", &r.width);
            printf("%.2f ", r.perimeter(&r));
            printf("%.2f\n", r.area(&r));
            p += r.perimeter(&r);
            a += r.area(&r);
        }

        if (type == 'S')
        {
            scanf("%lf", &s.edge);
            printf("%.2f ", s.perimeter(&s));
            printf("%.2f\n", s.area(&s));
            p += s.perimeter(&s);
            a += s.area(&s);
        }

        if (type == 'T')
        {
            scanf("%lf", &t.edge1);
            scanf("%lf", &t.edge2);
            scanf("%lf", &t.edge3);
            printf("%.2f ", t.perimeter(&t));
            printf("%.2f\n", t.area(&t));
            p += t.perimeter(&t);
            a += t.area(&t);
        }
    }

    printf("%.2f %.2f\n", p, a);
}
