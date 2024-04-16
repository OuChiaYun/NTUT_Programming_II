#include <stdio.h>
#include <string.h>
#include <math.h>

typedef enum scoreType_s
{
    G,
    GPA,
    S
} scoreType_t;

typedef enum grade_g
{
    AA,
    A,
    A_,
    BB,
    B,
    B_,
    CC,
    C,
    C_,
    F,
    X

} grade_gt;
typedef union score_s
{
    int score;
    grade_gt grade;
} score_t;

typedef struct student_s
{
    char id[20];
    double avg;
    score_t student[7];
    scoreType_t type[7];
} student_data;

void swap(student_data *s1, student_data *s2)
{

    float t = s2->avg;
    s2->avg = s1->avg;
    s1->avg =t;

    char g[20 ];
    strcpy(g,s1->id);
    strcpy(s1->id,s2->id);
    strcpy(s2->id,g);

}

void print(student_data s[15], int k, int t)
{
    int test[] = {95, 87, 82, 78, 75, 70, 68, 65, 60, 50, 0};
    for (int i = 0; i < t; i++)
    {
        // printf("%s\n", s[i].id);
        double a = 0;
        for (int j = 0; j < k; j++)
        {

            a += test[s[i].student[j].grade];
            // printf("===> %d",test[s[i].student[j].grade]);
        }
        s[i].avg = a / k;
        // printf("=>%d\n",y);
    }

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {

            if (s[i].avg < s[j].avg)
            {

                swap(&s[i],&s[j]);
            }
        }
    }

    for(int i = 0;i<t;i++){

        int y = round(s[i].avg);
        printf("%s %d\n",s[i].id,y);
    }
}
void test()
{
    student_data data[15];
    int state[14] = {AA, A, A_, BB, B, B_, CC, C, C_, F, X};
    char score_[3][12][10] =
        {{"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "F", "X"},
         {"4.3", "4.0", "3.7", "3.3", "3.0", "2.7", "2.3", "2.0", "1.7", "1", "0"},
         {"90-100", "85-89", "80-84", "77-79", "73-76", "70-72", "67-69", "63-66", "60-62", "1-59", "0"}};

    char type[4][5] = {"G", "GPA", "S"};
    int type_s[4] = {G, GPA, S};
    int tt[10] = {0, 0, 0, 0, 0, 0, 0};
    int k = 0;
    int t = 0;

    scanf("%d", &k);

    for (int i = 0; i < k; i++)
    {
        char str[10];
        scanf(" %s", str);
        int j = 0;
        // printf("str = %s", str);
        for (j = 0; j < 3; j++)
        {
            if (strcmp(type[j], str) == 0)
            {
                break;
            }
        }

        tt[i] = type_s[j];
        // printf("cewds");
    }
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%s", data[i].id);
        for (int j = 0; j < k; j++)
        {
            data[i].type[j] = type_s[tt[j]];
            char c[10];
            scanf("%s", c);
            for (int m = 0; m < 12; m++)
            {
                if (strcmp(score_[tt[j]][m], c) == 0)
                {
                    // printf("==> %s",score_[tt[j]][m]);
                    data[i].student[j].grade = state[m];

                    // printf("%d %d\n",state[m],m);
                    // printf("%s %s",c,score_[tt[j]][m]);
                    break;
                }
            }
        }
        // printf("==>%d %d %d\n",data[i].id,data[i].type[0],data[i].student[0].grade);
    }

    print(data, k, t); // k kind tnumber
}

int main()
{

    test();
}