/***************************************************************************************************
Object-oriented programming Homework
Author: Mihai Liviu-Marius
***************************************************************************************************/

#include "pch.h"
#include "Rational.hpp"

void Rational::get_canonical_function()
{
	int copy_num = abs(this->m_num);
	int copy_denom = abs(this->m_denom);

	if (copy_num == 0 && copy_denom != 0)
		return;

	if (copy_num == 0 && copy_denom == 0)
	{
		std::cout << "0/0 division!";
		return;
	}

	if (copy_denom != 0)
	{
		while (copy_num != copy_denom)
		{
			if (copy_num > copy_denom)
				copy_num = copy_num - copy_denom;
			else
				copy_denom = copy_denom - copy_num;
		}
	}
	else
	{
		std::cout << "Division by 0 is forbidden!";
		exit(0);
	}

	this->m_num /= copy_num;
	this->m_denom /= copy_denom;

	if ( (this->m_num < 0) && (this->m_denom < 0) )
	{
		this->m_num = -(this->m_num);
		this->m_denom = -(this->m_denom);
	}

}

Rational::Rational(int num, int denom)
{
	m_num = num;
	m_denom = denom;
	if (num != 0 && denom != 1)
	get_canonical_function();
}

Rational::Rational(const Rational &rational)
{
	m_num = rational.m_num;
	m_denom = rational.m_denom;
}

Rational::~Rational()
{
}

void Rational::set_num_and_denom(int num_value, int denom_value)
{
	this->m_num = num_value;
	this->m_denom = denom_value;
}

void Rational::set_num(int value)
{
	this->m_num = value;
}

int Rational::get_num() const
{
	return this->m_num;
}

void Rational::set_denom(int value)
{
	this->m_denom = value;
}

int Rational::get_denom() const
{
	return this->m_denom;
}

void Rational::operator += (const Rational &rational_number)
{
	m_num *= rational_number.m_denom;
	m_num += rational_number.m_num * m_denom;
	m_denom *= rational_number.m_denom;
	this->get_canonical_function();
}

void Rational::operator += (const int integer_number)
{
	m_num += integer_number * m_denom;
	this->get_canonical_function();
}

void Rational::operator -= (const Rational &rational_number)
{
	m_num *= rational_number.m_denom;
	m_num -= rational_number.m_num * m_denom;
	m_denom *= rational_number.m_denom;
	this->get_canonical_function();
}

void Rational::operator -= (const int integer_number)
{
	m_num -= integer_number * m_denom;
	this->get_canonical_function();
}

void Rational::operator *= (const Rational &rational_number)
{
	m_num *= rational_number.m_num;
	m_denom *= rational_number.m_denom;
	this->get_canonical_function();
}

void Rational::operator *= (const int integer_number)
{
	m_num *= integer_number;
	this->get_canonical_function();
}

void Rational::operator /= (const Rational &rational_number)
{
	m_num *= rational_number.m_denom; 
	m_denom *= rational_number.m_num;
	this->get_canonical_function();
	
}

void Rational::operator /= (const int integer_number)
{
	m_denom *= integer_number;
	this->get_canonical_function();
}

Rational & Rational::operator+()
{
	return *this;
}

Rational & Rational::operator-()
{
	m_num *= -1;
	return *this;
}

Rational double_to_rational(double double_number)
{
	int int_part = (int)floor(double_number);
	double frac_part = double_number - int_part;
	int i = 0;

	while (frac_part != 0)
	{
		frac_part *= 10;
		int_part *= 10;
		int_part += (int)floor(frac_part);
		frac_part -= floor(frac_part);
		i++;
	}

	Rational *result = new Rational(int_part, (int)pow(10, i));

	return *result;
}

Rational Rational::operator+(Rational &other)
{
	Rational *res = new Rational();

	res->m_num = this->m_num * other.m_denom + this->m_denom * other.m_num;
	res->m_denom = this->m_denom * other.m_denom;
	res->get_canonical_function();

	return *res;
}

Rational Rational::operator+(int other)
{
	Rational *res = new Rational();

	res->m_num = this->m_num + other * this->m_denom;
	res->m_denom = this->m_denom;
	res->get_canonical_function();

	return *res;
}

Rational operator+(double double_number, Rational &rational_number)
{
	Rational *res = new Rational(rational_number);
	Rational other = double_to_rational(double_number);

	res->m_num = rational_number.m_num * other.m_denom + rational_number.m_denom * other.m_num;
	res->m_denom = rational_number.m_denom * other.m_denom;
	res->get_canonical_function();

	return *res;
}

Rational Rational::operator-(Rational &other)
{
	Rational *res = new Rational();

	res->m_num = this->m_num * other.m_denom - this->m_denom * other.m_num;
	res->m_denom = this->m_denom * other.m_denom;
	res->get_canonical_function();

	return *res;
}

Rational Rational::operator-(int other)
{
	Rational *res = new Rational();

	res->m_num = this->m_num - other * this->m_denom;
	res->m_denom = this->m_denom;
	res->get_canonical_function();

	return *res;
}

Rational operator-(double double_number, Rational &rational_number)
{
	Rational *res = new Rational(rational_number);
	Rational other = double_to_rational(double_number);

	res->m_num = rational_number.m_num * other.m_denom - rational_number.m_denom * other.m_num;
	res->m_denom = rational_number.m_denom * other.m_denom;
	res->get_canonical_function();

	return *res;
}

Rational Rational::operator*(Rational &other)
{
	Rational *res = new Rational();

	res->m_num = this->m_num * other.m_num;
	res->m_denom = this->m_denom * other.m_denom;
	res->get_canonical_function();

	return *res;
}

Rational Rational::operator*(int other)
{
		Rational *res = new Rational();
		res->m_num = this->m_num * other;
		res->m_denom = this->m_denom;
		res->get_canonical_function();

		return *res;
}

Rational operator*(double double_number, Rational &rational_number)
{
	Rational *res = new Rational(rational_number);
	Rational other = double_to_rational(double_number);

	res->m_num = rational_number.m_num * other.m_num;
	res->m_denom = rational_number.m_denom * other.m_denom;
	res->get_canonical_function();

	return *res;
}

Rational Rational::operator/(Rational &other)
{
	Rational *res = new Rational();

	res->m_num = this->m_num * other.m_denom;
	res->m_denom = this->m_denom * other.m_num;
	res->get_canonical_function();

	return *res;
}

Rational Rational::operator/(int other)
{
	Rational *res = new Rational();

	res->m_num = this->m_num;
	res->m_denom = this->m_denom * other;
	res->get_canonical_function();

	return *res;
}

Rational operator/(double double_number, Rational &rational_number)
{
	Rational *res = new Rational(rational_number);
	Rational other = double_to_rational(double_number);

	res->m_num = other.m_num * rational_number.m_denom;
	res->m_denom = other.m_denom * rational_number.m_num;
	res->get_canonical_function();

	return *res;
}

Rational Rational::operator^(int exponent)
{
	Rational *res = new Rational();

	if (exponent == -1) {
		res->m_num = this->m_denom;
		res->m_denom = this->m_num;

		if (res->m_denom < 0) {
			res->m_num *= -1;
			res->m_denom *= -1;
		}

		return *res;
	}
	else {
		res->m_num = (int)pow(this->m_num, exponent);
		res->m_denom = (int)pow(this->m_denom, exponent);
		res->get_canonical_function();

		return *res;
	}
}

bool operator==(Rational &first, Rational &second)
{
	first.get_canonical_function();
	second.get_canonical_function();
	if (first.m_num == second.m_num && first.m_denom == second.m_denom)
		return true;
	return false;

}

bool operator==(Rational &rational_number, int integer_number)
{
	rational_number.get_canonical_function();
	if (rational_number.m_num / rational_number.m_denom == integer_number)
		return true;
	return false;
}

bool operator==(int integer_number, Rational &rational_number)
{
	rational_number.get_canonical_function();
	if (rational_number.m_num / rational_number.m_denom == integer_number)
		return true;
	return false;
}


bool operator!=(Rational &first, Rational &second)
{
	first.get_canonical_function();
	second.get_canonical_function();
	if (first.m_num == second.m_num && first.m_denom == second.m_denom)
		return false;
	return true;
}


bool operator!=(Rational &rational_number, int integer_number)
{
	rational_number.get_canonical_function();
	if (rational_number.m_num / rational_number.m_denom == integer_number)
		return false;
	return true;
}

bool operator!=(int integer_number, Rational &rational_number)
{
	rational_number.get_canonical_function();
	if (rational_number.m_num / rational_number.m_denom == integer_number)
		return false;
	return true;
}

bool operator<(Rational &first, Rational &second)
{
	if (first.m_num * second.m_denom < second.m_num * first.m_denom)
		return true;
	return false;
}

bool operator<(Rational &rational_number, int integer_number)
{
	if (rational_number.m_num < integer_number * rational_number.m_denom)
		return true;
	return false;
}

bool operator<(int integer_number, Rational &rational_number)
{
	if (integer_number * rational_number.m_denom < rational_number.m_num)
		return true;
	return false;
}

bool operator<=(Rational &first, Rational &second)
{
	if (first.m_num * second.m_denom <= second.m_num * first.m_denom)
		return true;
	return false;
}

bool operator<=(Rational &rational_number, int integer_number)
{
	if (rational_number.m_num <= integer_number * rational_number.m_denom)
		return true;
	return false;
}

bool operator<=(int integer_number, Rational &rational_number)
{
	if (integer_number * rational_number.m_denom <= rational_number.m_num)
		return true;
	return false;
}

bool operator>(Rational &first, Rational &second)
{
	if (first.m_num * second.m_denom > second.m_num * first.m_denom)
		return true;
	return false;
}

bool operator>(Rational &rational_number, int integer_number)
{
	if (rational_number.m_num > integer_number * rational_number.m_denom)
		return true;
	return false;
}

bool operator>(int integer_number, Rational &rational_number)
{
	if (integer_number * rational_number.m_denom > rational_number.m_num)
		return true;
	return false;
}

bool operator>=(Rational &first, Rational &second)
{
	if (first.m_num * second.m_denom >= second.m_num * first.m_denom)
		return true;
	return false;
}

bool operator>=(Rational &rational_number, int integer_number)
{
	if (rational_number.m_num >= integer_number * rational_number.m_denom)
		return true;
	return false;
}

bool operator>=(int integer_number, Rational &rational_number)
{
	if (integer_number * rational_number.m_denom >= rational_number.m_num)
		return true;
	return false;
}


std::istream& operator>> (std::istream& stream, Rational& rational_number) {
	std::string input;
	stream >> input;

	size_t backspace_pos = input.find('/');
	bool denom_exists = (backspace_pos != std::string::npos);

	if (denom_exists) {
		rational_number.m_num = std::stoi(input.substr(0, backspace_pos));
		rational_number.m_denom = std::stoi(input.substr(backspace_pos + 1, input.length()));
	}
	else {
		rational_number.m_num = std::stoi(input);
		rational_number.m_denom = 1;
	}

	rational_number.get_canonical_function();
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const Rational & rational_number)
{
	stream << rational_number.m_num << '/' << rational_number.m_denom;
	return stream;
}
