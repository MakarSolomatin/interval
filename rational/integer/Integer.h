#ifndef INTERVAL_INTEGER_H
#define INTERVAL_INTEGER_H

#include <string>

class Integer {
public:
    Integer( int number );
    Integer( const Integer &copy );

    class ArithmeticError : public std::exception {
        public:
            explicit ArithmeticError(std::string message ) : message(std::move(message)) {}
            std::string getMessage() { return message; }
        private:
            std::string message;
        };

    Integer operator+( const Integer &another );
    Integer operator-( const Integer &another );
    Integer operator*( const Integer &another );
    Integer operator/( const Integer &another );
    Integer & operator+=( const Integer &another );
    Integer & operator-=( const Integer &another );
    Integer & operator*=( const Integer &another );
    Integer & operator/=( const Integer &another );
    operator int() const;
private:
    int number;
    static const int min = std::numeric_limits<int>::min();
    static const int max = std::numeric_limits<int>::max();
};


#endif //INTERVAL_INTEGER_H
