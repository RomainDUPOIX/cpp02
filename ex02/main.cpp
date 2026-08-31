#include "Fixed.hpp"
#include <iostream>

/***************************************************************************************/

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( b ) / Fixed( 2 ));
	Fixed const d( Fixed ( b ) + Fixed( c ));
	Fixed const e( Fixed ( b ) - Fixed( c ));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << c << std::endl;
	std::cout << Fixed::max( a, c ) << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;

	return (0);
}