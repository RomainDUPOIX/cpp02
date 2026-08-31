#include "Fixed.hpp"

/***************************************************************************************/

Fixed::Fixed() : _fixed(0) {}
Fixed::~Fixed() {}

/***************************************************************************************/

Fixed::Fixed(const int i) 
{
	this->_fixed = i;
	this->_fixed = this->_fixed << this->_fractionalPart;
}

Fixed::Fixed(const float f)
{
	this->_fixed = roundf((1 << _fractionalPart) * f);
}

Fixed::Fixed(const Fixed & copy) 
{
	operator=(copy);
}


/***************************************************************************************/

Fixed & Fixed::operator=(const Fixed & to_copy)
{
	this->_fixed = to_copy.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed & rhs) const {return (this->_fixed > rhs._fixed);}

bool Fixed::operator<(const Fixed & rhs) const {return (this->_fixed < rhs._fixed);}

bool Fixed::operator>=(const Fixed & rhs) const {return (this->_fixed >= rhs._fixed);}

bool Fixed::operator<=(const Fixed & rhs) const {return (this->_fixed <= rhs._fixed);}

bool Fixed::operator==(const Fixed & rhs) const {return (this->_fixed == rhs._fixed);}

bool Fixed::operator!=(const Fixed & rhs) const {return (this->_fixed != rhs._fixed);}

Fixed Fixed::operator+(const Fixed & rhs)
{
	Fixed result;

	result = this->_fixed + rhs._fixed;
	return (result);
}

Fixed Fixed::operator-(const Fixed & rhs)
{
	Fixed result;

	result = this->_fixed - rhs._fixed;
	return (result);
}

Fixed Fixed::operator*(const Fixed & rhs)
{
	Fixed result;

	result = ((float)this->_fixed / (1 << 8)) * ((float)rhs._fixed / (1 << 8));
	return (result);
}

Fixed Fixed::operator/(const Fixed & rhs)
{
	Fixed result;

	result = ((float)this->_fixed / (1 << 8)) / ((float)rhs._fixed / (1 << 8));
	return (result);
}

Fixed & Fixed::operator++(void)
{
	++(this->_fixed);
	return (*this);
}


Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

/***************************************************************************************/


/***************************************************************************************/

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(this->_fixed);
	return (tmp);
}

/***************************************************************************************/

Fixed & Fixed::operator--(void)
{
	--(this->_fixed);
	return (*this);
}

/***************************************************************************************/

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

Fixed & Fixed::min(Fixed & first, Fixed & second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	else
		return (second);
}

const Fixed & Fixed::min(const Fixed & first, const Fixed & second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	else
		return (second);
}

Fixed & Fixed::max(Fixed & first, Fixed & second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	else
		return (second);
}

const Fixed & Fixed::max(const Fixed & first, const Fixed & second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	else
		return (second);
}

/**************************************************************************************/

// 
// | 128 64 32 16 | 8 4 2 1 |