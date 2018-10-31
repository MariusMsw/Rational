/***************************************************************************************************
Object-oriented programming Homework
Author: Mihai Liviu-Marius
***************************************************************************************************/

#include "pch.h"
#include "Rational.hpp"

std::string Rational::rational_to_string()
{
	std::string string_number;
	if (m_denom == 1)
	{
		string_number = std::to_string(this->m_num);
	}
	else
	{
		string_number = std::to_string(m_num) + "/" + std::to_string(m_denom);
	}

	return string_number;
}

void Rational::simplify_rational_number()
{
	int copy_num = abs(this->m_num);
	int copy_denom = abs(this->m_denom);

	if (copy_num == 0 && copy_denom != 0)
		return;

		while (copy_num != copy_denom)
		{
			if (copy_num > copy_denom)
				copy_num = copy_num - copy_denom;
			else
				copy_denom = copy_denom - copy_num;
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
	if (denom == 0)
	{
		std::cout << "The denominator can't be 0!";
		exit(0);
	}

	if (denom < 0)
	{
		m_num = -num;
		m_denom = abs(denom);
	}

	else
	{
		m_num = num;
		m_denom = denom;
	}

	if (num != 0 && denom != 1)
	simplify_rational_number();
}

Rational::Rational(const Rational &rational)
{
	m_num = rational.m_num;
	m_denom = rational.m_denom;
	simplify_rational_number();
}

Rational::~Rational()
{
}

void Rational::set_num_and_denom(int num_value, int denom_value)
{
	this->m_num = num_value;
	this->m_denom = denom_value;
	simplify_rational_number();
}

void Rational::set_num(int value)
{
	this->m_num = value;
	simplify_rational_number();
}

int Rational::get_num() const
{
	return this->m_num;
}

void Rational::set_denom(int value)
{
	this->m_denom = value;
	simplify_rational_number();
}

int Rational::get_denom() const
{
	return this->m_denom;
}

Rational &Rational::operator += (const Rational &rational_number)
{
	m_num *= rational_number.m_denom;
	m_num += rational_number.m_num * m_denom;
	m_denom *= rational_number.m_denom;
	this->simplify_rational_number();
	return *this;
}

Rational &Rational::operator += (int integer_number)
{
	m_num += integer_number * m_denom;
	this->simplify_rational_number();
	return *this;
}

Rational &Rational::operator -= (const Rational &rational_number)
{
	m_num *= rational_number.m_denom;
	m_num -= rational_number.m_num * m_denom;
	m_denom *= rational_number.m_denom;
	this->simplify_rational_number();
	return *this;
}

Rational &Rational::operator -= (int integer_number)
{
	m_num -= integer_number * m_denom;
	this->simplify_rational_number();
	return *this;
}

Rational &Rational::operator *= (const Rational &rational_number)
{
	m_num *= rational_number.m_num;
	m_denom *= rational_number.m_denom;
	this->simplify_rational_number();
	return *this;
}

Rational &Rational::operator *= (int integer_number)
{
	m_num *= integer_number;
	this->simplify_rational_number();
	return *this;
}

Rational &Rational::operator /= (const Rational &rational_number)
{
	m_num *= rational_number.m_denom; 
	m_denom *= rational_number.m_num;
	this->simplify_rational_number();
	return *this;
	
}

Rational &Rational::operator /= (int integer_number)
{
	m_denom *= integer_number;
	this->simplify_rational_number();
	return *this;
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

Rational operator+(const Rational &left, const Rational &right)
{
	Rational result(left);
	result += right;
	return result;
}

Rational operator+(const Rational &rational_number, int integer_number)
{
	Rational result(rational_number);
	result += integer_number;
	return result;
}

Rational operator+(int integer_number, const Rational &rational_number)
{
	Rational result(rational_number);
	result += integer_number;
	return result;
}

Rational operator-(const Rational &left, const Rational&right)
{
	Rational result(left);
	result -= right;
	return result;
}

Rational operator-(const Rational &rational_number, int integer_number)
{
	Rational result(rational_number);
	result -= integer_number;
	return result;
}

Rational operator-(int integer_number, const Rational &rational_number)
{
	Rational result(rational_number);
	result -= integer_number;
	return -result;
}

Rational operator*(const Rational &left, const Rational &right)
{
	Rational result(left);
	result *= right;
	return result;
}

Rational operator*(const Rational &rational_number, int integer_number)
{
	Rational result(rational_number);
	result *= integer_number;
	return result;
}

Rational operator*(int integer_number, const Rational &rational_number)
{
	Rational result(rational_number);
	result *= integer_number;
	return result;
}

Rational operator/(const Rational &left, const Rational &right)
{
	Rational result(left);
	result /= right;
	return result;
}

Rational operator/(const Rational &rational_number, int integer_number)
{
	Rational result(rational_number);
	result /= integer_number;
	return result;
}

Rational operator/(int integer_number, const Rational &rational_number)
{
	Rational result(rational_number);
	result /= integer_number;
	return result^(-1);
}

Rational operator^(const Rational &base, int exponent)
{
	Rational result(base);

	if (exponent == -1)
	{
		result.m_num = base.m_denom;
		result.m_denom = base.m_num;

		if (result.m_denom < 0) {
			result.m_num *= -1;
			result.m_denom *= -1;
		}

		return result;
	}
	else
	{
		result.m_num = (int)pow(result.m_num, exponent);
		result.m_denom = (int)pow(result.m_denom, exponent);
		result.simplify_rational_number();

		return result;
	}
}

bool operator==(const Rational &first, const Rational &second)
{
	Rational first_copy(first), second_copy(second);
	first_copy.simplify_rational_number();
	second_copy.simplify_rational_number();
	return (first_copy.m_num == second_copy.m_num && first_copy.m_denom == second_copy.m_denom);

}

bool operator==(const Rational &rational_number, int integer_number)
{
	Rational rational_number_copy(rational_number);
	rational_number_copy.simplify_rational_number();
	return (rational_number_copy.m_num / rational_number_copy.m_denom == integer_number);
}

bool operator==(int integer_number, const Rational &rational_number)
{
	Rational rational_number_copy(rational_number);
	rational_number_copy.simplify_rational_number();
	return (rational_number_copy.m_num / rational_number_copy.m_denom == integer_number);
}


bool operator!=(const Rational &first, const Rational &second)
{
	Rational first_copy(first), second_copy(second);
	first_copy.simplify_rational_number();
	second_copy.simplify_rational_number();
	return !(first_copy == second_copy);
}


bool operator!=(const Rational &rational_number, int integer_number)
{
	Rational rational_number_copy(rational_number);
	rational_number_copy.simplify_rational_number();
	return !(rational_number_copy == integer_number);
		
}

bool operator!=(int integer_number, const Rational &rational_number)
{
	Rational rational_number_copy(rational_number);
	rational_number_copy.simplify_rational_number();
	return !(integer_number == rational_number_copy);
}

bool operator<(const Rational &first, const Rational &second)
{
	return (first.m_num * second.m_denom < second.m_num * first.m_denom);
}

bool operator<(const Rational &rational_number, int integer_number)
{
	return (rational_number.m_num < integer_number * rational_number.m_denom);
}

bool operator<(int integer_number, const Rational &rational_number)
{
	return (integer_number * rational_number.m_denom < rational_number.m_num);
}

bool operator<=(const Rational &first, const Rational &second)
{
	return (first.m_num * second.m_denom <= second.m_num * first.m_denom);

}

bool operator<=(const Rational &rational_number, int integer_number)
{
	return (rational_number.m_num <= integer_number * rational_number.m_denom);
}

bool operator<=(int integer_number, const Rational &rational_number)
{
	return (integer_number * rational_number.m_denom <= rational_number.m_num);

}

bool operator>(const Rational &first, const Rational &second)
{
	return !(first < second);
}

bool operator>(const Rational &rational_number, int integer_number)
{
	return !(rational_number < integer_number);
}

bool operator>(int integer_number, const Rational &rational_number)
{
	return !(integer_number < rational_number);
}

bool operator>=(const Rational &first, const Rational &second)
{
	return (first.m_num * second.m_denom >= second.m_num * first.m_denom);
}

bool operator>=(const Rational &rational_number, int integer_number)
{
	return (rational_number.m_num >= integer_number * rational_number.m_denom);
}

bool operator>=(int integer_number, const Rational &rational_number)
{
	return (integer_number * rational_number.m_denom >= rational_number.m_num);

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

	rational_number.simplify_rational_number();
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const Rational & rational_number)
{
	stream << rational_number.m_num << '/' << rational_number.m_denom;
	return stream;
}
