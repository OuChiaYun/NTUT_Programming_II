#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define NUMBER 32
#define COL 8
#define ROW 4
#define MAX_X 800
#define MAX_Y 600
#define ORIGIN 100
#define C_WIDTH 50
#define EMPTY   -1
#define INVALID -2

typedef enum {COVERED,NORMAL,CHOOSED, CLEAR} display_t;
typedef enum {General=10, Guard, Elephant, Rook, Horse, Bom, Pawn} black_level_t;
typedef enum {King=10, Assistant, Bishop, Chariot, Knight, Cannon, Soldier} red_level_t;
//typedef enum {false=0, true=1} bool;
const char CHESS_NAME[][10]={"General","Guard","Guard","Elephant","Elephant","Rook","Rook",
                              "Horse","Horse","Bom","Bom","Pawn","Pawn","Pawn","Pawn","Pawn",
                             "King","Assistant","Assistant","Bishop","Bishop","Chariot","Chariot",
                             "Knight","Knight","Cannon","Cannon","Soldier","Soldier","Soldier","Soldier","Soldier"};
const int CHESS_LEVEL[]={General,Guard,Guard,Elephant,Elephant,Rook,Rook,Horse,Horse,
                              Bom,Bom,Pawn,Pawn,Pawn,Pawn,Pawn,
                         King,Assistant,Assistant,Bishop,Bishop,Chariot,Chariot,Knight,Knight,
                              Cannon,Cannon,Soldier,Soldier,Soldier,Soldier,Soldier};
//const int CHESS_ID[]={101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,
//                      201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216};
typedef struct check_item {
    int id;
    int level;
    char name[10];
    int x, y;
    display_t display;
} chess_item_t;
void init(chess_item_t chess_items[]);
void print(chess_item_t chess_items[]);
bool isNeighbor(int x1, int y1, int x2, int y2);
bool isOpposite(chess_item_t *x, chess_item_t *y);
bool isNeighborItem(chess_item_t *x, chess_item_t *y);
bool isEat(chess_item_t chess_items[], chess_item_t *x, chess_item_t *y);
void getData(chess_item_t chess_items[]);
chess_item_t* getItem(chess_item_t chess_items[], int x, int y);
bool isValid(int x, int y);
void eat(chess_item_t chess_items[], int x1, int y1, int x2, int y2);
void checkEat(chess_item_t chess_items[]);
void game(chess_item_t chess_items[NUMBER]);

void drawBoard(chess_item_t chess_items[NUMBER]);
