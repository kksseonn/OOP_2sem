#include <gtest/gtest.h>
#include <functions/functions.h>
#define SIZE 4
//1
TEST(FunctionTest, DefoltConstructorFunctionTest) {
    Function func = Function();
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

    Function func = Function();
    func.set_x(2);
    func.set_a(2.1);
    func.set_b(2.2);
    func.set_c(2.3);
    func.set_w(2.4);
    func.set_fi(2.5);
    func.set_type(HARMONIC);
    EXPECT_EQ(func.get_type(), HARMONIC);
    EXPECT_NEAR(func.get_x(), 2, 0.001);
    EXPECT_NEAR(func.get_a(), 2.1, 0.001);
    EXPECT_NEAR(func.get_b(), 2.2, 0.001);
    EXPECT_NEAR(func.get_c(), 2.3, 0.001);
    EXPECT_NEAR(func.get_w(), 2.4, 0.001);
    EXPECT_NEAR(func.get_fi(), 2.5, 0.001);
}
//3
TEST(FunctionsTest, FunctionsConstructorTest) {

    Function func = Function(HARMONIC, 2, 2.1, 2.2, 2.3, 2.4, 2.5);
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
    Function func = Function(QUADRATIC, 2, 1, 2, 3, 0, 0);
    Function func1 = Function(HARMONIC, 2, 1, 0, 0, 4, 5);
    EXPECT_EQ(func.calc_from_argument(), 11);
    EXPECT_NEAR(func1.calc_from_argument(), 0.9074, 0.001);
}
//5
TEST(FunctionsTest, FunctionsDerivativeTest) {
    Function func = Function(QUADRATIC, 2, 1, 2, 3, 0, 0);
    Function func1 = Function(HARMONIC, 2, 1, 0, 0, 4, 5);
    EXPECT_EQ(func.getting_the_derivative(), 6);
    EXPECT_NEAR(func1.getting_the_derivative(), -1.6805, 0.001);
}
//6
TEST(FunctionsTest, FunctionsAntiderivativeTest) {
    Function func = Function(QUADRATIC, 2, 1, 2, 3, 0, 0);
    Function func1 = Function(HARMONIC, 2, 1, 0, 0, 4, 5);
    EXPECT_NEAR(func.obtaining_the_antiderivative(), 12.666, 0.002);
    EXPECT_NEAR(func1.obtaining_the_antiderivative(), 0.1050, 0.002);
}

TEST(FunctionsSetTest, FunctionsSetDefaultConstructor) {
    FunctionsSet funcs = FunctionsSet();
    EXPECT_EQ(funcs.get_size(), 5);
    EXPECT_EQ(funcs[4].get_type(), QUADRATIC);
    EXPECT_EQ(funcs[4].calc_from_argument(), 3);
}

TEST(FunctionsSetTest, FunctionSetConstructor){
    Function func[SIZE];
    func[0] = Function(QUADRATIC, 1, 2, 3, 4, 0, 0);
    func[1] = Function(HARMONIC, 1, 1, 0, 0, 1, 1);
    func[2] = Function(QUADRATIC, 2, 2, 2, 2, 0, 0);
    func[3] = Function(HARMONIC, 3, 3, 0, 0, 3, 3);
    FunctionsSet funcs = FunctionsSet(func, SIZE);
    EXPECT_EQ(func[2].getting_the_derivative(), 10);
    EXPECT_EQ(func[0].get_type(), QUADRATIC);
    EXPECT_EQ(func[1].get_type(), HARMONIC);
}

TEST(FunctionsSetTest, FunctionsSetAddTest) {
    FunctionsSet funcs = FunctionsSet();
    Function f = Function(HARMONIC, 2, 3, 0, 0, 4, 5);
    funcs.add(2, f);
    EXPECT_EQ(funcs.get_size(), 6);
    EXPECT_EQ(funcs[2].get_type(), HARMONIC);
}

TEST(FunctionsSetTest, FunctionsSetDelTest) {
    FunctionsSet funcs = FunctionsSet();
    funcs.del(2);
    EXPECT_EQ(funcs.get_size(), 4);
    EXPECT_EQ(funcs[3].get_type(), QUADRATIC);
}

TEST(FunctionsSetTest, FunctionsSetMaxDerTest) {
    Function funcs[SIZE];
    funcs[0] = Function(QUADRATIC, 1, 2, 3, 4, 0, 0);
    funcs[1] = Function(HARMONIC, 1, 1, 0, 0, 1, 1);
    funcs[2] = Function(QUADRATIC, 2, 2, 2, 2, 0, 0);
    funcs[3] = Function(HARMONIC, 3, 3, 0, 0, 3, 3);
    FunctionsSet set = FunctionsSet(funcs, SIZE);
    EXPECT_EQ(set.find_function_max_derivative(), 0);
}

TEST(ExceptionsTest, DenominatorTest) {
    Function func = Function(HARMONIC, 2, 1, 0, 0, 0, 5);
    EXPECT_THROW(func.obtaining_the_antiderivative(), std::runtime_error);
}

TEST(ExceptionsTest, AddTest) {
    FunctionsSet func = FunctionsSet();
    Function func1 = Function();
    EXPECT_THROW(func.add(6, func1), std::runtime_error);
    EXPECT_THROW(func.add(-1, func1), std::runtime_error);
}

TEST(ExceptionsTest, DelTest) {
    FunctionsSet func = FunctionsSet();
    func.clear();
    EXPECT_THROW(func.del(2), std::runtime_error);
}