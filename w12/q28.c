#include <stdio.h>

// c/r local move way

void c_left_front(int map[12][12])
{
    int tmp[5] = {map[0][3], map[1][3], map[2][3]};
    int left[10] = {map[3][0], map[3][1], map[3][2],
                    map[4][0], map[4][1], map[4][2],
                    map[5][0], map[5][1], map[5][2]};

    map[3][0] = left[2];
    map[4][0] = left[1];
    map[5][0] = left[0];

    map[3][0] = left[2];
    map[3][1] = left[5];
    map[3][2] = left[8];

    map[3][2] = left[8];
    map[4][2] = left[7];
    map[5][2] = left[6];

    map[5][2] = left[6];
    map[5][1] = left[3];
    map[5][0] = left[0];
    ///////////////////////////////////////////
    map[0][3] = map[3][3];
    map[1][3] = map[4][3];
    map[2][3] = map[5][3];

    map[3][3] = map[6][3];
    map[4][3] = map[7][3];
    map[5][3] = map[8][3];

    map[6][3] = map[5][11];
    map[7][3] = map[4][11];
    map[8][3] = map[3][11];

    map[3][11] = tmp[2];
    map[4][11] = tmp[1];
    map[5][11] = tmp[0];
}

void c_mid_front(int map[12][12])
{

    int tmp[5] = {map[0][4], map[1][4], map[2][4]};

    ///////////////////////////////////////////
    map[0][4] = map[3][4];
    map[1][4] = map[4][4];
    map[2][4] = map[5][4];

    map[3][4] = map[6][4];
    map[4][4] = map[7][4];
    map[5][4] = map[8][4];

    map[6][4] = map[5][10];
    map[7][4] = map[4][10];
    map[8][4] = map[3][10];

    map[3][10] = tmp[2];
    map[4][10] = tmp[1];
    map[5][10] = tmp[0];
}

void c_right_front(int map[12][12])
{
    int tmp[5] = {map[0][5], map[1][5], map[2][5]};

    int top[10] = {map[3][6], map[3][7], map[3][8],
                   map[4][6], map[4][7], map[4][8],
                   map[5][6], map[5][7], map[5][8]};

    map[3][8] = top[0];
    map[3][7] = top[3];
    map[3][6] = top[6];

    map[5][8] = top[2];
    map[4][8] = top[1];
    map[3][8] = top[0];

    map[4][6] = top[8];
    map[4][7] = top[5];
    map[4][8] = top[2];

    map[3][6] = top[6];
    map[4][6] = top[7];
    map[5][6] = top[8];

    ///////////////////////////////////////////////

    map[0][5] = map[3][5];
    map[1][5] = map[4][5];
    map[2][5] = map[5][5];

    map[3][5] = map[6][5];
    map[4][5] = map[7][5];
    map[5][5] = map[8][5];

    map[6][5] = map[5][9];
    map[7][5] = map[4][9];
    map[8][5] = map[3][9];

    map[3][9] = tmp[2];
    map[4][9] = tmp[1];
    map[5][9] = tmp[0];
}

void r_top_left(int map[12][12])
{

    int tmp[5] = {map[3][0], map[3][1], map[3][2]};

    int top[10] = {map[0][3], map[0][4], map[0][5],
                   map[1][3], map[1][4], map[1][5],
                   map[2][3], map[2][4], map[2][5]};

    map[0][5] = top[0];
    map[0][4] = top[3];
    map[0][3] = top[6];

    map[2][5] = top[2];
    map[1][5] = top[1];
    map[0][5] = top[0];

    map[2][3] = top[8];
    map[2][4] = top[5];
    map[2][5] = top[2];

    map[0][3] = top[6];
    map[1][3] = top[7];
    map[2][3] = top[8];

    ///////////////////////////////////////////////

    map[3][0] = map[3][3];
    map[3][1] = map[3][4];
    map[3][2] = map[3][5];

    map[3][0] = map[3][3];
    map[3][1] = map[3][4];
    map[3][2] = map[3][5];

    map[3][3] = map[3][6];
    map[3][4] = map[3][7];
    map[3][5] = map[3][8];

    map[3][6] = map[3][9];
    map[3][7] = map[3][10];
    map[3][8] = map[3][11];

    map[3][9] = tmp[0];
    map[3][10] = tmp[1];
    map[3][11] = tmp[2];
}

void r_mid_left(int map[12][12])
{

    int tmp[5] = {map[4][0], map[4][1], map[4][2]};

    map[4][0] = map[4][3];
    map[4][1] = map[4][4];
    map[4][2] = map[4][5];

    map[4][0] = map[4][3];
    map[4][1] = map[4][4];
    map[4][2] = map[4][5];

    map[4][3] = map[4][6];
    map[4][4] = map[4][7];
    map[4][5] = map[4][8];

    map[4][6] = map[4][9];
    map[4][7] = map[4][10];
    map[4][8] = map[4][11];

    map[4][9] = tmp[0];
    map[4][10] = tmp[1];
    map[4][11] = tmp[2];
}

void r_under_left(int map[12][12])
{

    int tmp[5] = {map[5][0], map[5][1], map[5][2]};

    int left[10] = {map[6][3], map[6][4], map[6][5],
                    map[7][3], map[7][4], map[7][5],
                    map[8][3], map[8][4], map[8][5]};

    map[6][3] = left[2];
    map[7][3] = left[1];
    map[8][3] = left[0];

    map[6][3] = left[2];
    map[6][4] = left[5];
    map[6][5] = left[8];

    map[6][5] = left[8];
    map[7][5] = left[7];
    map[8][5] = left[6];

    map[8][5] = left[6];
    map[8][4] = left[3];
    map[8][3] = left[0];

    //////////////////////////////////
    map[5][0] = map[5][3];
    map[5][1] = map[5][4];
    map[5][2] = map[5][5];

    map[5][0] = map[5][3];
    map[5][1] = map[5][4];
    map[5][2] = map[5][5];

    map[5][3] = map[5][6];
    map[5][4] = map[5][7];
    map[5][5] = map[5][8];

    map[5][6] = map[5][9];
    map[5][7] = map[5][10];
    map[5][8] = map[5][11];

    map[5][9] = tmp[0];
    map[5][10] = tmp[1];
    map[5][11] = tmp[2];
}

void print_map(int map[12][12])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 3; j < 6; j++)
        {
            printf("%d ", map[i][j]);
        }
        if (i != 2)
        {

            printf("\n");
        }
    }
}

int main()
{

    int map[12][12] =
        //             l  m  r
        {
            //   0  1  2  3  4  5  6  7  8  9  0  1
            {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 0
            {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 1
            {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 2
            {5, 5, 5, 4, 4, 4, 2, 2, 2, 3, 3, 3}, // 3 t
            {5, 5, 5, 4, 4, 4, 2, 2, 2, 3, 3, 3}, // 4 m
            {5, 5, 5, 4, 4, 4, 2, 2, 2, 3, 3, 3}, // 5 u
            {0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0}, // 6
            {0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0}, // 7
            {0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0}  // 8
        };

    int n = 0;
    int op = 0;

    //     top
    // left front right back
    //     under

    // 1:blue 2:red 3:yellow 4:white 5: orange 6:green

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &op);

        if (op == 10)
        {
            c_left_front(map);
        }
        if (op == 11)
        {
            c_mid_front(map);
        }
        if (op == 12)
        {
            c_right_front(map);
        }
        if (op == 20)
        {
            r_top_left(map);
        }
        if (op == 21)
        {
            r_mid_left(map);
        }
        if (op == 22)
        {
            r_under_left(map);
        }
    }
    
    print_map(map);
    
}