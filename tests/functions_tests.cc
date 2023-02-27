#include <gtest/gtest.h>

#include <functions/functions.h>

TEST(FunctionTest, DefoltConstructorFunctionTest) {
    Functions func = Functions();
    EXPECT_EQ(func.get_type(),QUADRATIC);
}