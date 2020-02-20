#include "Rational.h"

Rational::Rational( int p, int q ) : p(p), q(q) {

}

bool Rational::operator==( const Rational &another ) {
    return p * another.q == another.p * q;
}

Integer Rational::gcd() {
    Integer a = p, b = q;
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return Integer(0);
}
