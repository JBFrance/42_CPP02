#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

    private:
        int _rawBits;
        static const int _fractionalBits = 8;


    public:
        Fixed();
        Fixed( const Fixed &p );
        Fixed& operator=( const Fixed &p );
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );

};

#endif