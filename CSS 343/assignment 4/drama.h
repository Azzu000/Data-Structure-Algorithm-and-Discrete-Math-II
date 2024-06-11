//----------------------------------------------------------------------------------------------Drama--------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Drama is the child class of movies. The virtual functions of drama is getStock and setStock which overrides the same functions in the Movie class. The other virtual functiosn 
//the >, <, ==, != which is used to compare the movies and sort them according to their spcified sorting criteria. For drama, the sorting criteria is to sort by director then title. 
//The display function is also virtual as it is used to display drama movie types.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//We assume that all the necessary information about the drama movie is given.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

#ifndef DRAMA_H_
#define DRAMA_H_

#include <string>
#include <vector>
#include <iostream>
#include "movie.h"

using namespace std;

class Drama : public Movie
{
public:
	//Constructors
	Drama(char movie_type, int stock, string director, string title, int year); //C, Stock, Director, Title, Release Year

	//Getters and Setters
	virtual void setStock(int stock); //Stocks needs to be able to be changed
	virtual int getStock() const;
	string getDirector() const;
	string getTitle() const;
	int getYear() const;

	//Operator Overloads
	//sorted by director then title
	//We need the operators to compare to movies because the Binary tree holds movies
	virtual bool operator > (const Movie& drama) const;  //return true if this Classic is bigger than other Classic and false otherwise
	virtual bool operator < (const Movie& drama) const; //returns true if this Classic is smaller than other Classic and false otherwise
	virtual bool operator == (const Movie& drama) const; //return true if this Classic is equal to other Classic and false otherwise
	virtual bool operator != (const Movie& drama) const; //return true if this Classic is not equal to other Classic and false otherwise

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

