//----------------------------------------------------------------------------------------------Borrow------------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//The Customer calss includes everything that defines a customer. We can identify a customer by its first name, last name, and id. Each customer is gonna have a queue that will hold
// all the transaction they have tried and the showHistory function will print out that history. Each addCommands method broken down into movie types. This will help us determine 
// which borrow and return constructor we should use to represent that command. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// We assume that all customers have a unique ID that we can identify them by and sort them by. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include "command.h"
#include "borrow.h"
#include "return.h"

using namespace std;

class Customer
{
public:
	//Constructor and Destrctors
	Customer(int customer_id, string first_name, string last_name); 
	~Customer();

	//Getters 
	string getFirst();
	string getLast();
	int getID();

	//Actions
	//We need different add commands methosd for the different type of movies because each type contains different sorting criterias
	void addComedyCommand(char command_type, int customer_id, char media_type, char movie_type, string title, int year); //Add command for comedy movies. Could be Borrow or Return. Return true if the command have been added and false otherwise
	void addDramaCommand(char command_type, int customer_id, char media_type, char movie_type, string director, string title); //Add command for drama movies. Could be Borrow or Return. Return true if the command have been added and false otherwise
	void addClassicCommand(char command_type, int customer_id, char media_type, char movie_type, int month, int year, string actor); //Add command for classic movies. Could be Borrow or Return. Return true if the command have been added and false otherwise
	void showHistory(); //Show the history of the customer

private:
	//our queue that holds the customer's transactions
	queue<Command*> commands;
	int commands_size = 0; //Keeps track of how many commands are in the queue
	
	string first_name;
	string last_name;
	int customer_id;

};
#endif

