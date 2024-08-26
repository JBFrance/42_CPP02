#include "Fixed.hpp"

Fixed::Fixed() { 
    _rawBits = 0;
}

Fixed::Fixed( const Fixed &p ) {
    this->operator=(p);
}

Fixed::Fixed( const int num ) {
    _rawBits = num << _fractionalBits;
}

Fixed::Fixed( const float num ) {
    _rawBits = (roundf(num * (1 << _fractionalBits)));
}

Fixed& Fixed::operator=( const Fixed &p ) {
    _rawBits = p.getRawBits();
    return *this; 
}

Fixed::~Fixed() {
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

//OVERLOAD FUNCTIONS

//COMPARISON FUNCTIONS
bool Fixed::operator>( const Fixed &p ) const {
    return _rawBits > p.getRawBits();
}

bool Fixed::operator<( const Fixed &p ) const {
    return _rawBits < p.getRawBits();
}

bool Fixed::operator>=( const Fixed &p ) const {
    return _rawBits >= p.getRawBits();
}

bool Fixed::operator<=( const Fixed &p ) const {
    return _rawBits <= p.getRawBits();
}

bool Fixed::operator==( const Fixed &p ) const {
    return _rawBits == p.getRawBits();
}

bool Fixed::operator!=( const Fixed &p ) const {
    return _rawBits != p.getRawBits();
}

//OVERLOAD ARITHMETIC OPERATORS

Fixed Fixed::operator+( const Fixed &p ) {
    
    Fixed result(this->_rawBits + p.getRawBits());
    return result;
}

Fixed Fixed::operator-( const Fixed &p ) {
    
    Fixed result(this->_rawBits - p.getRawBits());
    return result;
}

Fixed Fixed::operator*( const Fixed &p ) {
    
    Fixed result(this->toFloat() * p.toFloat());
    return result;
}

Fixed Fixed::operator/( const Fixed &p ) {
    Fixed result(this->toFloat() / p.toFloat());
    return result;
}

//OVERLOAD ITERATORS

Fixed& Fixed::operator++() {
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++( int ) {
    Fixed old = *this;
    ++_rawBits;
    return old;
}

Fixed& Fixed::operator--() {
    _rawBits--;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed old = *this;
    --_rawBits;
    return old;
}

Fixed& Fixed::min( Fixed& num1, Fixed& num2 ) {
    
    if (num1 > num2)
        return num2;
    else
        return num1;
}

//MIN AND MAX FUNCTIONS

const Fixed& Fixed::min( const Fixed& num1, const Fixed& num2 ) {
    
    if (num1 > num2)
        return num2;
    else
        return num1;
}

Fixed& Fixed::max( Fixed& num1, Fixed& num2 )  {
    
    if (num1 < num2)
        return num2;
    else
        return num1;
}

const Fixed& Fixed::max( const Fixed& num1, const Fixed& num2 )  {
    
    if (num1 < num2)
        return num2;
    else
        return num1;
}