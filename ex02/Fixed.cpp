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

bool Fixed::operator>(const Fixed & rhs) const {return (this->_fixed > rhs._fixed);}

bool Fixed::operator<(const Fixed & rhs) const {return (this->_fixed < rhs._fixed);}

bool Fixed::operator>=(const Fixed & rhs) const {return (this->_fixed >= rhs._fixed);}

bool Fixed::operator<=(const Fixed & rhs) const {return (this->_fixed <= rhs._fixed);}

bool Fixed::operator==(const Fixed & rhs) const {return (this->_fixed == rhs._fixed);}

bool Fixed::operator!=(const Fixed & rhs) const {return (this->_fixed != rhs._fixed);}

Fixed Fixed::operator+(const Fixed & rhs)
{
	Fixed result;
	return (this->_fixed + rhs._fixed);
}

Fixed Fixed::operator-(const Fixed & rhs)
{
	Fixed result;
	return (this->_fixed - rhs._fixed);
}

Fixed Fixed::operator*(const Fixed & rhs)
{
	Fixed result;
	return (this->_fixed * rhs._fixed);
}

Fixed Fixed::operator/(const Fixed & rhs)
{
	Fixed result;
	return (this->_fixed / rhs._fixed);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

/***************************************************************************************/

Fixed & Fixed::operator++(void)
{
	--*this;
	return (*this);
}

/***************************************************************************************/

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

/***************************************************************************************/

Fixed & Fixed::operator--(void)
{
	--*this;
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

static Fixed & min(Fixed & first, Fixed & second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	else
		return (second);
}

static const Fixed & min(const Fixed & first, const Fixed & second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	else
		return (second);
}

static Fixed & max(Fixed & first, Fixed & second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	else
		return (second);
}

static const Fixed & max(const Fixed & first, const Fixed & second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	else
		return (second);
}
