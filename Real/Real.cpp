#include <algorithm>
#include <array>

#include "Real.hpp"
using namespace solomatin;

Real::Real( const Rational &a, const Rational &b ) : a(a), b(b) {

}

Real Real::operator+(const Real &another) const {
    return {a + another.a, b + another.b};
}

Real Real::operator-(const Real &another) const {
    return {a - another.b, b - another.a};
}

Real Real::operator*(const Real &another) const {
    std::array<Rational, 4> x = {a * another.a, a * another.b, b * another.a, b * another.b};
    return {*std::min_element(x.begin(), x.end()), *std::max_element(x.begin(), x.end())};
}

Real Real::operator/(const Real &another) const {
    std::array<Rational, 4> x = {a / another.a, a / another.b, b / another.a, b / another.b};
    return {*std::min_element(x.begin(), x.end()), *std::max_element(x.begin(), x.end())};
}
