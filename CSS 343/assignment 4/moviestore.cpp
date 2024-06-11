//----------------------------------------------------------------------------------------------MovieStore--------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//The Movie Store is the parent of all the classes as it manages everything including the Inventory, customers, and transactions/commands. The movie store keeps track of the movies
//using the Inventory class that has a BinarySearchTree of movies. The movie store also keeps track of the customer by a hashtable which stores all the customer depending on their
//ID. The movie store initiates commadns y first reading a file of commands and then sotring them in a queue. Then we use initiateCommands function to actually initiate the commands.
//The rest of the function of the MovieStore class includes reading the customer file, movie file and the commands file.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//We assume that all the file are in the right format
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "moviestore.h"

//No Args Constructor
MovieStore::MovieStore()
{
}

//Destructor
MovieStore::~MovieStore()
{
}

//-------------------------readMovies--------------------------
//Takes in a movie file and reads it and insert the Binary
//Search Trees in the Inventory depending on its movie type.
//Preconditions:  The file must not be empty and must be 
//in the right format.
//Postconditions: The Inventory is filled with movies from
//the file.
//-------------------------------------------------------------
void MovieStore::readMovies(const string& file_name)
{
	ifstream file;
	file.open(file_name);
	string temp_movie_type; //This is goign to temporarily hold the string version of movie_type
	char movie_type = 'a'; //a is the default value for movie type
	string temp_stock; //This is going to temporarily hold the string version of stock
	int stock = 0;
	string title;
	string director;
	string actor_first; //this is going to hold the first name of the actor before we merge
	string actor_last; //this is going to hold the last name of the actor before we merge
	string actor;
	int month = 0;
	string temp_year;
	int year = 0;
	string line; //is going to hold our current line of movies

	getline(file, line); //get the first line

	if (file.eof() == true) {
		cerr << "ERROR: Unable to read the file." << endl;
	}

	while (!file.eof()) {
		stringstream ss(line);
		getline(ss, temp_movie_type, ',');
		movie_type = temp_movie_type[0]; //Make movie_type equal to only the first char of temp_movie_type string
		getline(ss, temp_stock, ',');
		stock = stoi(temp_stock);
		getline(ss, director, ',');
		getline(ss, title, ',');
		//if the movie type is comedy or drama
		if ((movie_type == 'F') || (movie_type == 'D')) {
			getline(ss, temp_year, ',');
			year = stoi(temp_year);
		}
		else if ((movie_type == 'C')) {
			ss >> actor_first >> actor_last;
			actor = actor_first + " " + actor_last;
			ss >> month;
			ss >> year;
		}
		else {
			cerr << "ERROR: Movie type does not exist. Terminated one transaction." << endl;
		}

		if ((movie_type == 'F') || (movie_type == 'D')) {
			movie_inventory.addMovie(movie_type, stock, director, title, "none", 0, year); //none and month is set to default values because it does not exist for comedy and drama
		}
		else if (movie_type == 'C') {
			movie_inventory.addMovie(movie_type, stock, director, title, actor, month, year);
		}

		getline(file, line); //get the next line and loop
	}
	file.close();

}

//-------------------------readCommands--------------------------
//Takes in commands from the command file and puts it into a queue
// to be initiated. 
//Preconditions:  The file must be in the right format and not empty.
//Postconditions: The queue is filled with commands.
//-------------------------------------------------------------
void MovieStore::readCommands(const string& file_name)
{
	ifstream file;
	file.open(file_name);
	char command_type;
	int id = 0;
	char media_type;
	char movie_type;
	string title;
	int year = 0;
	string director;
	int month = 0;
	string actor_first; //the first section of actor before we merge
	string actor_last; //the last section of actor before we merge
	string actor;
	string line; //is going to hold our current line of commands

	//temp is used to see what the next information given by a undefined movie type command
	string temp;
	string temp2;

	getline(file, line); //get the first line

	if (file.eof() == true) {
		cerr << "ERROR: Unable to read the file." << endl;
	}

	while (!file.eof()) {
		stringstream ss(line);
		ss >> command_type;
		ss >> id;
		ss >> media_type;
		ss >> movie_type;

		if (command_type == 'I') {
			Command* new_command = new Command(command_type); //temperorily holds the command to be pushed into queue
			command_list.push(new_command);
		}
		else if (command_type == 'H') {
			Command* new_command = new Command(command_type, id);
			command_list.push(new_command);
		} else if (movie_type == 'F') {
			getline(ss, title, ',');
			ss >> year;
			if ((command_type == 'B')) {
				Command* new_command = new Borrow(command_type, id, media_type, movie_type, title, year);
				command_list.push(new_command);
			}
			else if ((command_type == 'R')) {
				Command* new_command = new Return(command_type, id, media_type, movie_type, title, year);
				command_list.push(new_command);
			}
			else {
				Command* new_command = new Command(command_type, id, media_type, movie_type, title, year);
				command_list.push(new_command);
			}
		}
		else if (movie_type == 'D') {
			getline(ss, director, ',');
			getline(ss, title, ',');
			if ((command_type == 'B') || (command_type == 'R')) {
				Command* new_command = new Borrow(command_type, id, media_type, movie_type, director, title);
				command_list.push(new_command);
			}
			else if ((command_type == 'R')) {
				Command* new_command = new Return(command_type, id, media_type, movie_type, director, title);
				command_list.push(new_command);
			}
			else {
				Command* new_command = new Command(command_type, id, media_type, movie_type, director, title);
				command_list.push(new_command);
			}
		}
		else if (movie_type == 'C') {
			ss >> month;
			ss >> year;
			ss >> actor_first;
			ss >> actor_last;
			actor = actor_first + " "  + actor_last;

			if ((command_type == 'B') || (command_type == 'R')) {
				Command* new_command = new Borrow(command_type, id, media_type, movie_type, month, year, actor);
				command_list.push(new_command);
			}
			else if ((command_type == 'R')) {
				Command* new_command = new Return(command_type, id, media_type, movie_type, month, year, actor);
				command_list.push(new_command);
			}
			else {
				Command* new_command = new Command(command_type, id, media_type, movie_type, month, year, actor);
				command_list.push(new_command);
			}
		}
		//If it is a wrong movie type
		else if((movie_type != 'F') && (movie_type != 'D') && (movie_type != 'C') && (command_type != 'I') && (command_type != 'H')) {
			ss >> temp;
			//if the next variable is a title and year then it is comedy
			//if the next variable is a director and title then it is drama
			//if the next two variable is a date then it is classic (month year)
			//For these movie types we are jsut not gonna remove the comma
			//if the first variable is not a string then we know it is a classic formatted command
			//***since we reading the line over we have to start at command type.
			if (isdigit(temp[0])) {
				stringstream ss(line);
				ss >> command_type;
				ss >> id;
				ss >> media_type;
				ss >> movie_type;
				ss >> month;
				ss >> year;
				ss >> actor_first;
				ss >> actor_last;
				actor = actor_first + " " + actor_last;
				Command* new_command = new Command(command_type, id, media_type, movie_type, month, year, actor);
				command_list.push(new_command);
			}
			else {
				stringstream ss(line);
				ss >> command_type;
				ss >> id;
				ss >> media_type;
				ss >> movie_type;
				getline(ss, temp, ',');
				ss >> temp2;
				//if the second varible is a string then it is a drama formatted command
				if (!isdigit(temp2[0])) {
					stringstream ss(line);
					ss >> command_type;
					ss >> id;
					ss >> media_type;
					ss >> movie_type;
					getline(ss, director, ',');
					getline(ss, title, ',');
					Command* new_command = new Command(command_type, id, media_type, movie_type, director, title);
					command_list.push(new_command);
				}
				//else if it a comedy formatted command
				else {
					stringstream ss(line);
					ss >> command_type;
					ss >> id;
					ss >> media_type;
					ss >> movie_type;
					getline(ss, title, ',');
					ss >> year;
					Command* new_command = new Command(command_type, id, media_type, movie_type, title, year);
					command_list.push(new_command);
				}
			}
			//else it is either a comedy or a drama movie

		}

		if ((command_type != 'I') && (command_type != 'H') && (command_type != 'B') && (command_type != 'R')) {
			cerr << "ERROR: Command type cannot be recognized. Command cannot be initialized." << endl;
		}
		else if ((movie_type != 'F') && (movie_type != 'D') && (movie_type != 'C') && (command_type != 'I') && (command_type != 'H')) {
			cerr << "ERROR: Movie type for command cannot be recognized. Command cannot be initialized." << endl;
		}

		getline(file, line); //get the next line and loop
	}
	file.close();

}

//-------------------------readCustomer--------------------------
//Reads a customer file and puts them into the customer hash
//table. 
//Preconditions:  The file must not be empty and must be 
//in the right format.
//Postconditions: The HashTable is filled with customers in file.
//---------------------------------------------------------------
void MovieStore::readCustomer(const string& file_name)
{
	ifstream file;
	file.open(file_name);
	int id;
	string first_name;
	string last_name;
	string line; //is going to hold our current line of customer
	getline(file, line); //get the frist line

	if (file.eof() == true) {
		cerr << "ERROR: Unable to read the file." << endl;
	}

	while (!file.eof()) {
		stringstream ss(line);
		ss >> id;
		ss >> last_name;
		ss >> first_name;
		Customer* new_customer = new Customer(id, first_name, last_name);
		customer_list.Insert(id, new_customer);

		getline(file, line); //get the next line and loop
	}
	file.close();
}

//-------------------------initiateCommands--------------------------
//Initiates the commands in the queue and saves the commands in each
// specific cusotmer queue for history.
//Preconditions: The queue must not be empty.
//Postconditions: The customers queue of transactions is filled 
// accordingly.
//-------------------------------------------------------------------
void MovieStore::initiateCommands()
{
	int temp_id;
	Customer* temp_customer;
	//while the command list queue is not empty
	while (command_list.empty() == false) {
		//if I then print all movie inventory
		if (command_list.front()->getCommandType() == 'I') {
			movie_inventory.listMovies();
		}
		else if (command_list.front()->getCommandType() == 'H') {
			temp_id = command_list.front()->getCustomerID();
			customer_list.Search(temp_id, temp_customer);
			temp_customer->showHistory();
		}
		else if (command_list.front()->getCommandType() == 'R') {
			if (command_list.front()->getMovieType() == 'F') {
				int temp_id = command_list.front()->getCustomerID();
				customer_list.Search(temp_id, temp_customer);
				string temp_title = command_list.front()->getTitle();
				int temp_year = command_list.front()->getYear();
				movie_inventory.returnComedy(temp_title, temp_year);
				temp_customer->addComedyCommand('R', temp_id, command_list.front()->getMediaType(), 'F', temp_title, temp_year);

			}
			else if (command_list.front()->getMovieType() == 'D') {
				int temp_id = command_list.front()->getCustomerID();
				customer_list.Search(temp_id, temp_customer);
				string temp_director = command_list.front()->getDirector();
				string temp_title = command_list.front()->getTitle();
				movie_inventory.returnDrama(temp_director, temp_title);
				temp_customer->addDramaCommand('R', temp_id, command_list.front()->getMediaType(), 'D', temp_director, temp_title);
			}
			else if (command_list.front()->getMovieType() == 'C') {
				int temp_id = command_list.front()->getCustomerID();
				customer_list.Search(temp_id, temp_customer);
				int temp_month = command_list.front()->getMonth();
				int temp_year = command_list.front()->getYear();
				string temp_actor = command_list.front()->getActor();
				movie_inventory.returnClassic(temp_month, temp_year, temp_actor);
				temp_customer->addClassicCommand('R', temp_id, command_list.front()->getMediaType(), 'C', temp_month, temp_year, temp_actor);
			}
			//if the movie type is wrong
			else {
				if (command_list.front()->getTitle() == "none") {
					int temp_id = command_list.front()->getCustomerID();
					customer_list.Search(temp_id, temp_customer);
					int temp_month = command_list.front()->getMonth();
					int temp_year = command_list.front()->getYear();
					string temp_actor = command_list.front()->getActor();
					movie_inventory.returnClassic(temp_month, temp_year, temp_actor);
					temp_customer->addClassicCommand('R', temp_id, command_list.front()->getMediaType(), command_list.front()->getMovieType(), temp_month, temp_year, temp_actor);
				}
				else if (command_list.front()->getDirector() == "none") {
					int temp_id = command_list.front()->getCustomerID();
					customer_list.Search(temp_id, temp_customer);
					int temp_month = command_list.front()->getMonth();
					int temp_year = command_list.front()->getYear();
					string temp_actor = command_list.front()->getActor();
					movie_inventory.returnClassic(temp_month, temp_year, temp_actor);
					temp_customer->addClassicCommand('R', temp_id, command_list.front()->getMediaType(), command_list.front()->getMovieType(), temp_month, temp_year, temp_actor);
				}
				else {
					int temp_id = command_list.front()->getCustomerID();
					customer_list.Search(temp_id, temp_customer);
					string temp_director = command_list.front()->getDirector();
					string temp_title = command_list.front()->getTitle();
					movie_inventory.returnDrama(temp_director, temp_title);
					temp_customer->addDramaCommand('R', temp_id, command_list.front()->getMediaType(), command_list.front()->getMovieType(), temp_director, temp_title);
				}
			}
		}
		else if (command_list.front()->getCommandType() == 'B') {
			if (command_list.front()->getMovieType() == 'F') {
				int temp_id = command_list.front()->getCustomerID();
				customer_list.Search(temp_id, temp_customer);
				string temp_title = command_list.front()->getTitle();
				int temp_year = command_list.front()->getYear();
				movie_inventory.borrowComedy(temp_title, temp_year);
				temp_customer->addComedyCommand('B', temp_id, command_list.front()->getMediaType(), 'F', temp_title, temp_year);
			}
			else if (command_list.front()->getMovieType() == 'D') {
				int temp_id = command_list.front()->getCustomerID();
				customer_list.Search(temp_id, temp_customer);
				string temp_director = command_list.front()->getDirector();
				string temp_title = command_list.front()->getTitle();
				movie_inventory.borrowDrama(temp_director, temp_title);
				temp_customer->addDramaCommand('B', temp_id, command_list.front()->getMediaType(), 'D', temp_director, temp_title);
			}
			else if (command_list.front()->getMovieType() == 'C') {
				int temp_id = command_list.front()->getCustomerID();
				customer_list.Search(temp_id, temp_customer);
				int temp_month = command_list.front()->getMonth();
				int temp_year = command_list.front()->getYear();
				string temp_actor = command_list.front()->getActor();
				movie_inventory.borrowClassic(temp_month, temp_year, temp_actor);
				temp_customer->addClassicCommand('B', temp_id, command_list.front()->getMediaType(), 'C', temp_month, temp_year, temp_actor);
			}
			//if the movie type is wrong
			else {
				if (command_list.front()->getTitle() == "none") {
					int temp_id = command_list.front()->getCustomerID();
					customer_list.Search(temp_id, temp_customer);
					int temp_month = command_list.front()->getMonth();
					int temp_year = command_list.front()->getYear();
					string temp_actor = command_list.front()->getActor();
					movie_inventory.returnClassic(temp_month, temp_year, temp_actor);
					temp_customer->addClassicCommand('R', temp_id, command_list.front()->getMediaType(), command_list.front()->getMovieType(), temp_month, temp_year, temp_actor);
				}
				else if (command_list.front()->getDirector() == "none") {
					int temp_id = command_list.front()->getCustomerID();
					customer_list.Search(temp_id, temp_customer);
					int temp_month = command_list.front()->getMonth();
					int temp_year = command_list.front()->getYear();
					string temp_actor = command_list.front()->getActor();
					movie_inventory.returnClassic(temp_month, temp_year, temp_actor);
					temp_customer->addClassicCommand('R', temp_id, command_list.front()->getMediaType(), command_list.front()->getMovieType(), temp_month, temp_year, temp_actor);
				}
				else {
					int temp_id = command_list.front()->getCustomerID();
					customer_list.Search(temp_id, temp_customer);
					string temp_director = command_list.front()->getDirector();
					string temp_title = command_list.front()->getTitle();
					movie_inventory.returnDrama(temp_director, temp_title);
					temp_customer->addDramaCommand('R', temp_id, command_list.front()->getMediaType(), command_list.front()->getMovieType(), temp_director, temp_title);
				}
			}
		}
		//if it is not B or R then we can just add it to customer transaction but not initiate it.
		else {
			if (command_list.front()->getMovieType() == 'F') {
				int temp_id = command_list.front()->getCustomerID();
				customer_list.Search(temp_id, temp_customer);
				string temp_title = command_list.front()->getTitle();
				int temp_year = command_list.front()->getYear();
				char temp_command_type = command_list.front()->getCommandType();
				temp_customer->addComedyCommand(temp_command_type, temp_id, command_list.front()->getMediaType(), 'F', temp_title, temp_year);
			}
			else if (command_list.front()->getMovieType() == 'D') {
				int temp_id = command_list.front()->getCustomerID();
				customer_list.Search(temp_id, temp_customer);
				string temp_director = command_list.front()->getDirector();
				string temp_title = command_list.front()->getTitle();
				char temp_command_type = command_list.front()->getCommandType();
				temp_customer->addDramaCommand(temp_command_type, temp_id, command_list.front()->getMediaType(), 'D', temp_director, temp_title);
			}
			else if (command_list.front()->getMovieType() == 'C') {
				int temp_id = command_list.front()->getCustomerID();
				customer_list.Search(temp_id, temp_customer);
				int temp_month = command_list.front()->getMonth();
				int temp_year = command_list.front()->getYear();
				string temp_actor = command_list.front()->getActor();
				char temp_command_type = command_list.front()->getCommandType();
				temp_customer->addClassicCommand(temp_command_type, temp_id, command_list.front()->getMediaType(), 'C', temp_month, temp_year, temp_actor);
			}
			//if the movie type is wrong
			else {
				if (command_list.front()->getTitle() == "none") {
					int temp_id = command_list.front()->getCustomerID();
					customer_list.Search(temp_id, temp_customer);
					int temp_month = command_list.front()->getMonth();
					int temp_year = command_list.front()->getYear();
					string temp_actor = command_list.front()->getActor();
					movie_inventory.returnClassic(temp_month, temp_year, temp_actor);
					temp_customer->addClassicCommand(command_list.front()->getCommandType(), temp_id, command_list.front()->getMediaType(), command_list.front()->getMovieType(), temp_month, temp_year, temp_actor);
				}
				else if (command_list.front()->getDirector() == "none") {
					int temp_id = command_list.front()->getCustomerID();
					customer_list.Search(temp_id, temp_customer);
					int temp_month = command_list.front()->getMonth();
					int temp_year = command_list.front()->getYear();
					string temp_actor = command_list.front()->getActor();
					movie_inventory.returnClassic(temp_month, temp_year, temp_actor);
					temp_customer->addClassicCommand(command_list.front()->getCommandType(), temp_id, command_list.front()->getMediaType(), command_list.front()->getMovieType(), temp_month, temp_year, temp_actor);
				}
				else {
					int temp_id = command_list.front()->getCustomerID();
					customer_list.Search(temp_id, temp_customer);
					string temp_director = command_list.front()->getDirector();
					string temp_title = command_list.front()->getTitle();
					movie_inventory.returnDrama(temp_director, temp_title);
					temp_customer->addDramaCommand(command_list.front()->getCommandType(), temp_id, command_list.front()->getMediaType(), command_list.front()->getMovieType(), temp_director, temp_title);
				}
			}
			
		}

		command_list.pop();
	}
}



