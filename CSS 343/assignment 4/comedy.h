//----------------------------------------------------------------------------------------------Comedy--------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Comedy is the child class of movies. The virtual functions of comedy is getStock and setStock which overrides the same functions in the Movie class. The other virtual functiosn 
//the >, <, ==, != which is used to compare the movies and sort them according to their spcified sorting criteria. For comedy, the sorting criteria is to sort by title then year. 
//The display function is also virtual as it is used to display comedy movie types.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//We assume that all the necessary information about the comedy movie is given.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

#ifndef COMEDY_H_
#define COMEDY_H_

#include <string>
#include <vector>
#include <iostream>
#include "movie.h"

using namespace std;

class Comedy : public Movie
{
public:
	//Constructors
	Comedy(char movie_type, int stock, string director, string title, int year); //C, Stock, Director, Title, Release Year

	//Getters and Setters
	virtual void setStock(int stock); 
	virtual int getStock() const; 
	string getDirector() const;
	string getTitle() const;
	int getYear() const;

	//Operator Overloads
	//sorted by title then eyar of release
	//We need the operators to compare to movies because the Binary tree holds movies
	virtual bool operator > (const Movie& comedy) const;  //return true if this Classic is bigger than other Classic and false otherwise
	virtual bool operator < (const Movie& comedy) const; //returns true if this Classic is smaller than other Classic and false otherwise
	virtual bool operator == (const Movie& comedy) const; //return true if this Classic is equal to other Classic and false otherwise
	virtual bool operator != (const Movie& comedy) const; //return true if this Classic is not equal to other Classic and false otherwise

	//Actions
	virtual void display();

private:
	char movie_type = 'a'; //a is the default movie type
	int stock = 0; //number of stock
	string director; //director of movie
	string title; //title of movie
	int year = 0; //release year
};
#endif

