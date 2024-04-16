#include <stdio.h>
void print_map(int map[][5])
{

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d %d %d %d %d %d\n",map[2][1],map[1][1],map[0][1],map[1][3],map[1][2],map[1][0]);
}
void turn_up(int map[][5])
{

    int temp = map[2][1];

    map[2][1] = map[1][1];
    map[1][1] = map[0][1];
    map[0][1] = map[1][3];
    map[1][3] = temp;
};

void turn_left(int map[][5])
{

    int temp = map[1][0];

    map[1][0] = map[1][1];
    map[1][1] = map[1][2];
    map[1][2] = map[1][3];
    map[1][3] = temp;
};

void turn_right(int map[][5])
{

    int temp = map[1][3];

    map[1][3] = map[1][2];
    map[1][2] = map[1][1];
    map[1][1] = map[1][0];
    map[1][0] = temp;
};

void copy(int map1[][5], int map2[][5])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int temp = map1[i][j];
            map1[i][j] = map2[i][j];
            map2[i][j] = temp;
        }
    }
};

int main()
{

    int R[5][5] = {
        {0, 3, 0, 0},
        {5, 1, 2, 6},
        {0, 4, 0, 0},
    };
    int M[5][5] = {
        {0, 3, 0, 0},
        {5, 1, 2, 6},
        {0, 4, 0, 0},
    };
    int L[5][5] = {
        {0, 3, 0, 0},
        {5, 1, 2, 6},
        {0, 4, 0, 0},
    };

    // int **dice[3] = {R, M, L};
    //     3
    // {0,   back, 0, 0},
    // {left, top, right, under}, 4
    // {0,   front, 0, 0},
    // 前、上、後、下、右、左

    int n = 0;
    scanf("%d", &n);

    char op1 = ' ';
    char op2 = ' ';
    int **op_dice;
    for (int i = 0; i < n; i++)
    {

        scanf(" %c %c", &op1, &op2);
        if (op1 == 'R')
        {
            // op_dice = R;

            if (op2 == '1')
            {
                turn_up(R);
                // print_map(R);
            }
            if (op2 == '2')
            {
                turn_left(R);
                // print_map(R);
            }
            if (op2 == '3')
            {
                turn_right(R);
                // print_map(R);
            }
            if (op2 == 'L')
            {
                copy(R, L);
                // print_map(R);
            }
            if (op2 == 'M')
            {
                copy(R, M);
                // print_map(R);
            }
        }
        if (op1 == 'M')
        {
            // op_dice = R;

            if (op2 == '1')
            {
                turn_up(M);
                // print_map(M);
            }
            if (op2 == '2')
            {
                turn_left(M);
                // print_map(M);
            }
            if (op2 == '3')
            {
                turn_right(M);
                // print_map(M);
            }

            if (op2 == 'R')
            {
                copy(M, R);
                // print_map(M);
            }
            if (op2 == 'L')
            {
                copy(M, L);
                // print_map(M);
            }
        }
        if (op1 == 'L')
        {
            // op_dice = R;

            if (op2 == '1')
            {
                turn_up(L);
                // print_map(L);
            }
            if (op2 == '2')
            {
                turn_left(L);
                // print_map(L);
            }
            if (op2 == '3')
            {
                turn_right(L);
                // print_map(L);
            }
            if (op2 == 'R')
            {
                copy(L, R);
                // print_map(L);
            }
            if (op2 == 'M')
            {
                copy(L, M);
                // print_map(L);
            }
        }
    }

    print_map(L);
    print_map(M);
    print_map(R);
    
}