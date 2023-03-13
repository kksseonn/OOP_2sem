#pragma once

enum FunctionsType {
	QUADRATIC,
	HARMONIC
};

class Function {
	FunctionsType type;
	float x, a, b, c, w, fi;
public:
	Function();
	Function(FunctionsType type, float x, float a, float b, float c, float w, float fi);

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

	float calc_from_argument();
	float getting_the_derivative();
	float obtaining_the_antiderivative();
};

class FunctionsSet {
	static const int CAPACITY = 10;
	Function funcs[CAPACITY];
	int size;
public:
	FunctionsSet();
	FunctionsSet(Function funcs[], int size);

	int get_size();
	Function get_function_by_index(int ind);
	Function& operator[](int ind);
	void add(int ind, Function func);
	void del(int ind);
	void clear();
	int find_function_max_derivative();
};