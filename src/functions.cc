#include <functions/functions.h>

int sum_stub(int lhs, int rhs) {
    return lhs + rhs;
}

Functions::Functions() {
    type = QUADRATIC;
    x = 1;
    a = 1;
    b = 1;
    c = 1;
}

FunctionsType Functions::get_type() {
    return type;
}

float Functions::get_x() {
    return x;
}

float Functions::get_a() {
    return a;
}

float Functions::get_b() {
    return b;
}

float Functions::get_c() {
    return c;
}

float Functions::get_w() {
    return w;
}

float Functions::get_fi() {
    return fi;
}

void Functions::set_type(FunctionsType type) {
    this->type = type;
}

void Functions::set_x(float x) {
    this->x = x;
}

void Functions::set_a(float a) {
    this->a = a;
}

void Functions::set_b(float b) {
    this->b = b;
}

void Functions::set_c(float c) {
    this->c = c;
}

void Functions::set_w(float w) {
    this->w = w;
}

void Functions::set_fi(float fi) {
    this->fi = fi;
}

