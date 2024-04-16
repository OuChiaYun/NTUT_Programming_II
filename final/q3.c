#include <stdio.h>

typedef struct task
{

    int id; //work's task id
    int need_mech;
    int time; //work's task

} task_t;

typedef struct work
{

    int id; //work id
    int size;
    int now_p;
    int pre_workday;
    int status;
    int end; //work
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

void working(work_t work[100], int m, int n, int size)
{

    int mech[100] = {0};
    int ok = 0;
    int g = 0;
    while (size > 0)
    {
        int init = 0;
        while (1)
        {
            if (work[init].status == 2)
            {
                init++;
            }
            else
            {
                break;
            }
        } //set init work
        g++;

        int point = work[init].now_p;
        int p_day = work[init].task[point].time;
        int p_mech = work[init].task[point].need_mech;
        int min = max(work[init].pre_workday, mech[p_mech]) + p_day;
        int n_time = 0;
        int m_id = point;
        int m_work = init;
        int m_need_m = p_mech; //set first min work

        for (int i = 0; i < m; i++)
        {
            if (work[i].status == 2)
            {
                continue;
            } //if is ok, next one
            point = work[i].now_p;
            p_day = work[i].task[point].time;
            p_mech = work[i].task[point].need_mech;
            n_time = max(work[i].pre_workday, mech[p_mech]) + p_day; //find min day

            if (n_time < min || (n_time == min && i < m_work))
            {

                min = n_time;
                m_work = i;
                m_need_m = work[i].task[point].need_mech;
                m_id = work[i].now_p; //store info
            }
        }

        work[m_work].pre_workday = min;
        mech[m_need_m] = min; //update new tiem
        work[m_work].now_p++;

        if (work[m_work].now_p >= work[m_work].size && work[m_work].status != 2)
        {
            work[m_work].status = 2;
            work[m_work].end = min; //save min time
        }

        size--;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {

        sum += work[i].end;
    }
    printf("%d\n",sum);
}
int main()
{

    int n, m;

    work_t work[200];

    scanf("%d%d", &n, &m); //set n mechime n work

    int all_task = 0;

    for (int i = 0; i < m; i++)
    {
        int k = 0;
        scanf("%d", &k); //a work have how many task
        work[i].size = k;
        work[i].id = i;
        work[i].now_p = 0;
        for (int j = 0; j < k; j++)
        {

            scanf("%d%d", &work[i].task[j].need_mech, &work[i].task[j].time); //set task mech & time
            work[i].task[j].id = j;
            all_task++;
        }
    }

    print_time(work, m); //print info
    working(work, n, m, all_task);
}
