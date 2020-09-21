#include <iostream>
#include <queue>

#include "GraphLesson.h"

vector<vector<int> > adjacencyMatrix()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int> > matrix(n, vector<int>(n, 0));

    for (int i = 1; i <= e; ++i)
    {
        int fv, sv;
        cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }

    return matrix;
}

void printGraphDFS(vector<vector<int> > graph, int sv, vector<bool>& visited)
{
    cout << sv << endl;
    visited[sv] = true;
    int n = graph.size();
    for (int i = 0; i < n; ++i)
    {
        if (graph[sv][i] == 1 && visited[i] == false)
        {
            printGraphDFS(graph, i, visited);
        }
    }
}

void printGraphBFS(vector<vector<int> > graph, int sv, vector<bool>& visited)
{
    queue<int> children;
    children.push(sv);
    visited[sv] = true;
    while (!children.empty())
    {
        int front = children.front();
        children.pop();

        cout << front << endl;
        for (int i = 0; i < graph.size(); ++i)
        {
            if (graph[front][i] && !visited[i])
            {
                children.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(vector<vector<int> > matrix)
{
    vector<bool> visited(matrix.size(), false);
    for (int i = 0; i < matrix.size(); ++i)
    {
        if (!visited[i])
        {
            printGraphDFS(matrix, i, visited);
        }
    }
}

void BFS(vector<vector<int> > matrix)
{
    vector<bool> visited(matrix.size(), false);
    for (int i = 0; i < matrix.size(); ++i)
    {
        if (!visited[i])
        {
            printGraphBFS(matrix, i, visited);
        }
    }
}

int ComponentCountDFS(vector<vector<int>> matrix)
{
    int count = 0;
    vector<bool> visited(matrix.size(), false);
    for (int i = 0; i < matrix.size(); ++i)
    {
        if (!visited[i])
        {
            ++count;
            printGraphDFS(matrix, i, visited);
        }
    }

    return count;
}

int ComponentCountBFS(vector<vector<int>> matrix)
{
    int count = 0;
    vector<bool> visited(matrix.size(), false);
    for (int i = 0; i < matrix.size(); ++i)
    {
        if (!visited[i])
        {
            ++count;
            printGraphBFS(matrix, i, visited);
        }
    }

    return count;
}
