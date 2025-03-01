#ifndef POINT_HPP
# define POINT_HPP

# include <string>
# include "Fixed.hpp"

class Point
{
    private:
        Fixed &x;
        Fixed &y;

    public:
        Point(void);
        Point(const Fixed &new_x, const Fixed &new_y);
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point(void);

        bool operator==(const Point &other) const;
        Fixed &get_x(void) const;
        Fixed &get_y(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif