//----------------------------------------------------------------------------------------------Movie--------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//This the parent class of comedy, classic, and drama movies.The constructor of the movie calss represents the different type of movies  and the functions are all similar to those 
//in the child classes. There is getter methods and operator overload in which helps sort the movie. The oeprators and the setStock and getStock methods are all virtual as it depends 
//on the movie type. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//We assume that all the necessary information is there to make the movie.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef MOVIE_H_
#define MOVIE_H_

#include <string>
#include <fstream>
#include <iostream>


using namespace std;

class Movie
{
public:
	//Constructors
	//Maybe add movie type which consist only D
	Movie(char movie_type, int stock, string director, string title, int year);
	Movie(char movie_type, int stock, string director, string title, string actor, int month, int year);

	//Getters and Setters
	virtual void setStock(int stock);
	char getMovieType() const;
	virtual int getStock() const;
	string getTitle() const;
	string getActor() const;
	int getMonth() const;
	int getYear() const;
	string getDirector() const;

	//Actions
	virtual void display();

	//Operator Overloads
	//We need to implement overloads to compare for sorting in binary tree
	virtual bool operator > (const Movie& movie) const;
	virtual bool operator < (const Movie& movie) const;
	virtual bool operator == (const Movie& movie) const;
	virtual bool operator != (const Movie& movie) const;

	friend ostream& operator<<(ostream& out, const Movie& movie); //For binary tree class

private:
	char movie_type = 'a'; // Default type is a, will be changed 
	string director;
	string title;
	int month = 0;
	int year = 0;
	int stock = 0;
	string actor;
};
#endif

