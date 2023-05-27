#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
    _fixedPoint = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int Constructor called" << std::endl;
	_fixedPoint = num << _fractionalBits;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float Constructor called" << std::endl;
    _fixedPoint = static_cast<int>(roundf(num * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &obj)
{
    _fixedPoint = obj._fixedPoint;
    std::cout << "Copy Constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Descructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &obj)
{
    if (this != &obj)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->_fixedPoint = obj._fixedPoint;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& op) ///
{
	stream << op.toFloat();
	return (stream);
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(_fixedPoint) / (1 << _fractionalBits)); ///
}

int Fixed::toInt( void ) const
{
	return (_fixedPoint >> _fractionalBits); ///
}

int Fixed::getRawBits(void)const
{
   // std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}

void Fixed::setRawBits(int const row)
{
    _fixedPoint = row;
}
