#ifndef INTERVAL_INTEGER_HPP
#define INTERVAL_INTEGER_HPP

#include <string>
#include <limits>

namespace solomatin {
    class Integer {
    public:
        Integer(int number = 0);

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
        double operator/(const double &another);
        float operator/(const float &another);
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

        operator int() const;
        operator float() const;
        operator double() const;
    private:
        int number;
        static const int min = std::numeric_limits<int>::min();
        static const int max = std::numeric_limits<int>::max();
    };
}

#endif //INTERVAL_INTEGER_HPP