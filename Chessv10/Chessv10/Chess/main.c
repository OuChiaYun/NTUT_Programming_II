#include "chess.h"
void drawChess(chess_item_t *item)
{
    int x = 0, y = 0;
    char fileName[20];
    x = item->x;
    y = item->y;
    if (isValid(x, y))
    {
        strcpy(fileName, item->name);
        if (item->display == CLEAR)
            strcpy(fileName, "Clear.GIF");
        else if (item->display == COVERED)
            strcpy(fileName, "Covered.GIF");
        else if (item->display == CHOOSED)
            strcat(fileName, "_.GIF");
        else
            strcat(fileName, ".GIF");
        readimagefile(fileName, ORIGIN + y * C_WIDTH + 2, ORIGIN + x * C_WIDTH + 2, ORIGIN + y * C_WIDTH + C_WIDTH - 2, ORIGIN + x * C_WIDTH + C_WIDTH - 2);
    }
}
void drawBoard(chess_item_t chess_items[NUMBER])
{
    int i = 0, x = 0, y = 0;
    char fileName[] = "Clear.GIF";
    for (i = 0; i < 5; i++)
    {
        line(ORIGIN, ORIGIN + i * C_WIDTH, 500, ORIGIN + i * C_WIDTH);
    }
    for (i = 0; i < 9; i++)
    {
        line(ORIGIN + i * C_WIDTH, ORIGIN, ORIGIN + i * C_WIDTH, 300);
    }
    for (i = 0; i < NUMBER; i++)
    {
        x = i / COL;
        y = i % COL;
        readimagefile(fileName, ORIGIN + y * C_WIDTH + 2, ORIGIN + x * C_WIDTH + 2, ORIGIN + y * C_WIDTH + C_WIDTH - 2, ORIGIN + x * C_WIDTH + C_WIDTH - 2);
    }
    for (i = 0; i < NUMBER; i++)
    {
        if (chess_items[i].x >= 0)
        {
            drawChess(&chess_items[i]);
        }
    }
}
int getOp(int *x, int *y, chess_item_t chess_items[])
{
    int i = 0, _x = 0, _y = 0;
    if ((*x - ORIGIN) < 0 || (*y - ORIGIN) < 0)
        return INVALID;
    _x = (*y - ORIGIN) / C_WIDTH;
    _y = (*x - ORIGIN) / C_WIDTH;
    (*x) = _x;
    (*y) = _y;
    if (isValid(_x, _y))
    {
        printf("%d,%d\n", _x, _y);
        for (i = 0; i < NUMBER; i++)
        {
            if ((chess_items[i].x == _x) && (chess_items[i].y == _y))
            {
                return i;
            }
        }
        return EMPTY;
    }
    return INVALID;
}
bool playMove(int *choosedId, bool choosed, chess_item_t chess_items[], int x, int y)
{
    if (choosed && (chess_items[*choosedId].display == CHOOSED) && isNeighbor(chess_items[*choosedId].x, chess_items[*choosedId].y, x, y))
    {
        printf("@>%d,choosedId=%d,id.display=%d,x=%d,y=%d\n", choosed, *choosedId, chess_items[*choosedId].display, x, y);
        chess_items[*choosedId].display = CLEAR;
        drawChess(&chess_items[*choosedId]);
        chess_items[*choosedId].x = x;
        chess_items[*choosedId].y = y;
        chess_items[*choosedId].display = NORMAL;
        drawChess(&chess_items[*choosedId]);
        *choosedId = -1;
        choosed = false;
    }
    return choosed;
}
bool playEat(int id, int *choosedId, bool choosed, chess_item_t chess_items[])
{
    if (chess_items[id].display == COVERED)
    {
        if (choosed)
        {
            chess_items[*choosedId].display = NORMAL;
            drawChess(&chess_items[*choosedId]);
        }
        chess_items[id].display = NORMAL;
        drawChess(&chess_items[id]);
        (*choosedId) = id;
        choosed = false;
    }
    else if ((!choosed) && (chess_items[id].display == NORMAL))
    {
        chess_items[id].display = CHOOSED;
        drawChess(&chess_items[id]);
        (*choosedId) = id;
        choosed = true;
    }
    else if (choosed && (chess_items[id].display == NORMAL) && (!isOpposite(&chess_items[*choosedId], &chess_items[id])))
    {
        chess_items[*choosedId].display = NORMAL;
        drawChess(&chess_items[*choosedId]);
        chess_items[id].display = CHOOSED;
        drawChess(&chess_items[id]);
        (*choosedId) = id;
        choosed = true;
    }
    else if (choosed && (chess_items[id].display == NORMAL) && isEat(chess_items, &chess_items[*choosedId], &chess_items[id]))
    {
        chess_items[id].display = CLEAR;
        chess_items[*choosedId].display = CLEAR;
        drawChess(&chess_items[*choosedId]);
        chess_items[*choosedId].x = chess_items[id].x;
        chess_items[*choosedId].y = chess_items[id].y;
        chess_items[*choosedId].display = NORMAL;
        drawChess(&chess_items[*choosedId]);
        chess_items[id].x = chess_items[id].y = -1;
        (*choosedId) = -1;
        choosed = false;
    }
    return choosed;
}
void run()
{
    int x = 0, y = 0, id = 0;
    chess_item_t chess_items[NUMBER];
    bool choosed = false;
    int choosedId = 0;
    initwindow(MAX_X, MAX_Y, "Chess"); // 初始化棋盤
    getData(chess_items);              // 獲取棋子訊息
    game(chess_items);                 // 初始化遊戲
    drawBoard(chess_items);            // 劃出整個版面的圖像
    while (!ismouseclick(WM_LBUTTONDOWN))
    {                                        // 滑鼠監聽，判斷WM_LBUTTONDOWN左鍵是否按下，參考https://home.cs.colorado.edu/~main/bgi/doc/ismouseclick.html
        delay(300);                          // 放慢遊戲速度
        getmouseclick(WM_LBUTTONDOWN, x, y); // 獲取點擊的鼠標座標，調用 getmouseclick（獲取事件的坐標）來處理鼠標事件。
        id = getOp(&x, &y, chess_items);     // 獲取棋子的操作，回傳要動作的棋子
        if (id >= 0)
        {
            printf("%d-choosedId=%d-id=%d-id.display=%d\n", choosed, choosedId, id, chess_items[id].display); // 顯示被選取的棋子，操作模式等訊息
            choosed = playEat(id, &choosedId, choosed, chess_items);
            // printf("%d-choosedId=%d-id=%d\n",choosed, choosedId, id);
        }
        else if ((id == EMPTY) && (choosed))
        {                                                                                                              // 先選取棋子再選取空白處，判斷棋子是否可以移至此的函數
            printf("=>%d-choosedId=%d-id=%d-id.display=%d\n", choosed, choosedId, id, chess_items[choosedId].display); // 顯示被選取的棋子被執行的動作，位移，吃子模式等訊息
            choosed = playMove(&choosedId, choosed, chess_items, x, y);                                                // 移動棋子
        }
    } // 遊戲迴圈
    getch();
    closegraph(); // 關閉視窗
}
int main()
{
    run(); // 呼叫遊戲迴圈
    return 0;
}
