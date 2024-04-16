#include <stdio.h>

#define START 0
#define VH 1
#define VB 2
#define VAR 3
#define IH 4
#define IB 5
#define INT 6
#define FH 7
#define FB 8
#define FF 9
#define FLO 10
#define PH 11
#define PB 12
#define PT 13
#define PF 14
#define PRO 15
#define AH 16
#define AB 17
#define ALG 18
#define PG 19
#define ERROR 100
// wrong name ,ALG == proper fraction,PRO == algebraic fraction

int getState(int state, char key)
{

    if (state == START && ((key >= 'a' && key <= 'z') || key == '_' || (key >= 'A' && key <= 'Z')))
    {
        return VH;
    }
    else if (state == START && key >= '1' && key <= '9')
    {
        return IH;
    }
    else if (state == START && key == '0')
    {
        return FH;
    }
    else if (state == VH && ((key >= 'a' && key <= 'z') || key == '_' || (key >= 'A' && key <= 'Z') || (key >= '0' && key <= '9')))
    {
        return VB;
    }
    else if (state == VH && (key == '\0'))
    {
        return VAR;
    }
    else if (state == VB && ((key >= 'a' && key <= 'z') || key == '_' || (key >= 'A' && key <= 'Z') || (key >= '0' && key <= '9')))
    {
        return VB;
    }

    else if (state == VB && key == '\0')
    {
        return VAR;
    }

    else if (state == IH && (key >= '0' && key <= '9'))
    {
        return IB;
    }

    else if (state == IH && key == '.')
    {
        return FB;
    }
    else if (state == IH && key == '\0')
    {
        return INT;
    }

    else if (state == IB && (key >= '0' && key <= '9'))
    {
        return IB;
    }

    else if (state == IB && (key == '.'))
    {
        return FB;
    }

    else if (state == IB && key == '\0')
    {
        return INT;
    }

    else if (state == FH && key == '.')
    {
        return FB;
    }
    else if (state == FH && key == '\0')
    {
        return INT;
    }
    else if (state == FB && (key >= '0' && key <= '9'))
    {
        return FF;
    }

    else if (state == FF && (key >= '0' && key <= '9'))
    {
        return FF;
    }
    else if (state == FF && key == '\0')
    {
        return FLO;
    }
    //

    else if (state == IH && key == '/')
    {
        return AH;
    }

    else if (state == AH && key >= '1' && key <= '9')
    {
        return AB;
    }

    else if (state == AB && key >= '0' && key <= '9')
    {
        return AB;
    }

    else if (state == AB && key == '\0')
    {
        return ALG;
    }
    else if (state == IB && key == '/')
    {
        return AH;
    }
    // else if(state == FH && key == '('){
    //     return PH;
    // }

    //

    else if (state == IH && key == '(')
    {
        return PH;
    }
    else if (state == PH && key >= '1' && key <= '9')
    {
        return PB;
    }
    else if (state == PB && key >= '0' && key <= '9')
    {
        return PB;
    }
    else if (state == PB && key == '/')
    {
        return PT;
    }
    else if (state == PT && key >= '1' && key <= '9')
    {
        return PF;
    }
    else if (state == PF && key >= '0' && key <= '9')
    {
        return PF;
    }
    else if (state == PF && key == ')')
    {
        return PG;
    }

    else if (state == PG && key == '\0')
    {
        return PRO;
    }
    else if (state == IB && key == '(')
    {
        return PH;
    }
    // else if(state == FH && key == '/'){
    //     return AH;
    // }
    else
    {
        if (key == '\0')
        {
            return state;
        }
        return ERROR;
    }
    // no PRO ALG
}

int main()
{

    int n = 0;
    scanf("%d", &n);
    int state = 0;
    long long int a, b = 0;
    int flag = 0;

    // int cflag = 0;
    // int k = 0;

    for (int i = 0; i < n; i++)
    {
        a = 0;
        b = 0;
        flag = 0;

        state = 0;
        char arr[50] = {' '};
        scanf("%s", arr);

        for (int j = 0; j < 25; j++)
        {

            state = getState(state, arr[j]);


            if (arr[j] == '/'|| arr[j]=='.')
            {
                flag = 1;
            }else if (flag == 1 && arr[j]!= '\0' &&arr[j]!= ')')
            {
                b = 10 * b + (arr[j] - '0');
            }

            if (arr[j] == '(')
            {
                a = 0;

            }else if (flag == 0)
            {
                a = 10 * a + (arr[j] - '0');
            }
            // printf("u %d\n",(arr[j] - '0'));
            // printf("a %d ,b %d \n", a, b);
        }

        if (state == ERROR)
        {
            printf("error\n");
        }

        else if (state == FLO)
        {
            printf("float\n");
            printf("%lld\n%lld\n",a,b);
            // printf("%s\n%s\n",c,d);
        }

        else if (state == INT)
        {
            printf("integer\n");
        }
        else if (state == VAR)
        {
            printf("variable\n");
        }
        else if (state == ALG && a<b)
        {
            printf("proper fraction\n");
        }
        else if (state == PRO&&a<b)
        {
            printf("algebraic fraction\n");
        }
        else
        {
            printf("error\n");
        }
        // printf("%s %s\n",c,d);
    }
}