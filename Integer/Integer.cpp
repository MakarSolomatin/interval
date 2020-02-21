#include <iostream>
#include <limits>
#include <cmath>
#include "Integer.hpp"

using namespace solomatin;
Integer::Integer( int number ) : number(number) {

}

Integer Integer::operator+( const Integer &another ) const {
    if (max - another.number > number)
        throw ArithmeticError("[+] Integer overflowed");
    return Integer(number + another.number);
}

Integer Integer::operator-( const Integer &another ) const {
    if (min + another.number > number)
        throw ArithmeticError("[-] Integer overflowed");
    return Integer(number - another.number);
}

Integer Integer::operator*( const Integer &another ) const {
    if ((((number > 0 && another.number > 0) || (number < 0 && another.number < 0)) && abs(number) > max / abs(another.number)) ||
        (((number < 0 && another.number > 0) || (number > 0 && another.number < 0)) && abs(number) > min / abs(another.number)))
        throw ArithmeticError("[*] Integer overflowed");
    return Integer(number * another.number);
}

Integer Integer::operator/( const Integer &another ) const {
    if (another.number == 0)
        throw ArithmeticError("[/] Division by zero");
    return Integer(number / another.number);
}

Integer::Integer( const Integer &copy ) {
    number = copy.number;
}

Integer::operator int() const {
    return number;
}

Integer &Integer::operator+=(const Integer &another) {
    *this = *this + another;
    return *this;
}

Integer &Integer::operator*=(const Integer &another) {
    *this = *this * another;
    return *this;
}

Integer & Integer::operator-=( const Integer &another ) {
    *this = *this - another;
    return *this;
}

Integer & Integer::operator/=( const Integer &another ) {
    *this = *this / another;
    return *this;
}

bool Integer::operator==( const Integer &another ) const {
    return number == another.number;
}

bool Integer::operator==( const int &another ) const {
    return number == another;
}

Integer::operator double() const {
    return (double)number;
}

double Integer::operator/(const double &another) const {
    return number / another;
}

Integer::operator float() const {
    return (float)number;
}

float Integer::operator/(const float &another) const {
    return number / another;
}

bool Integer::operator!=(const Integer &another) const {
    return number != another.number;
}

bool Integer::operator!=(const int &another) const {
    return number != another;
}

bool Integer::operator>(const int &another) const {
    return number > another;
}

bool Integer::operator<(const int &another) const {
    return number < another;
}

bool Integer::operator>(const Integer &another) const {
    return number > another.number;
}

bool Integer::operator<(const Integer &another) const {
    return number < another.number;
}

bool Integer::operator>=(const int &another) const {
    return number >= another;
}

bool Integer::operator>=(const Integer &another) const {
    return number >= another.number;
}

bool Integer::operator<=(const int &another) const {
    return number <= another;
}

bool Integer::operator<=(const Integer &another) const {
    return number <= another.number;
}

std::ostream & solomatin::operator<<( std::ostream &output, Integer i ) {
    output << i.number;
    return output;
}
