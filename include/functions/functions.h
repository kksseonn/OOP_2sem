#pragma once
#include <memory>
#include <iostream>
#include <vector>
#define FunctionPtr shared_ptr<Function>
//#define make_sp_function make_shared<Function>
using namespace std;

class Function {
public:
	float get_x();
	float get_a();
	void set_x(float x);
	void set_a(float a);

	virtual float calc_from_argument() const = 0;
	virtual float getting_the_derivative() const = 0;
	virtual float obtaining_the_antiderivative() const = 0;
	
	virtual FunctionPtr clone() = 0;
	virtual FunctionPtr cin(istream& in) = 0;
	virtual void print(ostream& stream) const = 0;
	virtual void swap(Function& other);

	virtual ~Function() = default;

protected:
	float x, a;
	Function() = default;
	Function(const Function& func) = default;
	Function& operator =(const Function& other) = default;
};

class Quadratic : public Function {
	float b, c;
public:
	float get_b();
	float get_c();
	void set_b(float b);
	void set_c(float c);

	Quadratic();
	Quadratic(float x, float a, float b, float c);
	Quadratic(const Quadratic& func);

	Quadratic& operator=(Quadratic& other);
	FunctionPtr clone() override;
	
	float calc_from_argument() const override;
	float getting_the_derivative() const override;
	float obtaining_the_antiderivative() const override;

	void print(ostream& stream) const override;
	void swap(Quadratic& other);
	FunctionPtr cin(istream& in) override;
};

class Harmonic : public Function {
	float w, fi;
public:
	float get_w();
	float get_fi();
	void set_w(float w);
	void set_fi(float fi);

	Harmonic();
	Harmonic(float x, float a, float w, float fi);
	Harmonic(const Harmonic& func);

	Harmonic& operator=(Harmonic& other);
	FunctionPtr clone() override;

	float calc_from_argument() const override;
	float getting_the_derivative() const override;
	float obtaining_the_antiderivative() const override;

	void print(ostream& stream) const override;
	void swap(Harmonic& other);
	FunctionPtr cin(istream& in) override;

	
};

class FunctionsSet {
	vector<FunctionPtr> _function;
public:
	FunctionsSet() = default;
	FunctionsSet(vector<FunctionPtr> funcs);
	FunctionsSet(FunctionsSet& other);
	void swap(FunctionsSet& other);
	FunctionsSet& operator=(FunctionsSet& other);

	int get_size();
	FunctionPtr operator[](int ind) const;
	FunctionPtr& operator[](int ind);
	
	void add(int ind, FunctionPtr func);
	void del(int ind);
	void clear();
	void print_current(int ind) const;
	float find_function_max_derivative() const;
	FunctionPtr get_function_by_index(int ind);
};

FunctionPtr input(Function& func);