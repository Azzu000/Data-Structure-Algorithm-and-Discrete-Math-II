//----------------------------------------------------------------------- GraphM --------------------------------------------------------------------------------
// Ruiqi Huang CSS 343 
// Date started: 4/28/2023
// Date of last modification: 4/5/2023
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
// Purpose - This program uses a adjacency matrix to keep track of the edges and it's information. We build a graph by reading into a file that contains
// all the infromation we need to build that graph. We are going to use that adjacency matrix to find Dijkstra's shortest paht using the function findShortestPath.
// The psuedocode given in class was used to create this method. We also have functions such as insertEdge and removeEdge that will insert and remove edges if needed. 
// We will also have two display function that will work differently. The first display function is displayAll, which displays all the paths of ever node to every 
// other node. This function is helpful to check if your graph and path is correct. The next display function is called display and it will take in a from_node, 
// which is the node our edge will start at, and the to_node which the node our edge will end at. We take those two nodes and display the shortest path given by the 
// findShortestPath function. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Assumptions - We are assumming that the file order of the information is correct - meaning the size is in the first line and the data is next and so on. 
// We also assume that the given grpah is a weighted graph with edges. We are also assuming there is a max of 100 nodes.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "graphm.h"

//------------------- GraphM No Args Constructor ----------------------------
// Creates a "empty" graph. All values start as INT_MAX or infinity
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
GraphM::GraphM()
{
	size = 0; //default size of graph is zero

	//nested for loop for 2 dimensional array
	//setting all dist to infinity, all visited to false, and sets all path to 0 as instructed
	for (int i = 0; i < MAXNODES; i++) {
		for (int j = 0; j < MAXNODES; j++) {
			C[i][j] = INT_MAX; //since c++ does not has infinity as a number we will set it as the max number c++ can have, which is declared by INT_MAX
			T[i][j].dist = INT_MAX; 
			T[i][j].visited = false;
			T[i][j].path = 0;
		}
	}
}


//----------------------------- buildGraph ----------------------------------
// builds a graph given a file
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
//CHECK
void GraphM::buildGraph(ifstream& file)
{
	//To define the edges we need these variables
	int from_node; 
	int to_node;
	int dist;
	string line; //going to be the string of each line

	//the first line in the text is going to be the number of nodes in our graph
	file >> size;

	//We cannot have a size smaller than 1 (negative)
	if (size < 1) {
		return;
	}
	else {
		getline(file, line);

		//Getting the nodes
		for (int i = 1; i < size + 1; i++) {
			data[i].setData(file);
		}

		//Now we have to use a while loop for the edges because we don't know how many edges there are
		//So as long as we are not at the end of the line we continoue to read the line for edges
		while (!file.eof()) {
			file >> from_node >> to_node >> dist;

			// 0 0 0 means we are at the end of our edge list 
			if ((from_node == 0) && (to_node == 0) && (dist == 0)) {
				return;
			}

			insertEdge(from_node, to_node, dist);
		}
	}
}

//------------------------------- insertEdge---------------------------------
// Insert an edge into the current fraph given the from node and to node.
// Preconditions: the from_node and to_node have to be bigger than 0. 
// The from_node and the to_node also can't be bigger than the current size
// as that means the nodes does nto exist.
// Postconditions: An edge is inserted into the graph
//---------------------------------------------------------------------------
bool GraphM::insertEdge(int from_node, int to_node, int distance)
{
	//The nodes cannot be less than 0
	if (from_node <= 0 || to_node <= 0) {
		return false;
	}
	//The nodes and the distance cannot be more than the size (the number of nodes)
	else if(from_node > size || to_node > size){
		return false;
	}
	else {
		C[from_node][to_node] = distance;
		return true;
	}
}

bool GraphM::removeEdge(int from_node, int to_node)
{
	//The nodes and the distance cannot be less than 0
	if (from_node <= 0 || to_node <= 0) {
		return false;
	}
	//The nodes and the distance cannot be more than the size (the number of nodes)
	else if (from_node > size || to_node > size) {
		return false;
	}
	else {
		//Default value set by constructor is inifinity (INT_MAX in this case)
		C[from_node][to_node] = INT_MAX;
		return true;
	}
}

//------------------------------ findShorestPath------------------------------
// Finds the shortest path for all the nodes and updates the
// matrixwith the new path information with the path found.
// Preconditions: The size have to be bigger than 0. 
// Postconditions: The shortest path is updated and recorded
//----------------------------------------------------------------------------
/*NOTE: Ignore this comment, this is for self reference only
*psuedocode given in class:
*for (int source = 1; source <= nodeSize; source++) {
*	T[source][source].dist = 0;
*	// finds the shortest distance from source to all other nodes
*	for (int i = 1; i<= nodeSize; i++) {
*		find v //not visited, shortest distance at this point
*		mark v visited
*		for each w adjacent to v
*			if (w is not visited)
*				T[source][w].dist=min(T[source][w].dist, T[source][v].dist+C[V][W])
*	}
*}
*/
void GraphM::findShortestPath()
{
	//v is going to be the shortest path
	int v = 0;
	//shortest is going to be our shortest distance, it will first equal to infinity as we don't want the shortest path to be bigger than the current shortest
	int shortest = 0;
	//we are going to use the current variable to keep track of our while loops
	int current = 1;

	//The top part is derived form the psuedocode given in the assignment
	//for every source we are looking at, the distance to itself is 0
	for (int source = 1; source < size + 1; source++) {
		//The distance of the source vertex to itself should be 0
		T[source][source].dist = 0;
		
		//i is the from_node and j is the to_node
		for (int i = 1; i < size + 1; i++) {
			//reset all the the vaiables v, shortest, current for next node
			v = -1;
			shortest = INT_MAX;
			current = 1;
			//Here we are using a while loop to find v that is not visited and is the shortest distance
			while (current != size + 1) {
				//if the path is not visited and the distance is by far the shortest
				if ((T[source][current].visited == false) && (T[source][current].dist < shortest)) {
					//set the new shortest distance to this new distance
					shortest = T[source][current].dist;
					//set v to i to keep track of the node
					v = current;
				}
				current = current + 1;
			} //After the while loop we should have checked all the neighboring nodes
			//If the  v does not equal -1 that means we found a shortest path
			if (v != -1) {
				//set v as visited
				T[source][v].visited = true;
				//for each w adjacent to v
				for (int w = 1; w < size + 1; w++) {
					//if w is not visited
					if ((T[source][w].visited == false) && (C[v][w] < INT_MAX)) {
						//check which one is the smallest distance and set it equal to the min distance
						T[source][w].dist = min(T[source][w].dist, T[source][v].dist + C[v][w]);
						//if it is w is bigger or equal to v then we can jsut set the path to it as well, else we don't have to change anything
						if (T[source][w].dist >= T[source][v].dist + C[v][w]) {
							T[source][w].path = v;
						}
					}
				}
			}
		}
	}
	//clear everything for possible next iteration
	for (int i = 1; i < size + 1; i++) {
		for (int j = 1; j < size + 1; j++) {
			T[i][j].visited = false;
		}
	}
}

//------------------------------ findShorestPath------------------------------
// Display all the information of the graph in an organized manner. This includes:
// The graph data, paths, Dijkstra's distance, and the nodes (from_node, to_node)
// Preconditions: The size have to be bigger than 0. 
// Postconditions: The graph is not changed except the paths might be updated.
//----------------------------------------------------------------------------
void GraphM::displayAll()
{
	findShortestPath();
	//Following the format given in the assignment.
	//Note to self: 10 space from description to from node, 4 space from from node to to node, 4 from to node to Dijkstra's, and 4 from Dijkstra's to path.
	cout << "Description" << "          " << "From node" << "    " << "To node" << "    " << "Dijstra's" << "    " << "Path" << endl;
	
	//description only runs for the outer for loop because it is deisplayed once
	//current_node represents the current node we are on (our from_node)
	for (int current_node = 1; current_node < size + 1; current_node++) {
		cout << data[current_node] << endl; //data[i] holds the description of each node
		//other_node represents the node we are comparing the current_node with (our to_node)
		for (int other_node = 1; other_node < size + 1; other_node++) {
			//we don't need to display when from_node is the same as our to_node
			if (current_node != other_node) {
				cout << "                     " << current_node;
				cout << "            " << other_node;
				//if the Disjkstra is infinity, it means there is no edge between the two nodes and so we represent that with a ---
				if (T[current_node][other_node].dist == INT_MAX) {
					cout << "          ---" << endl;
				}
				else {
					cout << "          " << T[current_node][other_node].dist;
				}
				//... display the path here (maybe use a pathfinder helper class
				cout << "           ";
				recursiveDisplayPath(current_node, other_node);
				cout << endl;
			}
		}
	}
	cout << endl;
}

//---------------------------------- display ---------------------------------
// Display the shortest path of the given from_node to the to_node. 
// Preconditions: The size have to be bigger than 0. 
// Postconditions: The graph is not changed except the paths might be updated.
//----------------------------------------------------------------------------
void GraphM::display(int from_node, int to_node)
{
	findShortestPath();
	//the from_node and to_node cannot be smalelr than 1
	if ((from_node < 1) || (to_node < 1)) {
		return;
	}
	//the from_node and to_node cannot be smaller than 1
	else if ((from_node > size) || (to_node > size)) {
		return;
	}
	else {
		cout << from_node << "    " << to_node;
 		//if our distance is infinity then we know there isn't a path
		if (T[from_node][to_node].dist = INT_MAX) {
			cout << "    ---";
		}else {
			cout << "    " << T[from_node][to_node].dist;
		}
		
		//now we print the path and the name after in order shown in assignment
		cout << "    ";
		//Display path 
		recursiveDisplayPath(from_node, to_node);
		cout << endl;
		//Display data
		recursiveDisplayData(from_node, to_node);
		cout << endl;
	}
}

//-------------------------- recursiveDisplayPath ----------------------------
// Recursive helper thayt displays the path. Is used by displayAll and display
// Preconditions: The size have to be bigger than 0. 
// Postconditions: The graph is not changed except the paths might be updated.
//----------------------------------------------------------------------------
void GraphM::recursiveDisplayPath(int from_node, int to_node)
{
	//if the form_node and the to_node is not itself 
	if (T[from_node][to_node].path != 0) {
		recursiveDisplayPath(from_node, T[from_node][to_node].path);
		//print out the to_node data
		cout << to_node << " ";
	}
	//We also want to print the node itself
	else if (from_node == to_node) {
		cout << to_node << " ";
	}
}

//-------------------------- recursiveDisplayData ----------------------------
// Recursive helper thayt displays the path. Is used by displayAll.
// Preconditions: The size have to be bigger than 0. 
// Postconditions: The graph is not changed except the paths might be updated.
//----------------------------------------------------------------------------
void GraphM::recursiveDisplayData(int from_node, int to_node)
{
	
	if (T[from_node][to_node].path != 0) {
		recursiveDisplayData(from_node, T[from_node][to_node].path);
		cout << data[to_node] << endl;
	}
	
	if (from_node == to_node) {
		cout << data[to_node] << endl;
	}
}
