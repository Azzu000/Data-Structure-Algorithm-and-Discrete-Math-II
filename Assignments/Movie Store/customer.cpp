//----------------------------------------------------------------------------------------------Borrow------------------------------------------------------------------------------
// Ruiqi Huang CSS 343
// Date started: 5/26/2023
// Date of last modification: 6/2/2023
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//The Customer calss includes everything that defines a customer. We can identify a customer by its first name, last name, and id. Each customer is gonna have a queue that will hold
// all the transaction they have tried and the showHistory function will print out that history. Each addCommands method broken down into movie types. This will help us determine 
// which borrow and return constructor we should use to represent that command. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// We assume that all customers have a unique ID that we can identify them by and sort them by. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "customer.h"

//------------------------  Customer Constructor ----------------------------
// Initiates the variables for each customer.
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
Customer::Customer(int customer_id, string first_name, string last_name)
{
	this->customer_id = customer_id;
	this->first_name = first_name;
	this->last_name = last_name;
}

Customer::~Customer()
{
}

//------------------------  getFirst ----------------------------
// Gets the customer's first name and returns it.
// Preconditions: NONE
// Postconditions: returns first_name.
//---------------------------------------------------------------
string Customer::getFirst()
{
	string temp_first_name = this->first_name;
	return temp_first_name;
}

//------------------------  getLast ----------------------------
// Gets the customer's last name and returns it.
// Preconditions: NONE
// Postconditions: returns last_name.
//---------------------------------------------------------------
string Customer::getLast()
{
	string temp_last_name = this->last_name;
	return temp_last_name;
}

//------------------------  getID ----------------------------
// Gets the customer's ID and returns it.
// Preconditions: NONE
// Postconditions: returns customer_id.
//------------------------------------------------------------
int Customer::getID()
{
	int temp_id = this->customer_id;
	return temp_id;
}

//------------------------  addComedyCommand ----------------------------
// Adds comedy borrow or return command into the customer queue.
// Preconditions: NONE
// Postconditions: A command is added to queue. 
//-----------------------------------------------------------------------
void Customer::addComedyCommand(char command_type, int customer_id, char media_type, char movie_type, string title, int year)
{
	if (command_type == 'R') {
		Command* new_command = new Return(command_type, customer_id, media_type, movie_type, title, year);
		commands.push(new_command);
		commands_size = commands_size + 1;
	} 
	else if(command_type == 'B'){
		Command* new_command = new Borrow(command_type, customer_id, media_type, movie_type, title, year);
		commands.push(new_command);
		commands_size = commands_size + 1;
	}
	else {
		cerr << "ERROR: Trying to add command other than Borrow and Return to transaction history" << endl;
	}
}

//------------------------  addDramaCommand ----------------------------
// Adds drama borrow or return command into the customer queue.
// Preconditions: NONE
// Postconditions: A command is added to queue. 
//----------------------------------------------------------------------
void Customer::addDramaCommand(char command_type, int customer_id, char media_type, char movie_type, string director, string title)
{
	if (command_type == 'R') {
		Command* new_command = new Return(command_type, customer_id, media_type, movie_type, director, title);
		commands.push(new_command);
		commands_size = commands_size + 1;
	}
	else if(command_type == 'B') {
		Command* new_command = new Borrow(command_type, customer_id, media_type, movie_type, director, title);
		commands.push(new_command);
		commands_size = commands_size + 1;
	}
	else {
		cerr << "ERROR: Trying to add command other than Borrow and Return to transaction history" << endl;
	}
}

//------------------------  addClassicCommand ---------------------------
// Adds classic borrow or return command into the customer queue.
// Preconditions: NONE
// Postconditions: A command is added to queue. 
//----------------------------------------------------------------------
void Customer::addClassicCommand(char command_type, int customer_id, char media_type, char movie_type, int month, int year, string actor)
{
	if (command_type == 'R') {
		Command* new_command = new Return(command_type, customer_id, media_type, movie_type, month, year, actor);
		commands.push(new_command);
		commands_size = commands_size + 1;
	}
	else if (command_type == 'B') {
		Command* new_command = new Borrow(command_type, customer_id, media_type, movie_type, month, year, actor);
		commands.push(new_command);
		commands_size = commands_size + 1;
	}
	else {
		cerr << "ERROR: Trying to add command other than Borrow and Return to transaction history" << endl;
	}
}

//--------------------------  showHistory ------------------------------
// Show the history of transactions for the customer.
// Preconditions: NONE
// Postconditions: Output customer command queue. 
//----------------------------------------------------------------------
void Customer::showHistory()
{
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	//temp command is going to temporarily hold the command once we pop the item we can save it and we can push item back after
	Command* temp_command;

	cout << "The History of Customer " << this->getFirst() << " " << this->getLast() << " with ID of " << this->getID() << ": " << endl;
	//If the customer don't have any transactions
	if (commands.empty() == true) {
		cerr << "ERROR: The customer's history is empty. Nothing to output." << endl;
		return;
	}
	//Use a for loop to go through all queue
	for (int i = 1; i < commands_size + 1; i++) {
		temp_command = commands.front();
		temp_command->display();
		commands.push(temp_command);
		commands.pop();
	}
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
}


