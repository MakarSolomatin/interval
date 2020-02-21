#ifndef INTERVAL_RATIONAL_HPP
#define INTERVAL_RATIONAL_HPP

#include <iostream>
#include "Integer.hpp"

namespace solomatin {
    class Rational {
    public:
        Rational( int p, int q );
        Rational( Integer p, Integer q );
        Rational( int x );
        Rational( Integer x );

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
        explicit operator float() const;
        explicit operator double() const;

        friend void operator<<( std::ostream cout, Rational r );
    private:
        Integer p, //numerator
                q; //denominator

        Integer gcd() const;
    };
    void operator<<( std::ostream cout, Rational r );
}
#endif //INTERVAL_RATIONAL_HPP
