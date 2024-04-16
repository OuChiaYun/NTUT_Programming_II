#include <stdio.h>

void findCode(int areaCode)
{
    switch (areaCode)
    {
    case 2:
        printf("02 是台北市、新北市與基隆市區域號碼四");
        break;
    case 3:
        printf("03是桃園市、新竹縣市與宜蘭花蓮縣區域號碼四");
        break;
    default:
        printf("資料庫無此資料\n");
    }
}
int main()
{
    findCode(2);
    findCode(3);
    findCode(9);
    return 0;
}