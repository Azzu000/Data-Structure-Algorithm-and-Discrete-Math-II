//----------------------------------------------------------------------------------------------Movie--------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//This the parent class of comedy, classic, and drama movies.The constructor of the movie calss represents the different type of movies  and the functions are all similar to those 
//in the child classes. There is getter methods and operator overload in which helps sort the movie. The oeprators and the setStock and getStock methods are all virtual as it depends 
//on the movie type. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//We assume that all the necessary information is there to make the movie.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "movie.h"

//------------------------ Movie Constructor -------------------------------
// This movie constructor is more drama and comedy movies.  
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Movie::Movie(char movie_type, int stock, string director, string title, int year)
{
	this->movie_type = movie_type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->year = year;
	int month = 13; //this is a default month which is non-exsistent
	string actor = "no actor"; //this is the default place-holder for actor
}

//------------------------ Movie Constructor -------------------------------
// This movie constructor is more classic movies.  
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Movie::Movie(char movie_type, int stock, string director, string title, string actor, int month, int year)
{
	this->movie_type = movie_type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->actor = actor;
	this->month = month;
	this->year = year;
}

//------------------------ setStock -------------------------------
// Set the stock to another value.  
// Preconditions: NONE
// Postconditions: NONE
//------------------------------------------------------------------
void Movie::setStock(int stock)
{
	this->stock = stock;
}

//------------------------ getMovieType ---------------------------
// Get the movie type and return it.  
// Preconditions: NONE
// Postconditions: return the movie type.
//------------------------------------------------------------------
char Movie::getMovieType() const
{
	char temp_movie_type = this->movie_type;
	return temp_movie_type;
}

//------------------------  getStock ---------------------------
// Get the stock and return it.  
// Preconditions: NONE
// Postconditions: return the stock.
//--------------------------------------------------------------
int Movie::getStock() const
{
	int temp_stock = this->stock;
	return temp_stock;
}

//------------------------ getTitle ---------------------------
// Get the title and return it.  
// Preconditions: NONE
// Postconditions: return the title.
//--------------------------------------------------------------
string Movie::getTitle() const
{
	string temp_title = this->title;
	return temp_title;
}

//------------------------ getActor ---------------------------
// Get the actor and return it.  
// Preconditions: NONE
// Postconditions: return the actor.
//--------------------------------------------------------------
string Movie::getActor() const
{
	string temp_actor = this->actor;
	return temp_actor;
}

//------------------------ getMonth ---------------------------
// Get the month and return it.  
// Preconditions: NONE
// Postconditions: return the month.
//--------------------------------------------------------------
int Movie::getMonth() const
{
	int temp_month = this->month;
	return temp_month;
}

//------------------------ getYear ---------------------------
// Get the year and return it.  
// Preconditions: NONE
// Postconditions: return the year.
//--------------------------------------------------------------
int Movie::getYear() const
{
	int temp_year = this->year;
	return temp_year;
}

//------------------------ getDirector ---------------------------
// Get the director and return it.  
// Preconditions: NONE
// Postconditions: return the director.
//--------------------------------------------------------------
string Movie::getDirector() const
{
	string temp_director = this->director;
	return temp_director;
}

//------------------------ display ---------------------------
// display the movie depdning on the movie type. It is overrided 
// by the child classes.   
// Preconditions: NONE
// Postconditions: Outputs the movie information.
//--------------------------------------------------------------
void Movie::display()
{
	//movie_type a is the default movie type and therefore it means this movie have not been declared
	if (this->getMovieType() == 'a') {
		return;
	}
	else if (this->getMovieType() == 'F' || this->getMovieType() == 'D') {
		cout << this->getMovieType() << ", " << this->getStock() << ", " << this->getDirector() << ", " << this->getTitle() << ", " << this->getYear() << endl;
	}
	else if (this->getMovieType() == 'C') {
		cout << this->getMovieType() << ", " << this->getStock() << ", " << this->getDirector() << ", " << this->getTitle() << ", " << this->getActor() << " " << this->getMonth() << " " << this->getYear() << endl;
	}
	cout << endl;
}

//------------------------ Ostream ---------------------------
// display the movie depdning on the movie type. It is overrided 
// by the child classes.Very similar to the display function. 
// Preconditions: NONE
// Postconditions: return the year.
//--------------------------------------------------------------
ostream& operator << (ostream& out, const Movie& movie)
{
	//movie_type a is the default movie type and therefore it means this movie have not been declared
	if (movie.getMovieType() == 'a') {
		out << " " << endl;
		cerr << "ERROR: The movie you are trying to output does not exist." << endl;
		return out;
	}
	else if (movie.getMovieType() == 'F' || movie.getMovieType() == 'D') {
		out << movie.getMovieType() << ", " << movie.getStock() << ", " << movie.getDirector() << ", " << movie.getTitle() << ", " << movie.getYear() << endl;
	}
	else if (movie.getMovieType() == 'C') {
		out << movie.getMovieType() << ", " << movie.getStock() << ", " << movie.getDirector() << ", " << movie.getTitle() << ", " << movie.getActor() << " " << movie.getMonth() << " " << movie.getYear() << endl;
	}
	return out;
}

//-------------------------------- operator > -------------------------------
// Returns true if the movie is bigger than the other movie
// and false otherwise. Default movie sort by year. 
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Movie::operator > (const Movie& movie) const
{
	if (this->getYear() > movie.getYear()) {
		return true;
	}
	else {
		return false;
	}
	//will return false and an error if none of the above if statements are passed
	cerr << "ERROR: Movie - Neither greater, less or equal. Something is wrong." << endl;
	return false;
	
}

//-------------------------------- operator < -------------------------------
// Returns true if the movie is smaller than the other movie
// and false otherwise. Default movie sort by year. 
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Movie::operator < (const Movie& movie) const
{
	if (this->getYear() < movie.getYear()) {
		return true;
	}
	else {
		return false;
	}
	//will return false and an error if none of the above if statements are passed
	cerr << "ERROR: Movie - Neither greater, less or equal. Something is wrong." << endl;
	return false;
}

//-------------------------------- operator == ------------------------------
// Returns true if the movie is equal than the other movie
// and false otherwise. Default movie sort by year. 
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Movie::operator == (const Movie& movie) const
{
	if ((this->getTitle() == movie.getTitle()) && (this->getYear() == movie.getYear())) {
		return true;
	}
	else {
		return false;
	}
}

//-------------------------------- operator != -------------------------------
// Returns true if the movie is not equal to the other movie
// and false otherwise. Default movie sort by year. 
// Preconditions: NONE
// Postconditions: Returns true or false. 
//---------------------------------------------------------------------------
bool Movie::operator != (const Movie& movie) const
{
	if (*this == movie) {
		return false;
	}
	else {
		return true;
	}
}

