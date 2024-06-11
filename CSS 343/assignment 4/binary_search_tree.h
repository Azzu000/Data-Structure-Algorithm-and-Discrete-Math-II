//----------------------------------------------------------------------------------------------MovieStore--------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//The BinarySearchTree is a Binary Search Tree of Movies. Each movie type is sorted depending on it's movie type. The Binary Search tree have all the regular Binary Search Tree 
//functions such as insert, retrieve, isEmpty, and display. Like any Binary Search Tree it has a root and a right and left node. The BinarySearchTree also have == and != operators
//help us check whether two BinarySearchTrees are the same.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//We assume that all the file are in the right format.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include "movie.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std; 

class BinarySearchTree
{
public:
	//Constructors
	BinarySearchTree();
	~BinarySearchTree();

	//Operator Overloads
	bool operator == (const BinarySearchTree& tree) const; //returns true if the BinarySearchTrees are the same and false otherwise. 
	bool operator != (const BinarySearchTree& tree) const; //returns true if the BinarySearchTrees are not the same and false otherwise. 

	//Actions
	bool insert(Movie*& movie); 
	
	//bool retrieve(Movie*& findMovie,Movie*& movie); //findMovie is the movie we need to find and movie is going to return us the movie if we found it
	bool retrieveComedy(Movie*& movie, string title, int year); 
	bool retrieveDrama(Movie*& movie, string director, string title);
	bool retrieveClassic(Movie*& movie, int month, int year, string actor);
	void display(); //display in sorted order
	bool isEmpty() const;
	void makeEmpty();
	
private:
	//The data is going to be the movie and the movie class is going to determine the placement of the movie in the binary search tree
	struct Node {
		Movie* movie; 
		Node* right;
		Node* left;
	};
	Node* root = nullptr;

	int count = 0;

	void makeEmptyHelper(Node* node);
	bool equalHelper(Node* this_root, Node* other_root) const;
	void displayHelper(Node* root);
};
#endif

