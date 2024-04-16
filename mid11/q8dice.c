#include <stdio.h>
void printf_D(int D[][5])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
}

void printf_need(int D[][5])
{
    printf("%d %d %d %d %d %d", D[0][1], D[1][1], D[2][1], D[1][3], D[1][2], D[1][0]);
}
void turn_right(int D[][5])
{
    int t = D[1][3];
    D[1][3] = D[1][2];
    D[1][2] = D[1][1];
    D[1][1] = D[1][0];
    D[1][0] = t;
}

void turn_front(int D[][5])
{
    int t = D[0][1];
    D[0][1] = D[1][1];
    D[1][1] = D[2][1];
    D[2][1] = D[1][3];
    D[1][3] = t;
    /*map
    back(0,1)
left(1,0) top(1,1) right(1,2) under(1,3)
    front(2,1)
*/
}

int main()
{
    int A[5][5] = {{0, 3, 0, 0},
                   {5, 1, 2, 6},
                   {0, 4, 0, 0}};
    int B[5][5] = {{0, 3, 0, 0},
                   {5, 1, 2, 6},
                   {0, 4, 0, 0}};
    int C[5][5] = {{0, 3, 0, 0},
                   {5, 1, 2, 6},
                   {0, 4, 0, 0}};
    int D[5][5] = {{0, 3, 0, 0},
                   {5, 1, 2, 6},
                   {0, 4, 0, 0}};

    // turn_front(A);
    // turn_front(A);
    // printf("\n-------\n");
    // printf_need(A);
    // printf("\n");
    // printf("\n");

    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x, y = 0;
        scanf("%d%d", &x, &y);
        if (x == 1)
        {
            turn_front(A);
        }
        else if (x == 2)
        {
            turn_right(A);
        }

        if (y == 1)
        {
            turn_front(B);
        }
        else if (y == 2)
        {
            turn_right(B);
        }
    }
    printf_need(A);
    printf("\n");
    printf_need(B);
    printf("\n");

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x, y = 0;
        scanf("%d%d", &x, &y);
        if (x == 1)
        {
            turn_front(C);
        }
        else if (x == 2)
        {
            turn_right(C);
        }

        if (y == 1)
        {
            turn_front(D);
        }
        else if (y == 2)
        {
            turn_right(D);
        }
    }
    printf_need(C);
    printf("\n");
    printf_need(D);
    printf("\n");

    int A_count = A[1][1] + B[1][1];
    int B_count = C[1][1] + D[1][1];
    if (A[1][1] == B[1][1])
    {
        A_count = 0;
    }
    if (C[1][1] == D[1][1])
    {
        B_count = 0;
    }

    if(A_count > B_count){
        printf("A win\n");
    }else if(A_count< B_count){
        printf("B win\n");
    }else {
        printf("Tie\n");
    }

    /*map
        back(0,1)
    left(1,0) top(1,1) right(1,2) under(1,3)
        front(2,1)
    */
}
