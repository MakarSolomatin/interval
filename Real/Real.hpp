#ifndef INTERVAL_REAL_HPP
#define INTERVAL_REAL_HPP

#include "Rational.hpp"
namespace solomatin {
    class Real {
    public:
        Real( const Rational &a = 0, const Rational &b = 1 );
        Real operator+( const Real &another ) const;
        Real operator-( const Real &another ) const;
        Real operator*( const Real &another ) const;
        Real operator/( const Real &another ) const;
    private:
        Rational a, b;
    };
}


#endif //INTERVAL_REAL_HPP
