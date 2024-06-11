//----------------------------------------------------------------------- Poly ------------------------------------------------------------------------
// Ruiqi Huang CSS 343 
// Date started: 4/13/2023
// Date of last modification: 4/21/2023
//-----------------------------------------------------------------------------------------------------------------------------------------------------
// Purpose - This program implements a binary tree. IN order to create a binary tree we have to either start with a empty tree (with no argument constructor)
// or copy another tree to this tree (using a copy constructor. It has all the functions of a regular binary tree like insert an element and retrieve 
// an element. A remove element function was not made but there is a function called makeEmpty which empties the binary tree. makeEmpty is used for the
// destructor of our binary too as it does everything a destructor needs to do. There are also ohters functions implemented for this binary such as 
// isEmpty, which checks whether a tree is empty or not. There is getHeight which gets the height of any tree, not just a binary tree. Operator overloads
// of == which checks whether two binary tree is equal or not, != which checks whether a two tree is not equal, and = which is a copy assignment which
// works like a copy constructor but it can be used after the tree is created (while a copy constructor can only be used to create the tree). We also have 
// functions such as arrayToBSTree and bstreeToArray which converts the tree to an array and vice versa. There are also a lot of helper functions that 
// is Recursive to help implement many of the functions we have such as makeEmpty, arrayToBSTree, bstreeToArray, getHeight, copy assignment and constructor, 
// and the operator overloads of == and !=. The two functions that are implemented iteratively is insert and retrieve. 
//-----------------------------------------------------------------------------------------------------------------------------------------------------
// We assume that the polynomial coefficient and exponent 10 be less than 1,000,000 and we also assume that the exponent is not negative. 
// We assume that the array's max size is 100. We assume that the file given is going to have all the binary tree elements we want to insert 
// listed and ends with a $$ to show that the list has ended. Our binary also does not take in duplicates. 
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef BIN_TREE_H_
#define BIN_TREE_H_
#include "nodedata.h"
#include <iostream>
#include <string>

using namespace std;

class BinTree {				// you add class/method comments and assumptions
	//...
public:
	BinTree();								// constructor (Creates a empty tree)
	BinTree(const BinTree& bintree);				// copy constructor (deep copy of a BinTree)
	~BinTree();								// destructor, calls makeEmpty	

	//Operator Overloads
	friend ostream& operator << (ostream& out, const BinTree& bintree);   //In-order display of the data in our tree

	BinTree& operator = (const BinTree& bintree);     // Assign one tree to another
	bool operator == (const BinTree& bintree) const;    // Define if two tree is equal. If both tree is equal it will return true and return false otherwise.
	bool operator != (const BinTree& bintree) const;    // Define if two tree is not equal. If both tree is not equal it will return true and return false otherwise.

	//Getters
	int getHeight(const NodeData& data);     // Finds the height of a given NodeData in the tree. The height of a NodeData that does not exist in tree is 0.

	//Actions
	bool isEmpty() const;   // true if tree is empty, otherwise false
	void makeEmpty();	    // make the tree empty so isEmpty returns true

	bool insert(NodeData* data);                 // Insert given data to tree
	bool retrieve(const NodeData& data, NodeData*& new_data) const;   //Get the NodeData* of a given object in the tree and report whether the object exists in the tree or not. Return true if it does exist and false otherwise. 
	void displaySideways() const;			// provided below, displays the tree sideways

	void bstreeToArray(NodeData* array[]);      // Fill an array of NodeData* using in-order traversal of tree. At the end the tree should be empty and the array should be filled.
	void arrayToBSTree(NodeData* array[]);      // Builds a balanced BinTree from a sorted array of NodeData*. At the end the array should be empty and the tree should be filled. 
private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointergvf
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

	// utility functions
	void RecursiveCopy(Node* other_root);   //Recursive helper for the copy constructor and copy assignment. other_root is a pointer to the other binary tree. 
	void RecursiveMakeEmpty(Node* node);  //Recursive helper function for makeEmpty
	bool RecursiveEqual(Node* this_root, Node* other_root) const; //Recursive helper for the equal and not equal operator overloads. this_root is used to traverse this tree and other_root is used to traverse the other tree.
	void inorderHelper(Node* node) const;   //Help traverse the tree in order and display it. Recursive helper function used for ostream.
	void RecursiveTreeToArray(Node* root, NodeData* array[], int& size); //Helps convert tree into sorted array.
	void RecursiveArrayToTree(Node* root, NodeData* array[], int index, int highest_index); //Helps convert sorted array into tree.
	int RecursiveHeight(Node* root, const NodeData& data, int& height); //Returns the height of any tree.
	void sideways(Node* current, int level) const;	// provided below, helper for displaySideways()

};
#endif
