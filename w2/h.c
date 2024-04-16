#include<stdio.h>

int main(){
    //1
    // int i = 4,*p = &i,*q = &i;

    // printf("%d %d\n",*p,*&i);
    // i+=(*q)*(*p);
    // printf("%d %d\n",i,q);

    // 4,4,20,20

//3
    // double i = 4,j = 6,*p = &j,*q = &i,*r;
    // printf("%f %f \n",*p,*q);
    // r = p;
    // p = q;
    // q = r;
    // printf("%f %f\n",*p,*q);


    // int i = 4,j ,number=3,*p = &number;

    // for(j = 0;j<number;j++){
    //     // printf("%d ",i);
    //     (*p)+= i--;
    //     // printf("\n%d \n",*p);
    //     // printf("%d.",i);
    //     //3+4= 7
    //     //7+3 = 10
    //     //10+2 = 12
    //     //12+1 = 13
    //     //13+0 = 0
    //     // 13+ -1 = 12
    //     //12+-2 = 10
    //     //10 - 3 = 7

    // }

    int i ,j=21,*p = &j,*q=p;
    printf("%d %d\n",*p,*q);
    for(i = 0;i<4;i++){
        *(p++);
    (*q++);
    }

    printf("%d %d %d",*p,*q,i);

    printf("%d %d %d %d\n",*p,number,j,i);




}