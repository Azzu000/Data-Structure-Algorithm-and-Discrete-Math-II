//----------------------------------------------------------------------------------------------Borrow------------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Borrow is a child class of Command as it is one of the commands a customer can give. Borrow is a very simple class in which allows it's parent class (Command) display it's borrow 
//transactions in the right order by using virtual to override the Command's display function. Other than that, that is pretty much the only thing the Borrow calss do. There are also
//getters for the Borrow command that is useful when needed. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//No Assumptions.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "borrow.h"

//------------------------  Brrow Constructor -------------------------------
// Initiates the variables for borrowing comedy movies. 
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Borrow::Borrow(char command_type, int customer_id, char media_type, char movie_type, string title, int year) :
	Command(command_type, customer_id, media_type, movie_type, title, year)
{
	this->command_type = command_type;
	this->customer_id = customer_id;
	this->media_type = media_type;
	this->movie_type = movie_type;
	this->year = year;
	this->title = title;

	//rest is default values
	this->director = "none";
	this->month = 0;
	this->actor = "none";
}

//------------------------  Brrow Constructor -------------------------------
// Initiates the variables for borrowing drama movies. 
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Borrow::Borrow(char command_type, int customer_id, char media_type, char movie_type, string director, string title) :
	Command(command_type, customer_id, media_type, movie_type, director, title)
{
	this->command_type = command_type;
	this->customer_id = customer_id;
	this->media_type = media_type;
	this->movie_type = movie_type;
	this->director = director;
	this->title = title;

	//rest is default values
	this->year = 0;
	this->month = 0;
	this->actor = "none";
}

//------------------------  Brrow Constructor -------------------------------
// Initiates the variables for borrowing classic movies. 
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Borrow::Borrow(char command_type, int customer_id, char media_type, char movie_type, int month, int year, string actor) :
	Command(command_type, customer_id, media_type, movie_type, month, year, actor)
{
	this->command_type = command_type;
	this->customer_id = customer_id;
	this->media_type = media_type;
	this->movie_type = movie_type;
	this->year = year;
	this->month = month;
	this->actor = actor;

	//rest is default values
	this->director = "none";
	this->title = "none";
}

//-------------------------- getCommandType --------------------------------
// Gets the Command Type and reutrn it
// Preconditions: NONE
// Postconditions: returns the command type.
//--------------------------------------------------------------------------
char Borrow::getCommandType()
{
	char temp_command_type = command_type;
	return temp_command_type;
}

//--------------------------- getCustomerID --------------------------------
//Gets the Customer ID and reutrn it
// Preconditions: NONE
// Postconditions: returns the customer id.
//--------------------------------------------------------------------------
int Borrow::getCustomerID()
{
	int temp_id = customer_id;
	return temp_id;
}

//--------------------------- getMediaType --------------------------------
// Gets the Meida Type and reutrn it
// Preconditions: NONE
// Postconditions: returns the media type.
//-------------------------------------------------------------------------
char Borrow::getMediaType()
{
	char temp_media_type = media_type;
	return temp_media_type;
}

//---------------------------- getMovieType --------------------------------
// Gets the Movie Type and reutrn it
// Preconditions: NONE
// Postconditions: returns the movie type.
//--------------------------------------------------------------------------
char Borrow::getMovieType()
{
	char temp_movie_type = movie_type;
	return temp_movie_type;
}

//---------------------------- getDirector --------------------------------
// Gets the Director and reutrn it
// Preconditions: NONE
// Postconditions: returns the director.
//-------------------------------------------------------------------------
string Borrow::getDirector()
{
	string temp_director = director;
	return temp_director;
}

//---------------------------- gettTitle --------------------------------
// Gets the Title and reutrn it
// Preconditions: NONE
// Postconditions: returns the title type.
//----------------------------------------------------------------------
string Borrow::getTitle()
{
	string temp_title = title;
	return temp_title;
}
//---------------------------- getYear --------------------------------
// Gets the year and reutrn it
// Preconditions: NONE
// Postconditions: returns the year.
//----------------------------------------------------------------------

int Borrow::getYear()
{
	int temp_year = year;
	return temp_year;
}

//---------------------------- getMonth --------------------------------
// Gets the month and return it
// Preconditions: NONE
// Postconditions: returns the month.
//----------------------------------------------------------------------
int Borrow::getMonth()
{
	int temp_month = month;
	return temp_month;
}

//---------------------------- getActor --------------------------------
// Gets the actor and return it
// Preconditions: NONE
// Postconditions: returns the actor.
//----------------------------------------------------------------------
string Borrow::getActor()
{
	string temp_actor = actor;
	return temp_actor;
}

//---------------------------- display --------------------------------
// Display the Borrow commands depending on the movie type.
// Preconditions: NONE
// Postconditions: Outputs Borrow Command.
//----------------------------------------------------------------------
void Borrow::display()
{
	if (this->getMovieType() == 'F') {
		cout << this->getCommandType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() <<
			" " << this->getTitle() << " " << this->getYear() << endl;
	}
	else if (this->getMovieType() == 'D') {
		cout << this->getCommandType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() <<
			" " << this->getDirector() << " " << this->getTitle() << endl;
	}
	else if (this->getMovieType() == 'C') {
		cout << this->getCommandType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() <<
			" " << this->getMonth() << " " << this->getYear() << " " << this->getActor() << endl;
	}
	else {
		
		//if the title is not declared the commadn format is in classic movie format
		if (this->title == "none") {
			cout << this->getCommandType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() <<
				" " << this->getMonth() << " " << this->getYear() << " " << this->getActor() << endl;
		}
		//if the director is not declared then it is in comedy movie format
		else if (director == "none") {
			cout << this->getCommandType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() <<
				" " << this->getTitle() << " " << this->getYear() << endl;
		}
		//else it is in drama format
		else {
			cout << this->getCommandType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() <<
				" " << this->getDirector() << " " << this->getTitle() << endl;
		}
	}
}