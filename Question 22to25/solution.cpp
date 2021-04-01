#include <iostream>
#include <algorithm>

using namespace std;

class Fraction {
  private:
    int numerator;
    int denominator;

  public:
    Fraction(){
      numerator = 0;
      denominator = 1;
    }

    Fraction(int n, int d){
      numerator = n;
      denominator = d;
    }

    int getNumerator(){
      return numerator;
    }

    int getDenominator(){
      return denominator;
    }

    void setNumerator(int n){
      numerator = n;
    }

    void setDenominator(int d){
      denominator = d;
    }

    /* Alternate GCD function
    int gcd(int a, int b) {
      if (a == 0) {
        return b;
      }
      return gcd(b%a, a);
    }
    */

    void reducedForm(){
      int d;
      d = __gcd(numerator, denominator);
      numerator/=d;
      denominator/=d;
      if(denominator < 0){
        denominator *= -1;
        numerator *= -1;
      }
    }

    void display(){
      reducedForm();
      if(denominator != 1){
        cout << "(" << numerator << "/" << denominator << ")";
      } else {
        cout << "(" << numerator << ")";
      }
    }

    Fraction operator+ (Fraction f){
      int newDenominator = __gcd(denominator, f.getDenominator());
      newDenominator = (denominator * f.getDenominator()) / newDenominator;
      int newNumerator = (numerator) * (newDenominator/denominator) + (f.getNumerator()) * (newDenominator/f.getDenominator());
      Fraction result(newNumerator, newDenominator);
      return result;
    }

    Fraction operator- (Fraction f){
      int newDenominator = __gcd(denominator, f.getDenominator());
      newDenominator = (denominator * f.getDenominator()) / newDenominator;
      int newNumerator = (numerator) * (newDenominator/denominator) - (f.getNumerator()) * (newDenominator/f.getDenominator());
      Fraction result(newNumerator, newDenominator);
      return result;
    }

    Fraction operator* (Fraction f){
      int newNumerator = numerator * f.getNumerator();
      int newDenominator = denominator * f.getDenominator();
      Fraction result(newNumerator, newDenominator);
      return result;
    }

    Fraction operator/ (Fraction f){
      int newNumerator = numerator * f.getDenominator();
      int newDenominator = denominator * f.getNumerator();
      Fraction result(newNumerator, newDenominator);
      return result;
    }

    friend ostream& operator<< (ostream &out, Fraction f){
      f.reducedForm();
      if(f.denominator != 1){
        out << "(" << f.numerator << "/" << f.denominator << ")";
      } else {
        out << "(" << f.numerator << ")";
      }

      return out; 
    }

    Fraction operator! (){
      return Fraction(denominator, numerator);
    }
};

int main(){
  Fraction a;
  Fraction b(1,2);
  Fraction c(3,6);
  Fraction d(10,15);
  Fraction e(6,7);
  Fraction f(2,10);
  
  a = (((b + c) - d) * e) / f;

  cout << a << endl;
  cout << !a;
  return 0;
}