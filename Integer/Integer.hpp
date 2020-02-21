#ifndef INTERVAL_INTEGER_HPP
#define INTERVAL_INTEGER_HPP

#include <iostream>
#include <string>
#include <limits>

namespace solomatin {
    class Integer {
    public:
        explicit Integer( int number = 0 );

        Integer(const Integer &copy);

        class ArithmeticError : public std::exception {
        public:
            explicit ArithmeticError(std::string message) : message(std::move(message)) {}

            std::string getMessage() { return message; }

        private:
            std::string message;
        };

        Integer operator+(const Integer &another) const;
        Integer operator-(const Integer &another) const;
        Integer operator*(const Integer &another) const;
        Integer operator/(const Integer &another) const;
        double operator/(const double &another) const;
        float operator/(const float &another) const;
        Integer &operator+=(const Integer &another);
        Integer &operator-=(const Integer &another);
        Integer &operator*=(const Integer &another);
        Integer &operator/=(const Integer &another);

        bool operator==(const Integer &another) const;
        bool operator==(const int &another) const;
        bool operator!=(const Integer &another) const;
        bool operator!=(const int &another) const;
        bool operator>(const int &another) const;
        bool operator>(const Integer &another) const;
        bool operator<(const int &another) const;
        bool operator<(const Integer &another) const;
        bool operator>=(const int &another) const;
        bool operator>=(const Integer &another) const;
        bool operator<=(const int &another) const;
        bool operator<=(const Integer &another) const;

        explicit operator int() const;
        explicit operator float() const;
        explicit operator double() const;

        friend std::ostream & operator<<( std::ostream &output, Integer i );
    private:
        int number;
        static const int min = std::numeric_limits<int>::min();
        static const int max = std::numeric_limits<int>::max();
    };
    std::ostream & operator<<( std::ostream &output, solomatin::Integer i );
}



#endif //INTERVAL_INTEGER_HPP
