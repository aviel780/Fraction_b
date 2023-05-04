#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

TEST_CASE("Deviding test"){
    Fraction fra1(1,2);
    Fraction fra2(2,3);
    Fraction fra3(3,4);
    Fraction fra4(4,5);
    Fraction fra5(0,0);
    Fraction fra6(0);
    CHECK_THROWS(Fraction(9, 0));
    CHECK_NOTHROW(Fraction(1, 100));
    CHECK_NOTHROW(fra1/fra2);
    CHECK_NOTHROW(fra2/fra5);
    CHECK_THROWS(fra5/fra6);
    CHECK_NOTHROW(fra2/fra2);    
    CHECK_THROWS(fra3/fra5);
}


TEST_CASE("gcd and lcm test"){
    Fraction frc1(1,3);
    Fraction frc2(2,5);
    Fraction frc3(-2.3);
    Fraction frc4(1.4);
    
    int gcd_1 = frc1.gcd(frc1.getNumerator(), frc2.getNumerator());
    int gcd_2 = frc2.gcd(frc2.getNumerator(), frc3.getNumerator());
    int gcd_3 = frc3.gcd(frc4.getDenominator(), frc3.getDenominator());
    int gcd_4 = frc4.gcd(frc4.getNumerator(), frc4.getDenominator());
    int gcd_5 = frc4.gcd(frc2.getNumerator(), frc2.getDenominator());
    int lcm_1 = frc1.gcd(frc1.getNumerator(), frc1.getDenominator());
    int lcm_2 = frc2.gcd(frc2.getNumerator(), frc2.getDenominator());
    int lcm_3 = frc3.gcd(frc3.getNumerator(), frc3.getDenominator());
    int lcm_4 = frc4.gcd(frc4.getNumerator(), frc4.getDenominator());
    CHECK(gcd_1 == 1);
    CHECK(gcd_2 == 2);
    CHECK(gcd_3 == 1);
    CHECK(gcd_4 == 1);
    CHECK(lcm_1 == 3);
    CHECK(lcm_2 == 2);
    CHECK(lcm_3 == 230);
    CHECK(lcm_4 == 140);
    CHECK_FALSE(gcd_1 ==0);
    CHECK_FALSE(gcd_2 == 6);
}

TEST_CASE("operators test"){
    Fraction frc1(1,2);
    Fraction frc2(3,4);
    Fraction frc5(3,8);
    Fraction frc3(2.3);
    Fraction frc4(2,1);
    Fraction frc6(2,1);
    Fraction frc7(0);
    CHECK_NOTHROW(frc1 +frc2);
    CHECK_NOTHROW(frc2 +frc3);
    CHECK_NOTHROW(frc1 +2.6);
    CHECK_NOTHROW(2.1 +frc2);
    CHECK(frc1*frc2 == frc5);
    CHECK(frc1*frc2 == frc5);
    CHECK(frc3.getNumerator() == 23);
    CHECK(frc4-frc6 == frc7);
 
}

TEST_CASE("bool test"){
    Fraction frc1(1,2);
    Fraction frc2(3,4);
    Fraction frc5(3,8);
    Fraction frc3(2.3);
    Fraction frc4(2,1);
    Fraction frc6(2,1);
    Fraction frc7(0);
    CHECK_FALSE(frc1>frc2);
    CHECK(frc2>frc1);
    CHECK(frc1 != frc5);
    CHECK_FALSE(frc4!=frc6);
    CHECK(frc1<frc2);
    CHECK(frc1<=frc2);
    CHECK(frc7<=frc2);
    CHECK_FALSE(frc7>=frc6);
 
}


TEST_CASE("Increment and decrement methods test"){
    Fraction frc1(9,8);
    
    Fraction frc2(0);
    Fraction frc3(2.346);
    Fraction frc4(-1);
    CHECK(frc2 != frc4);
    frc2--;
    CHECK(frc2 == frc4);
    frc2++;
    CHECK(frc2 == Fraction(0));
}

