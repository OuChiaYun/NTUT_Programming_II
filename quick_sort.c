#include<stdio.h>
#define SWAP(x, y) \
    {              \
        int t;     \
        t = x;     \
        x = y;     \
        y = t;     \
    }
void QuickSort(int data[], int left, int right)
{
    int i, j, target;
    if (left >= right)
        return;
    i = left;
    j = right;
    target = data[left];
    while (i != j)
    {
        while ((data[j] > target) && (i < j))
            j--; // 從右邊開始找
        while ((data[i] <= target) && (i < j))
            i++; // 從左邊開始找
        // 左邊開始找比基準點大,如果有找到又沒與從右邊的相遇
        // 表示 data[i]一定可以換到比較小的
        // 否則 data[i]一定是小的最邊緣,可以跟中間值交換
        if (i <= j)
            SWAP(data[i], data[j]); // 左右沒相遇則可交換
    }
    SWAP(data[left], data[i])      // i是中間值
    QuickSort(data, left, i - 1);  // 處理左半邊
    QuickSort(data, i + 1, right); // 處理右半邊
}

int main(){

    int d[] = {0,6,4,2,5};
    QuickSort(d,0,5);   
    for(int i = 0;i<5;i++){
        printf("%d ",d[i]);
    }

}