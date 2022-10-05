#include <calculator.h>
#include <gtest/gtest.h>

TEST(Calculator, Add)
{
    EXPECT_EQ(Calculator::add(""), 0);
    EXPECT_EQ(Calculator::add("1"), 1);
    EXPECT_EQ(Calculator::add("3,4"), 7);
    EXPECT_EQ(Calculator::add("1,2,3"), 6);
    EXPECT_EQ(Calculator::add("7,6,11,3"), 27);
    EXPECT_THROW(Calculator::add("1.4"), CalculationError);
    EXPECT_THROW(Calculator::add("465das"), CalculationError);
    EXPECT_THROW(Calculator::add("564679867997"), CalculationError);
}
