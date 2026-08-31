#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

/***************************************************************************************/

class Fixed
{

	public :

	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed& copy);
	~Fixed();

	Fixed & operator=(const Fixed & rhs);
	bool operator>(const Fixed & rhs) const;
	bool operator<(const Fixed & rhs) const;
	bool operator>=(const Fixed & rhs) const;
	bool operator<=(const Fixed & rhs) const;
	bool operator==(const Fixed & rhs) const;
	bool operator!=(const Fixed & rhs) const;

	Fixed operator+(const Fixed & rhs) const;
	Fixed operator-(const Fixed & rhs) const;
	Fixed operator*(const Fixed & rhs) const;
	Fixed operator/(const Fixed & rhs) const;

	Fixed operator++(int);
	Fixed & operator++(void);
	Fixed operator--(int);
	Fixed & operator--(void);

	float toFloat() const;
	int toInt() const;

	static Fixed & min(Fixed & first, Fixed & second);
	static const Fixed & min(const Fixed & first, const Fixed & second);
	static Fixed & max(Fixed & first, Fixed & second);
	static const Fixed & max(const Fixed & first, const Fixed & second);

	int getRawBits() const;
	void setRawBits(int const raw);

	private :

	static const int _fractionalPart = 8;
	int _fixed;


};

std::ostream & operator<<(std::ostream & o, const Fixed & rhs);

/***************************************************************************************/

#endif