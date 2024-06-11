#pragma

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "movie.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "binary_search_tree.h"
#include "customer.h"
#include "command.h"
#include "return.h"
#include "borrow.h"
#include "hashtable.h"
#include "moviestore.h"
#include "inventory.h"

using namespace std;

int main() {
	MovieStore store1;

	store1.readCustomer("data4customers.txt");
	store1.readMovies("data4movies.txt");
	store1.readCommands("data4commands.txt");
	store1.initiateCommands();

	return 0;
}
