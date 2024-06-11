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

#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
    int count = 0;
}

BinarySearchTree::~BinarySearchTree()
{
    makeEmpty();
}

//----------------------------- Operator == ---------------------------------
// Checks if this BinarySearchTree is equal to the other BinarySearchTree.
// If it is equal it will return true and false otherwise.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//---------------------------------------------------------------------------
bool BinarySearchTree::operator==(const BinarySearchTree& tree) const
{
    //If both the binary search trees is empty then we know it is equal
    if ((this->isEmpty() == true) && (tree.isEmpty() == true)) {
        return true;
    }
    else {
        return equalHelper(this->root, tree.root);
    }
}

//--------------------------- Operator != -----------------------------------
// Checks if this BinarySearchTree is not equal to the other BinarySearchTree. 
// If it is not equal it will return true and false otherwise. Opposite of == so if 
// RecursiveEqual is true then we return false and vice versa. 
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//---------------------------------------------------------------------------
bool BinarySearchTree::operator!=(const BinarySearchTree& tree) const
{
    //If both bintree is empty then we know both tree is equal 
    if ((this->isEmpty() == true) && (tree.isEmpty() == true)) {
        return false;
    }
    if (equalHelper(this->root, tree.root) == true) {
        return false;
    }
    else if (equalHelper(this->root, tree.root) == false) {
        return true;
    }
    return false;
}

//----------------------------- equalHelper ------------------------------
// Recursive helper for equal, return true if the the BinTree are equal and 
// false otherwise. 
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//---------------------------------------------------------------------------
bool BinarySearchTree::equalHelper(Node* this_root, Node* other_root) const
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
    else if (*this_root->movie != *other_root->movie) {
        return false;
    }
    //if all base-cases is not met yet we continue to recusively traverse the trees and compare
    else {
        return (equalHelper(this_root->left, other_root->left) && equalHelper(this_root->right, other_root->right));
    }
}


//----------------------------insert-----------------------------
//Inserts movies into the Binary Search tree in the right order.
// returns true if the movie have been successfully inserted and 
// false otherwise. 
//Preconditions: The movies inserted must be the right movie type.
//Postconditions: The Binary Search Tree is filled with movies.
//---------------------------------------------------------------
bool BinarySearchTree::insert(Movie*& movie)
{
    //Used to search tree until it finds the spot for the movie
    Node* temp = root;
    //The future parent node of the movie
    Node* parent = nullptr;

    //if the tree is empty
    if (root == nullptr) {
        root = new Node();
        root->movie = movie;
        root->right = nullptr;
        root->left = nullptr;
        count++;
        return true;
    }

    //while the temp node is not empty, we will move until the next temp node is nullptr
    while ((temp != nullptr) && (*temp->movie != *movie)) {
        parent = temp;

        if (*temp->movie < *movie) {
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }

    //We cannot have two same movie
    //**We have to add to the stock of the original movie if it is the same
    if ((temp != nullptr) && (*temp->movie == *movie)) {
        cerr << "ERROR: The movie you want to insert already exsist. Adding stock to movie." << endl;
        int new_stock = temp->movie->getStock() + movie->getStock();
        temp->movie->setStock(new_stock);
        return false;
    }
    //if movie is smaller than their future parent node
    if ((parent != nullptr) && (*parent->movie > *movie)) {
        Node* newnode = new Node();
        newnode->movie = movie;
        parent->left = newnode;
        newnode->right = nullptr;
        newnode->left = nullptr;
        count++;
        return true;
    } //If movie is bigger than their future parent node
    else if ((parent != nullptr) && (*parent->movie < *movie)) {
        Node* newnode = new Node();
        newnode->movie = movie;
        parent->right = newnode;
        newnode->right = nullptr;
        newnode->left = nullptr;
        count++;
        return true;
    }

    //if all fails then return false;
    return false;

}

//-------------------------retrieveComedy--------------------------
//Retrieves a comedy movie from the comedy Binary Search Tree. 
//The argumen movie is going to be the reference pointer to the movie 
//retrieved.Returns true if movie have been successfully retrieved
//and false otherwise.
//Preconditions: The Binary Search Tree of movies is not empty
//and the movie we are trying to find exists in the binary tree.
//Postconditions: returns the movie that the user wanted to retrieve. 
//-----------------------------------------------------------------
bool BinarySearchTree::retrieveComedy(Movie*& movie, string title, int year)
{
    bool found = false;
    Node* temp = root;

    while ((temp != nullptr) && (found == false)) {
        if ((temp != nullptr) && (isEmpty() == false) && (temp->movie->getTitle() == title) && (temp->movie->getYear() == year)){
            movie = temp->movie;
            found = true;
            return true;
        }

        //if the tmep node is smaller than the movie we are looking for we go left, otherwise we go right
        else if ((temp != nullptr) && (temp->movie->getTitle() > title)) {
            temp = temp->left;
        }
        else if ((temp != nullptr) && (temp->movie->getTitle() == title) && (temp->movie->getYear() > year)) {
            temp = temp->left;
        }
        else if ((temp != nullptr) && (temp->movie->getTitle() < title)) {
            temp = temp->right;
        }
        else if ((temp != nullptr) && (temp->movie->getTitle() == title) && (temp->movie->getYear() < year)) {
            temp = temp->right;
        }
    }

    //If we are out of the while loop then we failed the find the movie
    cerr << "ERROR: The movie was not found. Retrieval failed." << endl;
    return false;
}

//--------------------------retrieveDrama---------------------------
//Retrieves a comedy movie from the drama Binary Search Tree. 
//The argumen movie is going to be the reference pointer to the movie 
//retrieved.Returns true if movie have been successfully retrieved
//and false otherwise.
//Preconditions: The Binary Search Tree of movies is not empty
//and the movie we are trying to find exists in the binary tree.
//Postconditions: returns the movie that the user wanted to retrieve. 
//-----------------------------------------------------------------
bool BinarySearchTree::retrieveDrama(Movie*& movie, string director, string title)
{
    bool found = false;
    Node* temp = root;

    while ((temp != nullptr) && (found == false)) {
        if ((temp != nullptr) && (isEmpty() == false) && (temp->movie->getTitle() == title) && (temp->movie->getDirector() == director)) {
            movie = temp->movie;
            found = true;
            return true;
        }

        //if the tmep node is smaller than the movie we are looking for we go left, otherwise we go right
        else if ((temp != nullptr) && (temp->movie->getDirector() > director)) {
            temp = temp->left;
        }
        else if ((temp != nullptr) && (temp->movie->getDirector() == director) && (temp->movie->getTitle() > title)) {
            temp = temp->left;
        }
        else if ((temp != nullptr) && (temp->movie->getDirector() < director)) {
            temp = temp->right;
        }
        else if ((temp != nullptr) && (temp->movie->getDirector() == director) && (temp->movie->getTitle() < title)) {
            temp = temp->right;
        }
    }

    //If we are out of the while loop then we failed the find the movie
    cerr << "ERROR: The movie was not found. Retrieval failed." << endl;
    return false;
}

//-------------------------retrieveClassic--------------------------
//Retrieves a comedy movie from the classic Binary Search Tree. 
//The argumen movie is going to be the reference pointer to the movie 
//retrieved. Returns true if movie have been successfully retrieved
//and false otherwise.
//Preconditions: The Binary Search Tree of movies is not empty
//and the movie we are trying to find exists in the binary tree.
//Postconditions: returns the movie that the user wanted to retrieve. 
//-----------------------------------------------------------------
bool BinarySearchTree::retrieveClassic(Movie*& movie, int month, int year, string actor)
{
    bool found = false;
    Node* temp = root;

    while ((temp != nullptr) && (found == false)) {
        if ((temp != nullptr) && (isEmpty() == false) && (temp->movie->getMonth() == month) && (temp->movie->getYear() == year) && (temp->movie->getActor() == actor)) {
            movie = temp->movie;
            found = true;
            return true;
        }
        //if the temp node is smaller than the movie we are looking for we fo left, other we go right
        else if ((temp != nullptr) && (temp->movie->getYear() > year)) {
            temp = temp->left;
        }
        else if ((temp != nullptr) && (temp->movie->getYear() == year) && (temp->movie->getMonth() > month)) {
            temp = temp->left;
        }
        else if ((temp != nullptr) && (temp->movie->getYear() == year) && (temp->movie->getMonth() == month) && (temp->movie->getActor() > actor)) {
            temp = temp->left;
        }
        else if ((temp != nullptr) && (temp->movie->getYear() < year)) {
            temp = temp->right;
        }
        else if ((temp != nullptr) && (temp->movie->getYear() == year) && (temp->movie->getMonth() < month)) {
            temp = temp->right;
        }
        else if ((temp != nullptr) && (temp->movie->getYear() == year) && (temp->movie->getMonth() == month) && (temp->movie->getActor() < actor)) {
            temp = temp->right;
        }
    }
    //If we are out of the while loop then we failed the find the movie
    cerr << "ERROR: The movie was not found. Retrieval failed." << endl;
    return false;
}

//----------------------------display-----------------------------
//Displays the BinarySearchTree in order. Usese the displayHelper
//function to recusrively do so. 
//Preconditions: The binary tree is not empty and the BinarySearchTree
//is sorted in the correctly order. 
//Postconditions: Outputs all the movies line by line in the 
//desired sorting order.
//-----------------------------------------------------------------
void BinarySearchTree::display()
{
    if (isEmpty() == true) {
        //If the node is null then we print out this error
        cerr << "ERROR: There is no this type of movie in the inventory." << endl;
    }
    else {
        displayHelper(root);
    }
}

//-------------------------displayHelper---------------------------
//Displays the BinarySearchTree in order. Usese the displayHelper
//function to recusrively do so. 
//Preconditions: The binary tree is not empty and the BinarySearchTree
//is sorted in the correctly order. 
//Postconditions: Outputs all the movies line by line in the 
//desired sorting order.
//-----------------------------------------------------------------
void BinarySearchTree::displayHelper(Node* root)
{
    if (root != nullptr) {
        displayHelper(root->left);
        root->movie->display();
        displayHelper(root->right);

    }
}

//----------------------------isEmpty------------------------------
//Checks if the BinarySearchTree is empty, if it is then it will
//return true and false otherwise. 
//Preconditions: The binary tree is not empty and the BinarySearchTree
//is sorted in the correctly order. 
//Postconditions: Outputs all the movies line by line in the 
//desired sorting order.
//-----------------------------------------------------------------
bool BinarySearchTree::isEmpty() const
{
    if (root == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

//--------------------------- RecursiveMakeEmpty ----------------------------
// Helper function for makeEmpty. Empties binary tree node by node.
// Preconditions: The binary tree is not already empty.
// Postconditions: The binary tree is empty at the end and the root becomes 
// nullptr. 
//---------------------------------------------------------------------------
void BinarySearchTree::makeEmptyHelper(Node* node)
{
    if (node != nullptr) {
        if (node->left != nullptr) {
            makeEmptyHelper(node->left);
        }
        if (node->right != nullptr) {
            makeEmptyHelper(node->right);
        }
        if (node->movie != nullptr) {
            delete node->movie;
            node->movie = nullptr;
        }
        delete node;
        node = nullptr;
    }
    root = nullptr;
}

//-------------------------------- makeEmpty --------------------------------
// Empties a binary tree. 
// Preconditions: The binary tree is not already empty.
// Postconditions: The binary tree is empty at the end and the root becomes 
// nullptr. 
//---------------------------------------------------------------------------
void BinarySearchTree::makeEmpty()
{
    if (this->isEmpty() == true) {
        return;
    }
    else {
        makeEmptyHelper(this->root);
    }
}

