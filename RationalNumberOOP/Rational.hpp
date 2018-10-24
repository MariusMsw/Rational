/***************************************************************************************************
Object-oriented programming Homework
Author: Mihai Liviu-Marius
***************************************************************************************************/
#pragma once
#include <iostream>
class Rational
{
public:
	Rational(const int, const int);
	Rational(const Rational&);
	~Rational();

	void set_num_and_denom(int, int);

	void set_num(int);
	int get_num() const;

	void set_denom(int);
	int get_denom() const;

	Rational &operator += (const Rational);
	Rational &operator += (const int);

	Rational &operator -= (const Rational);
	Rational &operator -= (const int);

	Rational &operator *= (const Rational);
	Rational &operator *= (const int);

	Rational &operator /= (const Rational);
	Rational &operator /= (const int); 

private:
	int m_num;
	int m_denom;
	void get_canonical_function();
};



