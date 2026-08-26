#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

/***************************************************************************************/

class Fixed
{

	public :

	Fixed();
	Fixed(const Fixed& copy);
	~Fixed();

	Fixed & operator=(const Fixed & to_copy);

	int getRawBits() const;
	void setRawBits(int const raw);

	private :

	int _value;
	static const int _nb = 8;

};

/***************************************************************************************/

#endif