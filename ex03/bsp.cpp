#include "Point.hpp"
#include "Fixed.hpp"

Fixed calculate_square(Point const a, Point const b, Point const c);

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    if (point == a || point == b || point == c)
        return (false);
    Fixed square_abc = calculate_square(a, b, c);
    Fixed square_abp = calculate_square(a, b, point);
    Fixed square_bcp = calculate_square(b, c, point);
    Fixed square_acp = calculate_square(a, c, point);
    if (square_abc == square_abp + square_acp + square_bcp)
        return (true);
    return (false);
}

Fixed calculate_square(Point const a, Point const b, Point const c)
{
    Fixed square;

    square = abs(a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * (a.get_y() - c.get_y()) + c.get_x() * (a.get_y() - b.get_y()) / Fixed(2));
    return (square);
}