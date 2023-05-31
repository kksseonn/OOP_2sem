#include <gtest/gtest.h>
#include <functions/functions.h>
#define SIZE 4

TEST(FunctionTest, SetterFunctionTest) {
    Quadratic func1;
    func1.set_x(1);
    func1.set_a(2);
    func1.set_b(3);
    func1.set_c(4);
    EXPECT_EQ(func1.get_x(), 1);
    EXPECT_EQ(func1.get_a(), 2);
    EXPECT_EQ(func1.get_b(), 3);
    EXPECT_EQ(func1.get_c(), 4);

    Harmonic func2;
    func2.set_x(2);
    func2.set_a(2.1);
    func2.set_w(2.4);
    func2.set_fi(2.5);
    EXPECT_NEAR(func2.get_x(), 2, 0.001);
    EXPECT_NEAR(func2.get_a(), 2.1, 0.001);
    EXPECT_NEAR(func2.get_w(), 2.4, 0.001);
    EXPECT_NEAR(func2.get_fi(), 2.5, 0.001);
}
//QUADRATIC
// 
TEST(QuadraticTest, QuadraticConstructorTest) {
    Quadratic func1 = Quadratic(1, 2, 3, 4);
    EXPECT_EQ(func1.get_x(), 1);
    EXPECT_EQ(func1.get_a(), 2);
    EXPECT_EQ(func1.get_b(), 3);
    EXPECT_EQ(func1.get_c(), 4);
}

TEST(QuadraticTest, QuadraticCopyConstructorTest) {
    Quadratic func = Quadratic(1, 2, 3, 4);
    Quadratic func1(func);
    EXPECT_EQ(func1.get_x(), 1);
    EXPECT_EQ(func1.get_a(), 2);
    EXPECT_EQ(func1.get_b(), 3);
    EXPECT_EQ(func1.get_c(), 4);
}

TEST(QuadraticTest, QuadraticOverloadCopyTest) {
    Quadratic func = Quadratic(1, 2, 3, 4);
    Quadratic func1 = func;
    EXPECT_EQ(func1.get_x(), 1);
    EXPECT_EQ(func1.get_a(), 2);
    EXPECT_EQ(func1.get_b(), 3);
    EXPECT_EQ(func1.get_c(), 4);
}

TEST(QuadraticTest, QuadraticCalcTest) {
    Quadratic func1 = Quadratic(1, 2, 3, 4);
    EXPECT_EQ(func1.calc_from_argument(), 9);
}

TEST(QuadraticTest, QuadraticDerTest) {
    Quadratic func1 = Quadratic(1, 2, 3, 4);
    EXPECT_EQ(func1.getting_the_derivative(), 7);
}

TEST(QuadraticTest, QuadraticAntiDerTest) {
    Quadratic func = Quadratic(2, 1, 2, 3);
    EXPECT_NEAR(func.obtaining_the_antiderivative(), 12.666, 0.002);
}

//HARMONIC

TEST(HarmonicTest, HarmonicConstructorTest) {
    Harmonic func1 = Harmonic(2, 1, 4, 5);
    EXPECT_EQ(func1.get_x(), 2);
    EXPECT_EQ(func1.get_a(), 1);
    EXPECT_EQ(func1.get_w(), 4);
    EXPECT_EQ(func1.get_fi(), 5);
}

TEST(HarmonicTest, HarmonicCopyConstructorTest) {
    Harmonic func = Harmonic(1, 2, 3, 4);
    Harmonic func1(func);
    EXPECT_EQ(func1.get_x(), 1);
    EXPECT_EQ(func1.get_a(), 2);
    EXPECT_EQ(func1.get_w(), 3);
    EXPECT_EQ(func1.get_fi(), 4);
}

TEST(HarmonicTest, HarmonicOverloadCopyTest) {
    Harmonic func = Harmonic(2, 1, 4, 5);
    Harmonic func1 = func;
    EXPECT_EQ(func1.get_x(), 2);
    EXPECT_EQ(func1.get_a(), 1);
    EXPECT_EQ(func1.get_w(), 4);
    EXPECT_EQ(func1.get_fi(), 5);
}

TEST(HarmonicTest, HarmonicCalcTest) {
    Harmonic func = Harmonic(2, 1, 4, 5);
    EXPECT_NEAR(func.calc_from_argument(), 0.9074, 0.002);
}

TEST(HarmonicTest, HarmonicDerTest) {
    Harmonic func = Harmonic(2, 1, 4, 5);
    EXPECT_NEAR(func.getting_the_derivative(), -1.6805, 0.001);
}

TEST(HarmonicTest, HarmonicAntiDerTest) {
    Harmonic func = Harmonic(2, 1, 4, 5);
    EXPECT_NEAR(func.obtaining_the_antiderivative(), 0.1050, 0.002);
}

//FUNCTIONSSET

TEST(FunctionsSetTest, FunctionSetConstructor){
    std::vector<FunctionPtr> funcs;
    Quadratic func = Quadratic(1, 2, 3, 4);
    Harmonic func1 = Harmonic(2, 1, 4, 5);
    funcs.push_back(std::make_shared<Quadratic>(func));
    funcs.push_back(std::make_shared<Harmonic>(func1));
    FunctionsSet set = FunctionsSet(funcs);
    EXPECT_EQ(set.get_size(), 2);
    EXPECT_EQ(set[0]->calc_from_argument(), 9);
    EXPECT_NEAR(set[1]->calc_from_argument(), 0.9074, 0.002);
}

TEST(FunctionsSetTest, FunctionSetCopyConstructor) {
    std::vector<FunctionPtr> funcs;
    Quadratic func = Quadratic(1, 2, 3, 4);
    Harmonic func1 = Harmonic(2, 1, 4, 5);
    funcs.push_back(std::make_shared<Quadratic>(func));
    funcs.push_back(std::make_shared<Harmonic>(func1));
    FunctionsSet set = FunctionsSet(funcs);
    FunctionsSet set1 = set;
    EXPECT_EQ(set1.get_size(), 2);
    EXPECT_EQ(set1[0]->calc_from_argument(), 9);
    EXPECT_NEAR(set1[1]->calc_from_argument(), 0.9074, 0.002);
}

TEST(FunctionsSetTest, FunctionsSetAddTest) {
    std::vector<FunctionPtr> funcs;
    Quadratic func = Quadratic(1, 2, 3, 4);
    Harmonic func1 = Harmonic(2, 1, 4, 5);
    funcs.push_back(std::make_shared<Quadratic>(func));
    funcs.push_back(std::make_shared<Harmonic>(func1));
    FunctionsSet set = FunctionsSet(funcs);
    set.add(1, func1.clone());
    EXPECT_EQ(set.get_size(), 3);
    EXPECT_EQ(set[0]->calc_from_argument(), 9);
    EXPECT_NEAR(set[1]->calc_from_argument(), 0.9074, 0.002);
    EXPECT_NEAR(set[2]->calc_from_argument(), 0.9074, 0.002);
}

TEST(FunctionsSetTest, FunctionsSetDelTest) {
    std::vector<FunctionPtr> funcs;
    Quadratic func = Quadratic(1, 2, 3, 4);
    Harmonic func1 = Harmonic(2, 1, 4, 5);
    Quadratic func2 = Quadratic(3, 3, 3, 3);
    funcs.push_back(std::make_shared<Quadratic>(func));
    funcs.push_back(std::make_shared<Harmonic>(func1));
    funcs.push_back(std::make_shared<Quadratic>(func2));
    FunctionsSet set = FunctionsSet(funcs);
    set.del(0);
    EXPECT_EQ(set.get_size(), 2);
    EXPECT_NEAR(set[0]->calc_from_argument(), 0.9074, 0.002);
    EXPECT_EQ(set[1]->calc_from_argument(), 39);
    
}

TEST(FunctionsSetTest, FunctionsSetClearTest) {
    std::vector<FunctionPtr> funcs;
    Quadratic func = Quadratic(1, 2, 3, 4);
    Harmonic func1 = Harmonic(2, 1, 4, 5);
    funcs.push_back(std::make_shared<Quadratic>(func));
    funcs.push_back(std::make_shared<Harmonic>(func1));
    FunctionsSet set = FunctionsSet(funcs);
    set.clear();
    EXPECT_EQ(set.get_size(), 0);
}

TEST(FunctionsSetTest, FunctionsSetMaxDerTest) {
    std::vector<FunctionPtr> funcs;
    Quadratic func = Quadratic(1, 2, 3, 4);
    Harmonic func1 = Harmonic(2, 1, 4, 5);
    funcs.push_back(std::make_shared<Quadratic>(func));
    funcs.push_back(std::make_shared<Harmonic>(func1));
    FunctionsSet set = FunctionsSet(funcs);
    EXPECT_EQ(set.find_function_max_derivative(), 0);
}
