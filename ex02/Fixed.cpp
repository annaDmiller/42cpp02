#include "Fixed.hpp"

Fixed::Fixed(void) : num_value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const int num) : num_value(num << bits)
{
    std::cout << "Int constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const float num) : num_value(static_cast<int>(num * (1 << bits)))
{
    std::cout << "Float constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(other.getRawBits());
    return ;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Fixed::getRawBits(void) const
{
    return (this->num_value);
}

void Fixed::setRawBits(int const raw)
{
    this->num_value = raw;
    return ;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->num_value) / (1 << bits));
}

int Fixed::toInt(void) const
{
    return (this->num_value >> bits);
}

std::ostream &operator<<(std::ostream& out, const Fixed& number)
{
    if (number.toFloat() == (int)number.toFloat())
        out << std::fixed << std::setprecision(0) << number.toFloat();
    else
        out << std::fixed << std::setprecision(2) << number.toFloat();
    return (out);
}