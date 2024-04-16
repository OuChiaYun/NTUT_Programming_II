#include <stdio.h>
void print(int a[], int n)
{ // 印出陣列a[0]~a[n-1]
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void copy(int C[], int a[], int m, int n)
{ // 將陣列C[m~n]複製到陣列a[m~n]
    for (int i = m; i <= n; i++)
        a[i] = C[i];
}
void merge(int C[], int A[], int am, int an, int B[], int bm, int bn)
{
    int k = am; // 將陣列 A[am~an], B[bm~bn]合併成 C[am~]
    while ((am <= an) && (bm <= bn))
    {
        if (A[am] <= B[bm])
            C[k++] = A[am++];
        else
            C[k++] = B[bm++];
    }
    while (am <= an)
        C[k++] = A[am++];
    while (bm <= bn)
        C[k++] = B[bm++];
}

void mergeSort(int a[], int m, int n)
{ // 合併排序主程式,遞迴
    int mid = 0, C[20];
    if (n > m)
    { // 陣列a長度大於1,可以切成兩塊
        mid = (m + n) / 2;
        mergeSort(a, m, mid);               // 切前半段 a[m~mid]
        mergeSort(a, mid + 1, n);           // 切後半段 a[mid+1~n]
        printf("\nm=%d, n=%d\n", m, n);     // 印出a處理範圍 m, n
        merge(C, a, m, mid, a, mid + 1, n); // 合併a前半段與後半段 到 陣列 C
        copy(C, a, m, n);                   // 將合併後的 C 再複製回 a
        print(a, 7);
    }
}
int main()
{
    int a[] = {34, 12, 30, 18, 78, 56, 25};
    mergeSort(a, 0, 6);
    return 0;
}