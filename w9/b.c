#include <stdio.h>
typedef enum scoreType_s
{
    G,
    S
} scoreType_t;
typedef enum grade_s
{
    A,
    B,
    C
} grade_t;
typedef union score_s
{
    int score;
    grade_t grade;
} score_t; // 兩種評分選一種
// 印出評分結果
void print(score_t s, scoreType_t t)
{
    char g[] = {'A', 'B', 'C'};
    if (t == G)
    {
        printf("%c\n", g[s.grade]);
    }
    else
    {
        printf("%d\n", s.score);
    }
    printf("\n");
}
int main()
{
    int i = 0;
    score_t student[3];
    scoreType_t type[3];
    char s[] = {'A', 'B', 'C'};
    student[0].score = 90;
    type[0] = S;
    student[1].grade = A;
    type[1] = G;
    student[2].grade = B;
    type[2] = G;
    for (i = 0; i < 3; i++){
        print(student[i], type[i]);
        printf("\n");
    }
}