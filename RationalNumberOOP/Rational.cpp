#include "pch.h"
#include "Rational.hpp"

void Rational::get_canonical_function()
{
	int copy_num = this->m_num;
	int copy_denom = this->m_denom;
	if (copy_num != 0)
	{
		if (copy_num < 0)
			copy_num = -copy_num;

		while (copy_num != copy_denom)
		{
			if (copy_num > copy_denom)
				copy_num = copy_num - copy_denom;
			else
				copy_denom = copy_denom - copy_num;
		}
	}
	this->m_num /= copy_num;
	this->m_denom /= copy_denom;

}

Rational::Rational(int num = 0, int denom = 1)
{
	m_num = num;
	m_denom = denom;
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

void Rational::set_num(int value)
{
	this->m_num = value;
}

int Rational::get_num()
{
	return this->m_num;
}

void Rational::set_denom(int value)
{
	this->m_denom = value;
}

int Rational::get_denom()
{
	return this->m_denom;
}

Rational & Rational::operator += (Rational rational_number)
{
	m_num *= rational_number.m_denom;
	m_num += rational_number.m_num * m_denom;
	m_denom *= rational_number.m_denom;
	get_canonical_function();
	return *this;
}

Rational & Rational::operator += (int integer_number)
{
	integer_number = integer_number * m_denom;
	m_num += integer_number;
	get_canonical_function();
	return *this;
}

Rational & Rational::operator -= (Rational rational_number)
{
	m_num *= rational_number.m_denom;
	m_num -= rational_number.m_num * m_denom;
	m_denom *= rational_number.m_denom;
	get_canonical_function();
	return *this;
}

Rational & Rational::operator -= (int integer_number)
{
	integer_number = integer_number * m_denom;
	m_num -= integer_number;
	get_canonical_function();
	return *this;
}

Rational & Rational::operator *= (Rational rational_number)
{
	m_num *= rational_number.m_num;
	m_denom *= rational_number.m_denom;
	get_canonical_function();
	return *this;
}

Rational & Rational::operator *= (int integer_number)
{
	m_num *= integer_number;
	get_canonical_function();
	return *this;
}

Rational & Rational::operator /= (Rational rational_number)
{
	m_num *= rational_number.m_denom;
	m_denom *= rational_number.m_num;
	get_canonical_function();
	return *this;
}

Rational & Rational::operator /= (int integer_number)
{
	m_denom *= integer_number;
	get_canonical_function();
	return *this;
}
