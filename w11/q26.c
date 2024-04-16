#include <stdio.h>

typedef struct WORK
{
    int p;
    int point;
    int pre;
    int mid[100];
    int time[100];
} work;

int ismax(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void putIn(work work[150], int mech_n, int work_n, int all_work)
{

    int mech[200] = {0};
    int big = 0;

    for (int i = 0; i < all_work; i++)
    {

        int init = 0;
        while (work[init].point >= work[init].p)
        {
            init++;
        }
        // printf("inti = %d ",init);
        int p = work[init].point;
        int k = work[init].mid[p];
        big = ismax(mech[k], work[init].pre);
        int min = work[init].time[p] + mech[k] + big;
        int min_index = init;

        for (int j = 0; j < work_n; j++)
        {
            p = work[j].point;
            k = work[j].mid[p];
            big = ismax(mech[k], work[j].pre);
            int tmp_min = work[j].time[p] + big;

            if ((tmp_min < min) && (p < work[j].p))
            {

                min = tmp_min;
                min_index = j;
            }
        }
        p = work[min_index].point;
        k = work[min_index].mid[p];

        mech[k] = min;

        work[min_index].pre = mech[k];
        work[min_index].point++;
    }
    int f = 0;
    for (int i = 0; i < work_n; i++)
    {
        f += work[i].pre;
    }
    printf("%d ", f);
}

int main()
{
    int n = 0;
    int m = 0;
    int info = 0;
    int count = 0;
    work work[150];

    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &info);
        work[i].p = info;
        work[i].point = 0;
        count += info;
        for (int j = 0; j < info; j++)
        {
            scanf("%d%d", &work[i].mid[j], &work[i].time[j]);
        }
    }

    putIn(work, n, m, count);
}