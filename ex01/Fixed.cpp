#include "Fixed.hpp"

/***************************************************************************************/

Fixed::Fixed() : _fixed(0) {std::cout << "Default constructor called" << std::endl;}
Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}

/***************************************************************************************/

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = i;
	this->_fixed = this->_fixed << this->_fractionalPart;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = (1 << _fractionalPart) * f;
}

Fixed::Fixed(const Fixed & copy) 
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(copy);
}


/***************************************************************************************/

Fixed & Fixed::operator=(const Fixed & to_copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = to_copy.getRawBits();
	return (*this);
}

std::ostream & operator<<(std::ostream & o, const Fixed & rhs)
{
	o << ((float)rhs.getRawBits() / (1 << 8));
	return (o);
}


/***************************************************************************************/

int Fixed::getRawBits() const {return (this->_fixed);}

void Fixed::setRawBits(int const raw) { this->_fixed = raw;}

/***************************************************************************************/

float Fixed::toFloat() const
{
	float f;

	f = this->_fixed << this->_fractionalPart;
	return (f);
}

int Fixed::toInt() const
{
	int i;

	i = this->_fixed << this->_fractionalPart;
	return (i);
}

/***************************************************************************************/
// 0000 0000 | 0000 0000 | 0000 0000 | 0100 0000
// 0000 0000 | 0000 0000 | 0010 1010 | 0000 0000
// 0000 0000 | 0000 0000 | 0000 0000 | 0010 1010

// 42.25

// 255 * 0.5 = 128
// 1/4 = 25% = 0.25

// 25% = 25/100 
// 25% de 500 	

// 255 * 0.25

// (255 * 42.42) = 255 * 1 + 255 * 0.42

//
