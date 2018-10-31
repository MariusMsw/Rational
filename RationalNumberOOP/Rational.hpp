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

	std::string rational_to_string();

	Rational &operator += (const Rational&);
	Rational &operator += (int);

	Rational &operator -= (const Rational&);
	Rational &operator -= (int);

	Rational &operator *= (const Rational&);
	Rational &operator *= (int);

	Rational &operator /= (const Rational&);
	Rational &operator /= (int);

	Rational &operator + ();
	Rational &operator - ();

	friend Rational operator + (const Rational&, const Rational&);
	friend Rational operator +(const Rational&, int);
	friend Rational operator+ (int, const Rational&);

	friend Rational operator- (const Rational&, const Rational&);
	friend Rational operator- (const Rational&, int);
	friend Rational operator- (int, const Rational&);

	friend Rational operator* (const Rational&, const Rational&);
	friend Rational operator* (const Rational&, int);
	friend Rational operator* (int, const Rational&);

	friend Rational operator/ (const Rational&, const Rational&);
	friend Rational operator/ (const Rational&, int);
	friend Rational operator/ (int, const Rational&);

	friend Rational operator^ (const Rational &, int);

	friend bool operator == (const Rational&, const Rational&);
	friend bool operator == (const Rational&, int);
	friend bool operator == (int, const Rational&);

	friend bool operator != (const Rational&, const Rational&);
	friend bool operator != (const Rational&, int);
	friend bool operator != (int, const Rational&);

	friend bool operator < (const Rational&, const Rational&);
	friend bool operator < (const Rational&, int);
	friend bool operator < (int, const Rational&);

	friend bool operator <= (const Rational&, const Rational&);
	friend bool operator <= (const Rational&, int);
	friend bool operator <= (int, const Rational&);

	friend bool operator > (const Rational&, const Rational&);
	friend bool operator > (const Rational&, int);
	friend bool operator > (int, const Rational&);

	friend bool operator >= (const Rational&, const Rational&);
	friend bool operator >= (const Rational&, int);
	friend bool operator >= (int, const Rational&);

	friend std::ostream& operator<<(std::ostream &, const Rational&);
	friend std::istream& operator>>(std::istream &, Rational &);

private:
	void simplify_rational_number();
	int m_num;
	int m_denom;
};