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
// We assume that the polynomial coefficient and exponent 10 be less than 1,000,000 and we also assume that the exponent is not negative. 
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#include "poly.h"

//------------------------------------------- Poly Constructor for Coefficient and Exponent ----------------------------------------------------------
//Description: This is the constructor that takes in the coefficient and the exponent to create a Poly. 
//Pre-condition: The exponent cannot be negative and the coefficient and exponent cannot exceed the limit of 1,000,000 (the alrgest coefficient and 
//exponent expected).
//----------------------------------------------------------------------------------------------------------------------------------------------------
Poly::Poly(int coeff, int exp)
{
	//The max coeff and exp is 1000000
	if ((coeff > 1000000) || (exp > 1000000)) {
		//size will be 1 since there is only a constant zero.
		size = 1;
		coeffPtr = new int[size];
		coeffPtr[0] = 0;
	}
	else {
		//the exponent cannot be negative, if the exponent is negative the polynomial will be set to 0
		if ((exp < 0)) {
			//size will be 1 since there is only a constant zero.
			size = 1;
			coeffPtr = new int[size];
			coeffPtr[0] = 0;
		}
		else {
			//Remember, exponent represent the index of the array
			size = exp + 1;
			coeffPtr = new int[size];

			//Use for loop to set all coeff to zero, except the last index which will hold our initial coeff
			for (int i = 0; i < size - 1; i++) {
				coeffPtr[i] = 0;
			}

			coeffPtr[exp] = coeff;
		}
	}
}

//--------------------------------------------------------- Poly Constructor for Coefficients --------------------------------------------------------
//Description: This is a constructor that takes in the coefficient to create a Poly.
// Pre-condition: The coefficient cannot exceed the limit of 1,000,000 (The largest coefficient expected).
//----------------------------------------------------------------------------------------------------------------------------------------------------
Poly::Poly(int coeff)
{
	//The max coeff is 1000000
	if (coeff > 1000000) {
		//size will be 1 since there is only a constant zero.
		size = 1;
		coeffPtr = new int[size];
		coeffPtr[0] = 0;
	}
	else {
		size = 1;
		coeffPtr = new int[size];
		coeffPtr[0] = coeff;
	}
}

//------------------------------------------------------------------ Poly Constructor ----------------------------------------------------------------
//Description: This is a automatic constructor that makes a Poly with 0 as the start constant.
//----------------------------------------------------------------------------------------------------------------------------------------------------
Poly::Poly()
{
	size = 1;
	coeffPtr = new int[size];
	coeffPtr[0] = 0;
}

//--------------------------------------------------------------- Poly Copy Constructor --------------------------------------------------------------
//Description: This is a copy constructor for Poly.
//----------------------------------------------------------------------------------------------------------------------------------------------------
Poly::Poly(const Poly& poly)
{
	//Copy over the other poly to this poly
	this->size = poly.size;
	coeffPtr = new int[this->size];

	//Using a while loop to copy over all the index
	int currentIndex = 0;
	while (currentIndex != this->size) {
		coeffPtr[currentIndex] = poly.coeffPtr[currentIndex];
		currentIndex = currentIndex + 1;
	} //While loop ends when currentIndex = this->size
}

//------------------------------------------------------------------- Poly Destructor ----------------------------------------------------------------
//Description: This is the destructor of Poly.
//----------------------------------------------------------------------------------------------------------------------------------------------------
Poly::~Poly()
{
	//delete the pointer to delete array
	delete this->coeffPtr;
}

//---------------------------------------------------------------------- getCoeff --------------------------------------------------------------------
//Description: This is a getter method that gets the coefficient of the given exponent.
//Pre-condition: The exponent inputted must not be negative and the exponent cannot be bigger than the biggest exponent in the polynomial. 
//If any of the two is true then -1 will be returned. 
//----------------------------------------------------------------------------------------------------------------------------------------------------
int Poly::getCoeff(int exp) const
{
	//The exponent cannot be negative
	if (exp < 0) {
		return -1;
	}
	//The exponent is bigger than our biggest exponent
	else if (exp >= size) {
		return -1;
	}
	else {
		return this->coeffPtr[exp];
	}
}

//--------------------------------------------------------------------- setCoeff ---------------------------------------------------------------------
//Description: This sets the coefficient for a given exponent and the coefficient we want to set.
//Pre-condition: The exponent cannot be bigger than 1,000,000 and cannot be negative. The coefficient limit is also 1,000,00
//----------------------------------------------------------------------------------------------------------------------------------------------------
void Poly::setCoeff(int coeff, int exp)
{
	if (coeff <= 1000000 && exp <= 1000000 && exp > -1) {
		//If the exponent is bigger than the current array
		if ((exp + 1) > size) {
			int newSize = exp + 1;
			//tempPtr will point to an array that will fit our new polynomial
			int* tempPtr;

			tempPtr = new int[newSize];

			//Copy over everything from the old polynomial array to the temp array
			int current_index = 0;
			while (current_index != this->size) {
				tempPtr[current_index] = coeffPtr[current_index];
				current_index = current_index + 1;
			}

			//If there is at least 1 index in between the new exp and the old exp then we fill it in with a 0 to show that there is no coefficients there.
			if ((newSize - size) >= 1) {
				for (int i = size; i < newSize - 1; i++) {
					tempPtr[i] = 0;
				}
			}

			tempPtr[exp] = coeff;

			//delete old array and coeffPtr now points to the new array
			delete coeffPtr;
			coeffPtr = tempPtr;
			size = newSize;
		}
		//if the exponent given is smaller or equal to the current size of the polynomial array and is not negative
		else if ((exp + 1) <= size && (exp + 1) > 0) {
			coeffPtr[exp] = coeff;
		}
	}
}

//--------------------------------------------------------------------- = operator ---------------------------------------------------------------------
//Description: This functions copies the polynomial in the left hand side to this polynomial.
//Pre-condition: If the polynomial is already equal to the other polynomial we can just kepe the polynomial as it is. 
//----------------------------------------------------------------------------------------------------------------------------------------------------
Poly& Poly::operator=(const Poly& poly)
{
	//Check if both poly is the same, if so we don't need to change anything
	if (&poly == this) {
		return *this;
	}

	//delete the old polynomial array and make a new one with the new size.
	delete[] this->coeffPtr;
	this->size = poly.size;
	coeffPtr = new int[size];

	//copy all the data from given poly to this poly
	for (int i = 0; i < size; i++) {
		coeffPtr[i] = poly.coeffPtr[i];
	}

	return* this;
}

//--------------------------------------------------------------------- == operator ---------------------------------------------------------------------
//Description: Checks if the polynomial is equal to each other. If the polynomial is equal it will return true else it would return false. 
//----------------------------------------------------------------------------------------------------------------------------------------------------
bool Poly::operator == (const Poly& poly)
{
	//We can first check if both the size is the same, if not then they are automatically not equal so return false;
	if (this->size != poly.size) {
		return false;
	}

	//Used to keep track of the index we are on. We can use this variable to implement while loop to loop through array and compare.
	int current_index = 0;
	while (current_index != size) {
		if (coeffPtr[current_index] != poly.coeffPtr[current_index]) {
			return false;
		}
		else {
			current_index = current_index + 1;
		}
	}

	//If we checked all the index and all of the values of both poly is the same then we exit loop and return true.
	return true;
}

//--------------------------------------------------------------------- != operator ---------------------------------------------------------------------
//Description: Checks if this polynomial equals the given polynomial, if it is then it will return true and if does not equal then it will reutrn false. 
//----------------------------------------------------------------------------------------------------------------------------------------------------
bool Poly::operator!=(const Poly& poly)
{
	//if the size are not equal then we know the two poly is not equal
	if (this->size != poly.size) {
		return true;
	}

	//Used to keep track of the index we are on.
	int current_index = 0;
	while (current_index != size) {
		if (coeffPtr[current_index] != poly.coeffPtr[current_index]) {
			return true;
		}
		else {
			current_index = current_index + 1;
		}
	}

	//If we checked all the index and all of the values of both poly is the samr then we exit the loop and return false.
	return false;
}

//--------------------------------------------------------------------- + operator ---------------------------------------------------------------------
//Description: Adds two polynomial together. It will set the size of the polynomial to the bigges polynomial size. The polynomial sum is going to hold 
// the sum of the polynomials. 
//----------------------------------------------------------------------------------------------------------------------------------------------------
Poly Poly::operator+(const Poly& poly)
{
	//newSize will hold the size of the new poly that is the sum of the two poly
	int newSize = 0;

	//check which poly size is bigger and take on that size as the new size
	if (this->size < poly.size) {
		newSize = newSize + poly.size;
	}
	else {
		newSize = newSize + size;
	}

	//We know that the exponent is going to be the size of our array so we make the exponent equal to newSize. All values of this starter array should be zero.
	Poly sum(0, newSize);


	//By knowing which polynomial is bigger, we know when we can add the bigger polynomial by 0 when the smaller polynomial ends.
	if (this->size < poly.size) {
		for (int i = 0; i < size; i++) {
			sum.coeffPtr[i] = this->coeffPtr[i] + poly.coeffPtr[i];
		}

		//If given poly is 0 then the sum will just be this poly value
		for (int i = size; i < newSize; i++) {
			sum.coeffPtr[i] = poly.coeffPtr[i];
		}
	}
	else {
		for (int i = 0; i < poly.size; i++) {
			sum.coeffPtr[i] = this->coeffPtr[i] + poly.coeffPtr[i];
		}

		//If given poly is 0 then the sum will just be this poly value
		for (int i = poly.size; i < newSize; i++) {
			sum.coeffPtr[i] = this->coeffPtr[i];
		}
	}
	
	return sum;
}

//-------------------------------------------------------------------- += operator ------------------------------------------------------------------------
//Description: Implemented using the - operator that is already implemented. Instead of just subtracting two polynomial it subtracts the polynomial 
//in the left hand side to this polynomial and sets this equal to that value. 
//----------------------------------------------------------------------------------------------------------------------------------------------------
Poly& Poly::operator+=(const Poly& poly)
{
	//We already overloaded + so we can just use that to add
	*this = *this + poly;
	return *this;
}

//--------------------------------------------------------------------- - operator ---------------------------------------------------------------------
//Description: Subtracts two polynomial. It will set the size of the polynomial to the biggest polynomial size. The polynomial difference is going to hold 
// the difference of the polynomials. Note: this function is implemented similar to the add operator function. 
//----------------------------------------------------------------------------------------------------------------------------------------------------
Poly Poly::operator-(const Poly& poly)
{
	//newSize will hold the size of the new poly that is the sum of the two poly
	int newSize = 0;

	//check which poly size is bigger and take on that size as the new size
	if (this->size < poly.size) {
		newSize = newSize + poly.size;
	}
	else {
		newSize = newSize + size;
	}

	//We know that the exponent is going to be the size of our array so we make the exponent equal to newSize. All values of this starter array should be zero.
	Poly difference(0, newSize);

	//By knowing which polynomial is bigger, we know when we can subtract the bigger polynomial by 0 when the smaller polynomail ends.
	if (this->size < poly.size) {
		//We first subtract all the polynomial that both this poly and given poly have
		for (int i = 0; i < size; i++) {
			difference.coeffPtr[i] = this->coeffPtr[i] - poly.coeffPtr[i];
		}

		//If this is 0 then the difference will just be the negation of given poly value
		for (int i = size; i < newSize; i++) {
			difference.coeffPtr[i] = - (poly.coeffPtr[i]);
		}
	}
	else {
		for (int i = 0; i < poly.size; i++) {
			difference.coeffPtr[i] = this->coeffPtr[i] - poly.coeffPtr[i];
		}

		//If given poly is 0 then the difference will just be this poly value
		for (int i = poly.size; i < newSize; i++) {
			difference.coeffPtr[i] = this->coeffPtr[i];
		}
	}

	return difference;
}

//-------------------------------------------------------------------- -= operator ------------------------------------------------------------------------
//Description: Implemented using the - operator that is already implemented. Instead of just subtracting two polynomial it subtracts the polynomial 
// in the left hand side to this polynomial and sets this equal to that value. 
//----------------------------------------------------------------------------------------------------------------------------------------------------
Poly& Poly::operator-=(const Poly& poly)
{
	//We already overloaded - so we can just use that to subtract
	*this = *this - poly;
	return *this;
}

//-------------------------------------------------------------------- * operator ------------------------------------------------------------------------
//Description: Multiplies two polynomials using the FOIL method which is implemented with a nested for loop. 
//----------------------------------------------------------------------------------------------------------------------------------------------------
Poly Poly::operator*(const Poly& poly)
{
	//Using what I know about multiplying polynomials, the largest exponent of the product of the polynomial should always be:
	//largest exponent of first polynomial plus largest exponent of second polynomial minus one. 
	//Knowing this I can make the size of the product poly to be this->size + poly.size - 1.
	int newSize = (this->size + poly.size) - 1;
	Poly product(0, newSize);

	//We are going to use FOIL to get the product of the two polynomials. We are going to use two for loops to go through each polynomial and multiply them accordingly.
	for (int i = 0; i < size; i++) {
		//Make sure the coefficient is not 0. If it is then we don't need to multiply.
		if (coeffPtr[i] != 0) {
			for (int j = 0; j < poly.size; j++) {
				//NOTE: when we multiply two exponential variables we add the exponents. That is why it is i + j, where i is the exponent of this poly and j is the exponent of the given poly. 
				product.coeffPtr[i + j] = product.coeffPtr[i + j] + (this->coeffPtr[i] * poly.coeffPtr[j]);
			}
		}
	}

	return product;
}

//-------------------------------------------------------------------- *= operator ------------------------------------------------------------------------
//Description: Implemented using the * operator that is already implemented. Instead of just multiplying two polynomial it multiplies the polynomial 
// in the left hand side to this polynomial and sets this equal to that value. 
//----------------------------------------------------------------------------------------------------------------------------------------------------
Poly& Poly::operator*=(const Poly& poly)
{
	//We already overloaded * so we can just use that to add
	*this = *this * poly;
	return *this;
}

//-------------------------------------------------------------------- Osteam ------------------------------------------------------------------------
//Description: This prints out the poly class in polynomial form using ostream. 
//----------------------------------------------------------------------------------------------------------------------------------------------------
ostream& operator << (ostream& out, const Poly& poly)
{
	//I am going to use a while loop to check if poly contains all zeroes or not.
	//The current_index is going to count how many index contain a 0 before we find a non-zero number.
	//When we find a non-zero number we will get out of the while loop or if we are at the end of the poly array we will also get out of the while loop.
	//If the poly array is all zeroes than the number of index counted to have zero should equal the size of the array. 
	int current_index = 0;
	bool check = false;

	while ((current_index < poly.size) && (check == false)) {
		if (poly.coeffPtr[current_index] != 0) {
			check = true;
		}
		else {
			current_index = current_index + 1;
		}
	}

	//If the current_index (number of index that is zero) is equal to the number of element in the array then we just print out 0.
	if (current_index == poly.size) {
		out << " 0";
	}
	else {
		//We are going to print the polynomial from biggest exponent (left) to smallest exponent (right)
		for (int i = poly.size - 1; i > -1; i--) {
			if (poly.coeffPtr[i] != 0) {
				if (poly.coeffPtr[i] > 0) {
					if (i != 0) {
						out << " +" << poly.coeffPtr[i] << "x^" << i;
					}
					else {
						//if the index is 0 then it is jsut a constant
						out << " +" << poly.coeffPtr[i];
					}
				}
				else if (poly.coeffPtr[i] < 0) {
					//NOTE: We don't have to add negative sign because the number already have a negative sign if printed
					if (i != 0) {
						out << " " << poly.coeffPtr[i] << "x^" << i;
					}
					else {
						out << " " << poly.coeffPtr[i];
					}
				}
			}
		}
	}

	out << endl;
	return out;
	
}

//-------------------------------------------------------------------- Isteam ------------------------------------------------------------------------
//Description: Takes in the user input in order of coefficient exponent coefficient expoenent. input -1 -1 to tell the program to end. 
//----------------------------------------------------------------------------------------------------------------------------------------------------
istream& operator >> (istream& in, Poly& poly)
{
	//addCoeff is the coefficient from user input that we need to add to poly. 
	int addCoeff;

	//addExp is the exponent from user input we need to add to poly.
	int addExp;

	//Look at our first Coeff and Exp
	in >> addCoeff >> addExp;
	while ((addCoeff != -1) && (addExp != -1)) {
		//The exponent cannot be negative. Only add to polynomial is the exponent is not negative. 
		if (addExp > -1) {
			poly.setCoeff(addCoeff, addExp);
		}
		in >> addCoeff >> addExp;
	}

	return in;
}
