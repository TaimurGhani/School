//
//  Rational.cpp
//  Lab08
//
//  Created by Taimur Ghani on 3/23/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#include <iostream>
#include "Rational.hpp"
using namespace std;

namespace CS2124{
    
    int greatestCommonDivisor(int x, int y) {
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
    
    Rational operator+(const Rational& lhs, const Rational& rhs){
        Rational result(lhs);
        result += rhs;
        return result;
    }
    
    Rational operator--(Rational& lhs){
        //Rational result(lhs);
        lhs += Rational(-1);
        return lhs;
    }
    
    Rational operator--(Rational& lhs, int){
        Rational result(lhs);
        lhs += Rational(-1);
        return result;
    }
    
    Rational operator!=(const Rational& lhs, const Rational& rhs){
        return !(lhs == rhs);
    }
    
    ostream& operator<<(ostream& os, const Rational& rhs){
        os << rhs.num << "/" << rhs.denom;
        return os;
    }

    istream& operator>>(istream& is, Rational& rhs){
        char slash;
        is >> rhs.num >> slash >> rhs.denom;
        rhs.normalize();
        return is;
    }

    bool operator==(const Rational& lhs, const Rational& rhs){
        if (lhs.num == rhs.num && lhs.denom == rhs.denom){
            return true;
        }
        return false;
    }

    bool operator<(const Rational& lhs, const Rational& rhs){
        return (lhs.num*rhs.denom < rhs.num*lhs.denom);
    }
    
    bool operator>(const Rational& lhs, const Rational& rhs){
        return !(lhs<rhs);
    }
    
    bool operator<=(const Rational& lhs, const Rational& rhs){
        return (lhs<rhs || lhs==rhs);
    }
    
    bool operator>=(const Rational& lhs, const Rational& rhs){
        return (lhs>rhs || lhs==rhs);
    }
    
    
    Rational::Rational (int num, int denom) : num(num), denom(denom) {
        normalize();
    }

    Rational::operator bool() const {return num!= 0;}

    Rational& Rational::operator+=(const Rational& rhs){
        int tempdenom = denom;
        denom *= rhs.denom;
        num = num*(rhs.denom) + (rhs.num)*tempdenom;
        normalize();
        return *this;
    }

    Rational& Rational::operator++(){
        num += denom;
        return *this;
    }

    Rational Rational::operator++(int dummy){
        Rational result(*this);
        num += denom;
        return result;
    }

    void Rational::normalize(){
        int gcd = greatestCommonDivisor(num, denom);
        num = num / gcd;
        denom = denom / gcd;
    }
}
