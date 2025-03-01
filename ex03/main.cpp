#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

static void print_coords(const Point &point);

int main(void)
{
    Point a(0, 0);
    Point b(10, 30);
    Point c(20, 0);

    Point p1(10, 15); //inside
    Point p2(30, 15); //outside
    Point p3(10, 30); //vertex
    Point p4(10, 0); //edge

    bool check;

    std::cout << "Test" << std::endl;
    std::cout << "Point inside: Point p1";
    print_coords(p1);
    std::cout << " is inside the triangle? => ";
    check = bsp(a, b, c, p1);
    if (check)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    std::cout << std::endl;

    std::cout << "Point outside: Point p2";
    print_coords(p2);
    std::cout << " is inside the triangle? => ";
    check = bsp(a, b, c, p2);
    if (check)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    std::cout << std::endl;

    std::cout << "Point on vertex: Point p3";
    print_coords(p3);
    std::cout << " is inside the triangle? => ";
    check = bsp(a, b, c, p3);
    if (check)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    std::cout << std::endl;

    std::cout << "Point on edge: Point p4";
    print_coords(p4);
    std::cout << " is inside the triangle? => ";
    check = bsp(a, b, c, p4);
    if (check)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    std::cout << std::endl;

    return (0);
}

static void print_coords(const Point &point)
{
    std::cout << "(";
    std::cout << point.get_x();
    std::cout << ",";
    std::cout << point.get_y();
    std::cout << ")";
    return ;
}