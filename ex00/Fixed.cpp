#include "Fixed.hpp"

/***************************************************************************************/

Fixed::Fixed() : _value(0) {std::cout << "Default constructor called" << std::endl;}
Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}

Fixed::Fixed( const Fixed & copy) 
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(copy);
}


/***************************************************************************************/

Fixed & Fixed::operator=(const Fixed & to_copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = to_copy.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const 
{ 
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}
void Fixed::setRawBits(int const raw) { this->_value = raw;}


