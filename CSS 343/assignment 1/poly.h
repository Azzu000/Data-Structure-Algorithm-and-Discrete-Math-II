//----------------------------------------------------------------------- Poly ------------------------------------------------------------------------
// Ruiqi Huang CSS 343 
// Date started: 3/39/2023
// Date of last modification: 4/5/2023
//-----------------------------------------------------------------------------------------------------------------------------------------------------
// Purpose - This programs can make a polynomial given a coefficient and a exponent. If only a coefficient is given then the program will assume that 
// the exponent is 0. If no coefficient and exponent is given to create the poly the program will make a exmpty polynomial with the constant 0.
// After creating the polynomial you can always add more polynomials using the setCoeff function. You can also get the coefficient of a specific polynomial 
// by giving the exponent. You can add, subtract and multiply polynomials with regular operations as shown: +,-,*,+=,-=,*=. You can print out the polynomial
// by using the regular ostream function << and you can also create a polynomial by typing in the coefficient first then the exponent. WHen you are done 
// type in -1 -1 to tell the program you have finished typing your polynomial. 
//-----------------------------------------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef POLY_H_
#define POLY_H_
#include <iostream>
using namespace std;

class Poly
{
public:
	//Constructors and Destructor
	//Constructor for polynomial with coefficient (coeff) and exponent (exp)
	Poly(int coeff, int exp);
	//Constructor for polynomial with exponent as 0
	Poly(int coeff);
	//Constructor where coefficient is 0 and exponent is 0
	Poly();
	//Copy Constructor
	Poly(const Poly& poly); 
	//Destructor
	~Poly();
	
	//Getters and Setters
	//Get a coefficient given the exponent (index)
	int getCoeff(int exp) const;
	//Set one coefficient for a specific exponent (index) in overall polynomial
	void setCoeff(int coeff, int exp);

	//Iostreams
	//Output
	friend ostream& operator << (ostream& out, const Poly& poly);
	//Input
	friend istream& operator >> (istream& in, Poly& poly);

	//Operator Overloads
	Poly& operator = (const Poly& poly);

	//see if both poly is equal
	bool operator == (const Poly& poly);
	//see if both poly is not equal
	bool operator != (const Poly& poly);
	
	//Addition of two poly
	Poly operator + (const Poly& poly);
	//Addition of given poly to this poly
	Poly& operator += (const Poly& poly);

	//subtraction of two poly
	Poly operator - (const Poly& poly);
	//subtraction of given poly to this poly
	Poly& operator -= (const Poly& poly);

	//multiplication of two poly
	Poly operator * (const Poly& poly);
	//multiplication of given poly to this poly
	Poly& operator *= (const Poly& poly);

private:
	//Pointer pointing to our dynamic array
	int* coeffPtr;
	//Keeps track of the size of our array
	int size = 0;
};
#endif