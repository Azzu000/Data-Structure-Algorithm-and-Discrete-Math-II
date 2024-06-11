//----------------------------------------------------------------------------------------------Comedy--------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Comedy is the child class of movies. The virtual functions of comedy is getStock and setStock which overrides the same functions in the Movie class. The other virtual functiosn 
//the >, <, ==, != which is used to compare the movies and sort them according to their spcified sorting criteria. For comedy, the sorting criteria is to sort by title then year. 
//The display function is also virtual as it is used to display comedy movie types.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//We assume that all the necessary information about the comedy movie is given.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "comedy.h"

//------------------------  Comedy Constructor -----------------------------
// Initiates the variables for Comedy Movies
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Comedy::Comedy(char movie_type, int stock, string director, string title, int year) : Movie(movie_type, stock, director, title, year) {
	this->movie_type = movie_type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->year = year;
}

//-------------------------------- setStock ---------------------------------
// sets the stock for the comedy movie. Useed to add or subtract stocks
// accordingly.
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
void Comedy::setStock(int stock)
{
	this->stock = stock;
}

//-------------------------------- getStock ---------------------------------
// Gets the stock and returns it
// Preconditions: NONE
// Postconditions: Returns the stock.
//---------------------------------------------------------------------------
int Comedy::getStock() const
{
	int temp_stock = this->stock;
	return temp_stock;
}

//------------------------------- getSDirector ------------------------------
// Gets the director and returns it
// Preconditions: NONE
// Postconditions: Returns the director.
//---------------------------------------------------------------------------
string Comedy::getDirector() const
{
	string temp_director = this->director;
	return temp_director;
}

//--------------------------------- getTitle --------------------------------
// Gets the title and returns it
// Preconditions: NONE
// Postconditions: Returns the title.
//---------------------------------------------------------------------------
string Comedy::getTitle() const
{
	string temp_title = this->title;
	return temp_title;
}

//--------------------------------- getYear --------------------------------
// Gets the year and returns it
// Preconditions: NONE
// Postconditions: Returns the year.
//---------------------------------------------------------------------------
int Comedy::getYear() const
{
	int temp_year = this->year;
	return temp_year;
}

//-------------------------------- operator > -------------------------------
// Returns true if the comedy movie is bigger than the other comedy movie
// and false otherwise.
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Comedy::operator>(const Movie& comedy) const
{
	if (this->getTitle() < comedy.getTitle()) {
		return false;
	}
	else if (this->getTitle() > comedy.getTitle()) {
		return true;
	}
	else if (this->getTitle() == comedy.getTitle()) {
		if (this->getYear() < comedy.getYear()) {
			return false;
		}
		else if (this->getYear() > comedy.getYear()) {
			return true;
		}
		else if(this->getYear() == comedy.getYear()) {
			return false; //Both comedy are equal
		}
	}
	//will return false and an error if none of the above if statements are passed
	cerr << "ERROR: Comedy - Neither greater, less or equal. Something is wrong." << endl;
	return false;
}

//-------------------------------- operator < -------------------------------
// Returns true if the comedy movie is smaller than the other comedy movie
// and false otherwise.
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Comedy::operator<(const Movie& comedy) const
{
	if (this->getTitle() > comedy.getTitle()) {
		return false;
	}
	else if (this->getTitle() < comedy.getTitle()) {
		return true;
	}
	else if (this->getTitle() == comedy.getTitle()) {
		if (this->getYear() > comedy.getYear()) {
			return false;
		}
		else if (this->getYear() < comedy.getYear()) {
			return true;
		}
		else if (this->getYear() == comedy.getYear()) {
			return false; //Both comedy are equal
		}
	}//will return false and an error if none of the above if statements are passed
	cerr << "ERROR: Comedy - Neither greater, less or equal. Something is wrong." << endl;
	return false;
	
}

//-------------------------------- operator == ------------------------------
// Returns true if the comedy movie is equal than the other comedy movie
// and false otherwise.
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Comedy::operator==(const Movie& comedy) const
{
	if (this->getMovieType() == comedy.getMovieType() && this->getDirector() == comedy.getDirector() && this->getTitle() == comedy.getTitle() && this->getYear() == comedy.getYear()) {
		return true;
	}
	else {
		return false;
	}
}

//-------------------------------- operator != ------------------------------
// Returns true if the comedy movie is does not equal than the other comedy
// movie
// and false otherwise.
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Comedy::operator!=(const Movie& comedy) const
{
	//if it is equal then it is false and if it is not equal then it is true
	if (this->getMovieType() == comedy.getMovieType() && this->getDirector() == comedy.getDirector() && this->getTitle() == comedy.getTitle() && this->getYear() == comedy.getYear()) {
		return false;
	}
	else {
		return true;
	}
	
}

//---------------------------------- display --------------------------------
// Display the comedy movie and it's information in the same order as file. 
// Preconditions: NONE
// Postconditions: Outputs comedy movie. 
//---------------------------------------------------------------------------
void Comedy::display()
{
	cout << this->getMovieType() << ", " << this->getStock() << ", " << this->getDirector() << ", " << this->getTitle() << ", " << this->getYear() << endl;
}



