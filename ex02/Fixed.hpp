#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
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

        bool operator>(const Fixed &other);
        bool operator<(const Fixed &other);
        bool operator>=(const Fixed &other);
        bool operator<=(const Fixed &other);
        bool operator==(const Fixed &other);
        bool operator!=(const Fixed &other);

        int operator+(const Fixed &other);
        int operator-(const Fixed &other);
        int operator*(const Fixed &other);
        int operator/(const Fixed &other);
};

std::ostream &operator<<(std::ostream& out, const Fixed& number);

#endif