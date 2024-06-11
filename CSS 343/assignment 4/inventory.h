//----------------------------------------------------------------------------------------------Borrow------------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//The inventory is where all the movies are stored. We have BinarySearchTrees for each type of movie since they are all sorted using different sorting criterias. The inventroy also
//functions that will help us maintain our inventory of movies. We can list the movies, which is needed for the I command, we can return or borrow movies, and we can addMovies (add movies)
//into our BinarySearchTrees depending on their movie type. When we are returning and borrowing movies, we will have to retrieve the movies in the binary trees by it's given information
//and -1 or +1 of the stocks from that specific movie.The inventory can only be accessed by the MovieStore. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//No Assumptions.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classic.h"
#include "binary_search_tree.h"

using namespace std;


class Inventory
{
public:
	//Constructor and Destructor
	Inventory();
	~Inventory();

	//Actions
	void listMovies(); //Uses the display method from BinarySearchTree to display all the movies
	bool borrowComedy(string title, int year); //Borrows comedy movie (-stock). Return true if borrow is successful and false otherwise
	bool borrowDrama(string director, string title); //Borrows drama movie (-stock). Return true if borrow is successful and false otherwise
	bool borrowClassic(int month, int year, string actor); //Borrows classic movie (-stock). Return true if borrow is successful and false otherwise
	bool returnComedy(string title, int year); //Return comedy (+stock). Return true if borrow is successful and false otherwise
	bool returnDrama(string director, string title); //Return drama (+stock). Return true if borrow is successful and false otherwise
	bool returnClassic(int month, int year, string actor); //Return classic (+stock). Return true if borrow is successful and false otherwise
	bool addMovie(char movie_type, int stock, string director, string title, string actor, int month, int year); //Adds a new movie to the binary tree

private:
	BinarySearchTree comedy_tree; //Holds all the comedy movie for the inventory
	BinarySearchTree drama_tree; //Holds all the drama movie for the inventory
	BinarySearchTree classic_tree; //Holds all the classic movie for the inventory

};
#endif

