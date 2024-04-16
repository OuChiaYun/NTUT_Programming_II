#include <stdio.h>

typedef struct Work
{

    int prework[100];
    int pre_size;
    int day;
    int id;
    int statue;
} WORK;

void task_print(WORK work[100], int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("id:%d day:%d  presize:%d st:%d\n", work[i].id + 1, work[i].day, work[i].pre_size, work[i].statue);
        printf("  ");
        for (int j = 0; j < work[i].pre_size; j++)
        {
            printf("id : %d status:%d ", work[i].prework[j]+1,work[j].statue);
        }
        printf("\n");
    }
    printf("\n");
}

void task_line(WORK work[100], int m)
{
    int all_time = 0;


    while (1)
    {
        for(int i = 0;i<m;i++){
            if(work[i].statue == 0){
                int flag = 0;
                for(int j = 0;j<work[i].pre_size;j++){
                    if(work[work[i].prework[j]].statue== 2){ //先檢測前面所有status狀態
                        flag++;
                    }
                }
                if(flag == work[i].pre_size){
                    work[i].statue = 1;
                    work[i].day --;
                }
            }else if (work[i].statue == 1){
                work[i].day --;
            }
        }

        int ok = 0;

        for(int i = 0;i<m;i++){
            if(work[i].day == 0){
                work[i].statue = 2;
            }
            if(work[i].statue != 2){
                ok =1;
            }
        }
        all_time++;
        if(ok ==0){
            break;
        }

    }
    printf("%d\n",all_time);
}

int main()
{

    int n = 0;
    int m = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        WORK work[100];
        scanf("%d", &m);
        for (int j = 0; j < 100; j++)
        {
            for (int h = 0; work[j].pre_size; h++)
            {
                work[j].prework[h] = 0;
            }
            work[j].day = 0;
            work[j].id = 0;
            work[j].pre_size = 0;
            work[j].statue = 1;
        }

        for (int j = 0; j < m; j++)
        {

            work[j].id = j;
            int tmp_back_size = 0;

            scanf("%d%d", &work[j].day, &tmp_back_size);

            for (int k = 0; k < tmp_back_size; k++)
            {
                int id = 0;
                scanf("%d", &id);
                work[id - 1].prework[work[id - 1].pre_size] = j;
                work[id - 1].statue = 0;
                work[id - 1].pre_size++;
                
            }
        }

        task_line(work, m);
        printf("\n");
    }
}