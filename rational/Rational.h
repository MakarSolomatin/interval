#ifndef INTERVAL_RATIONAL_H
#define INTERVAL_RATIONAL_H

#include "integer/Integer.h"

class Rational {
public:
    Rational( int p, int q );
    void Cut();

    bool operator==( const Rational &another );

private:
    Integer p, //numerator
        q; //denumerator

    Integer gcd();
};

#endif //INTERVAL_RATIONAL_H
