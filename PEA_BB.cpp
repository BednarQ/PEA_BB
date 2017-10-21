// PEA_TSP_BB.cpp : Defines the entry point for the console application.
//

#include "Graph.h"
#include <vector>



int main()
{
	string fileName;
	cout << "Provide file name to load graph:" << endl;
	cin >> fileName;

	Graph *g = new Graph(fileName);
	g ->printGraph();


	cin.ignore();
	cin.get();
	return 0;
}

