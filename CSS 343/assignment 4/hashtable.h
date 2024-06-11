//----------------------------------------------------------------------------------------------Borrow------------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//This HashTable stores Customers depending on their ID. So their ID is the key and the Customer is the value. The HashTable have most of the HashTable functions. One of the most 
//important one is the Hash functions which helps determine where the customer should be stored based on it's hashed key. It is important to note that this HashTable utilizes
//the linear probing technique to store customers. The insert functions inserts the customer depening on the key hash function hased and the Search function is used to find and
//retrieve the customer. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//No Assumptions.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef HASHTABLEH_
#define HASHTABLE_H_
#include <iostream>
#include <string>
#include <list>
#include "customer.h"

using namespace std;

class HashNode {
public:
	int ID; //This is gonna be the key of our hash table
	Customer* customer; //This is gonna be the value of our hash table. We are pointing to the address of the customer

	//Constructor for HashNode
	HashNode(int key, Customer* value) {
		this->ID = key;
		this->customer = value;
	}
};

//Linear Probing
class HashTable
{
public:
	HashTable(); //Creates a HashTable 
	int Hash(int key); //Takes a key and calculate where the HashNode beings in the array (Hash Function)
	bool Insert(int key, Customer*& value); //Inserts a HashNode into our HashTable given the key and the value
	bool Search(int key, Customer*& value); //Given the ID of the customer we searh the hash table for the customer. The customer is going to be retrieved by the value parameter of this function.


private:
	HashNode** array; //This is the HashTable Array that we are going to use
	int capacity;
	int size;
};
#endif

