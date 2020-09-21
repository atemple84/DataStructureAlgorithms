#pragma once
#include <vector>

using namespace std;

vector<vector<int> > adjacencyMatrix();
void printGraphDFS(vector<vector<int> > graph, int sv, vector<bool>& visited);
void printGraphBFS(vector<vector<int> > graph, int sv, vector<bool>& visited);
void DFS(vector<vector<int> > matrix);
void BFS(vector<vector<int> > matrix);
int ComponentCountDFS(vector<vector<int> > matrix);
int ComponentCountBFS(vector<vector<int> > matrix);
