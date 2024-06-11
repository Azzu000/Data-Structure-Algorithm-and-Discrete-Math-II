//------------------------------------------------------------------------------------------------Return----------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Return is a child class of Command as it is one of the commands a customer can give. Return is a very simple class in which allows it's parent class (Command) display it's reutrn 
//transactions in the right order by using virtual to override the Command's display function. Other than that, that is pretty much the only thing the Return class do. There are also
//getters for the Return command that is useful when needed. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//No Assumptions.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "return.h"

//------------------------ Return Constructor ------------------------------
// Initiates the variables for returning comedy movies. 
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Return::Return(char command_type, int customer_id, char media_type, char movie_type, string title, int year) :
	Command(command_type, customer_id, media_type, movie_type, title, year)
{
	this->command_type = command_type;
	this->customer_id = customer_id;
	this->media_type = media_type;
	this->movie_type = movie_type;
	this->year = year;
	this->title = title;

	//rest is default values
	this->director;
	this->month = 0;
	this->actor = "none";
}

//------------------------ Return Constructor -------------------------------
// Initiates the variables for returning drama movies. 
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Return::Return(char command_type, int customer_id, char media_type, char movie_type, string director, string title) : 
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

//------------------------ Return Constructor -------------------------------
// Initiates the variables for reutrning classic movies. 
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Return::Return(char command_type, int customer_id, char media_type, char movie_type, int month, int year, string actor) :
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
// Gets the Command Type and return it
// Preconditions: NONE
// Postconditions: returns the command type.
//--------------------------------------------------------------------------
char Return::getCommandType()
{
	char temp_command_type = command_type;
	return temp_command_type;
}


//--------------------------- getCustomerID --------------------------------
//Gets the Customer ID and return it
// Preconditions: NONE
// Postconditions: returns the customer id.
//--------------------------------------------------------------------------
int Return::getCustomerID()
{
	int temp_id = customer_id;
	return temp_id;
}

//--------------------------- getMediaType --------------------------------
// Gets the Meida Type and return it
// Preconditions: NONE
// Postconditions: returns the media type.
//-------------------------------------------------------------------------
char Return::getMediaType()
{
	char temp_media_type = media_type;
	return temp_media_type;
}

//---------------------------- getMovieType --------------------------------
// Gets the Movie Type and reutrn it
// Preconditions: NONE
// Postconditions: returns the movie type.
//--------------------------------------------------------------------------
char Return::getMovieType()
{
	char temp_movie_type = movie_type;
	return temp_movie_type;
}

//---------------------------- getDirector --------------------------------
// Gets the Director and reutrn it
// Preconditions: NONE
// Postconditions: returns the director.
//-------------------------------------------------------------------------
string Return::getDirector()
{
	string temp_director = director;
	return temp_director;
}

//---------------------------- gettTitle --------------------------------
// Gets the Title and reutrn it
// Preconditions: NONE
// Postconditions: returns the title type.
//----------------------------------------------------------------------
string Return::getTitle()
{
	string temp_title = title;
	return temp_title;
}

//---------------------------- getYear --------------------------------
// Gets the year and reutrn it
// Preconditions: NONE
// Postconditions: returns the year.
//----------------------------------------------------------------------
int Return::getYear()
{
	int temp_year = year;
	return temp_year;
}

//---------------------------- getMonth --------------------------------
// Gets the month and return it
// Preconditions: NONE
// Postconditions: returns the month.
//----------------------------------------------------------------------
int Return::getMonth()
{
	int temp_month = month;
	return temp_month;
}

//---------------------------- getActor --------------------------------
// Gets the actor and return it
// Preconditions: NONE
// Postconditions: returns the actor.
//----------------------------------------------------------------------
string Return::getActor()
{
	string temp_actor = actor;
	return temp_actor;
}

//---------------------------- display --------------------------------
// Display the Return commands depending on the movie type.
// Preconditions: NONE
// Postconditions: Outputs Return Command.
//----------------------------------------------------------------------
void Return::display()
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

