//----------------------------------------------------------------------------------------------Drama--------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Drama is the child class of movies. The virtual functions of drama is getStock and setStock which overrides the same functions in the Movie class. The other virtual functiosn 
//the >, <, ==, != which is used to compare the movies and sort them according to their spcified sorting criteria. For drama, the sorting criteria is to sort by director then title. 
//The display function is also virtual as it is used to display drama movie types.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//We assume that all the necessary information about the drama movie is given.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "drama.h"

//------------------------  Drama Constructor -----------------------------
// Initiates the variables for Drama Movies
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Drama::Drama(char movie_type, int stock, string director, string title, int year) : Movie(movie_type, stock, director, title, year)
{
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
void Drama::setStock(int stock)
{
	this->stock = stock;
}

//-------------------------------- getStock ---------------------------------
// Gets the stock and returns it
// Preconditions: NONE
// Postconditions: Returns the stock.
//---------------------------------------------------------------------------
int Drama::getStock() const
{
	int temp_stock = this->stock;
	return temp_stock;
}

//------------------------------- getSDirector ------------------------------
// Gets the director and returns it
// Preconditions: NONE
// Postconditions: Returns the director.
//---------------------------------------------------------------------------
string Drama::getDirector() const
{
	string temp_director = this->director;
	return temp_director;
}

//--------------------------------- getTitle --------------------------------
// Gets the title and returns it
// Preconditions: NONE
// Postconditions: Returns the title.
//---------------------------------------------------------------------------
string Drama::getTitle() const
{
	string temp_title = this->title;
	return temp_title;
}

//--------------------------------- getYear --------------------------------
// Gets the year and returns it
// Preconditions: NONE
// Postconditions: Returns the year.
//---------------------------------------------------------------------------
int Drama::getYear() const
{
	int temp_year = this->year;
	return temp_year;
}

//-------------------------------- operator > -------------------------------
// Returns true if the drama movie is bigger than the other drama movie
// and false otherwise.
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Drama::operator>(const Movie& drama) const
{
	if (this->getDirector() < drama.getDirector()) {
		return false;
	}
	else if (this->getDirector() > drama.getDirector()) {
		return true;
	}
	else if (this->getDirector() == drama.getDirector()) {
		if (this->getTitle() < drama.getTitle()) {
			return false;
		}
		else if (this->getTitle() > drama.getTitle()) {
			return true;
		}
		else if (this->getTitle() == drama.getTitle()) {
			return false; //Both drama are equal
		}
	}
	//will return false and an error if none of the above if statements are passed
	cerr << "ERROR: Drama - Neither greater, less or equal. Something is wrong." << endl;
	return false;
}

//-------------------------------- operator < -------------------------------
// Returns true if the drama movie is smaller than the other drama movie
// and false otherwise.
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Drama::operator<(const Movie& drama) const
{
	if (this->getDirector() > drama.getDirector()) {
		return false;
	}
	else if (this->getDirector() < drama.getDirector()) {
		return true;
	}
	else if (this->getDirector() == drama.getDirector()) {
		if (this->getTitle() > drama.getTitle()) {
			return false;
		}
		else if (this->getTitle() < drama.getTitle()) {
			return true;
		}
		else if (this->getTitle() == drama.getTitle()) {
			return false; //Both drama are equal
		}
	}
	//will return false and an error if none of the above if statements are passed
	cerr << "ERROR: Drama - Neither greater, less or equal. Something is wrong." << endl;
	return false;
}

//-------------------------------- operator == ------------------------------
// Returns true if the drama movie is equal than the other drama movie
// and false otherwise.
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Drama::operator==(const Movie& drama) const
{
	//Everything have to equal in order for this to return true.
	if (this->getMovieType() == drama.getMovieType() && this->getDirector() == drama.getDirector() && this->getTitle() == drama.getTitle() && this->getYear() == drama.getYear()) {
		return true;
	}
	else {
		return false;
	}
}

//-------------------------------- operator != ------------------------------
// Returns true if the drama movie is does not equal than the other drama
// movie
// and false otherwise.
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Drama::operator!=(const Movie& drama) const
{
	if (this->getMovieType() == drama.getMovieType() && this->getDirector() == drama.getDirector() && this->getTitle() == drama.getTitle() && this->getYear() == drama.getYear()) {
		return false;
	}
	else {
		return true;
	}
}

//---------------------------------- display --------------------------------
// Display the drama movie and it's information in the same order as file. 
// Preconditions: NONE
// Postconditions: Outputs drama movie. 
//---------------------------------------------------------------------------
void Drama::display()
{
	cout << this->getMovieType() << ", " << this->getStock() << ", " << this->getDirector() << ", " << this->getTitle() << ", " << this->getYear() << endl;
}

