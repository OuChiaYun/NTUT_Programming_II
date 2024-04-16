#include <cstdlib>
#include <gtest/gtest.h>
#include "fms.h"
TEST(fmsTest, HandleInput)
{
    char s[] = "rate R2D2 2 time 55566 23 12 #";
    char expOutput[] = "rate - identifier\nR2D2 - identifier\n2 - number\ntime - identifier\n55566 - number\n23 - number\n12 - number\n";
    ASSERT_STREQ(expOutput, FMS(s));
}

TEST(fmsTest2, HandleInput)
{
    char s[] = " ";
    char expOutput[] = "rate - identifier\nR2D2 - identifier\n2 - number\ntime - identifier\n55566 - number\n23 - number\n12 - number\n";
    ASSERT_STREQ("", FMS(s));
}
TEST(fmsTest3, HandleInput)
{

    char s[] = "aA_";
    char expOutput[] = "aA_";

    ASSERT_STREQ(expOutput, FMS(s));

}

TEST(fmsTest4, HandleInput)
{

    char s[] = "3_";
    char expOutput[] = "3_";

    ASSERT_STREQ(expOutput, FMS(s));

}

TEST(fmsTest5, HandleInput)
{

    char s[] = "+_";
    char expOutput[] = "+";

    ASSERT_STREQ(expOutput, FMS(s));

}

TEST(fmsTest6, HandleInput)
{

    char s[] = "\0";
    char expOutput[] = "";
    // getNextState("start","6");
    ASSERT_STREQ(expOutput, FMS(s));

}

int main(int argc, char **argv)
{
    testing ::InitGoogleTest(&argc, argv);
   
    return RUN_ALL_TESTS();
}
