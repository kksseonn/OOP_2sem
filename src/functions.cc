#include <functions/functions.h>
#include <cmath>
#include <stdexcept>

Functions::Functions() {
    type = QUADRATIC;
    x = 1;
    a = 1;
    b = 1;
    c = 1;
    w = 0;
    fi = 0;
}

Functions::Functions(FunctionsType type, float x, float a, float b, float c, float w, float fi) {
    this->type = type;
    this->x = x;
    this->a = a;
    this->b = b;
    this->c = c;
    this->w = w;
    this->fi = fi;
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

float Functions::calc_from_argument() {
    switch (type)
    {
    case QUADRATIC:
        return a * pow(x, 2) + b * x + c;
    case HARMONIC:
        return a * cos(w * x + fi);
    }
}

float Functions::getting_the_derivative() {
    switch (type)
    {
    case QUADRATIC:
        return 2*a*x+b;
    case HARMONIC:
        return (-a)* sin(w * x + fi)* w;
    }
}

float Functions::obtaining_the_antiderivative() {
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

//float Functions::search_in_the_last_feature_set() {
//    switch (type)
//    {
//    case QUADRATIC:
//        break;
//    case HARMONIC:
//        break;
//    }
//}