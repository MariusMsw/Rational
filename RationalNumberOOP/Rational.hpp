/***************************************************************************************************
Object-oriented programming Homework
Author: Mihai Liviu-Marius
***************************************************************************************************/

#pragma once
#include <iostream>
#include <cmath>
#include <string>
class Rational
{
public:
	Rational(int num = 0, int denom = 0);
	Rational(const Rational&);
	~Rational();

	void set_num_and_denom(int, int);

	void set_num(int);
	int get_num() const;

	void set_denom(int);
	int get_denom() const;

	void operator += (const Rational&);
	void operator += (const int);

	void operator -= (const Rational&);
	void operator -= (const int);

	void operator *= (const Rational&);
	void operator *= (const int);

	void operator /= (const Rational&);
	void operator /= (const int);

	Rational &operator + ();
	Rational &operator - ();

	Rational operator + (Rational&);
	Rational operator +(int);
	friend Rational operator+ (double, Rational&);

	Rational operator- (Rational&);
	Rational operator- (int);
	friend Rational operator- (double, Rational&);

	Rational operator* (Rational&);
	Rational operator* (int);
	friend Rational operator* (double, Rational&);

	Rational operator/ (Rational&);
	Rational operator/ (int);
	friend Rational operator/ (double, Rational&);

	Rational operator^ (int);

	friend Rational double_to_rational(double);

	friend bool operator == (Rational&, Rational&);
	friend bool operator == (Rational&, int);
	friend bool operator == (int, Rational&);

	friend bool operator != (Rational&, Rational&);
	friend bool operator != (Rational&, int);
	friend bool operator != (int, Rational&);

	friend bool operator < (Rational&, Rational&);
	friend bool operator < (Rational&, int);
	friend bool operator < (int, Rational&);

	friend bool operator <= (Rational&, Rational&);
	friend bool operator <= (Rational&, int);
	friend bool operator <= (int, Rational&);

	friend bool operator > (Rational&, Rational&);
	friend bool operator > (Rational&, int);
	friend bool operator > (int, Rational&);

	friend bool operator >= (Rational&, Rational&);
	friend bool operator >= (Rational&, int);
	friend bool operator >= (int, Rational&);

	friend std::ostream& operator<<(std::ostream &, const Rational&);
	friend std::istream & operator>>(std::istream &, Rational &);

private:
	int m_num;
	int m_denom;
	void get_canonical_function();
};



