//----------------------------------------------------------------------- Poly ------------------------------------------------------------------------
// Ruiqi Huang CSS 343 
// Date started: 3/39/2023
// Date of last modification: 4/5/2023
//-----------------------------------------------------------------------------------------------------------------------------------------------------
// Purpose - This is the main driver created to test the Poly Class.
//-----------------------------------------------------------------------------------------------------------------------------------------------------
// All tests are commented above the test itself.
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#include "poly.h"
#include <iostream>
using namespace std;

int main() {
	//------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing Constructors and setter
	Poly poly1(3, 4);
	poly1.setCoeff(2, 2);
	//poly1.setCoeff(-1, 0);
	poly1.setCoeff(4, 6);
	cout << " poly1: " << poly1 << endl;

	Poly poly2(poly1);
	cout << " poly2: " << poly2 << endl;

	Poly poly3(1);
	cout << " poly3: " << poly3 << endl;

	Poly poly4;
	cout << "poly4 declared." << endl;
 	cout << " poly4: " << poly4 << endl;
	cout << endl;
	//------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing Getter
	cout << " " << poly1.getCoeff(0) << endl;
	cout << " " << poly1.getCoeff(1) << endl;
	cout << " " << poly1.getCoeff(2) << endl;
	cout << " " << poly1.getCoeff(3) << endl;
	cout << " " << poly1.getCoeff(4) << endl;
	cout << " " << poly1.getCoeff(5) << endl;

	//This should return -1
	cout << " " << poly1.getCoeff(6) << endl;

	cout << endl;
	//------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing operators
	Poly poly5(3, 3);
	poly5.setCoeff(2, 2);
	poly5.setCoeff(4, 4);

	Poly poly6(1, 1);

	//Same poly as poly5
	Poly poly7(3, 3);
	poly7.setCoeff(2, 2);
	poly7.setCoeff(4, 4);

	Poly poly8(1, 5);
	Poly poly9(1, 4);
	Poly poly10(1, 3);
	poly10.setCoeff(1, 2);
	poly10.setCoeff(1, 4);

	//Same poly as poly5
	Poly poly11(3, 3);
	poly11.setCoeff(2, 2);
	poly11.setCoeff(4, 4);

	//Testing operator =
	cout << "Starting tests for = operator..." << endl;
	poly6 = poly5;
	cout << "1.poly5: " << poly5 << " vs " << " poly6: " << poly6 << endl;

	cout << endl;
	//Testing operators == and !=
	cout << "Starting tests for == and != operators..." << endl;
	cout << "2.poly5: " << poly5 << " vs " << " poly7 : " << poly7 << endl;
	if (poly7 == poly5) {
		cout << "poly7 == poly5 is true!" << endl;
	}
	else {
		cout << "poly7 == poly5 is false!" << endl;
	}
	cout << endl;

	//Testing operators + and +=
	cout << "Starting tests for + and += operators..." << endl;
	cout << "3.poly5 (" << poly5 << ") + poly8 (" << poly8 << ") = " << poly5 + poly8 << endl;
	cout << "4.poly5 (" << poly5 << ") + poly9 (" << poly8 << ") = " << poly5 + poly9 << endl;

	//Should have the same result as 4.
	poly5 += poly9;
	cout << "5.After poly5 += poly9, poly5 = " << poly5 << endl;

	//Testing operators - and -=
	cout << "Starting tests for - and -= operators..." << endl;
	cout << "6.poly7 (" << poly7 << ") - poly10 (" << poly10 << ") = " << poly7 - poly10 << endl;

	//Should have the same result as 6
	poly7 -= poly10;
	cout << "7.After poly7 -= poly10, poly7 = " << poly7 << endl;

	cout << endl;
	//Testing operators * and *=
	cout << "Starting tests for * and *= operators..." << endl;
	cout << "8.poly11 (" << poly11 << ") * poly8 (" << poly8 << ") = " << poly11 * poly8 << endl;
	cout << "9.poly11 (" << poly11 << ") * poly7 (" << poly7 << ") = " << poly11 * poly7 << endl;

	//Should have the same result as 9
	poly11 *= poly7;
	cout << "10.After poly11 -= poly7, poly11 = " << poly11 << endl;

	cout << endl;
	//------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing end points
	//too big coefficients on  constructor
	Poly poly12(10000000, 1);
	cout << " poly12: " << poly12 << endl;

	//too big coefficients using setCoeff
	Poly poly13;
	poly13.setCoeff(10000000, 1);
	cout << " poly13: " << poly13 << endl;

	//too big exponent
	Poly poly14(1, 10000000);
	cout << " poly14: " << poly14 << endl;

	Poly poly15;
	poly15.setCoeff(1, 10000000);
	cout << " poly15: " << poly15 << endl;

	//------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing cin (comment out to turn in)
	//cout << "starting test for cin..." << endl;
	//Poly polyI(1, 1);
	//cin >> polyI;

	//cout << " polyI: " << polyI << endl;
	//------------------------------------------------------------------------------------------------------------------------------------------------

	return 0;
}