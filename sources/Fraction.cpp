#include "Fraction.hpp"

#include <climits>
#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
using namespace ariel;
using namespace std;
Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numerat, int denominat) : numerator(numerat), denominator(denominat) {
  if (denominat == 0) {
    throw invalid_argument("its invalid to creat frucsion with 0 in the denominator");
  }
  reduce();
}

Fraction::Fraction(float numerat, float denominat) : numerator(numerat), denominator(denominat) {
  if (denominat == 0) {
    throw invalid_argument("its invalid to creat frucsion with 0 in the denominator");
  }
  numerator = round(numerat * 1000);
  denominator = 1000 * denominat;
  reduce();
}

Fraction::Fraction(float numerat) {
  numerator =round(numerat * 1000);
  denominator = 1000;
  reduce();
}

Fraction Fraction::operator+(const Fraction &other) {
  if ((long long)numerator * other.denominator + other.numerator * denominator >numeric_limits<int>::max()) {
      throw overflow_error("Invalid, its to big");}

  if((long long)numerator * other.denominator + other.numerator * denominator < numeric_limits<int>::min()){
      throw overflow_error("Invalid, its to small");}
  
  if((long long)denominator * other.denominator > numeric_limits<int>::max()){
    throw overflow_error("Invalid, the denominator to big");
  }

  if((long long)numerator * other.numerator > numeric_limits<int>::max()){
    throw overflow_error("Invalid, the numerator to big");
  }
  
  float commen_denominat = lcm(denominator,other.denominator);
  float numerat = ((float)numerator * ((float)commen_denominat/(float)denominator)) + 
  ((float)other.numerator * ((float)commen_denominat/(float)other.denominator));
  reduce();
  return Fraction(numerat, commen_denominat);
}

Fraction Fraction::operator-(const Fraction &other) {
  if ((long long)numerator * other.denominator - other.numerator * denominator > numeric_limits<int>::max() ){
    throw overflow_error("error its Invalid");
  }
          
   if ((long long)denominator * other.denominator > numeric_limits<int>::max())
   {
    throw overflow_error("error its Invalid");
   }

  float commen_denominat = lcm(denominator,other.denominator);
  float numerat = ((float)numerator * ((float)commen_denominat/(float)denominator)) -
  ((float)other.numerator * ((float)commen_denominat/(float)other.denominator));
   reduce();
  return Fraction(numerat, commen_denominat);
}

Fraction Fraction::operator*(const Fraction &other) {
  if ((long long)numerator * other.numerator > numeric_limits<int>::max()) {
    throw overflow_error("error its Invalid");
  }
  
   if ((long long)denominator * other.denominator > numeric_limits<int>::max()) {
    throw overflow_error("error its Invalid");
  }
  int numerat = numerator * other.numerator;
  int denominat = denominator * other.denominator;
  reduce();
  return Fraction(numerat, denominat);
}

Fraction Fraction::operator/(const Fraction &other) {
  if (other.numerator == 0 ){
    throw runtime_error("error cant be whane sapre between 2 frucsion");
  } 

  if (other.denominator == 0) {
    throw runtime_error("error divided by zero!");
  }
  
  if ((long long)numerator * other.denominator > numeric_limits<int>::max()){
    throw overflow_error(" error its Invalid");
  }
  if ((long long)denominator * other.numerator > numeric_limits<int>::max()) {
    throw overflow_error(" error its Invalid");
  }

  int new_numeretor = numerator * other.denominator; // the ear rule
  int new_denominator = denominator * other.numerator;
  reduce();

  return Fraction(new_numeretor, new_denominator);
}

bool Fraction::operator==(const Fraction &other) const {
  bool flag = false;
  if(numerator == other.numerator && denominator == other.denominator){
    flag = true;
  }
  return flag;
}

bool Fraction::operator!=(const Fraction &other) const {
  return !(*this == other);
}

bool Fraction::operator>(const Fraction &other) const {
  bool flag = false;

  float commen_denominat = lcm(denominator,other.denominator);
  if ((float)numerator * ((float)commen_denominat/(float)denominator) >
   other.numerator * ((float)commen_denominat/(float)other.denominator)){
    flag = true;
  }


  return flag;
}

bool Fraction::operator<(const Fraction &other) const {
  bool flag = false;

  float commen_denominat = lcm(denominator,other.denominator);
  if ((float)numerator * ((float)commen_denominat/(float)denominator) <
   other.numerator * ((float)commen_denominat/(float)other.denominator)){
    flag = true;
  }


  return flag;
}

bool Fraction::operator>=(const Fraction &other) const {
  bool flag = false;

  float commen_denominat = lcm(denominator,other.denominator);
  if ((float)numerator * ((float)commen_denominat/(float)denominator) >=
   other.numerator * ((float)commen_denominat/(float)other.denominator)){
    flag = true;
  }


  return flag;
}

bool Fraction::operator<=(const Fraction &other) const {
  bool flag = false;

  float commen_denominat = lcm(denominator,other.denominator);
  if ((float)numerator * ((float)commen_denominat/(float)denominator) <=
   other.numerator * ((float)commen_denominat/(float)other.denominator)){
    flag = true;
  }


  return flag;
}

Fraction &Fraction::operator++() {
  numerator += denominator;
  reduce();
  return *this;
}

Fraction Fraction::operator++(int) {
  Fraction newfrac(*this);
  ++(*this);
  return newfrac;
}
Fraction &Fraction::operator--() {
  numerator -= denominator;
  reduce();
  return *this;
}
Fraction Fraction::operator--(int) {
  Fraction newfrac(*this);
  --(*this);
  return newfrac;
}

void Fraction::reduce() {// take the idea from the internt
  if (denominator == 0) {
    cerr << "the demointor canot be 0" << endl;
    return;
  }

  if (numerator == 0) {
    denominator = 1;
    cerr << "the frucsion value is 0" << endl;
    return;
  }

  int pos_neg = 1;

  if (numerator < 0) { 
    pos_neg *= -1;
    numerator *= -1;
  }

  if (denominator < 0) {
    pos_neg *= -1;
    denominator *= -1;
  }

  int div = gcd(numerator, denominator);
  numerator = pos_neg * numerator / div;
  denominator = denominator / div;
}


int Fraction::getNumerator() { return this->numerator; }
int Fraction::getDenominator() { return this->denominator;}

int Fraction::gcd(int a, int b) { //taken feom gpt
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int Fraction::lcm(int a, int b) {//taken feom gpt
  return ((a * b) / gcd(a, b));
};

Fraction Fraction::floatToFraction(float numerat) { // taken from gpt
  int decimal_places = 0;
  float temp = numerat;

  // Count the number of decimal places
  while (temp != floor(temp)) {
    decimal_places++;
    temp *= 10;
  }

  // Multiply numerator and denominator by 10^decimal_places
  float numeratt = numerat * pow(10, decimal_places);
  float denominat = pow(10, decimal_places);

  // Simplify the fraction
  int gcd_ = gcd(numeratt, denominat);
  numeratt /= gcd_;
  denominat /= gcd_;

  return Fraction(numeratt,denominat);
}