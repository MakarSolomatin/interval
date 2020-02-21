#ifndef INTERVAL_RATIONAL_HPP
#define INTERVAL_RATIONAL_HPP

#include "Integer.hpp"

namespace solomatin {
    class Rational {
    public:
        Rational( int p = 0, int q = 0 );

        Rational &cut();

        Rational operator+( const Rational &another ) const;
        Rational operator-( const Rational &another ) const;
        Rational operator*( const Rational &another ) const;
        Rational operator/( const Rational &another ) const;
        Rational &operator+=( const Rational &another );
        Rational &operator-=( const Rational &another );
        Rational &operator*=( const Rational &another );
        Rational &operator/=( const Rational &another );

        bool operator==( const Rational &another ) const;
        bool operator!=( const Rational &another ) const;
        bool operator>( const Rational &another ) const;
        bool operator>=( const Rational &another ) const;
        bool operator<( const Rational &another ) const;
        bool operator<=( const Rational &another ) const;
        operator float() const;
        operator double() const;
    private:
        Integer p, //numerator
                q; //denominator

        Integer gcd() const;
    };
}
#endif //INTERVAL_RATIONAL_HPP
