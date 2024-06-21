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

#include "bintree.h"

//------------------- BinTree No Args Constructor ---------------------------
// Creates an empty array
// Preconditions: NONE
// Postconditions: BinTree is empty
//---------------------------------------------------------------------------
BinTree::BinTree()
{
	this->root = nullptr;
}

//---------------------- BinTree Copy Constructor ---------------------------
// Make a copy of another BinTree
// Preconditions: This Binary Tree is empty
// Postconditions: BinTree is the same as other BinTree
//---------------------------------------------------------------------------
BinTree::BinTree(const BinTree& bintree)
{
	//Makes sure this root is nullptr
	this->root = nullptr;
	RecursiveCopy(bintree.root);
}

//------------------------ BinTree Destructor -------------------------------
// Empty all BinTree
// Preconditions: NONE
// Postconditions: BinTree's are all empty by the end
//---------------------------------------------------------------------------
BinTree::~BinTree()
{
	//We can just use the make empty to empty the tree and that wil; be our destructor
	RecursiveMakeEmpty(this->root);
}

//----------------------------- Operator = ----------------------------------
// Make a copy of another BinTree
// Preconditions: The BinTree is not already equal or of the same address.
// Postconditions: BinTree is the same as other BinTree
//---------------------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree& bintree)
{
	//if the trees are already equal then we don't need to copy 
	if (*this == bintree) {
		return *this;
	}
	else {
		//We first have to empty the current tree in order to copy the new tree
		makeEmpty();
		root = nullptr;
		RecursiveCopy(bintree.root);
		return *this;
	}
}

//---------------------------- RecursiveCopy --------------------------------
// Recursive helper of Copy Constructor and Copy Assignment =. Helps copy
// other binary tree to this binary tree.
// Preconditions: Other BinTree is not empty
// Postconditions: BinTree is the same as other BinTree
//---------------------------------------------------------------------------
void BinTree::RecursiveCopy(Node* other_root)
{
	//We will continue the recursive as long as it is not null
	if (other_root != nullptr) {
		//Using NodeData copy constructor to copy the data from one tree to another. This is going to be called temp because this is only temporary placeholder for the data.
		NodeData* temp = new NodeData(*other_root->data);
		//We can just use the insert function to insert the data as we go
		insert(temp);

		//Recursive calls to traverse binary tree
		RecursiveCopy(other_root->left);
		RecursiveCopy(other_root->right);
	}
}

//----------------------------- Operator == ---------------------------------
// Checks if this BinTree is equal to the other BinTree. If it is equal it
// will return true and false otherwise.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//---------------------------------------------------------------------------
bool BinTree::operator==(const BinTree& bintree) const
{
	//If both bintree is empty then we know both tree is equal
	if ((this->isEmpty() == true) && (bintree.isEmpty() == true)) {
		return true;
	}
	else {
		return RecursiveEqual(this->root, bintree.root);
	}
}

//--------------------------- Operator != -----------------------------------
// Checks if this BinTree is not equal to the other BinTree. If it is not 
// equal it will return true and false otherwise. Opposite of == so if 
// RecursiveEqual is true then we return false and vice versa. 
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//---------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree& bintree) const
{
	//If both bintree is empty then we know both tree is equal 
	if ((this->isEmpty() == true) && (bintree.isEmpty() == true)) {
		return false;
	}
	if (RecursiveEqual(this->root, bintree.root) == true) {
		return false;
	}
	else if (RecursiveEqual(this->root, bintree.root) == false) {
		return true;
	}
	return false;
}

//----------------------------- RecursiveEqual ------------------------------
// Recursive helper for equal, return true if the the BinTree are equal and 
// false otherwise. 
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//---------------------------------------------------------------------------
bool BinTree::RecursiveEqual(Node* this_root, Node* other_root) const
{
	//base-cases:
	//If both ends with nullptr and all the other nodes passed the equality check then return true. 
	if ((this_root == nullptr) && (other_root == nullptr)) {
		return true;
	}
	//if this root is null but the other root is not null then we know it is not equal
	else if ((this_root == nullptr) && (other_root != nullptr)) {
		return false;
	}
	//if this root is not null but the other root is null then we know it is not equal
	else if ((this_root != nullptr) && (other_root == nullptr)) {
		return false;
	}
	//if we find one data that does not equal while traversing then return false
	else if (*this_root->data != *other_root->data) {
		return false;
	}
	//if all base-cases is not met yet we continue to recursively traverse the trees and compare
	else {
		return (RecursiveEqual(this_root->left, other_root->left) 
			&& RecursiveEqual(this_root->right, other_root->right));
	}
}

//--------------------------------- isEmpty ---------------------------------
//Checks if a binary tree is empty or not. If it is empty then it returns
// true and false otherwise. 
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//---------------------------------------------------------------------------
bool BinTree::isEmpty() const
{
	//If we want to know if a tree is empty we can check if the root is null or not.
	if (root == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

//-------------------------------- makeEmpty --------------------------------
// Empties a binary tree. 
// Preconditions: The binary tree is not already empty.
// Postconditions: The binary tree is empty at the end and the root becomes 
// nullptr. 
//---------------------------------------------------------------------------
void BinTree::makeEmpty()
{
	if (this->isEmpty() == true) {
		return;
	}
	else {
		//We are going to use a helper recursive method
		RecursiveMakeEmpty(this->root);
	}
}

//--------------------------- RecursiveMakeEmpty ----------------------------
// Helper function for makeEmpty. Empties binary tree node by node.
// Preconditions: The binary tree is not already empty.
// Postconditions: The binary tree is empty at the end and the root becomes 
// nullptr. 
//---------------------------------------------------------------------------
//need to CHECK
void BinTree::RecursiveMakeEmpty(Node* node)
{
	if (node != nullptr) {
		//Base-case = only if the node we are on is not nullptr we do the recusive calls. Check both left and right before traverse.
		if (node->left != nullptr) {
			RecursiveMakeEmpty(node->left);
		}
		if (node->right != nullptr) {
			RecursiveMakeEmpty(node->right);
		}

		if (node->data != nullptr) {
			delete node->data;
			node->data = nullptr;
		}
		delete node;
		node = nullptr;
	}
	root = nullptr;
}

//--------------------------------- insert ----------------------------------
// Insert NodeData into the right place in the binary tree. 
// Preconditions: The binary tree is not empty. The tree is a binary tree. 
// Postconditions: A new node is added to the binary tree.
//---------------------------------------------------------------------------
bool BinTree::insert(NodeData* data)
{
	//Temp will be used to traverse the tree
	Node* temp = root;
	//This will hold the previous position where the data will be inserted
	Node* prev = nullptr;
	//new_node will be out new node that holds our data
	Node* new_node = new Node;
	new_node->data = data;

	//If the tree is already empty then we can insert the data as the root
	if (this->root == nullptr) {
		root = new_node;
		root->right = nullptr;
		root->left = nullptr;
		return true;
	}
	
	while((temp != nullptr) && (*temp->data != *new_node->data)){
		//prev will always equal to the currrent temp before traversal
		prev = temp;

		//if the data is bigger than the current temp node then we traverse left
		if (*temp->data < *new_node->data) {
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	} 
	//We should get out the while loop if the temp == nullptr or if temp->data == data

	//if the temp-> data is the same as the data we want to insert we return false since we cannot have duplicates
	if ((temp != nullptr) && (*temp->data == *new_node->data)) {
		return false;
	}

	//if the data is smaller than the prev data then we insert the data to the left 
	if ((prev != nullptr) && (*prev->data > *new_node->data)) {
		prev->left = new_node;
		new_node->left = nullptr;
		new_node->right = nullptr;
		return true;
	}

	//if the data is bigger than the prev data then we insert the data to the right
	if ((prev != nullptr) && (*prev->data < *new_node->data)) {
		prev->right = new_node;
		new_node->left = nullptr;
		new_node->right = nullptr;
		return true;
	}

	//if all fails return false
	return false;
}

//--------------------------------- Retrieve --------------------------------
// Retrieve a data from the binary tree. Return true if the item is in the 
// the binary tree and false otherwise. 
// Preconditions: TThe tree is a binary tree. The tree is not empty.  
// Postconditions: The BinTree is not changed.
//---------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData& data, NodeData*& new_data) const
{
	//if the data we want to retrieve is found found is going to be true, otherwise is will be false
	bool found = false;
	Node* temp = root;

	//First check if the tree is empty. If it is we jsut return false.
	if (root == nullptr) {
		delete temp;
		return false;
	}

	//Also check if the root is the node we are looking for. If so then we can jsut return 
	//we will traverse the tree until we found the data or until we are at the end of the tree 
	while ((temp != nullptr) && (found == false)) {
		if ((temp != nullptr) && (*temp->data == data)) {
			new_data = temp->data;
			found = true;
			return true;
		}

		//traverse left if the data is smaller than current temp data and right otherwise
		if ((temp != nullptr) && (*temp->data > data)) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	
	//if we get out of loop that means that we have not foudn the data so we return false
	return false;
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// NOTE: This method was given to us by the assignment.
//---------------------------------------------------------------------------
void BinTree::displaySideways() const
{
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// NOTE: This method was given to us by the assignment.
//---------------------------------------------------------------------------
void BinTree::sideways(Node* current, int level) const
{
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}

//---------------------------- bstreeToArray --------------------------------
// Turns the binary tree into a sorted array leaving the binary tree empty.
// Preconditions: the binary tree is not empty. 
// Postconditions: The binary tree is empty and the array given is sorted. 
//---------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData* array[])
{
	//this is going to keep track of the size of our array, we need this to traverse the array
	int size = 0;

	//if the root is null then we know the tree is empty and therefore the array is going to be empty.
	//if only the root is not empty then we only need to insert that one element into array.
	if (this->root == nullptr) {
		array[0] = nullptr;
	}
	else if ((this->root != nullptr) && (this->root->left == nullptr) && (this->root->right == nullptr)) {
		array[0] = root->data;
		this->makeEmpty();
	}
	else {
		RecursiveTreeToArray(this->root, array, size);
		//empty the binary tree after we are done.
		this->makeEmpty();
	}

}

//------------------------- RecursiveTreeToArray ----------------------------
// Recursive helper of bstreeToArray. 
// Turns the binary tree into a sorted array leaving the binary tree empty.
// Preconditions: the binary tree is not empty. 
// Postconditions: The binary tree is empty and the array given is sorted. 
//---------------------------------------------------------------------------
void BinTree::RecursiveTreeToArray(Node* root, NodeData* array[], int& size)
{
	
	if (root == nullptr) {
		//if it nullptr then we don't do anything.
		return;
	}
	else {
		//if we are not at the end of our array we want to traverse in order
		//Traverse through left subtree
		RecursiveTreeToArray(root->left, array, size);
		//Set the array to the data as we traverse
		array[size] = root->data;
		//increase the size of the array
		size = size + 1;
		//start emptying the nodes as we traverse of tree
		root->data = nullptr;
		//Traverse through right subtree
		RecursiveTreeToArray(root->right, array, size);
	}

}

//---------------------------- arrayToBSTree --------------------------------
// Turns sorted array into binary tree using binary search. 
// Preconditions: the array is not empty and the array is sorted.
// Postconditions: The array is empty and a binary tree is created 
//---------------------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData* array[])
{
	//Keeps track of the size of our array, we will use this to know when the array ends
	int size = 0;

	//Make sure the tree is empty before inserting array elements
	this->makeEmpty();

	//index is going to traverse our while loop to find the size of the array
	int index = 0;
	while (array[index] != nullptr) {
		size = size + 1;
		index = index + 1;
	} //Gets out of while loop when array[index] == nullptr
	RecursiveArrayToTree(root, array, 0, size - 1);
}

//------------------------- RecursiveArrayToTree -----------------------------
// Recursive helper function of arrayToBSTree. 
// Turns sorted array into binary tree using binary search. 
// Preconditions: the array is not empty and the array is sorted.
// Postconditions: The array is empty and a binary tree is created 
//---------------------------------------------------------------------------
void BinTree::RecursiveArrayToTree(Node* root, NodeData* array[], int index, int highest_index)
{
	//this is our midpoint for our binary search
	int midpoint = (index + highest_index) / 2;
	//we have to use binary search to add element into tree in order to make it a complete binary tree
	if (index > highest_index) {
		root = nullptr;
	}
	else {
		//temp is goign to temporary hold our data to put into binary tree
		NodeData* temp = array[midpoint];
		//we can use insert method to insert the data into our binary tree in order
		insert(temp);
		//empty array
		array[midpoint] = nullptr;

		//recursively traverse through array in half each time (binary search)
		RecursiveArrayToTree(root, array, index, midpoint - 1);
		RecursiveArrayToTree(root, array, midpoint + 1, highest_index);
	}

}

//------------------------------ getHeight ----------------------------------
// Gets the height of a data in the tree given. It does not have to be a 
// binary tree.
// Preconditions: The binary tree is not empty and the data we want
// to retrieve the height for exists. 
// Postconditions: Nothing is changed in the tree.
//---------------------------------------------------------------------------
int BinTree::getHeight(const NodeData& data)
{
	//temp us going to hold our data temporarily
	NodeData* temp = new NodeData(data);
	//the height is going to be our height
	int height = 0;
	//if the root equals the data then we just return height of 0
	if (*root->data == data) {
		height = 0;
		return height;
	}
	//if the value is not in tree then return 0
	//By using retrieve we can see if the data exists in our tree
	else if (this->retrieve(data, temp) == false) {
		return 0;
	}
	else {
		//Recursive height will find the height of our tree recursively
		RecursiveHeight(root, data, height);
		return height;
	}
}

//--------------------------- RecursiveHeight -------------------------------
// Gets the height of a data in the tree given. It does not have to be a 
// binary tree.
// Preconditions: The binary tree is not empty and the data we want
// to retrieve the height for exists. 
// Postconditions: Nothing is changed in the tree.
//---------------------------------------------------------------------------
int BinTree::RecursiveHeight(Node* root, const NodeData& data, int& height)
{
	int update_height = 0;
	//Base-case
	if (root == nullptr) {
		return 0;
	}

	//Recursively finds the height of our left and right tree
	int left = RecursiveHeight(root->left, data, height);
	int right = RecursiveHeight(root->right, data, height);

	//If we traverse the tree and the left is bigger than that is going to be our new updated height.
	if (left >= right) {
		update_height = left + 1;
	}
	//else the right is going to be our new updated height. 
	else {
		update_height = right + 1;
	}
	//If we are at our data, our height is just going to be that last updated height when we get to the node we want
	if (*root->data == data) {
		height = update_height;
	}

	return update_height;
}

//----------------------------- inorderHelper -------------------------------
// Recursive helper that print out the tree in order (left root right)
// Preconditions: The binary tree is not empty. 
// Postconditions: Nothing is changed in the tree.
//---------------------------------------------------------------------------
void BinTree::inorderHelper(Node* node) const
{
	//In order is from left to right. This is just a basic in-order traversal implementation.
	if (node != nullptr) {
		inorderHelper(node->left);
		cout << *node->data << " ";
		inorderHelper(node->right);
 	}
}

//--------------------------------- Ostream ---------------------------------
// Prints out the binary tree in order.
// Preconditions: The binary tree is not empty. 
// Postconditions: Nothing is changed in the tree.
//---------------------------------------------------------------------------
ostream& operator << (ostream& out, const BinTree& bintree)
{
	bintree.inorderHelper(bintree.root);
	out << endl;
	return out;
}
