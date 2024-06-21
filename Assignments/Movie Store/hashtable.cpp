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

#include "hashtable.h"

//------------------------  HashTable Constructor ---------------------------
// Initiates the variables needed for the HashTable
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
HashTable::HashTable()
{
	capacity = 30;
	size = 0;
	array = new HashNode*[capacity];

	//Make all the slots of the hash tables empty
	for (int i = 0; i < capacity; i++) {
		array[i] = nullptr;
	}
}

//------------------------  Hash Function ---------------------------
// Hashs the key to an index.
// Preconditions: NONE
// Postconditions: returns the index for the designated key.
//---------------------------------------------------------------------------
int HashTable::Hash(int key)
{
	//Hashes the key to see where the HashNode belongs
	int index = key % capacity;
	return index;
}

//------------------------------  Insert -----------------------------------
// Inserts a customer into an index that is hashed by the hash function
// Preconditions: NONE
// Postconditions: NONE
//--------------------------------------------------------------------------
bool HashTable::Insert(int key, Customer*& value)
{
	HashNode* temp_hashnode = new HashNode(key, value);

	//We are going to use the hash function to find a place to insert the HashNode
	int index = Hash(key);
	int current = index; //current is going to keep track of whether we are at the end of our hash table or not

	//We have to make sure that index we hashed is empty otherwise we have to linearly find a new slot for it 
	while ((array[index] != nullptr) && (current + 1 != this->size)) {
		index = index + 1;
		current = current + 1;
	} //When we get out of our while loop our index is nullptr or it has reached the end of the hash table

	//if we have reached the end of our list
	if ((current + 1) == size) {
		cerr << "ERROR: We have reached the end of our customer list." << endl;
		return false;
	}

	if (array[index] == nullptr) {
		array[index] = temp_hashnode;
		return true;
	}
	//if everything fails jsut return false
	return false;
}

//------------------------------  Search -----------------------------------
// Searches the customer depending on the key value given. The reference pointer
// value is going to point to the customer of the key if found. 
// Preconditions: NONE
// Postconditions: Reference pointer to customer of given key.
//--------------------------------------------------------------------------
bool HashTable::Search(int key, Customer*& value)
{
	//first find the where the hash node could be hashed using the hash function
	int index = Hash(key);
	int current = 0;

	//while we are not at the end of the list
	while (array[index] != nullptr) {
		if (array[index]->ID == key) {
			value = array[index]->customer;
			return true;
		}
		//If the customer is not found in that index we will continue to linearly search
		index = index + 1;
	}
	
	//if we have reached nullptr, then we know that the key we are trying to find does not exist in our hash table. 
	cerr << "ERROR: The customer you are trying to find does not exist." << endl;
	return false;
}
