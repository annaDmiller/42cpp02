#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );
    Fixed const d( Fixed( 5.05f ) + Fixed( 2 ) );
    Fixed const e( Fixed( 5.05f ) - Fixed( 2 ) );
    Fixed const b1 = b;

    std::cout << "a = " << a << std::endl;
    std::cout << std::endl;
    
    std::cout << "Incrementing" << std::endl;
    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << std::endl;

    std::cout << "Decrementing" << std::endl;
    std::cout << "--a = " << --a << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "a-- = " << a-- << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << std::endl;

    std::cout << "Arithmetic operations" << std::endl;
    std::cout << "b = 5.05 * 2 = " << b << std::endl;
    std::cout << "c = 5.05 / 2 = " << c << std::endl;
    std::cout << "d = 5.05 + 2 = " << d << std::endl;
    std::cout << "e = 5.05 - 2 = " << e << std::endl;
    std::cout << std::endl;

    std::cout << "Comparisons" << std::endl;
    std::cout << "b < d ? " << (b < d) << std::endl;
    std::cout << "b > d ? " << (b > d) << std::endl;
    std::cout << "b <= d ? " << (b <= d) << std::endl;
    std::cout << "b >= d ? " << (b >= d) << std::endl;
    std::cout << "b == d ? " << (b == d) << std::endl;
    std::cout << "b != d ? " << (b != d) << std::endl;
    std::cout << "b1 = b; b == b1 ? " << (b == b1) << std::endl;
    std::cout << std::endl;

    std::cout << "MIN/MAX" << std::endl;
    std::cout << "MAX between a and b - (b)" << Fixed::max( a, b ) << std::endl;
    std::cout << "MIN between a and b - (a)" << Fixed::min( a, b ) << std::endl;
    std::cout << "MAX between b and c - (b)" << Fixed::max( b, c ) << std::endl;
    std::cout << "MIN between b and c - (c)" << Fixed::min( b, c ) << std::endl;

    return 0;
}