//
//  Rational.hpp
//  Lab08
//
//  Created by Taimur Ghani on 3/23/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#ifndef Rational_hpp
#define Rational_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
namespace CS2124{
    
    class Rational;
    
    int greatestCommonDivisor(int x, int y);
    Rational operator+(const Rational& lhs, const Rational& rhs);
    Rational operator--(Rational& lhs);
    Rational operator--(Rational& lhs, int);
    Rational operator!=(const Rational& lhs, const Rational& rhs);
    bool operator>(const Rational& lhs, const Rational& rhs);
    bool operator<=(const Rational& lhs, const Rational& rhs);
    bool operator>=(const Rational& lhs, const Rational& rhs);

    class Rational{
        friend ostream& operator<<(ostream& os, const Rational& rhs);
        friend istream& operator>>(istream& is, Rational& rhs);
        friend bool operator==(const Rational& lhs, const Rational& rhs);
        friend bool operator<(const Rational& lhs, const Rational& rhs);
    public:
        Rational (int num = 0, int denom = 1);
        explicit operator bool() const;
        Rational& operator+=(const Rational& rhs);
        Rational& operator++();
        Rational operator++(int dummy);
        
    private:
        void normalize();
        int num;
        int denom;
    };
}
#endif /* Rational_hpp */
