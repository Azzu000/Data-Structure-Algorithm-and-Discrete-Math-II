//----------------------------------------------------------------------------------------------Classic--------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Classic is the child class of movies. The virtual functions of classic is getStock and setStock which overrides the same functions in the Movie class. The other virtual functiosn 
//the >, <, ==, != which is used to comapre the movies and sort them according to their spcified sorting criteria. For classics, the sorting criteria is to sort by release date then
//major actors. The display function is also virtual as it is used to display classic movie types.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//We assume that all the necessary information about the classic movie is given.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

#ifndef CLASSIC_H_
#define CLASSIC_H_
#include <string>
#include <vector>
#include <iostream>
#include "movie.h"

using namespace std;

class Classic : public Movie
{
public:
	//Constructors
	Classic(char movie_type, int stock, string director, string title, string actor, int month, int year); //C, Stock, Director, Title, Major actor Release date (first last month year)

	//Getters and Setters
	virtual void setStock(int stock); //Stocks needs to be able to be changed
	virtual int getStock() const;
	string getDirector() const;
	string getTitle() const;
	string getActor() const;
	int getMonth() const;
	int getYear() const; 

	//Operator Overloads
	//sort by release date then major actor
	//We need the operators to compare to movies because the Binary tree holds movies
	virtual bool operator > (const Movie& classic) const;  //return true if this Classic is bigger than other Classic and false otherwise
	virtual bool operator < (const Movie& classic) const; //returns true if this Classic is smaller than other Classic and false otherwise
	virtual bool operator == (const Movie& classic) const; //return true if this Classic is equal to other Classic and false otherwise
	virtual bool operator != (const Movie& classic) const; //return true if this Classic is not equal to other Classic and false otherwise

	//Actions
	virtual void display();

private:
	char movie_type = 'a'; //a is the default movie type
	int stock = 0; //number of stock
	string director; //director of movie
	string title; //title of movie
	string actor; //major actor
	int month = 0; //release month
	int year = 0; //release year


};
#endif

