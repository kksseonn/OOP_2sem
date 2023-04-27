#pragma once
#include <iostream>
#define FunctionPtr Function*

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

	FunctionsType get_type() const;
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

	friend std::istream& operator>>(std::istream& in, Function& func);
	friend std::ostream& operator<<(std::ostream& out, const Function& func);
};

bool operator ==(const Function& func, const Function& other);
bool operator != (const Function& func, const Function& other);

class FunctionsSet {
	FunctionPtr* function;
	int size;
public:
	FunctionsSet();
	FunctionsSet(int size, FunctionPtr* functions);
	FunctionsSet(const FunctionsSet& func);
	~FunctionsSet();

	int get_size();
	FunctionPtr get_function_by_index(int ind);
	FunctionPtr operator[](int ind) const;
	FunctionPtr& operator[](int ind);
	FunctionsSet& operator=(FunctionsSet other);
	
	void add(int ind, Function func);
	void del(int ind);
	void clear();
	void print_current(int ind);
	int find_function_max_derivative();
	void swap(FunctionsSet& other);
};