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

#pragma once
#ifndef RETURN_H_
#define RETURN_H_
#include <string>
#include <iostream>
#include "command.h"

using namespace std;

class Return : public Command
{
public:
	Return(char command_type, int customer_id, char media_type, char movie_type, string title, int year); //Return for F (Comedy) 
	Return(char command_type, int customer_id, char media_type, char movie_type, string director, string title); //Return for D (Drama)
	Return(char command_type, int customer_id, char media_type, char movie_type, int month, int year, string actor); //Return for C (Classic)

	//Getters
	char getCommandType();
	int getCustomerID();
	char getMediaType();
	char getMovieType();
	string getDirector();
	string getTitle();
	int getYear();
	int getMonth();
	string getActor();

	//Actions
	virtual void display();

private:
	//All these information can be taken form the command and so there is this much variables.
	char command_type = 'a'; //a is the default command type
	int customer_id = 0; //0 is the default customer id
	char media_type = 'D'; //We know that we only have media type D (DVD)
	char movie_type = 'a'; //a is the default movie type
	string director;
	string title;
	int year = 0;
	int month = 0;
	string actor;

};
#endif

