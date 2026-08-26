#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

/***************************************************************************************/

class Fixed
{

	public :

	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed& copy);
	~Fixed();

	Fixed & operator=(const Fixed & to_copy);

	float toFloat() const;
	int toInt() const;

	int getRawBits() const;
	void setRawBits(int const raw);

	private :

	int _fixed;
	static const int _fractionalPart = 8;

};

std::ostream & operator<<(std::ostream & o, Fixed & f);

/***************************************************************************************/

// int 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000

#endif