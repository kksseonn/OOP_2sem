#pragma warning(disable:6386)
#include <functions/functions.h>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#define SIZE 4

std::string string_functions_type(FunctionsType type) {
    switch (type)
    {
    case QUADRATIC:
        return "QUADRATIC";
    case HARMONIC:
        return "HARMONIC";
    default:
        throw std::runtime_error("wrong type exception");
    }
    return "";
}

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

FunctionsType Function::get_type() const {
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

std::istream& operator>>(std::istream& in, Function& func) {
    std::cout << "choose function type:\n 0 - Quadratic\n 1 - Harmonic\n";
    int key;
    in >> key;
    if (key == 0) {
        func.type = QUADRATIC;
        func.fi = func.w = 0;
        std::cout << "input a: ";
        in >> func.a;
        std::cout << "input x: ";
        in >> func.x;
        std::cout << "input b: ";
        in >> func.b;
        std::cout << "input c: ";
        in >> func.c;
    }
    else if(key==1){
        func.type = HARMONIC;
        func.b = func.c = 0;
        std::cout << "input a: ";
        in >> func.a;
        std::cout << "input x: ";
        in >> func.x;
        std::cout << "input w: ";
        in >> func.w;
        std::cout << "input fi: ";
        in >> func.fi;
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Function& func) {
    out << "type:" << string_functions_type(func.type) << "\n";
    if (func.type == QUADRATIC) {
        out << "a = " << func.a << "\n" << "b = " << func.b << "\n" <<
            "c = " << func.c << "\n" << "x = " << func.x<<"\n";
    }
    else {
        out << "a = " << func.a << "\n" << "w = " << func.w << "\n" <<
            "fi = " << func.fi << "\n" << "x = " << func.x<<"\n";
    }
    return out;
}

bool operator ==(const Function& func, const Function& other) {
    bool eq_type = false;
    if (func.get_type() == other.get_type())
        eq_type = true;
    return eq_type;
}

bool operator !=(const Function& func, const Function& other) {
    return !(func == other);
}

FunctionsSet::FunctionsSet() {
    this->size = 5;
    function = new Function * [size];
    for (int i = 0; i < size; ++i) {
        this->function[i] = new Function();
    }
}

FunctionsSet::FunctionsSet(int size, FunctionPtr* functions) {
    this->size = size;
    function = new Function * [size];
    for (int i = 0; i < size; ++i) {
        this->function[i] = new Function();
        this->function[i]->set_type(functions[i]->get_type());
        this->function[i]->set_x(functions[i]->get_x());
        this->function[i]->set_a(functions[i]->get_a());
        this->function[i]->set_b(functions[i]->get_b());
        this->function[i]->set_c(functions[i]->get_c());
        this->function[i]->set_w(functions[i]->get_w());
        this->function[i]->set_fi(functions[i]->get_fi());
    }
}

FunctionsSet::FunctionsSet(const FunctionsSet& func) {
    function = new Function * [SIZE];
    this->size = func.size;
    for (int i = 0; i < SIZE; ++i) {
        this->function[i] = func.function[i];
    }
}

FunctionsSet::~FunctionsSet() {
    for (int i = 0; i < size; ++i) {
        delete function[i];
    }
    delete[] function;
}

FunctionPtr FunctionsSet::get_function_by_index(int i) {
    return function[i];
}

int FunctionsSet::get_size() {
    return size;
}

FunctionPtr FunctionsSet::operator[](int ind) const {
    if (ind<0 || ind>size) {
        throw std::runtime_error("invalid index");
    }
    return function[ind];
}

FunctionPtr& FunctionsSet::operator[](int ind) {
    if (ind<0 || ind>size) {
        throw std::runtime_error("invalid index");
    }
    return function[ind];
}

FunctionsSet& FunctionsSet::operator =(FunctionsSet other) {
    swap(other);
    return *this;
}

void FunctionsSet::add(int ind, Function func) {
    if (ind < 0 || ind > size) {
        throw std::runtime_error("Ind out of the range");
    }
    ++size;
    FunctionPtr* functions = new Function * [size];
    for (int i = 0; i < ind; ++i){
        functions[i] = new Function(*this->function[i]);
    }

    functions[ind] = new Function(func);

    for (int i = size - 1; i > ind; --i) {
        functions[i] = new Function(*this->function[i - 1]);
    }
    std::swap(this->function, functions);
}

void FunctionsSet::del(int ind) {
    if (size <= 0) {
        throw std::runtime_error("Array is empty");
    }
    for (int i = ind; i < size - 1; ++i) {
        function[i] = function[i + 1];
    }
    --size;
}

void FunctionsSet::clear() {
    function = nullptr;
    size = 0;
}

void FunctionsSet::print_current(int ind) {
    system("cls");
    std::cout << *function[ind];
}

int FunctionsSet::find_function_max_derivative() {
    int ind = 0;
    double max_der = function[0]->getting_the_derivative();
    for (int i = 1; i < size - 1; ++i) {
        double cur_der = function[i]->getting_the_derivative();
        if (cur_der >= max_der) {
            ind = i;
            max_der = cur_der;
        }
    }
    return ind;
}

void FunctionsSet::swap(FunctionsSet& other) {
    std::swap(function, other.function);
    std::swap(size, other.size);
}

