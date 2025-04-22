#include <gtest/gtest.h>
#include "loatlocation.hpp"

TEST(LoatLocationTest, EqualityOperatorWorks)
{
    LoatLocation loc1("q1");
    LoatLocation loc2("q1");
    LoatLocation loc3("q2");

    EXPECT_TRUE(loc1 == loc2);
    EXPECT_FALSE(loc1 == loc3);
}

TEST(LoatLocationTest, OutputStreamOperator)
{
    LoatLocation loc("q42");
    std::stringstream ss;
    ss << loc;
    EXPECT_EQ(ss.str(), "q42");
}