#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
    return ;
}

Point::Point(const Fixed &new_x, const Fixed &new_y) : x(new_x), y(new_y)
{
    return ;
}

Point::Point(const Point &other)
{
    this->x = other.x;
    this->y = other.y;
    return ;
}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        this->x = other.x;
        this->y = other.y;
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

Fixed &Point::get_x(void) const
{
    return (this->x);
}

Fixed &Point::get_y(void) const
{
    return (this->y);
}
