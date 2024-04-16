#include "chess.h"
void init(chess_item_t chess_items[]) {
    int i=0;
    for (i=0; i<NUMBER; i++) {
        chess_items[i].id = i;
        chess_items[i].level = CHESS_LEVEL[i];
        strcpy(chess_items[i].name, CHESS_NAME[i]);
        chess_items[i].x = -1;
        chess_items[i].y = -1;
        chess_items[i].display = COVERED;
    }
}
void print(chess_item_t chess_items[]) {
    int i=0;
    for (i=0; i<NUMBER*2; i++) {
        printf("%d, %d, %s", chess_items[i].id, chess_items[i].level, chess_items[i].name); //印出旗子id，旗子等級，棋子名字
        printf("(%d, %d)\n", chess_items[i].x, chess_items[i].y); //印出此棋子的xy座標
    }
}
bool isOpposite(chess_item_t *x, chess_item_t *y) {
     if ((x->id>=0)&&(x->id<=15)&&(y->id>=16)&&(y->id<=31)) return true;
     if ((x->id>=16)&&(x->id<=31)&&(y->id>=0)&&(y->id<=15)) return true;
     return false;
}
bool isNeighbor(int x1, int y1, int x2, int y2) {
   if ((x1==x2)&&(abs(y1-y2)==1)) return true;
   if ((y1==y2)&&(abs(x1-x2)==1)) return true;
   return false;
}
bool isNeighborItem(chess_item_t *x, chess_item_t *y) {
   return isNeighbor(x->x, x->y, y->x, y->y); //呼叫函式isNeighbor()，傳入物件座標來判斷物件是否相鄰
}
bool isOneItemRow(chess_item_t chess_items[], int x, int y1, int y2) {
    int i=0, count=0;
    if (y1>y2) {i=y1; y1=y2; y2=i;}
    for (i=0; i<NUMBER; i++) {
        if ((chess_items[i].x==x)&&(chess_items[i].y>y1)&&(chess_items[i].y<y2))
            count++;
    }
    if (count==1) return true;
    else return false;
}
bool isOneItemCol(chess_item_t chess_items[], int y, int x1, int x2) {
    int i=0, count=0;
    if (x1>x2) {i=x1; x1=x2; x2=i;}
    for (i=0; i<NUMBER; i++) {
        if ((chess_items[i].y==y)&&(chess_items[i].x>x1)&&(chess_items[i].x<x2))
            count++;
    }
    if (count==1) return true;
    else return false;
}
bool isCannonEat(chess_item_t chess_items[], chess_item_t *x, chess_item_t *y) {
    if ((x->x==y->x)&&isOneItemRow(chess_items, x->x, x->y, y->y)) return true;
    if ((x->y==y->y)&&isOneItemCol(chess_items, x->y, x->x, y->x)) return true;
    return false;
}
bool isEat(chess_item_t chess_items[], chess_item_t *x, chess_item_t *y) {
    if (isOpposite(x,y)&&isNeighborItem(x, y)) {
        if (x->level==King) {
            if (y->level!=Pawn) return true;
        }
        else if (x->level==Pawn) {
            if (y->level==General) return true;
            if (y->level==Pawn) return true;
        }
        else if(x->level<=y->level) return true;
    }
    if (isOpposite(x,y)) {
        if (x->level==Cannon) {
            return (isCannonEat(chess_items, x, y));
            if ((x->x==y->x)&&(abs(x->y - y->y)==2)) return true;
            if ((abs(x->x - y->x)==2)&&(x->y==y->y)) return true;
        }
    }
    return false;
}
void getData(chess_item_t chess_items[]) {
    chess_items[0].x=0; chess_items[0].y=0;
    chess_items[16].x=1;chess_items[16].y=1;
    chess_items[15].x=0;chess_items[15].y=1;
    chess_items[26].x=1;chess_items[26].y=0;
    chess_items[27].x=0;chess_items[27].y=2;
    chess_items[7].x=1; chess_items[7].y=2;
    chess_items[9].x=2; chess_items[9].y=1;
    chess_items[8].x=2; chess_items[8].y=0;
    chess_items[20].x=2;chess_items[20].y=2;
}
chess_item_t* getItem(chess_item_t chess_items[], int x, int y) {
     int i=0;
     for (i=0; i<NUMBER; i++) {
         if ((chess_items[i].x==x) &&(chess_items[i].y==y)) {
             break;
         }
     }
     return (&chess_items[i]);
}
bool isValid(int x, int y) {
    if (x>=0 && x<ROW && y>=0 && y<COL) return true;
    return false;
}
void eat(chess_item_t chess_items[], int x1, int y1, int x2, int y2) {
    chess_item_t *item_x, *item_y;
    if (isValid(x1, y1)&&isValid(x2, y2)) {
       item_x=getItem(chess_items, x1  ,y1);
       item_y=getItem(chess_items, x2  ,y2);
       //printf("%s(%d,%d)\n", item_x->name, item_x->x, item_x->y);
       //printf("%s(%d,%d)\n", item_y->name, item_y->x, item_y->y);
       if (isEat(chess_items, item_x, item_y)) {
           printf("==>%s(%d,%d)", item_x->name, item_x->x, item_x->y);
           printf("->%s(%d,%d)\n", item_y->name, item_y->x, item_y->y);
       }
    }
}
void checkEat(chess_item_t chess_items[]) {
    int i=0, j=0;
    for (i=0; i<NUMBER; i++) {
        for (j=0; j<NUMBER; j++) {
            eat(chess_items, i/ROW, i%ROW, j/COL,j%COL);
        }
    }
}
void game(chess_item_t chess_items[NUMBER]) {
    init(chess_items);
    getData(chess_items);
    checkEat(chess_items);
}
