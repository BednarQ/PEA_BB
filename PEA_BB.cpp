// PEA_TSP_BB.cpp : Defines the entry point for the console application.
//

#include "Graph.h"

using namespace std;

int main()
{
	string fileName;
	cout << "Provide file name to load graph" << endl;
	cin >> fileName;

	Graph *g = new Graph(fileName);
	g ->printGraph();


	system("PAUSE");
	return 0;
}

