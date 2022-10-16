#include <calculator.h>
#include <gtest/gtest.h>

TEST(Calculator, BasicTest)
{
    EXPECT_EQ(Calculator::add(""), 0);
    EXPECT_EQ(Calculator::add("1"), 1);
    EXPECT_EQ(Calculator::add("3,4"), 7);
    EXPECT_EQ(Calculator::add("1,2,3"), 6);
    EXPECT_EQ(Calculator::add("7,6,11,3"), 27);
    EXPECT_THROW(Calculator::add("1.4"), CalculationError);
    EXPECT_THROW(Calculator::add("465das"), CalculationError);
}

TEST(Calculator, DelimeterTest)
{
    EXPECT_EQ(Calculator::add("1\n2,3"), 6);
    EXPECT_THROW(Calculator::add("1,\n"), CalculationError);
    EXPECT_THROW(Calculator::add("1,,3"), CalculationError);
    EXPECT_EQ(Calculator::add("//;\n1;2"), 3);
    EXPECT_EQ(Calculator::add("//;\n1"), 1);
    EXPECT_EQ(Calculator::add("//;\n1;2;4"), 7);
    EXPECT_THROW(Calculator::add("//\n1,2"), CalculationError);
    EXPECT_THROW(Calculator::add("//;1;3"), CalculationError);
    EXPECT_THROW(Calculator::add("1;3"), CalculationError);
}

TEST(Calculator, NegativeTest)
{
    try {
        Calculator::add("-1");
        FAIL() << "Calling add(\"-1\") should throw an exception";
    } catch (const CalculationError &e) {
        EXPECT_STREQ(e.what(), "negatives not allowed: -1");
    }
    try {
        Calculator::add("-1,-8");
        FAIL() << "Calling add(\"-1,-8\") should throw an exception";
    } catch (const CalculationError &e) {
        EXPECT_STREQ(e.what(), "negatives not allowed: -1, -8");
    }
    try {
        Calculator::add("1,-8");
        FAIL() << "Calling add(\"1,-8\") should throw an exception";
    } catch (const CalculationError &e) {
        EXPECT_STREQ(e.what(), "negatives not allowed: -8");
    }
    EXPECT_THROW(Calculator::add("-1,"), CalculationError);
}

TEST(Calculator, BigNumbersTest)
{
    EXPECT_EQ(Calculator::add("3,1001"), 3);
    EXPECT_EQ(Calculator::add("//;\n3;1001;4"), 7);
    EXPECT_EQ(Calculator::add("3,1000"), 1003);
    EXPECT_EQ(Calculator::add("1001"), 0);
    EXPECT_EQ(Calculator::add("564679867997"), 0);
}
