#include <limits>
#include <cmath>
#include "Integer.h"

Integer::Integer( int number ) : number(number) {

}

Integer Integer::operator+( const Integer &another ) {
    if (max - another.number > number)
        throw ArithmeticError("[+] Integer overflowed");
    return {number + another.number};
}

Integer Integer::operator-( const Integer &another ) {
    if (min + another.number > number)
        throw ArithmeticError("[-] Integer overflowed");
    return {number - another.number};
}

Integer Integer::operator*( const Integer &another ) {
    if ((((number > 0 && another.number > 0) || (number < 0 && another.number < 0)) && abs(number) > max / abs(another.number)) ||
        (((number < 0 && another.number > 0) || (number > 0 && another.number < 0)) && abs(number) > min / abs(another.number)))
        throw ArithmeticError("[*] Integer overflowed");
    return {number * another.number};
}

Integer Integer::operator/( const Integer &another ) {
    if (another.number == 0)
        throw ArithmeticError("[/] Division by zero");
    return {number / another.number};
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