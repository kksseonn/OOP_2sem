#pragma once

int sum_stub(int lhs, int rhs);
enum FunctionsType {
	QUADRATIC,
	HARMONIC
};

class Functions {
public:
	const float FI = 1.618;
private:
	FunctionsType type;
	float x, a, b, c, w;
public:
	Functions();
	FunctionsType get_type();

};
