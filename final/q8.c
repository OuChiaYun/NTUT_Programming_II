#include <stdio.h>
#include <string.h>

typedef struct Work
{

    int prework[100];
    int pre_size;
    int day;
    int id;
    int statue;
} WORK;

void print_list(WORK Work[100], int n)
{

    for (int i = 0; i < n; i++)
    {

        printf("%d =>\n", Work[i].id);

        for (int j = 0; j < Work[i].pre_size; j++)
        {
            printf("%d ,", Work[i].prework[j]);
        }
        printf("\n");
    }
}

void working(WORK work[100], int n)
{

    int all_time = 0;

    while (1)
    {
        for (int i = 0; i < n; i++)
        {

            if (work[i].statue == 0)
            {
                int flag = 0;
                for (int j = 0; j < work[i].pre_size; j++)
                {
                    if (work[work[i].prework[j]].statue == 2) //檢測前面是否都已執行完成
                    {
                        flag++;
                    }
                }

                if (flag == work[i].pre_size) //執行完的話改變狀態
                {
                    work[i].statue = 1;
                    work[i].day--;//並扣除天數
                }
            }
            else if (work[i].statue == 1) 
            {
                work[i].day--;
            }
        }

        int ok = 0;
        for (int i = 0; i < n; i++)
        {

            if (work[i].day == 0)
            {
                work[i].statue = 2;
            } // 順序不可調換，因為需要立刻停止
            if (work[i].statue != 2)
            {
                ok = 1;
            }
        }

        all_time++;
        if (ok == 0)
        {
            break;
        }
    }

    printf("{%d}", all_time);
}

int main()
{

    int n = 0;
    WORK work[100];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int h = 0; h < work[i].pre_size; h++)
        {
            work[i].prework[h] = 0;
        }
        work[i].day = 0;
        work[i].id = 0;
        work[i].pre_size = 0;
        work[i].statue = 1;
    } // 先init

    for (int i = 0; i < n; i++)
    {

        int time = 0;
        int k;

        scanf("%d", &time);
        work[i].id = i;
        work[i].day = time;
        work[i].statue = 0;
        scanf("%d", &k);

        for (int j = 0; j < k; j++)
        {
            int id = 0;
            scanf("%d", &id);

            work[id - 1].prework[work[id - 1].pre_size] = i;
            work[id - 1].pre_size++;
            work[id - 1].statue = 0;
        }
    }

    print_list(work, n);
    working(work, n);
}