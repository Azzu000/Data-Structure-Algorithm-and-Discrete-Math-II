//----------------------------------------------------------------------------------------------Borrow------------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//The inventory is where all the movies are stored. We have BinarySearchTrees for each type of movie since they are all sorted using different sorting criterias. The inventroy also
//functions that will help us maintain our inventory of movies. We can list the movies, which is needed for the I command, we can return or borrow movies, and we can addMovies (add movies)
//into our BinarySearchTrees depending on their movie type. When we are returning and borrowing movies, we will have to retrieve the movies in the binary trees by it's given information
//and -1 or +1 of the stocks from that specific movie.The inventory can only be accessed by the MovieStore. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//No Assumptions.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "inventory.h"

//------------------------  Inventory Constructor ---------------------------
// Initiates the variables for inventroy. 
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Inventory::Inventory()
{
	BinarySearchTree comedy_tree;
	BinarySearchTree drama_tree;
	BinarySearchTree classic_tree;
}

Inventory::~Inventory()
{

}

//------------------------  listMovies ---------------------------
// list the movies in order of comedy, drama, and then classic. Uses the 
// display function fothe binary search trees to do so. 
// Preconditions: NONE
// Postconditions: NONE
//----------------------------------------------------------------
void Inventory::listMovies()
{
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	cout << "The current movies in our inventory are..." << endl;
	cout << "Comedy Movies: " << endl;
	if (comedy_tree.isEmpty() == true) {
		cout << "There is no comedy movies available at the moment." << endl;
	}
	else {
		comedy_tree.display();
	}
	cout << endl;
	cout << "Drama Movies: " << endl;
	if (drama_tree.isEmpty() == true) {
		cout << "There is no drama movies available at the moment." << endl;
	}
	else {
		drama_tree.display();
	}
	cout << endl;
	cout << "Classic Movies: " << endl;
	if (classic_tree.isEmpty() == true) {
		cout << "ERROR: There is no classic movies available at the moment." << endl;
	}
	else {
		classic_tree.display();
	}
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
}

//------------------------  borrowComedy ---------------------------
// Borrows a movie form the comedy binary search tree. 
// Preconditions: The movie exists. 
// Postconditions: NONE
//----------------------------------------------------------------
bool Inventory::borrowComedy(string title, int year)
{
	Movie* temp_movie;
	//comedy_tree.retrieveComedy(temp_movie, title, year);
	if (comedy_tree.retrieveComedy(temp_movie, title, year) == false) {
		cerr << "ERROR: Movie cannot be found. Retrieve failed." << endl;
		return false;
	}
	else {
		//if the number of movies is 0
		if (temp_movie->getStock() < 1) {
			cerr << "ERROR: There is no stock of this comedy movie to borrow. Transaction failed." << endl;
			return false;
		}

		int new_stock = temp_movie->getStock() - 1;
		temp_movie->setStock(new_stock);
		return true;
	}
	cout << endl;
}

//------------------------  borrowDrama -------------------------
// Borrows a movie from the drama binary search tree. 
// Preconditions: The movie exists. 
// Postconditions: NONE
//----------------------------------------------------------------
bool Inventory::borrowDrama(string director, string title)
{
	Movie* temp_movie;
	//drama_tree.retrieveDrama(temp_movie, director, title);
	if (drama_tree.retrieveDrama(temp_movie, director, title) == false) {
		cerr << "ERROR: Movie cannot be found. Retrieve failed." << endl;
		return false;
	}
	else {
		//if the number of movies is 0
		if (temp_movie->getStock() < 1) {
			cerr << "ERROR: There is no stock of this comedy movie to borrow. Transaction failed." << endl;
			return false;
		}

		int new_stock = temp_movie->getStock() - 1;
		temp_movie->setStock(new_stock);
		return true;
	}
	cout << endl;
}

//------------------------  borrowClassic ------------------------
// Borrows a movie from the classic binary search tree. 
// Preconditions: The movie exists. 
// Postconditions: NONE
//----------------------------------------------------------------
bool Inventory::borrowClassic(int month, int year, string actor)
{
	Movie* temp_movie;
	//classic_tree.retrieveClassic(temp_movie, month, year, actor);
	if (classic_tree.retrieveClassic(temp_movie, month, year, actor) == false) {
		cerr << "ERROR: Movie cannot be found. Retrieve failed." << endl;
		return false;
	}
	else {
		//if the number of movies is 0
		if (temp_movie->getStock() < 1) {
			cerr << "ERROR: There is no stock of this comedy movie to borrow. Transaction failed." << endl;
			return false;
		}

		int new_stock = temp_movie->getStock() - 1;
		temp_movie->setStock(new_stock);
		return true;
	}
	cout << endl;
}

//------------------------  returnComedy ------------------------
// Returns a movie from the comedy binary search tree. 
// Preconditions: The movie exists. 
// Postconditions: NONE
//----------------------------------------------------------------
bool Inventory::returnComedy(string title, int year)
{
	Movie* temp_movie;
	//comedy_tree.retrieveComedy(temp_movie, title, year);
	if (comedy_tree.retrieveComedy(temp_movie, title, year) == false) {
		cerr << "ERROR: Movie cannot be found. Retrieve failed." << endl;
		return false;
	}
	else {
		//if the number of movies is 0
		if (temp_movie->getStock() < 1) {
			cerr << "ERROR: There is no stock of this comedy movie to borrow. Transaction failed." << endl;
			return false;
		}

		int new_stock = temp_movie->getStock() + 1;
		temp_movie->setStock(new_stock);
		return true;
	}
	cout << endl;
}

//------------------------  returnDrama ------------------------
// Returns a movie from the drama binary search tree. 
// Preconditions: The movie exists. 
// Postconditions: NONE
//----------------------------------------------------------------
bool Inventory::returnDrama(string director, string title)
{
	Movie* temp_movie;
	//drama_tree.retrieveDrama(temp_movie, director, title);
	if (drama_tree.retrieveDrama(temp_movie, director, title) == false) {
		cerr << "ERROR: Movie cannot be found. Retrieve failed." << endl;
		return false;
	}
	else {
		//if the number of movies is 0
		if (temp_movie->getStock() < 1) {
			cerr << "ERROR: There is no stock of this comedy movie to borrow. Transaction failed." << endl;
			return false;
		}

		int new_stock = temp_movie->getStock() + 1;
		temp_movie->setStock(new_stock);
		return true;
	}
	cout << endl;
}

//------------------------  returnClassic ------------------------
// Returns a movie from the classic binary search tree. 
// Preconditions: The movie exists. 
// Postconditions: NONE
//----------------------------------------------------------------
bool Inventory::returnClassic(int month, int year, string actor)
{
	Movie* temp_movie;
	//classic_tree.retrieveClassic(temp_movie, month, year, actor);
	if (classic_tree.retrieveClassic(temp_movie, month, year, actor) == false) {
		cerr << "ERROR: Movie cannot be found. Retrieve failed." << endl;
		return false;
	}
	else {
		//if the number of movies is 0
		if (temp_movie->getStock() < 1) {
			cerr << "ERROR: There is no stock of this comedy movie to borrow. Transaction failed." << endl;
			return false;
		}

		int new_stock = temp_movie->getStock() + 1;
		temp_movie->setStock(new_stock);
		return true;
	}
	cout << endl;
}

//------------------------  addMovie ------------------------
// Adds a movie to the binary search trees according to the movie
// type. 
// Preconditions: The movie type is valid and the stocks are not
// negative or zero. 
// Postconditions: NONE
//----------------------------------------------------------------
bool Inventory::addMovie(char movie_type, int stock, string director, string title, string actor, int month, int year)
{
	//NOTE: We might have to check if the insert fails or not before we actually return true.
	//the stock cannot be negative or 0
	if (stock > 0) {
		if (movie_type == 'F') {
			Movie* temp_movie = new Comedy(movie_type, stock, director, title, year);
			comedy_tree.insert(temp_movie);
			return true;
		}
		else if(movie_type == 'D') {
			Movie* temp_movie = new Drama(movie_type, stock, director, title, year);
			drama_tree.insert(temp_movie);
			return true;
		}
		else if (movie_type == 'C') {
			Movie* temp_movie = new Classic(movie_type, stock, director, title, actor, month, year);
			classic_tree.insert(temp_movie);
			return true;
		}
		//if the movie_type is other than F, D, or C it is invalid
		else {
			cerr << "ERROR: Invalid movie type. Cannot add movie to inventory." << endl;
			return false;
		}
	}
	else {
		cerr << "ERROR: The stock is zero or negative." << endl;
		return false;
	}
}







