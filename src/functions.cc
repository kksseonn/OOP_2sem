#pragma warning(disable:6386)
#include <functions/functions.h>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include <vector>
#include <conio.h>
#define SIZE 4

//Function
float Function::get_x() {
    return x;
}

float Function::get_a() {
    return a;
}

void Function::set_x(float x) {
    this->x = x;
}

void Function::set_a(float a) {
    this->a = a;
}

void Function::swap(Function& other) {
    std::swap(x, other.x);
    std::swap(a, other.a);
}

//Quadratic

float Quadratic::get_b() {
    return b;
}

float Quadratic::get_c() {
    return c;
}

void Quadratic::set_b(float b) {
    this->b = b;
}

void Quadratic::set_c(float c) {
    this->c = c;
}

Quadratic::Quadratic() {
    x = 1;
    a = 1;
    b = 1;
    c = 1;
}

Quadratic::Quadratic(float x, float a, float b, float c) {
    this->x = x;
    this->a = a;
    this->b = b;
    this->c = c;
}

Quadratic::Quadratic(const Quadratic& func) {
    this->x = func.x;
    this->a = func.a;
    this->b = func.b;
    this->c = func.c;
}

Quadratic& Quadratic::operator=(Quadratic& other) {
    swap(other);
    return *this;
}

FunctionPtr Quadratic::clone() {
    return make_shared<Quadratic>(x, a, b, c);
}

float Quadratic::calc_from_argument() const {
    return a * pow(x, 2) + b * x + c;
}

float Quadratic::getting_the_derivative() const {
    return 2 * a * x + b;
}

float Quadratic::obtaining_the_antiderivative() const {
    return ((a * pow(x, 3)) / 3) + ((b * pow(x, 2)) / 2) + c * x;
}

void Quadratic::print(ostream& stream) const {
    stream << " Type of Function: Quadratic" << endl;
    stream << "x = " << x << "\n" << "a = " << a << "\n" << "b = " << b << "\n" << "c = " << c << "\n";
}

void Quadratic::swap(Quadratic& other) {
    std::swap(x, other.x);
    std::swap(a, other.a);
    std::swap(b, other.b);
    std::swap(c, other.c);
}

FunctionPtr Quadratic::cin(istream& in) {
    std::cout << "x = "; in >> x;
    std::cout << "a = "; in >> a;
    std::cout << "b = "; in >> b;
    std::cout << "c = "; in >> c;
    return this->clone();
}

//Harmonic

float Harmonic::get_w() {
    return w;
}

float Harmonic::get_fi() {
    return fi;
}

void Harmonic::set_w(float w) {
    this->w = w;
}

void Harmonic::set_fi(float fi) {
    this->fi = fi;
}


Harmonic::Harmonic() {
    x = 2;
    a = 2;
    w = 2;
    fi = 2;
}

Harmonic::Harmonic(float x, float a, float w, float fi) {
    this->x = x;
    this->a = a;
    this->w = w;
    this->fi = fi;
}

Harmonic::Harmonic(const Harmonic& func) {
    this->x = func.x;
    this->a = func.a;
    this->w = func.w;
    this->fi = func.fi;
}

Harmonic& Harmonic::operator=(Harmonic& other) {
    swap(other);
    return *this;
}

FunctionPtr Harmonic::clone() {
    return make_unique<Harmonic>(x, a, w, fi);
}

float Harmonic::calc_from_argument() const {
    return a * cos(w * x + fi);
}

float Harmonic::getting_the_derivative() const {
    return (-a) * sin(w * x + fi) * w;
}

float Harmonic::obtaining_the_antiderivative() const {
    if (w == 0) {
        throw std::runtime_error("denominator is wrong.");
    }
    return (a * sin(w * x + fi)) / w;
}

void Harmonic::print(ostream& stream) const {
    stream << " Type of Function: Harmonic" << endl;
    stream << "x = " << x << "\n" << "a = " << a << "\n" << "w = " << w << "\n" << "fi = " << fi << "\n";
}

void Harmonic::swap(Harmonic& other) {
    std::swap(x, other.x);
    std::swap(a, other.a);
    std::swap(w, other.w);
    std::swap(fi, other.fi);
}

FunctionPtr Harmonic::cin(istream& in) {
    std::cout << "x = "; in >> x;
    std::cout << "a = "; in >> a;
    std::cout << "w = "; in >> w;
    std::cout << "fi = "; in >> fi;
    return this->clone();
}

//FunctionsSet

FunctionsSet::FunctionsSet(vector<FunctionPtr> funcs) {
    for (auto elem : funcs) _function.push_back(elem->clone());
}

FunctionsSet::FunctionsSet(FunctionsSet& other) {
    _function.reserve(other.get_size());
    for (auto elem: other._function) {
        _function.push_back(elem->clone());
    }
}

void FunctionsSet::swap(FunctionsSet& other) {
    std::swap(_function, other._function);
}

FunctionsSet& FunctionsSet::operator=(FunctionsSet& other) {
    swap(other);
    return *this;
}

int FunctionsSet::get_size() {
    return _function.size();
}

FunctionPtr FunctionsSet::operator[](int ind) const {
    if (ind<0 || ind>_function.size()) {
        throw std::runtime_error("invalid index");
    }
    return _function[ind];
}

FunctionPtr& FunctionsSet::operator[](int ind) {
    if (ind<0 || ind>_function.size()) {
        throw std::runtime_error("invalid index");
    }
    return _function[ind];
}

void FunctionsSet::add(int ind, FunctionPtr func) {
    if (ind < 0 || ind >_function.size()) {
        throw std::runtime_error("Index out of the range");
    }
    else if (ind == (this->get_size() - 1)) {
        _function.push_back(func);
    }
    else _function.insert(_function.begin() + ind, func);
}

void FunctionsSet::del(int ind) {
    _function.erase(_function.begin() + ind);
}

void FunctionsSet::clear() {
    _function.clear();
}

void FunctionsSet::print_current(int ind) const{
    system("cls");
    _function[ind]->print(cout);
}

float FunctionsSet::find_function_max_derivative() const {
    int ind = 0;
    double max_der = _function[0]->getting_the_derivative();
    for (int i = 1; i < _function.size() - 1; ++i) {
        double cur_der = _function[i]->getting_the_derivative();
        if (cur_der >= max_der) {
            ind = i;
            max_der = cur_der;
        }
    }
    return ind;
}

FunctionPtr FunctionsSet::get_function_by_index(int ind) {
    return _function[ind];
}

FunctionPtr input(Function& func) {
    int type = -1;
    Quadratic quad;
    Harmonic harm;
    while (type < 0 || type>1) {
        std::cout << "Quadratic - 0\nHarmonic - 1\n";
        std::cin >> type;
    }
    switch (type) {
    case 0:
        return(quad.cin(std::cin));
    case 1:
        return(harm.cin(std::cin));
    }
}







