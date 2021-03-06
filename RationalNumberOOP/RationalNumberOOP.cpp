/***************************************************************************************************
Object-oriented programming Homework
Author: Mihai Liviu-Marius
***************************************************************************************************/

#include "pch.h"
#include "Rational.hpp"

int main()
{
	Rational a, b;
	try {
		a.set_num_and_denom(-3, 10);
		b.set_num_and_denom(5, 8);
	}
	catch (const std::runtime_error &e) {
		std::cout << e.what();
	}
	
	Rational c(b);

	std::cout << "Initialization constructor: a == " << a << '\n';
	std::cout <<"Copy constructor: c == "<< c <<'\n';
	
	c += a;
	std::cout << "c += a == " << c << '\n';
	c += 9;
	std::cout << "c += 9 == " << c << '\n';

	c -= a;
	std::cout << "c -= a == " << c << '\n';
	c -= 9;
	std::cout << "c += 9 == " << c << '\n';

	c *= a;
	std::cout << "c *= a == " << c << '\n';
	c *= 9;
	std::cout << "c *= 9 == " << c << '\n';

	try {
		c /= a;
		std::cout << "c /= a == " << c << '\n';
		c /= 9;
		std::cout << "c /= 9 == " << c << '\n';
	}
	catch (const std::runtime_error &e) {
		std::cout << e.what();
	}

	c = a + b;
	std::cout << "c = a + b == " << c << '\n';
	c = a + 9;
	std::cout << "c = a + 9 == " << c << '\n';
	c = 9 + a;
	std::cout << "c = 9 + a == " << c << '\n';

	c = a - b;
	std::cout << "c = a - b == " << c << '\n';
	c = a - 9;
	std::cout << "c = a - 9 == " << c << '\n';
	c = 9 - a;
	std::cout << "c = 9 - a == " << c << '\n';

	c = a * b;
	std::cout << "c = a * b == " << c << '\n';
	c = a * 9;
	std::cout << "c = a * 9 == " << c << '\n';
	c = 9 * a;
	std::cout << "c = 9 * a == " << c << '\n';

	try {
		c = a / b;
		std::cout << "c = a / b == " << c << '\n';
		c = a / 9;
		std::cout << "c = a / 9 == " << c << '\n';
		c = 9 / a;
		std::cout << "c = 9 / a == " << c << '\n';
	}
	catch (const std::runtime_error &e) {
		std::cout << e.what();
	}

	try {
		c = c ^ 5;
		std::cout << "c ^ 5 == " << c << '\n';
		c = c ^ (-1);
		std::cout << "c ^ (-1) == " << c << '\n';
		c = c ^ 0;
		std::cout << "c ^ 0 == " << c << '\n';
	}
	catch (const std::runtime_error &e) {
		std::cout << e.what();
	}

	std::cout << "c == a : " << (c == a) << '\n';
	std::cout << "c == 1 : " << (c == 1) << '\n';
	std::cout << "1 == c : " << (1 == c) << '\n';

	std::cout << "c != a : " << (c != a) << '\n';
	std::cout << "c != 1 : " << (c != 1) << '\n';
	std::cout << "1 != c : " << (1 != c) << '\n';

	std::cout << "c < a : " << (c < a) << '\n';
	std::cout << "c < 2 : " << (c < 2) << '\n';
	std::cout << "2 < c : " << (2 < c) << '\n';

	std::cout << "c <= a : " << (c <= a) << '\n';
	std::cout << "c <= 1 : " << (c <= 1) << '\n';
	std::cout << "1 <= c : " << (1 <= c) << '\n';

	std::cout << "c > a : " << (c > a) << '\n';
	std::cout << "c > 2 : " << (c > 2) << '\n';
	std::cout << "2 > c : " << (2 > c) << '\n';

	std::cout << "c >= a : " << (c >= a) << '\n';
	std::cout << "c >= 1 : " << (c >= 1) << '\n';
	std::cout << "1 >= c : " << (1 >= c) << '\n';

	std::cout << "b as a string: " << b.rational_to_string() << '\n';
	std::cout << "a as an int: " << (int)a << '\n';
	std::cout << "a as a double: " << (double)a << '\n';
	std::cout << "a as a string: " << (std::string)a << '\n';

	std::cout << "Read a rational number from text file:" << '\n';
	Rational z;

	std::ifstream in_file("input.txt");

	try {
		in_file >> z;
	}
	catch (const std::runtime_error &e) {
		std::cout << e.what();
	}

	std::cout << z << '\n';
	in_file.close();

	std::cout << "Write a rational number in a text file." << '\n';
	std::ofstream out_file("output.txt");
	out_file << z;
	out_file.close();
	
	return 0;
}
