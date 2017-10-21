#pragma once
#include <stdio.h>
#include <tchar.h>
#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <Windows.h>
#include <vector>

using namespace std;



class Graph
{
private:
	int N;
	int **matrix;
	
public:
	Graph(string fileName);
	~Graph();
	void printGraph();


};

