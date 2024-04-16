#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_N 3
#define INF 0x3f3f3f3f

int minValue(int x,int y){return (x>y?y:x);}

int Rec(int R[][1<<MAX_N],int d[][MAX_N],int v, int S,int n){
    int t = 0;
    int ans = INF;
    if(R[v][S] >= 0){return R[v][S];}
    printf("%d ",S>>0&1);
    for(int i = 0;i<n;i++){
        if(!(S>>i&1)){
            t = Rec(R,d,i,S|(1<<i),n);
            ans = minValue(ans,d[v][i]+t);
        }
    }  
    return R[v][S] = ans;  
}

void solve(){
    int v =0,S=(0|1<<v);

    int R[MAX_N][1<<MAX_N];
    int d[MAX_N][MAX_N]={
        {0,6,9},
        {6,0,3},
        {9,3,0}
    }; 
    

    memset(R,-1,sizeof(R));
    for(int i = 0;i<MAX_N;i++){
        R[i][(1<<MAX_N)-1] = d[i][0];
    }
    printf("%d\n",Rec(R,d,v,S,MAX_N));
    printf("%d\n %d\n",R[1][3],R[2][5]);
}

int main(){
    solve();
}