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
	this->_fixed = roundf((1 << _fractionalPart) * f);
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

	f = (float)this->_fixed / (1 << _fractionalPart);
	return (f);
}

int Fixed::toInt() const
{
	int i;

	i = this->_fixed / (1 << _fractionalPart);
	return (i);
}

/***************************************************************************************/
