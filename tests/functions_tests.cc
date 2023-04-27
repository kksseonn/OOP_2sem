#include <gtest/gtest.h>
#include <functions/functions.h>
#define SIZE 4
//1
TEST(FunctionTest, DefoltConstructorFunctionTest) {
    Function func;
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

    Function func;
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
//7
TEST(FunctionsSetTest, FunctionsSetDefaultConstructor) {
    FunctionsSet set;
    EXPECT_EQ(set.get_size(), 5);
}
//8
TEST(FunctionsSetTest, FunctionSetConstructor){
    FunctionPtr* functions = new Function * [SIZE];
    functions[0] = new Function(QUADRATIC, 1, 2, 3, 4, 0, 0);
    functions[1] = new Function(HARMONIC, 1, 1, 0, 0, 1, 1);
    functions[2] = new Function(QUADRATIC, 2, 2, 2, 2, 0, 0);
    functions[3] = new Function(HARMONIC, 3, 3, 0, 0, 3, 3);
    FunctionsSet func = FunctionsSet(SIZE, functions);
    EXPECT_EQ(func.get_size(), SIZE);
    EXPECT_EQ(func[2]->getting_the_derivative(), 10);
    EXPECT_EQ(func[0]->get_type(), QUADRATIC);
    EXPECT_EQ(func[1]->get_type(), HARMONIC);
}
//9
TEST(FunctionsSetTest, FunctionsSetAddTest) {
    FunctionsSet funcs;
    Function f = Function(HARMONIC, 2, 3, 0, 0, 4, 5);
    funcs.add(2, f);
    EXPECT_EQ(funcs.get_size(), 6);
    EXPECT_EQ(funcs[2]->get_type(), HARMONIC);
}
//10
TEST(FunctionsSetTest, FunctionsSetDelTest) {
    FunctionsSet funcs;
    funcs.del(2);
    EXPECT_EQ(funcs.get_size(), 4);
    EXPECT_EQ(funcs[3]->get_type(), QUADRATIC);
}
//11
TEST(FunctionsSetTest, FunctionsSetMaxDerTest) {
    FunctionPtr* funcs = new Function * [SIZE];
    funcs[0] = new Function(QUADRATIC, 1, 2, 3, 4, 0, 0);
    funcs[1] = new Function(HARMONIC, 1, 1, 0, 0, 1, 1);
    funcs[2] = new Function(QUADRATIC, 2, 2, 2, 2, 0, 0);
    funcs[3] = new Function(HARMONIC, 3, 3, 0, 0, 3, 3);
    FunctionsSet set = FunctionsSet(SIZE, funcs);
    EXPECT_EQ(set.find_function_max_derivative(), 2);
}
//12
TEST(FunctionsSetTest, FunctionsSetClearTest) {
    FunctionsSet funcs;
    funcs.clear();
    EXPECT_EQ(funcs.get_size(), 0);
}
//13
TEST(FunctionsSetTest, FunctionsSetGetItemTest) {
    FunctionsSet funcs;
    EXPECT_EQ(funcs[3]->get_type(), QUADRATIC);
}
//14
TEST(FunctionsSetTest, FunctionsSetSetItemTest) {
    FunctionsSet funcs;
    funcs[3]->set_type(HARMONIC);
    EXPECT_EQ(funcs[3]->get_type(), HARMONIC);
}
//15
TEST(FunctionsSetTest, FunctionsSetOverloadOperatorsTest) {
    Function func = Function(HARMONIC, 1, 1, 0, 0, 1, 1);
    Function func1;
    Function func2;
    EXPECT_TRUE(func2 == func1);
    EXPECT_TRUE(func != func1);
}
//16
TEST(ExceptionsTest, DenominatorTest) {
    Function func = Function(HARMONIC, 2, 1, 0, 0, 0, 5);
    EXPECT_THROW(func.obtaining_the_antiderivative(), std::runtime_error);
}
//17
TEST(ExceptionsTest, AddTest) {
    FunctionsSet func;
    Function func1;
    EXPECT_THROW(func.add(6, func1), std::runtime_error);
    EXPECT_THROW(func.add(-1, func1), std::runtime_error);
}
//18
TEST(ExceptionsTest, DelTest) {
    FunctionsSet func;
    func.clear();
    EXPECT_THROW(func.del(2), std::runtime_error);
}
//19
TEST(ExceptionsTest, OperatorTest) {
    FunctionsSet func;
    EXPECT_THROW(func[-1]->get_type(), std::runtime_error);
    EXPECT_THROW(func[10]->get_type(), std::runtime_error);
}
//20
TEST(ExceptionsTest, EmptyTest) {
    FunctionsSet func;
    func.clear();
    EXPECT_THROW(func.del(1), std::runtime_error);
}
