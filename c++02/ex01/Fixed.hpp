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
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

};

std::ostream& operator << (std::ostream& os, const Fixed& p);


#endif