#include "Fixed.hpp"

/***************************************************************************************/

Fixed::Fixed() : _fixed(0) {std::cout << "Default constructor called" << std::endl;}
Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}

/***************************************************************************************/

Fixed::Fixed(const int i) 
{
	this->_fixed >> this->_fractionalPart;
	this->_fixed = i;
}

Fixed::Fixed(const float f) 
{
	this->_fixed >> this->_fractionalPart;
	this->_fixed = f;
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
	o << rhs.getRawBits();
	return (o);
}


/***************************************************************************************/

int Fixed::getRawBits() const 
{ 
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

void Fixed::setRawBits(int const raw) { this->_fixed = raw;}

/***************************************************************************************/

float Fixed::toFloat() const
{
	this->_fixed << this->_fractionalPart;
	return (this->_fixed);
}

int Fixed::toInt() const
{
	this->_fixed << this->_fractionalPart;
	return (this->_fixed);
}

/***************************************************************************************/