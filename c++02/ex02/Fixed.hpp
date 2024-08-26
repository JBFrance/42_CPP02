#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

    private:
        int _rawBits;
        static const int _fractionalBits = 8;


    public:
        Fixed();
        Fixed( const Fixed &p );
        Fixed( const int num );
        Fixed( const float num );
        Fixed& operator=( const Fixed &p );
        bool operator>( const Fixed &p ) const;
        bool operator<( const Fixed &p ) const;
        bool operator>=( const Fixed &p ) const;
        bool operator<=( const Fixed &p ) const;
        bool operator==( const Fixed &p ) const;
        bool operator!=( const Fixed &p ) const;
        Fixed operator+( const Fixed &p );
        Fixed operator-( const Fixed &p );
        Fixed operator*( const Fixed &p );
        Fixed operator/( const Fixed &p );
        Fixed& operator++();
        Fixed operator++( int );
        Fixed& operator--();
        Fixed operator--( int );
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        static Fixed& min( Fixed& num1, Fixed& num2 );
        static const Fixed&	min( const Fixed& num1, const Fixed& num2 );
        static Fixed& max( Fixed& num1, Fixed& num2 );
		static const Fixed&	max( const Fixed& num1, const Fixed& num2 );

};

std::ostream& operator << (std::ostream& os, const Fixed& p);


#endif