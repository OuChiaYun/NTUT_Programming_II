#include <stdio.h>

#include <string.h>

#include <stdlib.h>

typedef struct task
{
    int id;
    int time;
    int mec;
} task_t;

typedef struct work
{
    int id;
    int end_time;
    int status;
    int now_p;
    int size;
    int pre_time;
    task_t task[100];
} work_t;

void show_info(work_t work[100], int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < work[i].size; j++)
        {
            printf("%d%d : m%d t%d\n",
                   work[i].id + 1, work[i].task[j].id + 1,
                   work[i].task[j].mec, work[i].task[j].time);
        }
    }
}

int max(int a, int b)
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

void work_ing(work_t work[100], int n, int m, int all_size)
{

    int mech[100] = {0};

    while (all_size > 0)
    {

        int init = 0;
        task_t min;
        int min_day = 0;
        int m_work = 0;
        for (int i = 0; i < m; i++)
        {

            if (work[i].status != 2)
            {
                init = i;
                break;
            }
        }

        min = work[init].task[work[init].now_p];
        min_day =
        max(mech[work[init].task[work[init].now_p].mec],work[init].pre_time) + 
        work[init].task[work[init].now_p].time;
        m_work = init;

        for (int i = 0; i < m; i++)
        {

            if (work[i].status == 2)
            {
                continue;
            }
            int now_p = work[i].now_p;

            int tmp_min = max(work[i].pre_time, 
            mech[work[i].task[now_p].mec]) + work[i].task[now_p].time;

            if (tmp_min < min_day || (tmp_min == min_day && i < init))
            {

                min = work[i].task[now_p];
                min_day = tmp_min;
                m_work = i;
            }
        }

        printf("%d%d => %d:%d\n", m_work + 1, min.id + 1, min.mec, min_day);
        work[m_work].pre_time = min_day;
        mech[min.mec] = min_day;
        work[m_work].now_p++;

        if (work[m_work].now_p >= work[m_work].size && work[m_work].status == 0)
        {

            work[m_work].status = 2;
            work[m_work].end_time = min_day;
        }

        for (int i = 0; i < n; i++)
        {
            printf("m%d => %d  ", i, mech[i]);
        }

        printf("\n");

        all_size--;
    }
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += work[i].end_time;
    }

    printf("  {sum:%d}\n", sum);
}

int main()
{

    int n = 0, m = 0;
    int all_size = 0;
    work_t work[100];
    // n mech /m work

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {

        int p = 0;
        scanf("%d", &p);
        work[i].size = p;
        work[i].id = i;
        for (int j = 0; j < p; j++)
        {

            scanf("%d%d", &work[i].task[j].mec, &work[i].task[j].time);
            all_size++;
            work[i].task[j].id = j;
        }
        work[i].now_p = 0;
    }

    show_info(work, m);

    work_ing(work, n, m, all_size);
}
