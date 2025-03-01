#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <iomanip>

class Fixed
{
    private:
        int num_value;
        static const int bits = 8;

    public:
        Fixed(void);
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        Fixed operator+(const Fixed &other);
        Fixed operator-(const Fixed &other);
        Fixed operator*(const Fixed &other);
        Fixed operator/(const Fixed &other);

        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);

        static Fixed &min(Fixed &first, Fixed &second);
        static Fixed &max(Fixed &first, Fixed &second);
        static const Fixed &min(const Fixed &first, const Fixed &second);
        static const Fixed &max(const Fixed &first, const Fixed &second);
};

std::ostream &operator<<(std::ostream& out, const Fixed& number);

#endif