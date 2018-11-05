/***************************************************************************************************
Object-oriented programming Homework
Author: Mihai Liviu-Marius
***************************************************************************************************/

#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

class Rational
{
public:
	Rational(int num = 0, int denom = 1);
	Rational(const Rational& rational_number);
	~Rational();

	void set_num_and_denom(int num_value, int denom_value);

	void set_num(int num_value);
	int get_num() const;

	void set_denom(int denom_value);
	int get_denom() const;

	std::string rational_to_string();
	operator int();
	operator double();
	operator std::string();

	Rational &operator += (const Rational& rational_number);
	Rational &operator += (int integer_number);

	Rational &operator -= (const Rational& rational_number);
	Rational &operator -= (int integer_number);

	Rational &operator *= (const Rational& rational_number);
	Rational &operator *= (int integer_number);

	Rational &operator /= (const Rational& rational_number);
	Rational &operator /= (int integer_numbe);

	Rational operator + ();
	Rational operator - ();

	friend Rational operator+ (const Rational& left, const Rational& right);
	friend Rational operator+ (const Rational& rational_number, int integer_number);
	friend Rational operator+ (int integer_number, const Rational& rational_number);

	friend Rational operator- (const Rational& left, const Rational& right);
	friend Rational operator- (const Rational& rational_number, int integer_number);
	friend Rational operator- (int integer_number, const Rational& rational_number);

	friend Rational operator* (const Rational& left, const Rational& right);
	friend Rational operator* (const Rational& rational_number, int integer_number);
	friend Rational operator* (int integer_number, const Rational& rational_number);

	friend Rational operator/ (const Rational& left, const Rational& right);
	friend Rational operator/ (const Rational& rational_number, int integer_number);
	friend Rational operator/ (int integer_number, const Rational& rational_number);

	friend Rational operator^ (const Rational &base, int exponent);

	friend bool operator == (const Rational& first, const Rational& second);
	friend bool operator == (const Rational& rational_number, int integer_number);
	friend bool operator == (int integer_number, const Rational& rational_number);

	friend bool operator != (const Rational& first, const Rational& second);
	friend bool operator != (const Rational& rational_number, int integer_number);
	friend bool operator != (int integer_number, const Rational& rational_number);

	friend bool operator < (const Rational& first, const Rational& second);
	friend bool operator < (const Rational& rational_number, int integer_number);
	friend bool operator < (int integer_number, const Rational& rational_number);

	friend bool operator <= (const Rational& first, const Rational& second);
	friend bool operator <= (const Rational& rational_number, int integer_number);
	friend bool operator <= (int integer_number, const Rational& rationl_number);

	friend bool operator > (const Rational& first, const Rational& second);
	friend bool operator > (const Rational& rational_number, int integer_number);
	friend bool operator > (int integer_number, const Rational& rational_number);

	friend bool operator >= (const Rational& first, const Rational& second);
	friend bool operator >= (const Rational& rational_number, int integer_number);
	friend bool operator >= (int integer_number, const Rational& rational_number);

	friend std::ostream& operator<<(std::ostream & stream, const Rational& rational_number);
	friend std::istream& operator>>(std::istream & stream, Rational & rational_number);

private:
	void simplify_rational_number();
	int m_num;
	int m_denom;
};