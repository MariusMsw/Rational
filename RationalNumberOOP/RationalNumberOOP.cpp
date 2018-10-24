
#include "pch.h"
#include "Rational.hpp"

int main()
{
	Rational a(2, 10);
	std::cout << a.get_num() << "/" << a.get_denom() << "\n";
	Rational b(3, 7);
	std::cout << b.get_num() << "/" << b.get_denom() << "\n";
	a += b;
	std::cout << a.get_num() << "/" << a.get_denom() << "\n";
	
	return 0;
}
