#include <stdio.h>
#include <string.h>

void case1(char a[500], char p[500], char q[500])
{

    char s[500] = {' '};
    char *point;

    strcpy(s, a);
    point = strtok(s, " ");

    while (point != NULL)
    {

        if (strcmp(point, p) == 0)
        {
            printf("%s ", q);
        }
        else
        {
            printf("%s ", point);
        }
        point = strtok(NULL, " ");
    }
}

void case2(char a[500], char p[500], char q[500])
{

    char s[500] = {' '};
    char *point;

    strcpy(s, a);
    point = strtok(s, " ");

    while (point != NULL)
    {

        if (strcmp(point, p) == 0)
        {
            printf("%s ", q);
            printf("%s ", point);
        }
        else
        {
            printf("%s ", point);
        }
        point = strtok(NULL, " ");
    }
}

void case3(char a[500], char p[500], char q[500])
{

    char s[500] = {' '};
    char *point;

    strcpy(s, a);
    point = strtok(s, " ");

    while (point != NULL)
    {

        if (strcmp(point, p) != 0)
        {
            printf("%s ", point);
        }
        point = strtok(NULL, " ");
    }
}

void case4(char a[500], char p[500], char q[500])
{

    char s[500] = {' '};
    char *point;

    char map[500][500] = {' '};
    int m = 0;
    int num[500] = {0};
    int k = 0;

    strcpy(s, a);
    point = strtok(s, " ");

    while (point != NULL)
    {
        int flag = 0;

        for (int i = 0; i < m; i++)
        {

            if (strcmp(map[i], point) == 0)
            {
                flag = 1;
                num[i] += 1;
                break;
            }
        }

        if (flag == 0)
        {
            strcpy(map[m], point);
            num[m] = 1;
            m += 1;
        }
        // }
        point = strtok(NULL, " ");
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (num[i] > num[j])
            {
                char tmp[100] = {' '};
                strcpy(tmp, map[i]);
                strcpy(map[i], map[j]);
                strcpy(map[j], tmp);

                int t = num[i];
                num[i] = num[j];
                num[j] = t;
            }
            else if (num[i] == num[j]) //排序
            {
                if (strcmp(map[i], map[j]) < 0)//str1 > str2 1 // str1 < str2 0
                {
                    char tmp[100] = {' '};
                    strcpy(tmp, map[i]);
                    strcpy(map[i], map[j]);
                    strcpy(map[j], tmp);

                    int t = num[i];
                    num[i] = num[j];
                    num[j] = t;
                }
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        printf("%s:%d\n", map[i], num[i]);
    }
}

void case5(char a[500], char p[500], char q[500], int z)
{

    char s[500] = {' '};
    char *point;

    char map[500][500] = {' '};
    int m = 0;
    int num[500] = {0};
    int k = 0;

    char now[100][100] = {' '};
    int no = 0;

    strcpy(s, a);
    point = strtok(s, " ");

    while (point != NULL)
    {

        int flag = 0;

        for (int i = 0; i < m; i++)
        {

            if (strcmp(map[i], point) == 0)
            {
                flag = 1;
                num[i] += 1;
                break;
            }
        }

        if (flag == 0)
        {
            strcpy(map[m], point);
            num[m] = 1;
            m += 1;
        }
        strcpy(now[no], point);
        no++;
        point = strtok(NULL, " ");
    }

    for (int i = 0; i < no; i++)
    {
        int flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (strcmp(now[i], map[j]) == 0)
            {
                if (num[j] < z)
                {
                    flag = 1;
                }
            }
        }
        if (flag == 0)
        {
            printf("%s ", now[i]);
        }
    }
}
int main()
{

    char string[500] = {' '};

    int op1 = 0;
    int op2 = 0;

    char p[500] = {' '};
    char q[500] = {' '};

    scanf(" %[^\n]", string);
    scanf(" %s", p);
    scanf(" %s", q);
    scanf("%d%d", &op1, &op2);

    if (op2 == 1)
    {
        case1(string, p, q);

        printf("\n");
    }

    if (op2 == 2)
    {
        case2(string, p, q);
        printf("\n");
    }

    if (op2 == 3)
    {
        case3(string, p, q);
        printf("\n");
    }

    if (op2 == 4)
    {
        case4(string, p, q);
        printf("\n");
    }

        if (op2 == 5)
    {
        case5(string, p, q,op1);
        printf("\n");
    }

}