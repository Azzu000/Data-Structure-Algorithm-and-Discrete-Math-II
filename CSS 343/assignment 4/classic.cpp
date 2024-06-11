//----------------------------------------------------------------------------------------------Classic--------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Classic is the child class of movies. The virtual functions of classic is getStock and setStock which overrides the same functions in the Movie class. The other virtual functiosn 
//the >, <, ==, != which is used to comapre the movies and sort them according to their spcified sorting criteria. For classics, the sorting criteria is to sort by release date then
//major actors. The display function is also virtual as it is used to display classic movie types.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//We assume that all the necessary information about the classic movie is given.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "classic.h"


//------------------------  Classic Constructor -----------------------------
// Initiates the variables for Classic Movies
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Classic::Classic(char movie_type, int stock, string director, string title, string actor, int month, int year) :
	Movie(movie_type, stock, director, title, actor, month, year)
{
	this->movie_type = movie_type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->actor = actor;
	this->month = month;
	this->year = year;
}

//-------------------------------- setStock ---------------------------------
// sets the stock for the classic movie. Useed to add or subtract stocks
// accordingly.
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
void Classic::setStock(int stock)
{
	this->stock = stock;
}

//-------------------------------- getStock ---------------------------------
// Gets the stock and returns it
// Preconditions: NONE
// Postconditions: Returns the stock.
//---------------------------------------------------------------------------

int Classic::getStock() const
{
	int temp_stock = this->stock;
	return temp_stock;
}

//------------------------------- getSDirector ------------------------------
// Gets the director and returns it
// Preconditions: NONE
// Postconditions: Returns the director.
//---------------------------------------------------------------------------
string Classic::getDirector() const
{
	string temp_director = this->director;
	return temp_director;
}

//--------------------------------- getTitle --------------------------------
// Gets the title and returns it
// Preconditions: NONE
// Postconditions: Returns the title.
//---------------------------------------------------------------------------
string Classic::getTitle() const
{
	string temp_title = this->title;
	return temp_title;
}


//--------------------------------- getActor --------------------------------
// Gets the actor and returns it
// Preconditions: NONE
// Postconditions: Returns the actor.
//---------------------------------------------------------------------------
string Classic::getActor() const
{
	string temp_actor = this->actor;
	return temp_actor;
}

//--------------------------------- getMonth --------------------------------
// Gets the month and returns it
// Preconditions: NONE
// Postconditions: Returns the month.
//---------------------------------------------------------------------------
int Classic::getMonth() const
{
	int temp_month = this->month;
	return temp_month;
}

//--------------------------------- getYear --------------------------------
// Gets the year and returns it
// Preconditions: NONE
// Postconditions: Returns the year.
//---------------------------------------------------------------------------
int Classic::getYear() const
{
	int temp_year = this->year;
	return temp_year;
}

//-------------------------------- operator > -------------------------------
// Returns true if the classic movie is bigger than the other classic movie
// and false otherwise.
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Classic::operator > (const Movie& classic) const
{

	if (this->getYear() < classic.getYear()) {
		return false;
	}
	else if (this->getYear() > classic.getYear()) {
		return true;
	}
	else if (this->getYear() == classic.getYear()) {
		if (this->getMonth() > classic.getMonth()) {
			return false;
		}
		else if (this->getMonth() < classic.getMonth()) {
			return true;
		}
		else if (this->getMonth() == classic.getMonth()) {
			if (this->getActor() < classic.getActor()) {
				return false;
			}
			else if (this->getActor() > classic.getActor()) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	//will return false and an error if none of the above if statements are passed
	cerr << "ERROR: Classic - Neither greater, less or equal. Something is wrong." << endl;
	return false;
}

//-------------------------------- operator < -------------------------------
// Returns true if the classic movie is smaller than the other classic movie
// and false otherwise.
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Classic::operator<(const Movie& classic) const
{
	if (this->getYear() > classic.getYear()) {
		return false;
	}
	else if (this->getYear() < classic.getYear()) {
		return true;
	}
	else if (this->getYear() == classic.getYear()) {
		if (this->getMonth() < classic.getMonth()) {
			return true;
		}
		else if (this->getMonth() > classic.getMonth()) {
			return false;
		}
		else if (this->getMonth() == classic.getMonth()) {
			if (this->getActor() > classic.getActor()) {
				return false;
			}
			else if (this->getActor() < classic.getActor()) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	//will return false and an error if none of the above if statements are passed
	cerr << "ERROR: Classic - Neither greater, less or equal. Something is wrong." << endl;
	return false;
}

//-------------------------------- operator == ------------------------------
// Returns true if the classic movie is equal than the other classic movie
// and false otherwise.
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Classic::operator==(const Movie& classic) const
{
	//movie_type, stock, director, title, actor, month, year
	if (this->getMovieType() == classic.getMovieType() && this->getDirector() == classic.getDirector() && this->getTitle() == classic.getTitle() && this->getYear() == classic.getYear() && this->getMonth() == classic.getMonth() && this->getActor() == classic.getActor()) {
		return true;
	}
	else {
		return false;
	}
}

//-------------------------------- operator != ------------------------------
// Returns true if the classic movie is does not equal than the other classic
// movie
// and false otherwise.
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Classic::operator!=(const Movie& classic) const
{
	if (this->getMovieType() == classic.getMovieType() && this->getDirector() == classic.getDirector() && this->getTitle() == classic.getTitle() && this->getYear() == classic.getYear() && this->getMonth() == classic.getMonth() && this->getActor() == classic.getActor()) {
		return false;
	}
	else {
		return true;
	}
}

//---------------------------------- display --------------------------------
// Display the classic movie and it's information in the same order as file. 
// Preconditions: NONE
// Postconditions: Outputs classic movie. 
//---------------------------------------------------------------------------
void Classic::display()
{
	cout << this->getMovieType() << ", " << this->getStock() << ", " << this->getDirector() << ", " << this->getTitle() << ", " << this->getActor() << " " << this->getMonth() << " " << this->getYear() << endl;
}

