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

#pragma once
#ifndef COMMAND_H_
#define COMMAND_H_
#include <string>
#include <iostream>

using namespace std;

class Command
{
public:
	Command(char command_type); //Command constructor for I (print inventory)
	Command(char command_type, int customer_id); //Command constructor for H (print customer history)
	Command(char command_type, int customer_id, char media_type, char movie_type, string title, int year); //For command B (Borrow) and R (Return) with F (Comedy)
	Command(char command_type, int customer_id, char media_type, char movie_type, string director, string title); //For command B (Borrow) and R (Return) with D (Drama)
	Command(char command_type, int customer_id, char media_type, char movie_type, int month, int year, string actor); //For command B (Borrow) and R (Return) with C (Classic) movies

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


