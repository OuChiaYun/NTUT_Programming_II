#include <stdio.h>

typedef struct task
{

    int id;
    int need_mech;
    int time;

} task_t;

typedef struct work
{

    int id;
    int size;
    int now_p;
    int pre_workday;
    int status;
    int end;

    task_t task[100];
} work_t;

void print_time(work_t work[100], int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("=>%d\n", i);
        for (int j = 0; j < work[i].size; j++)
        {
            printf("%d : %d => %d\n",
                   work[i].task[j].id, work[i].task[j].need_mech,
                   work[i].task[j].time);
        }

        printf("\n");
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
        a <= b;
        return b;
    }
}

void working(work_t work[100], int n, int m, int size)
{
    // n = mechine

    int mech[100] = {0};

    while (size > 0)
    {

        int init = 0;

        for (int i = 0; i < m; i++)
        {
            if (work[i].status != 2)
            {
                init = i;
                break;
            }
        }

        int m_point = work[init].now_p;
        int m_day = mech[work[init].task[m_point].need_mech];
        int m_pre_time = work[init].pre_workday;
        int m_work_day = work[init].task[m_point].time;
        int m_work = init;
        int min = max(m_day, m_pre_time) + m_work_day;

        for (int i = 0; i < m; i++)
        {
            if(work[i].status==2){
                continue;
            }
            int tmp_point = work[i].now_p;

            int tmp_mech = work[i].task[tmp_point].need_mech;
            int tmp_mech_t = mech[tmp_mech];
            int tmp_time = work[i].task[tmp_point].time;
            int tmp_pre = work[i].pre_workday;

            int tmp_min = max(tmp_mech_t, tmp_pre) + tmp_time;

            if (tmp_min < min || (tmp_min == min && tmp_point < m_point))
            {
                min = tmp_min;
                m_point = tmp_point;
                m_day = tmp_mech_t;
                m_pre_time = tmp_pre;
                m_work_day = tmp_time;
                m_work = i;
            }
        }

        mech[work[m_work].task[m_point].need_mech] = min;
        work[m_work].pre_workday = min;
        work[m_work].now_p += 1;

        if ((work[m_work].now_p>=work[m_work].size) && (work[m_work].status == 0))
        {

            work[m_work].status = 2;
            work[m_work].end = min;
        }
        size--;
    }
    int sum = 0;
    for (int i = 0; i < m; i++)
    {

        sum += work[i].end;
    }
    printf("%d\n", sum);
}
int main()
{

    int n, m;

    work_t work[200];

    scanf("%d%d", &n, &m);

    int all_task = 0;

    for (int i = 0; i < m; i++)
    {
        int k = 0;
        scanf("%d", &k);
        work[i].size = k;
        work[i].id = i;
        work[i].now_p = 0;
        for (int j = 0; j < k; j++)
        {

            scanf("%d%d", &work[i].task[j].need_mech, &work[i].task[j].time);
            work[i].task[j].id = j;
            all_task++;
        }
    }

    // print_time(work, m);
    working(work, n, m, all_task);
}
