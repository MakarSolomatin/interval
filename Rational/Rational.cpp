#include "Rational.hpp"
#include "Integer.hpp"

using namespace solomatin;
Rational::Rational( int p, int q ) : p(p), q(q) {
}

bool Rational::operator==( const Rational &another ) const {
    return p * another.q == another.p * q ;
}

Integer Rational::gcd() const {
    Integer a = p, b = q;
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

Rational & Rational::cut() {
    Integer d = gcd();
    p /= d;
    q /= d;

    return *this;
}

Rational Rational::operator+( const Rational &another ) const {
    if (q == another.q) {
        return {p + another.p, q};
    }
    return Rational{p * another.q + q * another.p, q * another.q}.cut();
}

Rational Rational::operator-( const Rational &another ) const {
    if (q == another.q) {
        return Rational{p - another.p, q}.cut();
    }
    return Rational{p * another.q - q * another.p, q * another.q}.cut();
}

Rational Rational::operator*( const Rational &another ) const {
    return Rational{p * another.p, q * another.q}.cut();
}

Rational Rational::operator/( const Rational &another ) const {
    return Rational{p * another.q, q * another.p}.cut();
}

Rational &Rational::operator+=( const Rational &another ) {
    *this = *this + another;
    return *this;
}

Rational &Rational::operator-=( const Rational &another ) {
    *this = *this - another;
    return *this;
}

Rational &Rational::operator*=( const Rational &another ) {
    *this = *this * another;
    return *this;
}

Rational &Rational::operator/=( const Rational &another ) {
    *this = *this / another;
    return *this;
}

Rational::operator float() const {
    return p.operator/((float)q);
}

Rational::operator double() const {
    return p.operator/((double)q);
}

bool Rational::operator!=(const Rational &another) const {
    return p * another.q != q * another.p;
}

bool Rational::operator>(const Rational &another) const {
    return p * another.q > q * another.p;
}

bool Rational::operator>=(const Rational &another) const {
    return p * another.q >= q * another.p;
}

bool Rational::operator<(const Rational &another) const {
    return p * another.q < q * another.p;
}

bool Rational::operator<=(const Rational &another) const {
    return p * another.q <= q * another.p;
}
