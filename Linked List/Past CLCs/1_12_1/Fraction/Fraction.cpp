// Fraction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Fraction {
#include <iostream>
	private:
		// denominator
		int denom;

		// numerator
		int num;
	public:
		Fraction() {
			denom = 1;
			num = 0;
		}
		Fraction(int n, int d) {
			num = n;
			denom = d;
		}
		int getDenom() {
			return denom;
		}
		void setDenom(int value) {
			denom = value;
		}
		int getNum() {
			return num;
		}
		void setNum(int value) {
			num = value;
		}

		// reducing factors
		void reduceFactors() {
			int factor = 2;

			// factor must not be greater than either the numerator or denominator
			while (factor <= denom && factor <= num) {

				// reduce while possible using one factor
				while (num % factor == 0 && denom % factor == 0) {
					num /= factor;
					denom /= factor;
				}
				factor++;
			}
		}
		
		// overload +
		Fraction operator+ (const Fraction &f) {
			Fraction result;
			result.num = (num * f.denom) + (f.num * denom);
			result.denom = denom * f.denom;
			return result;
		}

		// overload -
		Fraction operator- (const Fraction &f) {
			Fraction result;
			result.num = (num * f.denom) - (f.num * denom);
			result.denom = denom * f.denom;
			return result;
		}

		// overload /
		Fraction operator/ (const Fraction &f) {
			Fraction result;
			result.num = num * f.denom;
			result.denom = denom * f.num;
			return result;
		}

		// overload *
		Fraction operator* (const Fraction &f) {
			Fraction result;
			result.num = num * f.num;
			result.denom = denom * f.denom;
			return result;
		}

		// overload <<
		friend ostream &operator<<(ostream &o, const Fraction &f) {
			if (f.denom == 1)
				o << f.num;
			else
				o << f.num << "/" << f.denom;
			return o;
		}

		// overload >>
		friend istream &operator>>(istream &i, Fraction &f) {
			i >> f.num >> f.denom;
			return i;
		}
};

int main()
{
	// init fractions
	Fraction F1(5, 15), F2(3, 10), F3;
	F3 = F1 - F2;
	cout << F1 << endl;
	cout << F2 << endl;
	// subtraction test
	cout << F1 << " - " << F2 << " = " << F3 << endl;
	F3.reduceFactors();
	cout << "\treduced: " << F3 << endl;

	// addition test
	F3 = F1 + F2;
	cout << F1 << " + " << F2 << " = " << F3 << endl;
	F3.reduceFactors();
	cout << "\treduced: " << F3 << endl;
	
	// division test
	F3 = F1 / F2;
	cout << F1 << " / " << F2 << " = " << F3 << endl;
	F3.reduceFactors();
	cout << "\treduced: " << F3 << endl;

	// multiplication test
	F3 = F1 * F2;
	cout << F1 << " * " << F2 << " = " << F3 << endl;
	F3.reduceFactors();
	cout << "\treduced: " << F3 << endl;

	// multi-fraction equation
	Fraction F4 = F1 - F2 + F3;
	F4.reduceFactors();
	cout << F1 << " - " << F2 << " + " << F3 << " = " << F4 << endl;

	// input test
	Fraction F5;
	cout << "Enter a Fraction (numerator [enter] denominator)" << endl;
	cin >> F5;
	F5.reduceFactors();
	cout << "\treduced: " << F5 << endl;

    return 0;
}

