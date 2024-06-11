//----------------------------------------------------------------------- GraphL --------------------------------------------------------------------------------
// Ruiqi Huang CSS 343 
// Date started: 4/28/2023
// Date of last modification: 4/5/2023
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
// Purpose - This program uses a ajacency list to keep track of the graph. The adjacency is made up of an array list which holds different list which stores the edges.
// To make the graph we will use buildGraph get all the information from a file and insert everything into the graph. The no args constructor helps create a empty 
// adjacency list that will eventually store our graph. depthFirstSearch will search our graph using the DFS method and display the order in which the search is done. 
// displayGraph displays all the edges and the nodes in the graph. This can be used to check if our graph is right. It is important to note that for the DFS function, 
// we have a recursiveDepthSearch method that will help recursively and aggressively find the depth first path. 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Assumptions - We are assumming that the file order of the information is correct - meaning the size is in the first line and the data is next and so on. 
// We also assume that the given grpah is a weighted graph with edges. We are also assuming there is a max of 100 nodes.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "graphl.h"

//------------------- GraphL No Args Constructor ----------------------------
// Creates a "empty" graph. All values start as nullptr.
// Preconditions: NONE
// Postconditions: NONE
//---------------------------------------------------------------------------
GraphL::GraphL()
{
	//initialize all variables for constructors
	size = 0;
	//For node to traverse GraphNode Array
	for (int i = 0; i < MAXNODES2; i++) {
		nodeArray[i].edgeHead = nullptr;
		nodeArray[i].data = nullptr;
		nodeArray[i].visited = false;
	}

}

//-------------------------- GraphL Destructor ------------------------------
// Deletes the adjacency list and make lsit into a node pointer. 
// Preconditions: the list not already empty
// Postconditions: the list should be empty at the end
//---------------------------------------------------------------------------
GraphL::~GraphL()
{
	//If the size is smaller than 1 we know that the adjacency lsit is already empty, no need to delete anything
	if (size > 0) {
		//use a for loop to traverse the array
		for (int i = 1; i < size + 1; i++) {
			//first I am going to empty the lists within the array
			//We will use temp to traverse our list within the array
			EdgeNode* temp = nodeArray[i].edgeHead;
			//while we are not at the end of the list
			while (temp != nullptr) {
				//Make the head of the lsit the next node do we can delete from the head (delete from beginning and insert from beginning)
				nodeArray[i].edgeHead = nodeArray[i].edgeHead->nextEdge;
				delete temp;
				temp = nullptr;
				temp = nodeArray[i].edgeHead;
			}

		}
	}
	else {
		return;
	}
}

//------------------------------ buildGraph -----------------------------------
// Build a graph given a file and using an adjacency list. Assign all information
// to our adjacency list.
// Preconditions: The size given is not 0 or negative
// Postconditions: A new graph is built and the adjacency list is filled with all
// the new graph information.
//-----------------------------------------------------------------------------
//CHECK**
void GraphL::buildGraph(ifstream& file)
{
	//line keeps track of the string in each line from the file
	string line; 
	//In part 2 of this assignment we don't have an distance for the edges of each graph so we only need from_node and to_node to represetnt the edges. 
	int from_node;
	int to_node;

	//The first line is going to be the size
	file >> size;
	//Once we get the size we have to check if it is valid. 
	if (size < 1) {
		return;
	}
	else {
		getline(file, line);

		//we get the nodeData since that is the second thing provided in our file
		for (int i = 1; i < size + 1; i++) {
			//create a temporary new NodeData so we can add it into our nodeArray as our data
			nodeArray[i].data = new NodeData();
			nodeArray[i].data->setData(file);
		}
		//while we are not done reading our file
		while (!file.eof()) {
			//The next thing in our file should be the list of from_node and to_node representing our edges
			file >> from_node >> to_node;

			//0 0 means we are done reading the nodes. 
			if ((from_node == 0) || (to_node == 0)) {
				break;
			}

			//Now w have everything we can start building/initiating everything in our graph
			//We are going to use temp to traverse through list in array and insert the data (just like in a linked list)
			//We are going to use the simplified process of insertin g the EdgeNodes at the beginning of the adjacency list
			EdgeNode* temp = new EdgeNode;

			//if the edge head is nullptr then we can just make the head node the new data
			if (nodeArray[from_node].edgeHead == nullptr) {
				//Same thing as inserting an element into list but we are inserting in the beginning. (e=dgeHead is the beginning our our list
				//and from_node represent the index in our array. 
				nodeArray[from_node].edgeHead = temp;
				nodeArray[from_node].edgeHead->nextEdge = nullptr;
				//the adjacent node is the to_node so we assign that
				temp->adjGraphNode = to_node;
			}
			//if the list is not empty then we have to traverse the list
			else {
				//move the pointer to the next node that is empty
				temp->nextEdge = nodeArray[from_node].edgeHead;
				//Now the head node should also be the new beginning of the list (since we are adding nodes at the beginning of the list)
				nodeArray[from_node].edgeHead = temp;
				//the adjacent node is the to_node so we assign that
				temp->adjGraphNode = to_node;
			}
		}
	}
}

//--------------------------- depthFirstSearch ------------------------------
// Depth First Search algorithm where is searches aggressively.
// Preconditions: The size given is not 0 or negative
// Postconditions: A depth first search path will be displayed
//---------------------------------------------------------------------------
void GraphL::depthFirstSearch()
{
	cout << "Depth-first ordering: ";
	
	//if the size is 0 or negative then do not search as it won't work
	if (size >= 1) {
		//for all the nodes 
		for (int i = 1; i < size + 1; i++) {
			recursiveDepthSearch(i);
		}
	}

	cout << endl;
}

//---------------------------- recursiveDepthSearch ----------------------------
// helps DepthFirstSearch the graph recursively. 
// Preconditions: The size given is not 0 or negative
// Postconditions: A depth first search path will be displayed
//-----------------------------------------------------------------------------
/*NOTE: Ignore this comment, this is for self reference only
*psuedocode given in class:
*where G is the graph and v is the vertices and u is the nodes adjacent to v
*DFS(G,v){
*	if(visited[v] = false){
*		visited[v] = true;
*		for each v->u 
*			DFS(G.u);
*		Append u to output
*	}
* }
*/
void GraphL::recursiveDepthSearch(int v)
{
	//u is going to hold all the adjacent nodes to our v
	int u = 0;
	//we are going to be using temp traverse list
	EdgeNode* temp = nodeArray[v].edgeHead;

	//if it has not been visited
	if (nodeArray[v].visited == false) {
		//if v is not visited then we can print it and mark it as visited
		nodeArray[v].visited = true;
		cout << v << " ";

		//use a while loop to traverse the list and it is not null (similar to traversing a linked list)
		while (temp != nullptr) {
			//u will equal to our data
			u = temp->adjGraphNode;
			//if we have not visited 
			if (nodeArray[u].visited == false) {
				recursiveDepthSearch(u);
			}
			//move to the next edge in the loop
			temp = temp->nextEdge;
		} //We will be out of our while loop if the list is done
	}
}

//------------------------------- displayGraph --------------------------------
// Displays the edges of the graph in an organized manner
// Preconditions: The size given is not 0 or negative
// Postconditions: The graph information is displayed.
//-----------------------------------------------------------------------------
void GraphL::displayGraph()
{
	//we are going to use num to keep track of where we are in the array, this would also represent the current node we are on
	int num = 1;

	//nothing to print if the size is smaller or equal to 0
	if (size < 1) {
		return;
	}
	cout << "Graph: " << endl;
	while (num != size + 1) {
		//Used to traverse the list of each node and print it out
		EdgeNode* temp = nodeArray[num].edgeHead;

		//Follwoing the format shown in the assignment we have to print the node we are on and the data of the node.
		cout << "Node " << num << "        " << *nodeArray[num].data << " " << endl;

		while (temp != nullptr) {
			cout << "  edge " << num << " " << temp->adjGraphNode << endl; //print the adjacent node
			temp = temp->nextEdge; //move to the next node in list
		}
		
		//Will move on to the next node once the first adjacency list is done traversing (all adjacency node to this node is printed)
		num = num + 1;
	}
}