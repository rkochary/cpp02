#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{

        int _fixedPoint;
        static const int _fractionalBits;
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &obj);
        Fixed & operator=(const Fixed &obj);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        bool operator>(const Fixed &obj) const;
        bool operator<(const Fixed &obj) const;
        bool operator>=(const Fixed &obj) const;
        bool operator<=(const Fixed &obj) const;
        bool operator==(const Fixed &obj) const;
        bool operator!=(const Fixed &obj) const;
        Fixed operator+(const Fixed &obj) const;
        Fixed operator-(const Fixed &obj) const;
        Fixed operator*(const Fixed &obj) const;
        Fixed operator/(const Fixed &obj) const;
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        static Fixed &min(Fixed &obj1, Fixed &obj2);
        static Fixed &max(Fixed &obj1, Fixed &obj2);
        static const Fixed &min(Fixed const &obj1, Fixed const &obj2);
        static const Fixed &max(Fixed const &obj1, Fixed const &obj2);
};

std::ostream& operator<<(std::ostream& stream, const Fixed& op); ///

#endif

