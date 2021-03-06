#include "Graph.h"
#include <vector>


int numOfCities;
Graph::Graph(string fileName)
{
	ifstream file;
	string temp;
	file.open(fileName.c_str());

	if (file.is_open()) {

		do {
			file >> temp;
		} while (strcmp(temp.c_str(), "DIMENSION:") && strcmp(temp.c_str(), "DIMENSION"));
		file >> temp;
		if (!strcmp(temp.c_str(), ":"))
			file >> this->N;
		else {
			this->N = stoi(temp);
		}

		do {
			file >> temp;
		} while (strcmp(temp.c_str(), "EDGE_WEIGHT_SECTION"));

		numOfCities = N;
		this->matrix = new int*[N];
		for (int i = 0; i < N; i++) {
			matrix[i] = new int[N];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				file >> matrix[i][j];

				if (i == j) matrix[i][j] = -1;
				if (matrix[i][j] >= 9999 || matrix[i][j] == 0) matrix[i][j] = -1;
			}
		}
	}
	else {
		cout << "Error occured during loading from file\nFile was probably not found.";
	}
	//cout << "File loaded to matrix" << endl;
}


Graph::~Graph() {
	for (int i = 0; i < N; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Graph::printGraph() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout.width(4);
			cout.fill(' ');
			cout << matrix[i][j];
		}
		cout << endl;
	}
}
struct Node {
	vector<pair<int, int>> path;

	// stores the reduced matrix
	int reducedMatrix[numOfCities][numOfCities];

	// stores the lower bound
	int cost;

	//stores current city number
	int vertex;

	// stores number of cities visited so far
	int level;
};





