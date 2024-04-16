#include <stdio.h>
#include <string.h>
#define GATEVALUE(TYPE) int (*GateValue)(struct TYPE *)

typedef struct _Gate
{
    GATEVALUE(_Gate);
} Gate;

typedef struct _GateAnd
{
    GATEVALUE(_GateAnd);
    int i1;
    int i2;
} GateAnd;

typedef struct _GateOR
{
    GATEVALUE(_GateOR);
    int i1;
    int i2;
} GateOr;

typedef struct _GateXOR
{
    GATEVALUE(_GateXOR);
    int i1;
    int i2;
} GateXor;

typedef struct _GateNOT
{
    GATEVALUE(_GateNOT);
    int i1;
} GateNot;

typedef struct _GateEmpty
{
    GATEVALUE(_GateEmpty);
    int i1;
} GateEmpty;

int GateGetValue(Gate *obj) { return 0; }

int GateAndValue(GateAnd *obj)
{

    return obj->i1 & obj->i2;
}

int GateOrValue(GateOr *obj)
{

    return obj->i1 | obj->i2;
}

int GateXorValue(GateXor *obj)
{

    return obj->i1 ^ obj->i2;
}

int GateNotValue(GateNot *obj)
{

    return !(obj->i1);
}

int GateEmptyValue(GateEmpty *obj)
{

    return obj->i1;
}

void CreateGate(Gate *obj)
{
    obj->GateValue = GateGetValue;
}

void CreateGateAND(GateAnd *obj, int a, int b)
{
    obj->GateValue = GateAndValue;
    obj->i1 = a;
    obj->i2 = b;
}

void CreateGateOR(GateOr *obj, int a, int b)
{
    obj->GateValue = GateOrValue;
    obj->i1 = a;
    obj->i2 = b;
}

void CreateGateXOR(GateXor *obj, int a, int b)
{
    obj->GateValue = GateXorValue;
    obj->i1 = a;
    obj->i2 = b;
}

void CreateGateNOT(GateNot *obj, int a)
{
    obj->GateValue = GateNotValue;
    obj->i1 = a;
}

void CreateGateEMPTY(GateEmpty *obj, int a)
{
    obj->GateValue = GateEmptyValue;
    obj->i1 = a;
}

int main(int argc, char *argv[])
{

    char I[100] = {' '};

    char GATE[100] = {' '};

    // Gate *gate[7];

    scanf("%d,%d,%d,%d", &I[0], &I[1], &I[2], &I[3]);
    scanf(" %c,%c,%c,%c,%c,%c", &GATE[0], &GATE[1], &GATE[2], &GATE[3], &GATE[4], &GATE[5], &GATE[6]);
    // for(int i = 0;i<4;i++){
    //     printf("%d ",I[i] );
    // }
    // printf("\n");

    // for(int i = 0;i<6;i++){
    //     printf("%c ",GATE[i] );
    // }

    int tmp0, tmp1 = 0;
    int output[10] = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 6; i++)
    {

        tmp0 = 0;
        tmp1 = 0;
        if (i == 0)
        {
            tmp0 = I[0];
            tmp1 = I[1];
        }
        if (i == 1)
        {
            tmp0 = output[0];
        }
        if (i == 2)
        {
            tmp0 = output[0];
            tmp1 = I[2];
        }
        if (i == 3)
        {
            tmp0 = output[1];
            tmp1 = output[2];
        }
        if (i == 4)
        {
            tmp0 = output[2];
            tmp1 = I[3];
        }
        if (i == 5)
        {
            tmp0 = output[3];
            tmp1 = output[4];
        }

        if (GATE[i] == 'A')
        {
            GateAnd a;
            CreateGateAND(&a, tmp0, tmp1);
            output[i] = a.GateValue(&a);
        }
        if (GATE[i] == 'O')
        {
            GateOr o;
            CreateGateOR(&o, tmp0, tmp1);
            output[i] = o.GateValue(&o);
       }
        if (GATE[i] == 'X')
        {
            GateXor x;
            CreateGateXOR(&x, tmp0, tmp1);
            output[i] = x.GateValue(&x);
        }
        if (GATE[i] == 'N')
        {
            GateNot n;
            CreateGateNOT(&n, tmp0);
            output[i] = n.GateValue(&n);
        }
        if (GATE[i] == 'E')
        {
            GateEmpty e;
            CreateGateEMPTY(&e, tmp0);
            output[i] = e.GateValue(&e);
        }
    }

    printf("%d,%d,%d",output[1],output[3],output[5]);

    return 0;
}
