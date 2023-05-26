#include "Fixed.hpp"

Fixed::Fixed()
{
    _fixedPoint = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Descructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    _fixedPoint = obj._fixedPoint;
    std::cout << "Copy Constructor called" << std::endl;
}


Fixed & Fixed::operator=(const Fixed &obj)
{
    if (this != &obj)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->setRawBits(obj.getRawBits());
    }
    return *this;
}

int Fixed::getRawBits(void)const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}

void Fixed::setRawBits(int const row)
{
    _fixedPoint = row;
}