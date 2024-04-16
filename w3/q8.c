#include <stdio.h>
#include <string.h>
#include <math.h>

int lcd(int x, int y)
{
    int max = 0;
    int flag = 0;
    for (int i = 1; x >= i && y >= i; i++)
    {

        if (x % i == 0 && y % i == 0)
        {
            max = i;
        }
    }

    return max;
}
int mul(int m, int n, int j, int k)
{
    int down = m * n;
    int up = j * k;
    int _lcd = lcd(abs(down), abs(up));
    if ((down < 0) && (up < 0))
    {
        down = abs(down);
        up = abs(up);
    }

    if (up % down == 0)
    {
        printf("%d\n", up / down);
    }
    else if (up / down != 0)
    {
        printf("%d(%d/%d)\n", up / down, abs(up % down / _lcd), down / _lcd);
    }
    else
    {
        printf("%d/%d\n", up / _lcd, abs(down / _lcd));
    }

    return 0;
}

int add(int m, int n, int j, int k)
{

    int temp, i;
    int biggest = 0;

    if (m < n)
    {
        if (m < 0)
        {
            m *= -1;
        }
        biggest = m;
    }
    else
    {
        biggest = n;
        if (n < 0)
        {
            biggest *= -1;
        }
    }
    for (i = biggest; i > 0; i++)
    {
        if (i % m == 0 && i % n == 0)
        {
            break;
        }
    }

    int _add = (i / m) * j + (i / n) * k;

    int _lcd = 0;

    if (_add == 0)
    {
        printf("0\n");
        return 0;
    }
    else if (_add < 0)
    {
        _lcd = lcd(_add * -1, i);
    }
    else
    {
        _lcd = lcd(_add, i);
    }

    if (_add % i == 0)
    {
        printf("%d\n", _add / i);
    }
    else if (_add / i != 0)
    {
        printf("%d(%d/%d)\n", _add / i, (abs(_add) % i) / _lcd, i / _lcd);
    }
    else
    {
        printf("%d/%d\n", _add / _lcd, i / _lcd);
    }

    return 0;
}

int sub(int m, int n, int j, int k)
{

    int temp, i;
    int biggest = 0;

    if (m < n)
    {
        biggest = abs(m);
        // if (m < 0)
        // {
        //     biggest *= -1;
        // }
    }
    else
    {

        biggest = abs(n);
        // if (n < 0)
        // {
        //     biggest *= -1;
        // }
    }
    for (i = biggest; i > 0; i++)
    {
        if (i % m == 0 && i % n == 0)
        {
            break;
        }
    }

    int _sub = (i / m) * j - (i / n) * k;
    int _lcd = 0;
    if (_sub == 0)
    {
        printf("0\n");
        return 0;
    }
    if (_sub < 0)
    {
        _lcd = lcd(_sub * -1, i);
    }
    else
    {
        _lcd = lcd(_sub, i);
    }
    if (_sub % i == 0)
    {
        printf("%d\n", _sub / i);
    }
    else if (_sub / i != 0)
    {
        printf("%d(%d/%d)\n", _sub / i, abs(_sub % i) / _lcd, i / _lcd);
    }
    else
    {
        printf("%d/%d\n", _sub / _lcd, i / _lcd);
    }

    return 0;
}

int main()
{

    char str[200];

    int a = 0;
    int b = 0;
    int ab_num = 0;
    int flag = 0;
    char op = ' ';
    char n = 'y';
    int np = 1;

    while (n == 'y')
    {
        a = 0;
        b = 0;
        ab_num = 0;
        flag = 0;
        op = ' ';
        n = 'y';
        np = 1;
        scanf(" %s", str);

        for (int i = 0; i < strlen(str); i++)
        {

            char word = *(str + i);

            int word_n = word - '0';

            if (word == '-')
            {

                np = -1;

                continue;
            }

            if (word == '(')
            {

                ab_num = a;
                a = 0;
                continue;
            }

            if (word == ')')
            {
                break;
            }

            if (word == '/')
            {
                flag = 1;
                continue;
            }

            if (flag == 0)
            {
                a = a * 10 + word_n;
            }
            else if (flag == 1)
            {
                b = b * 10 + word_n;
            }
        }

        if (ab_num > 0)
        {
            a = a + (ab_num * b);
        }

        a = np * a;
        np = 1;
        int c = 0;
        int d = 0;
        flag = 0;
        int cd_num = 0;

        scanf(" %s", str);

        for (int i = 0; i < strlen(str); i++)
        {

            char word = *(str + i);

            int word_n = word - '0';

            if (word == '-')
            {

                np = -1;
                continue;
            }

            if (word == '(')
            {
                cd_num = c;
                c = 0;
                continue;
            }

            if (word == ')')
            {
                break;
            }

            if (word == '/')
            {
                flag = 1;
                continue;
            }

            if (flag == 0)
            {
                c = c * 10 + word_n;
            }
            else if (flag == 1)
            {
                d = d * 10 + word_n;
            }
        }

        if (cd_num > 0)
        {
            c = c + (cd_num * d);
        }

        scanf(" %c", &op);

        c = np * c;

        if (b != 0 && d != 0)
        {
            if (op == '+')
            {
                add(b, d, a, c);
            }
            else if (op == '-')
            {
                sub(b, d, a, c);
            }
            else if (op == '*')
            {
                mul(b, d, a, c);
            }
            else if (op == '/')
            {

                mul(b, c, a, d);
            }
        }
        else
        {
            printf("error\n");
        }
        scanf(" %c", &n);
    }
}