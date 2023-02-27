#include <gtest/gtest.h>

#include <functions/functions.h>

TEST(FunctionTest, DefoltConstructorFunctionTest) {
    Functions func = Functions();
    EXPECT_EQ(func.get_type(),QUADRATIC);
    EXPECT_NEAR(func.get_x(), 1, 0.1);
    EXPECT_NEAR(func.get_a(), 1, 0.1);
    EXPECT_NEAR(func.get_b(), 1, 0.1);
    EXPECT_NEAR(func.get_c(), 1, 0.1);
    
}

TEST(FunctionTest, SetterFunctionsTest) {

    Functions func = Functions();
    func.set_x(2);
    func.set_a(2.1);
    func.set_b(2.2);
    func.set_c(2.3);

    func.set_type(HARMONIC);
    EXPECT_EQ(func.get_type(), HARMONIC);
    EXPECT_NEAR(func.get_x(), 2, 0.001);
    EXPECT_NEAR(func.get_a(), 2.1, 0.001);
    EXPECT_NEAR(func.get_b(), 2.2, 0.001);
    EXPECT_NEAR(func.get_c(), 2.3, 0.001);
}