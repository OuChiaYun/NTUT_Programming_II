#include <stdio.h>
#include <string.h>
void add(int p1[], int p2[], int sum[]);
void printf_p(int p1[])
{

    int max = 0;
    for (int i = 60 - 1; i >= 0; i--)
    {
        if (p1[i] != 0)
        {
            max = i;
            break;
        }
    }
    for (int i = max; i >= 0; i--)
    {
        printf("%d", p1[i]);
    }
}

void reset(int p1[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p1[i] = 0;
    }
}
void swap(int p1[], int p2[])
{

    int temp = 0;
    for (int i = 0; i < 60; i++)
    {
        temp = p1[i];
        p1[i] = p2[i];
        p2[i] = temp;
    }

}

int isLager(int p1[], int p2[])
{

    for (int i = 59; i >= 0; i--)
    {
        if (p1[i] > p2[i])
        {
            return 1;
        }
        else if (p1[i] < p2[i])
        {
            return 0;
        }
        else
        {
            continue;
        }
    }

    return 2;
}

void printf_b(int p1[])
{

    int min = 0;
    int max = 0;
    for (int i = 0; i < 70; i++)
    {
        if (p1[i] != 0)
        {
            min = i;
            break;
        }
    }

    for (int i = 69; i >= 0; i--)
    {
        if (p1[i] != 0)
        {
            max = i;
            break;
        }
    }
    for (int i = max; i >= min; i--)
    {
        printf("%d", p1[i]);
    }
    // printf("\n");
}

void merge(int p[], int p_b[], int b, int m_p[], int m_b[])
{

    int t[60] = {0};
    int tt = 0;
    for (int i = 0; i < 60; i++)
    {
        t[i] = 0;
    }

    tt = 0;
    for (int i = 69; i >= 0; i--)
    {
        t[tt] = p_b[69];
        tt++;
    }
    // printf_p(t);
    // printf("\n");
    add(p, t, m_p);

    printf_p(m_p);
    printf(".");
    for (int i = 69; i >= 60; i--)
    {
        m_b[i] = 0;
    }
    for (int i = 59; i >= 0; i--)
    {
        m_b[i] = p_b[i];
    }
    printf_b(m_b);
}

void add(int p1[], int p2[], int sum[])
{

    int carry = 0;
    int i = 0;

    for (i = 0; i < 60; i++)
    {
        sum[i] = (carry + p1[i] + p2[i]) % 10;
        carry = (carry + p1[i] + p2[i]) / 10;
    }

    if (carry > 0)
    {
        sum[i] = carry;
    }
};

int sub(int p1[], int p2[], int sum[])
{

    int borrow = 0;
    int i = 0;

    for (i = 0; i < 60; i++)
    {
        sum[i] = p1[i] - p2[i] - borrow;
        if (sum[i] < 0)
        {
            borrow = 1;
            sum[i] += 10;
        }
        else
        {
            borrow = 0;
        }
    }
};

int mul(int p1[], int p2[], int sum[])
{
    for (int i = 0; i < 150; i++)
    {
        if (p1[i] == 0)
        {
            continue;
        }

        for (int j = 0; j < 150; j++)
        {
            sum[i + j] += p1[i] * p2[j];
        }
    }
    int carry = 0;
    for (int i = 0; i < 150; i++)
    {
        sum[i] += carry;
        carry = sum[i] / 10;
        sum[i] = sum[i] % 10;
    }
}

int deal(char p1[], int *np, int p1_n[], int p1_b[])
{

    int j = 59;
    int flag = 0;
    int m = 0;
    int size = 0;

    for (int i = 0; i < strlen(p1); i++)
    {
        if (p1[i] == '.')
        {
            m = i;
            flag = 1;
            continue;
        }
        else if (flag == 1)
        {
            p1_b[j] = p1[i] - '0';
            j--;
        }
    }
    size = strlen(p1) - m - 1;
    j = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        if (p1[i] == '-')
        {
            *np = -1;
            continue;
        }

        p1_n[j] = p1[i] - '0';
        j++;
    }

    return size;
}

int main()
{

    char p1[60] = {' '};

    int p1_n[60] = {0};
    int p1_b[70] = {0};
    int np_1 = 1;
    int b1_size = 0;

    char p2[60] = {' '};
    int p2_n[60] = {0};

    int p2_b[70] = {0};
    int np_2 = 1;
    int b2_size = 0;

    int sum_n[60] = {0};
    int sum_b[70] = {0};

    int m_n[60] = {0};
    int m_b[70] = {0};

    int borrow = 0;

    int p1_pro[400] = {0};
    int p2_pro[400] = {0};
    int sum_pro[400] = {0};

    for (int i = 0; i < 70; i++)
    {
        sum_b[i] = 0;
        m_b[i] = 0;
        p1_b[i] = 0;
        p2_b[i] = 0;
    }

    scanf("%s", p1);
    scanf("%s", p2);

    b1_size = deal(p1, &np_1, p1_n, p1_b);
    b2_size = deal(p2, &np_2, p2_n, p2_b);

    printf("%d %d \n", b1_size, b2_size);

    printf("++++++++++\n");
    if (np_1 == 1 && np_2 == 1)
    {
        add(p1_n, p2_n, sum_n);
        add(p1_b, p2_b, sum_b);
        merge(sum_n, sum_b, 60, m_n, m_b);
    }
    else if (np_1 == -1 && np_2 == -1)
    {

        add(p1_n, p2_n, sum_n);
        add(p1_b, p2_b, sum_b);
        printf("-");
        merge(sum_n, sum_b, 60, m_n, m_b);
    }
    else if (np_1 == -1 || np_2 == -1)
    {
        if (np_1 == -1)
        {
            swap(p1_n, p2_n);
            swap(p1_b, p2_b);
        }

        if (!isLager(p1_n, p2_n) || (isLager(p1_n, p2_n) == 2 && !isLager(p1_b, p2_b)))
        {
            int a[60] = {0};
            sub(p2_b, p1_b, sum_b);

            if (!isLager(p2_b, p1_b))
            {
                a[0] = 1;
                sub(p2_n, a, p2_n);
                sum_b[60] == 0;
            }

            sub(p2_n, p1_n, sum_n);
            
            printf("-");
            merge(sum_n, sum_b, 60, m_n, m_b);
    
        }
        else if (isLager(p1_n, p2_n) || (isLager(p1_n, p2_n) == 2 && isLager(p1_b, p2_b)))
        {

            int a[60] = {0};
            sub(p1_b, p2_b, sum_b);

            if (!isLager(p1_b, p2_b))
            {
                a[0] = 1;
                sub(p1_n, a, p1_n);
                sum_b[60] == 0;
            }

            sub(p1_n, p2_n, sum_n);
            // printf("\n");
            // printf("\n");
            sum_b[60] == 0;
            merge(sum_n, sum_b, 60, m_n, m_b);
        }
    }
    printf("\n");
    printf("----------------\n");

    int ttt = np_2;
    np_2 *= -1;

    if (np_1 == -1 && np_2 == -1)
    {
        add(p1_n, p2_n, sum_n);
        add(p1_b, p2_b, sum_b);
        printf("-");
        merge(sum_n, sum_b, 60, m_n, m_b);
    }
    else if (np_1 == 1 && np_2 == 1)
    {
        add(p1_n, p2_n, sum_n);
        add(p1_b, p2_b, sum_b);
        // printf("-");
        merge(sum_n, sum_b, 60, m_n, m_b);
    }
    else
    {

        if (np_1 == -1 && np_2 == 1)
        {
            swap(p1_n, p2_n);
            swap(p1_b, p2_b);
        }

        if (isLager(p1_n, p2_n) == 2)
        {
            printf("0\n");
        }
        else if (!isLager(p1_n, p2_n) || (isLager(p1_n, p2_n) == 2 && !isLager(p1_b, p2_b)))
        {
            int a[60] = {0};
            sub(p2_b, p1_b, sum_b);

            if (!isLager(p2_b, p1_b))
            {
                a[0] = 1;
                sub(p2_n, a, p2_n);
                sum_b[60] == 0;
            }

            sub(p2_n, p1_n, sum_n);

            printf("-");
            merge(sum_n, sum_b, 60, m_n, m_b);
        }
        else if (isLager(p1_n, p2_n) || (isLager(p1_n, p2_n) == 2 && isLager(p1_b, p2_b)))
        {

            int a[60] = {0};
            sub(p1_b, p2_b, sum_b);
            // printf_b(sum_b);
            if (!isLager(p1_b, p2_b))
            {
                a[0] = 1;
                sub(p1_n, a, p1_n);
                sum_b[60] == 0;
            }

            sub(p1_n, p2_n, sum_n);

            sum_b[60] == 0;
            merge(sum_n, sum_b, 60, m_n, m_b);
        }
    }

    printf("\n");
    printf("***********************\n");

    reset(sum_b, 60);
    reset(sum_n, 60);

    int u = b1_size;
    for (int i = 0; i < b1_size; i++)
    {
        p1_pro[i] = p1_b[60 - (u--)];
    }

    u = 0;
    for (int i = b1_size; i < 60; i++)
    {
        p1_pro[i] = p1_n[u++];
    }

    u = b2_size;
    for (int i = 0; i < b2_size; i++)
    {
        p2_pro[i] = p2_b[60 - (u--)];
        // p2_pro[i] =p2_n[i];
        // sum_pro[i] =sum_n[i];
    }

    u = 0;
    for (int i = b2_size; i < 60; i++)
    {
        p2_pro[i] = p2_n[u++];
    }

    mul(p1_pro, p2_pro, sum_pro);

    u = 0;
    for (int i = 0; i < b1_size + b2_size; i++)
    {
        sum_b[i] = sum_pro[i];
    }
    int k = 0;
    for (int i = b1_size + b2_size; i < 150; i++)
    {
        sum_n[k++] = sum_pro[i];
    }

    if (np_1 * ttt == -1)
    {
        printf("-");
    }

    merge(sum_n, sum_b, 60 + (b1_size * b2_size), m_n, m_b);
}