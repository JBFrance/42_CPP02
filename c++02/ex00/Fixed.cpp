#include "Fixed.hpp"

Fixed::Fixed() { 
    _rawBits = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &p ) {
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(p);
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
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits( int const raw ) { 
    this->_rawBits = raw;
}
