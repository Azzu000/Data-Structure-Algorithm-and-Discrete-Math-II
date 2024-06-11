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

#pragma once
#include "nodedata.h"
#ifndef GRAPHM_H_
#define GRAPHM_H_
#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include <climits>

using namespace std;

const int MAXNODES = 100; //The maximum amount of nodes you can have

class GraphM
{
public:
	//Constructor and Destructors
	GraphM(); //No-Args constructor 

	//All other actions
	void buildGraph(ifstream& file); //builds up graph node information and adjacency matrix of edges between each node reading from a data file
	bool insertEdge(int from_node, int to_node, int distance); //insert an edge into graph betweent wo given nodes, return true if edge is successfully inserted and false otherwise
	bool removeEdge(int from_node, int to_node); //remove an edge between two given nodes, return true if edge is successfully inserted and false otherwise
	void findShortestPath(); //find the shortest path between every node to every other node in the graph
	void displayAll(); //displays all data
	void display(int from_node, int to_node); //display shortest path with path info between the fromNode to toNode


private:
	struct TableType {
		bool visited; //whether node has been visited
		int dist; //shortest distance from source known so far
		int path; //previous node in path of min dist
	};

	NodeData data[MAXNODES]; //data for graph nodes
	int C[MAXNODES][MAXNODES]; //Cost array, the adjacency matrix
	int size; //number of nodes in the graph
	TableType T[MAXNODES][MAXNODES]; //stores visited, distrance, path
	void recursiveDisplayPath(int from_node, int to_node); //This is a recursive helper class that helps recursively display the path. display and displayAll both uses this helper class
	void recursiveDisplayData(int from_node, int to_node); //This is a recursive helper calss to help recursively display the data
};
#endif