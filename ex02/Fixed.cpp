#include "Fixed.hpp"

Fixed::Fixed(void) : num_value(0)
{
    return ;
}

Fixed::Fixed(const int num) : num_value(num << bits)
{
    return ;
}

Fixed::Fixed(const float num) : num_value((int)roundf(num * (1 << bits)))
{
    return ;
}

Fixed::Fixed(const Fixed &other)
{
    this->setRawBits(other.getRawBits());
    return ;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return (*this);
}

Fixed::~Fixed(void)
{
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
    return ((float)(this->num_value) / (1 << bits));
}

int Fixed::toInt(void) const
{
    return (this->num_value >> bits);
}

std::ostream &operator<<(std::ostream& out, const Fixed& number)
{
    if (number.toFloat() == (int)number.toFloat())
        out << number.toInt();
    else
        out << number.toFloat();
    //    out << std::fixed << std::setprecision(2) << number.toFloat();
    return (out);
}
bool Fixed::operator>(const Fixed &other) const
{
    if (this->getRawBits() > other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed &other) const
{
    if (this->getRawBits() < other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed &other) const
{
    if (this->getRawBits() >= other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
    if (this->getRawBits() <= other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed &other) const
{
    if (this->getRawBits() == other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed &other) const
{
    if (this->getRawBits() != other.getRawBits())
        return (true);
    return (false);
}

Fixed Fixed::operator+(const Fixed &other)
{
    Fixed temp;
    temp.setRawBits(this->getRawBits() + other.getRawBits());
    return (temp.toFloat());
}

Fixed Fixed::operator-(const Fixed &other)
{
    Fixed temp;
    temp.setRawBits(this->getRawBits() - other.getRawBits());
    return (temp.toFloat());
}

Fixed Fixed::operator*(const Fixed &other)
{
    Fixed temp;
    temp.setRawBits((this->getRawBits() * other.getRawBits()) / (1 << this->bits));
    return (temp);
}

Fixed Fixed::operator/(const Fixed &other)
{
    Fixed temp;
    temp.setRawBits(this->getRawBits() * (1 << this->bits) / other.getRawBits());
    return (temp.toFloat());
}

Fixed &Fixed::operator++(void)
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->setRawBits(this->getRawBits() + 1);
    return (temp);
}

Fixed &Fixed::operator--(void)
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->setRawBits(this->getRawBits() - 1);
    return (temp);
}