#include <gtest/gtest.h>

#include <functions/functions.h>
//1
TEST(FunctionTest, DefoltConstructorFunctionTest) {
    Functions func = Functions();
    EXPECT_EQ(func.get_type(),QUADRATIC);
    EXPECT_NEAR(func.get_x(), 1, 0.1);
    EXPECT_NEAR(func.get_a(), 1, 0.1);
    EXPECT_NEAR(func.get_b(), 1, 0.1);
    EXPECT_NEAR(func.get_c(), 1, 0.1);
    EXPECT_EQ(func.get_w(), 0);
    EXPECT_EQ(func.get_fi(), 0);
}
//2
TEST(FunctionTest, SetterFunctionsTest) {

    Functions func = Functions();
    func.set_x(2);
    func.set_a(2.1);
    func.set_b(2.2);
    func.set_c(2.3);
    //TODO W FI
    func.set_type(HARMONIC);
    EXPECT_EQ(func.get_type(), HARMONIC);
    EXPECT_NEAR(func.get_x(), 2, 0.001);
    EXPECT_NEAR(func.get_a(), 2.1, 0.001);
    EXPECT_NEAR(func.get_b(), 2.2, 0.001);
    EXPECT_NEAR(func.get_c(), 2.3, 0.001);
}
//3
TEST(FunctionsTest, FunctionsConstructorTest) {

    Functions func = Functions(HARMONIC, 2, 2.1, 2.2, 2.3, 2.4, 2.5);
    EXPECT_EQ(func.get_type(), HARMONIC);
    EXPECT_NEAR(func.get_x(), 2, 0.002);
    EXPECT_NEAR(func.get_a(), 2.1, 0.0002);
    EXPECT_NEAR(func.get_b(), 2.2, 0.0002);
    EXPECT_NEAR(func.get_c(), 2.3, 0.0002);
    EXPECT_NEAR(func.get_w(), 2.4, 0.0002);
    EXPECT_NEAR(func.get_fi(), 2.5, 0.0002);
}
//4
TEST(FunctionsTest, FunctionsCalcTest) {
    Functions func = Functions(QUADRATIC, 2, 1, 2, 3, 0, 0);
    Functions func1 = Functions(HARMONIC, 2, 1, 0, 0, 4, 5);
    EXPECT_EQ(func.calc_from_argument(), 11);
    EXPECT_NEAR(func1.calc_from_argument(), 0.9074, 0.001);
}
//5
TEST(FunctionsTest, FunctionsDerivativeTest) {
    Functions func = Functions(QUADRATIC, 2, 1, 2, 3, 0, 0);
    Functions func1 = Functions(HARMONIC, 2, 1, 0, 0, 4, 5);
    EXPECT_EQ(func.getting_the_derivative(), 6);
    EXPECT_NEAR(func1.getting_the_derivative(), -1.6805, 0.001);
}
//6
TEST(FunctionsTest, FunctionsAntiderivativeTest) {
    Functions func = Functions(QUADRATIC, 2, 1, 2, 3, 0, 0);
    Functions func1 = Functions(HARMONIC, 2, 1, 0, 0, 4, 5);
    EXPECT_NEAR(func.obtaining_the_antiderivative(), 12.666, 0.002);
    EXPECT_NEAR(func1.obtaining_the_antiderivative(), 0.1050, 0.002);
}

TEST(ExceptionsTest, DenominatorTest) {
    Functions func = Functions(HARMONIC, 2, 1, 0, 0, 0, 5);
    EXPECT_THROW(func.obtaining_the_antiderivative(), std::runtime_error);
}
