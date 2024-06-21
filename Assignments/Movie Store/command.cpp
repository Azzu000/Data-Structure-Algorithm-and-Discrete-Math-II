//----------------------------------------------------------------------------------------------Commands--------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// The Comand class is the parent class to the Return and Borrow class. The Command class have 5 constructors, one for each trasactions and transaction for different movie types. Each
// constructors is labeled in the comments for which command it represent. The reason why we don't have a explicit class for I (print inventory) and H (print customer history) is 
// because both of the commands don't need to be recorded for each customer. Both commadns simply just outputs the information it asks for. We have all the variables needed to 
// represent the information of each command. We have getters methods to help get those variavles as well. The dsiplay function is used to dipslay return and borrow transactions 
// when asked. It is overrided by the display function of both borrow and return, depening on which transaction it is. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//We assume that all the necessary information for the command is given. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "command.h"

//------------------------  Command Constructor -----------------------------
// Initiates the variables for the I command. 
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Command::Command(char command_type)
{
	this->command_type = command_type;

	//rest is default values
	this->customer_id = 0;
	this->media_type = 'a';
	this->movie_type = 'a';
	this->year = 0;
	this->title = "none";
	this->director;
	this->month = 0;
	this->actor = "none";
}

//------------------------  Command Constructor -----------------------------
// Initiates the variables for the H command. 
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Command::Command(char command_type, int customer_id)
{
	this->command_type = command_type;
	this->customer_id = customer_id;

	//rest is default values
	this->media_type = 'a';
	this->movie_type = 'a';
	this->year = 0;
	this->title = "none";
	this->director;
	this->month = 0;
	this->actor = "none";
}

//------------------------  Brrow Constructor -------------------------------
// Initiates the variables for borrow/return comedy movies. 
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Command::Command(char command_type, int customer_id, char media_type, char movie_type, string title, int year)
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
// Initiates the variables for borrow/return drama movies. 
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Command::Command(char command_type, int customer_id, char media_type, char movie_type, string director, string title)
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
// Initiates the variables for borrow/return classic movies. 
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Command::Command(char command_type, int customer_id, char media_type, char movie_type, int month, int year, string actor)
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

//-------------------------  getCommandType ---------------------------------
// Get the command type and return it.  
// Preconditions: NONE
// Postconditions: return command type. 
//---------------------------------------------------------------------------
char Command::getCommandType()
{
	char temp_command_type = command_type;
	return temp_command_type;
}

//---------------------------  getCustomerID --------------------------------
// Get the customer id and return it.  
// Preconditions: NONE
// Postconditions: return customer id. 
//---------------------------------------------------------------------------
int Command::getCustomerID()
{
	int temp_id = customer_id;
	return temp_id;
}

//----------------------------  getMediaType --------------------------------
// Get the media type and return it.  
// Preconditions: NONE
// Postconditions: return media type. 
//---------------------------------------------------------------------------
char Command::getMediaType()
{
	char temp_media_type = media_type;
	return temp_media_type;
}

//----------------------------  getMovieType --------------------------------
// Get the movie type and return it.  
// Preconditions: NONE
// Postconditions: return movie type. 
//---------------------------------------------------------------------------
char Command::getMovieType()
{
	char temp_movie_type = movie_type;
	return temp_movie_type;
}

//-----------------------------  getDirector --------------------------------
// Get the director and return it.  
// Preconditions: NONE
// Postconditions: return director. 
//---------------------------------------------------------------------------
string Command::getDirector()
{
	string temp_director = director;
	return temp_director;
}

//-------------------------------  getTitle ---------------------------------
// Get the title and return it.  
// Preconditions: NONE
// Postconditions: return title. 
//---------------------------------------------------------------------------
string Command::getTitle()
{
	string temp_title = title;
	return temp_title;
}

//-------------------------------  getYear ---------------------------------
// Get the year and return it.  
// Preconditions: NONE
// Postconditions: return year. 
//---------------------------------------------------------------------------
int Command::getYear()
{
	int temp_year = year;
	return temp_year;
}

//-------------------------------  getMonth ---------------------------------
// Get the month and return it.  
// Preconditions: NONE
// Postconditions: return month. 
//---------------------------------------------------------------------------
int Command::getMonth()
{
	int temp_month = month;
	return temp_month;
}

//-------------------------------  getActor ---------------------------------
// Get the actor and return it.  
// Preconditions: NONE
// Postconditions: return actor. 
//---------------------------------------------------------------------------
string Command::getActor()
{
	string temp_actor = actor;
	return temp_actor;
}

//-------------------------------  display ---------------------------------
// Display the commands according to the movie type. This is only for return
// and borrow commands. No need to display I and H commands. 
// Preconditions: The command type exists. 
// Postconditions: Outputs borrow and return commands. 
//---------------------------------------------------------------------------
void Command::display()
{
	//displays wrong commands
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
	
	cout << endl;
}
