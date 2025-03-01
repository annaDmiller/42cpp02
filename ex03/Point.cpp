#include "Point.hpp"

Point::Point(void) : x(Fixed(0)), y(Fixed(0))
{
    return ;
}

Point::Point(const Fixed &new_x, const Fixed &new_y) : x(new_x), y(new_y)
{
    return ;
}

Point::Point(const Point &other) : x(other.get_x()), y(other.get_y())
{
    return ;
}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        this->x = other.get_x();
        this->y = other.get_y();
    }
    return (*this);
}

Point::~Point(void)
{
    return ;
}

bool Point::operator==(const Point &other) const
{
    if (this->x == other.x && this->y == other.y)
        return (true);
    return (false);
}

Fixed Point::get_x(void) const
{
    Fixed temp = Fixed(this->x);
    return (temp);
}

Fixed Point::get_y(void) const
{
    return (this->y);
}
