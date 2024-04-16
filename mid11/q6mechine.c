#include <stdio.h>
#include <string.h>

#define START 0
#define VA 1
#define VB 2
#define VARIABLE 9

#define IA 11
#define IB 12
#define INTERGER 19

#define FA 21
#define FB 22
#define FC 23
#define FLOAT 29

#define PA 31
#define PB 32
#define PC 33
#define PROPER 39

#define AA 41
#define AB 42
#define AC 43
#define AD 44
#define AE 45
#define AF 46
#define AG 47
#define ALGEBRAIC 49

int getState(char key, int state)
{
    if (state == START)
    {
        if ((key == '_') || (key >= 'A' && key <= 'z'))
        {
            return VA;
        }

        if (key >= '1' && key <= '9')
        {
            return IA;
        }

        if (key == '0')
        {
            return FA;
        }
    }
    if (state == VA)
    {
        if ((key == '_') || (key >= 'A' && key <= 'z') || (key >= '0' && key <= '9'))
        {
            return VB;
        }
    }
    if (state == VB)
    {
        if ((key == '_') || (key >= 'A' && key <= 'z') || (key >= '0' && key <= '9'))
        {
            return VB;
        }
        if (key == '\0')
        {
            return VARIABLE;
        }
    }

    if (state == IA)
    {
        if (key >= '0' && key <= '9')
        {
            return IB;
        }

        if (key == '.')
        {
            return FB;
        }

        if (key == '/')
        {
            return PA;
        }
        if (key == '(')
        {
            return AA;
        }
    }

    if (state == IB)
    {
        if (key >= '0' && key <= '9')
        {
            return IB;
        }
        if (key == '.')
        {
            return FB;
        }
        if (key == '/')
        {
            return PA;
        }
        if (key == '(')
        {
            return AA;
        }
    }

    if (state == FA)
    {
        if (key == '.')
        {
            return FB;
        }
    }

    if (state == FB)
    {
        if (key >= '0' && key <= '9')
        {
            return FC;
        }
    }
    if (state == FC)
    {
        if (key >= '0' && key <= '9')
        {
            return FC;
        }
        if(key == '\0'){
            return FLOAT;
        }
    }

    if (state == PA)
    {
        if (key >= '1' && key <= '9')
        {
            return PB;
        }
    }
    if (state == PB)
    {
        if (key >= '0' && key <= '9')
        {
            return PC;
        }
    }

    if (state == PC)
    {
        if (key >= '0' && key <= '9')
        {
            return PC;
        }

        if (key == '\0')
        {
            return PROPER;
        }
    }

    if (state == AA)
    {
        if (key >= '1' && key <= '9')
        {
            return AB;
        }
    }
    if (state == AB)
    {
        if (key >= '0' && key <= '9')
        {
            return AC;
        }
        if (key == '/')
        {
            return AD;
        }
    }
    if (state == AC)
    {
        if (key >= '0' && key <= '9')
        {
            return AC;
        }

        if (key == '/')
        {
            return AD;
        }
    }

    if (state == AD)
    {
        if (key >= '1' && key <= '9')
        {
            return AE;
        }
    }

    if (state == AE)
    {
        if (key >= '0' && key <= '9')
        {
            return AF;
        }
        if (key == ')')
        {
            return AG;
        }
    }
    if (state == AF)
    {
        if (key >= '0' && key <= '9')
        {
            return AF;
        }
        if (key == ')')
        {
            return AG;
        }
    }

    if (state == AG)
    {
        if (key == '\0')
        {
            return ALGEBRAIC;
        }
    }

    if (state == VA || state == VB)
    {
        if (key == '\0')
        {
            return VARIABLE;
        }
    }

    if (state == IA || state == IB || state == FA)
    {
        if (key == '\0')
        {
            return INTERGER;
        }
    }

    if (state == PB || state == PC)
    {
        if (key == '\0')
        {
            return PROPER;
        }
    }
}

int main()
{

    char map[6][20] = {"variable", "integer", "float", "proper fraction", "algebraic fraction"};

    int n = 0;
    scanf("%d", &n);

    for (int j = 0; j < n; j++)
    {
        int state = 0;
        char str[100] = {" "};
        scanf("%s", str);
        int ac = 0;
        int pa = 0, pb = 0;
        int flag = 0;
        int findex = 0;
        for (int i = 0; i <= strlen(str); i++)
        {
            if (str[i] == '.')
            {
                findex = i;
            }

            if (str[i] == '(') //express algebraic we need to move pa in pc
            {
                ac = pa;
                pa = 0;
            }

            else if (str[i] != '\0' && str[i] != ')') //express maybe not algebraic we need to count pa and pb
            {
                if (str[i] == '/')
                {
                    flag = 1;
                }
                else if (flag == 0)
                {
                    pa = pa * 10 + (str[i] - '0');
                }
                else if (flag == 1 && str[i] != ')')
                {
                    pb = pb * 10 + (str[i] - '0');
                }
            }

            // printf("state : %d\n", state);
            // printf("key : %c\n", str[i]);
            state = getState(str[i], state);
        }
        // printf("final state : %d\n", state);

        if (state == 9)
        {
            printf("%s\n", map[0]);
        }
        else if (state == 19)
        {
            printf("%s\n", map[1]);
        }
        else if (state == 29)
        {
            printf("%s\n", map[2]);
            printf("%.*s\n", findex, str);
            for (int i = findex + 1; i < strlen(str); i++)
            {
                printf("%c", str[i]);
            }
            printf("\n");
        }

        else if (state == 39 && (pa < pb))
        {
            printf("%s\n", map[3]);
            // printf("%d /  %d\n", pa, pb);
        }
        else if (state == 49 && pa < pb)
        {
            printf("%s\n", map[4]);
            // printf("%d (%d / %d) \n", ac, pa, pb);
        }
        else
        {
            // printf("error %s\n", str);
            printf("error\n");
        }
    }
}