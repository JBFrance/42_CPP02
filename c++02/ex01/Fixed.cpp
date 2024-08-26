#include "Fixed.hpp"

Fixed::Fixed() { 
    _rawBits = 0; 
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &p ) {
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(p);
}

Fixed::Fixed( const int num ) {
    _rawBits = num << _fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float num ) {
    _rawBits = (roundf(num * (1 << _fractionalBits)));
    std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed &p ) { 
    
    std::cout << "Copy assignment operator called" << std::endl;
    _rawBits = p.getRawBits();
    return *this; 
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    return _rawBits;
}

void Fixed::setRawBits( int const raw ) { 
    this->_rawBits = raw;
}

float Fixed::toFloat( void ) const {
    return (float)(_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const {
    return _rawBits >> _fractionalBits;
}

std::ostream& operator << (std::ostream& os, const Fixed& p) {
    os << p.toFloat();
    return os;
} 
