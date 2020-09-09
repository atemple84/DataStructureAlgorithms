#pragma once
#include <vector>

using namespace std;

class PriorityQueue
{
public:
    vector<int> pq;

    PriorityQueue() {}

    bool isEmpty();
    int getSize();
    int getMin();
    void insert(int element);
    int RemoveMin();
};

void inplaceHeapSort(int* input, int n);
void kSortedArray(int* input, int n, int k);
void ksmallest(int* a, int n, int k);
