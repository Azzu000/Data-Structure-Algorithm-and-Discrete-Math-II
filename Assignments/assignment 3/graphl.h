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
#pragma once

#ifndef GRAPHL_H_
#define GRAPHL_H_
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include "nodedata.h"
#include <climits>

using namespace std;
const int MAXNODES2 = 100; //The maximum amount of nodes you can have

class GraphL
{
public:
	GraphL();
	~GraphL();

	void buildGraph(ifstream& file);
	void displayGraph();
	void depthFirstSearch();

private:
	struct EdgeNode; //forward reference for the compiler
	struct GraphNode { 
		EdgeNode* edgeHead; //head of the list of edges
		NodeData* data; //data information about each node
		bool visited;
	};

	struct EdgeNode {
		int adjGraphNode; //subscript of the adjacent graph node
		EdgeNode* nextEdge;
	};

	int size; //used to keep track of the size of our graph
	GraphNode nodeArray[MAXNODES2]; //the graphnode array

	void recursiveDepthSearch(int v); //This is our recursive helper to do our DFS search
};
#endif
