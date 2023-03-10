#include <functions/functions.h>
#include <cmath>
#include <stdexcept>

Function::Function() {
    type = QUADRATIC;
    x = 1;
    a = 1;
    b = 1;
    c = 1;
    w = 0;
    fi = 0;
}

Function::Function(FunctionsType type, float x, float a, float b, float c, float w, float fi) {
    this->type = type;
    this->x = x;
    this->a = a;
    this->b = b;
    this->c = c;
    this->w = w;
    this->fi = fi;
}

FunctionsType Function::get_type() {
    return type;
}

float Function::get_x() {
    return x;
}

float Function::get_a() {
    return a;
}

float Function::get_b() {
    return b;
}

float Function::get_c() {
    return c;
}

float Function::get_w() {
    return w;
}

float Function::get_fi() {
    return fi;
}

void Function::set_type(FunctionsType type) {
    this->type = type;
}

void Function::set_x(float x) {
    this->x = x;
}

void Function::set_a(float a) {
    this->a = a;
}

void Function::set_b(float b) {
    this->b = b;
}

void Function::set_c(float c) {
    this->c = c;
}

void Function::set_w(float w) {
    this->w = w;
}

void Function::set_fi(float fi) {
    this->fi = fi;
}

float Function::calc_from_argument() {
    switch (type)
    {
    case QUADRATIC:
        return a * pow(x, 2) + b * x + c;
    case HARMONIC:
        return a * cos(w * x + fi);
    }
}

float Function::getting_the_derivative() {
    switch (type)
    {
    case QUADRATIC:
        return 2*a*x+b;
    case HARMONIC:
        return (-a)* sin(w * x + fi)* w;
    }
}

float Function::obtaining_the_antiderivative() {
    switch (type)
    {
    case QUADRATIC:
        return ((a*pow(x,3))/3)+((b*pow(x,2))/2)+c*x;
    case HARMONIC:
        if (w == 0) {
            throw std::runtime_error("denominator is wrong.");
        }
        return (a*sin(w*x+fi))/w;
    }
}

FunctionsSet::FunctionsSet() {
    this->size = 5;
    for (int i = 0; i < 5; ++i) this->funcs[i]=Function();
}

Function FunctionsSet::get_function_by_index(int ind) {
    return funcs[ind];
}

int FunctionsSet::get_size() {
    return size;
}

Function& FunctionsSet::operator[](int ind) {
    return funcs[ind];
}