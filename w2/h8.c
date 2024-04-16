#include<stdio.h>

int main(){

    char map[3][3][3];

    for(int i = 0;i<3;i++){

        for(int j = 0;j<3;j++){

            scanf("%s",map[i][j]);
        }
    }

    for(int i = 0;i<3;i++){

        for(int j = 0;j<3;j++){
            char c = map[i][j][0];
            printf("%c ",c);
        }
        printf("\n");
    }


}