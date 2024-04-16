#include<iostream>
#include<vector>

using namespace std;

int main(){

    
    vector<int>a;
    vector<int*>b;
    int k = 0;
    a.push_back(k);
    b.push_back(&a[0]);
    b.push_back(&a[0]);
    a.push_back(*b[0]);
    b.push_back(&a[1]);
    printf("%p %p %p %p %p %p",&k,&a[0],b[0],b[1],&a[1],b[2]);

}