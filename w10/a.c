#include <stdio.h>

typedef struct flag
{
    unsigned short F1 : 16; // 2
    unsigned short F2 : 16; // 2
    unsigned short F3 : 1;  // 2
    unsigned short F4 : 1;  //
    unsigned short F5 : 16; /// 2
    unsigned int f6 : 1;    // 4
} room;                     //= 10 = 12
int main()
{

    printf("%d", sizeof(room));
}