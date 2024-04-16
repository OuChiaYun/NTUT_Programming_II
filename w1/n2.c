#include <stdio.h>
int main()
{
    int state = 0, input = 0, score = 0;
    scanf("%d", &input);
    state = (state << input) | (1 << (input - 1));
    printf("%d %d %d\n", state & 1, (state >> 1) & 1, (state >> 2) & 1);
    state = state & 7;
    scanf("%d", &input);
    state = (state << input) | (1 << (input - 1));
    state = state & 7;
    scanf("%d", &input);
    state = (state << input) | (1 << (input - 1));
    state = state & 7;
    printf("%d %d %d\n", state & 1, (state >> 1) & 1, (state >> 2) & 1);
    return 0;
}