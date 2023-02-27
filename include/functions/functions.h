#pragma once

int sum_stub(int lhs, int rhs);
enum FunctionsType {
	QUADRATIC,
	HARMONIC
};

class Functions {
	FunctionsType type;
	float x, a, b, c, w, fi;
public:
	Functions();

	FunctionsType get_type();
	float get_x();
	float get_a();
	float get_b();
	float get_c();
	float get_w();
	float get_fi();

	void set_type(FunctionsType type);
	void set_x(float x);
	void set_a(float a);
	void set_b(float b);
	void set_c(float c);
	void set_w(float w);
	void set_fi(float fi);

};
