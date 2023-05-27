#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
    _fixedPoint = 0;
   // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	//std::cout << "Int Constructor called" << std::endl;
	_fixedPoint = num << _fractionalBits;
}


Fixed::Fixed(const float num)
{
    //std::cout << "Float Constructor called" << std::endl;
    _fixedPoint = static_cast<int>(roundf(num * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &obj)
{
    _fixedPoint = obj._fixedPoint;
    //std::cout << "Copy Constructor called" << std::endl;
}

Fixed::~Fixed()
{
    //std::cout << "Descructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &obj)
{
    if (this != &obj)
    {
        //std::cout << "Copy assignment operator called" << std::endl;
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

bool Fixed::operator>(const Fixed &obj) const
{
    if(this->getRawBits() > obj.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<(const Fixed &obj) const
{
    if(this->getRawBits() < obj.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &obj) const
{
    if(this->getRawBits() >= obj.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &obj) const
{
    if(this->getRawBits() <= obj.getRawBits())
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &obj) const
{
    if(this->getRawBits() == obj.getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &obj) const
{
    if(this->getRawBits() != obj.getRawBits())
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed &obj) const
{
    return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj) const
{
    return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj) const
{
    return Fixed(this->toFloat() * obj.toFloat());
}

Fixed& Fixed::operator++()
{
     ++this->_fixedPoint;
     return *this;
}

Fixed& Fixed::operator--()
{
     --this->_fixedPoint;
     return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed obj(*this);
    ++(*this);
    return obj;
}

Fixed Fixed::operator--(int)
{
    Fixed obj(*this);
    --(*this);
    return obj;
}

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2)
{
    if(obj1.getRawBits() < obj2.getRawBits())
        return obj1;
    return obj2;
}

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2)
{
    if(obj1.getRawBits() > obj2.getRawBits())
        return obj1;
    return obj2;
}

const Fixed& Fixed::min(const Fixed &obj1,const Fixed &obj2)
{
    if(obj1.getRawBits() < obj2.getRawBits())
        return obj1;
    return obj2;
}

const Fixed& Fixed::max(const Fixed &obj1,const Fixed &obj2)
{
    if(obj1.getRawBits() > obj2.getRawBits())
        return obj1;
    return obj2;
}