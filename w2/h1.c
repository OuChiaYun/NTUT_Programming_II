#include <stdio.h>
#define START 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define FL 1
#define IN 2
#define VA 3
#define TR 4
#define MO 5

int getState(int state, char key)
{

    if (state == START && key == '0')
    {
        return A1;
    };

    if (state == START && key >= '1' && key <= '9')
    {
        return A3;
    };

    if (state == START && key >= 'a' && key <= ' Z' || key == '_')
    {
        return VA;
    };

    if (state == A1 && key >= 'a' && key <= ' Z' || key == '_')
    {
        return VA;
    };
    if (state == A1 && key >= '1' && key <= '9')
    {
        return A1;
    };
    if (state == A1 && key == '.')
    {
        return A2;
    };

    if (state == A1 && key == '\0')
    {
        return IN;
    };

    if (state == A2 && key >= '0' && key <= '9')
    {
        return A2;
    };

    if (state == A2 && key >= '\0')
    {
        return FL;
    };

    if (state == A2 && key >= '0' && key <= '9')
    {
        return A2;
    };

    if( state == A3 &&  key >= '0' && key <= '9'){
        return A3;
    };

    if (state == A3 && key == '\\'){
        return START;
    };

    if(state == A3 && key == '(' ){
        return A4;
    };

    if(state == A4&&  key >= '0' && key <= '9'){
        return START;
    };

    if(state == A3 &&key == ')'){
        return MO;
    }

}

int main()
{

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char key[50] = {' '};
    }
}