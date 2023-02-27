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
