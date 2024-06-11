//----------------------------------------------------------------------------------------------MovieStore--------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//The Movie Store is the parent of all the classes as it manages everything including the Inventory, customers, and transactions/commands. The movie store keeps track of the movies
//using the Inventory class that has a BinarySearchTree of movies. The movie store also keeps track of the customer by a hashtable which stores all the customer depending on their
//ID. The movie store initiates commadns y first reading a file of commands and then sotring them in a queue. Then we use initiateCommands function to actually initiate the commands.
//The rest of the function of the MovieStore class includes reading the customer file, movie file and the commands file.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//We assume that all the file are in the right format
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef MOVIE_STORE_H_
#define MOVIE_STORE_H_
#include <string>
#include <iostream>
#include <vector>
#include <fstream> 
#include <sstream>
#include <queue>
#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classic.h"
#include "inventory.h"
#include "customer.h"
#include "command.h"
#include "return.h"
#include "borrow.h"
#include "binary_search_tree.h"
#include "hashtable.h"

using namespace std;

class MovieStore
{
public:
	//Constructor Destructor
	MovieStore();
	~MovieStore();

	//Actions
	void readMovies(const string& file_name); //read a movie file
	void readCustomer(const string& file_name); //read a customer file
	void readCommands(const string& file_name); //read a command file
	void initiateCommands(); //Takes the queue of commands and initiates them

private:
	HashTable customer_list; //keeps track of all the customers
	queue<Command*> command_list; //keeps track of all the commands to initiate them
	Inventory movie_inventory; //The movie store is going to have one inventory that will hold all the movies

};
#endif

