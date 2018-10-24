#pragma once
#include <iostream>
class Rational
{
public:
	Rational(int, int);
	Rational(const Rational&);
	~Rational();

	void set_num(int);
	int get_num();

	void set_denom(int);
	int get_denom();

	Rational &operator += (Rational);
	Rational &operator += (int);

	Rational &operator -= (Rational);
	Rational &operator -= (int);

	Rational &operator *= (Rational);
	Rational &operator *= (int);

	Rational &operator /= (Rational);
	Rational &operator /= (int); 

private:
	int m_num;
	int m_denom;
	void get_canonical_function();
};



