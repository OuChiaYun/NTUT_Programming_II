#include <stdio.h>
#include <string.h>

void print_n(int n[],int k) {
    int maxi = 0;

    for(int i = k-1;i>=0;i--){
        if(n[i] !=0 ){
            maxi = i;
            break;
        }
    }

    for(int i = maxi ;i>=0;i--){
        printf("%d",n[i]);
    }   
}

void reset(int n[],int k){
    for (int u = 0;u<k;u++){
        n[u] = 0;
    }
}

void deal(char str[], int n[])
{
    int j = 0;
    for(int i = 0;i<50;i++){
        n[i] = 0;
    }
    for (int i = strlen(str)-1; i >=0 ; i--)
    {
        n[j] = (str[i]-'0');
        // printf("%d",n[j]);
        j++;
    }
    
}

void add(int a[],int b[],int sum[]){
    int carry = 0;

    for(int i = 0;i<50;i++){
        sum[i] = a[i] + b[i] + carry; //進位
        carry = sum[i]/10;
        sum[i] = sum[i]%10; 
    }

}

void sub(int a[],int b[],int sum[]){
    int borrow = 0;

    for(int i = 0;i<50;i++){
        sum[i] = a[i] - b[i] - borrow;
        if(sum[i] <0){
            borrow = 1;
            sum[i] +=10;
        }else{
            borrow = 0;
        }
    }
}

void mul(int a[],int b[],int sum[]){
    for(int i = 0;i<50-1;i++){
        if(b[i] == 0){
            continue;
        }
        for(int j = 0;j<50-1;j++){
            sum[i+j] += a[j]*b[i]; 
            // printf("%d ",sum[i]);
        }
    }

    int carry = 0;

    for(int i = 0;i<100;i++){
        sum[i] =sum[i]+carry;
        carry = sum[i]/10;
        sum[i] = sum[i]%10;
        
    }
}

int main()
{

    char str1[50] = {' '};
    char str2[50] = {' '};
    int n1[50] = {0};
    int n2[50] = {0};
    int sum[100] = {0};
    scanf("%s",str1);
    scanf("%s",str2);
    reset(n1,50);
    reset(n2,50);
    reset(sum,100);
    deal(str1, n1);
    deal(str2, n2);

    mul(n1,n2,sum);

    print_n(sum,100);
    printf("\n");
}