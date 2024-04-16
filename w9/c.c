#include <stdio.h>
typedef enum scoreType_s
{
    G,
    S,
} scoreType_t;
typedef enum grade_s
{
    Aa,
    A,
    A_,
    Bb,
    B,
    B_,
    Cc,
    C,
    C_,
    F,
    X
} grade_t;
typedef union score_s
{
    int score;
    grade_t grade;
} score_t;
void print(score_t s, scoreType_t t)
{
    char g[] = {'Aa', 'A', 'A_', 'Bb', 'B', 'B_', 'Cc', 'C', 'C_', 'F', 'X'};
    if (t == G)
    {
        printf("%c\n", g[s.grade]);
    }else if (t == G)
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
    for (i = 0; i < 3; i++)
    {
        print(student[i], type[i]);
        printf("\n");
    }
}