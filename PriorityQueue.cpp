#include "PriorityQueue.h"

#include <queue>
#include <iostream>

bool PriorityQueue::isEmpty()
{
    return pq.empty();
}

int PriorityQueue::getSize()
{
    return pq.size();
}

int PriorityQueue::getMin()
{
    if (isEmpty())
        return 0;
    return pq[0];
}

void PriorityQueue::insert(int element)
{
    pq.push_back(element);
    int ci = pq.size() - 1;

    while (ci > 0)
    {
        int pi = (ci - 1) / 2;
        if (pq[ci] < pq[pi])
        {
            swap(pq[ci], pq[pi]);
            ci = pi;
        }
        else
            break;
    }
}

int PriorityQueue::RemoveMin()
{
    if (isEmpty()) return 0;
    int pi = 0;
    int ans = pq[pi];
    swap(pq[pq.size() - 1], pq[pi]);
    pq.pop_back();

    while (pi < pq.size() - 1)
    {
        int leftI = (pi * 2) + 1;
        int rightI = (pi * 2) + 2;
        int minIndex = pi;

        if (leftI >= pq.size())
            break;
        if (pq[leftI] < pq[minIndex])
            minIndex = leftI;
        if (rightI < pq.size() && pq[rightI] < pq[minIndex])
            minIndex = rightI;

        if (minIndex == pi)
            break;

        swap(pq[pi], pq[minIndex]);
        pi = minIndex;
    }

    return ans;
}

void inplaceHeapSort(int* input, int n)
{
    // Build heap
    for (int i = 1; i < n; ++i)
    {
        int ci = i;

        while (ci > 0)
        {
            int pi = (ci - 1) / 2;
            if (input[ci] < input[pi])
            {
                swap(input[ci], input[pi]);
                ci = pi;
            }
            else
                break;
        }
    }

    // Remove min n times
    int size = n;
    while (size >= 1)
    {
        int pi = 0;
        swap(input[--size], input[pi]);
        while (pi < size)
        {
            int leftI = (pi * 2) + 1;
            int rightI = (pi * 2) + 2;
            int minIndex = pi;

            if (leftI >= size)
                break;
            if (input[leftI] < input[minIndex])
                minIndex = leftI;
            if (rightI < size && input[rightI] < input[minIndex])
                minIndex = rightI;

            if (minIndex == pi)
                break;

            swap(input[pi], input[minIndex]);
            pi = minIndex;
        }
    }
}

void kSortedArray(int* input, int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; ++i)
        pq.push(input[i]);

    int s = 0;
    for (int i = k; i < n; ++i)
    {
        input[s] = pq.top();
        pq.pop();
        ++s;
        pq.push(input[i]);
    }

    while (!pq.empty())
    {
        input[s] = pq.top();
        pq.pop();
        ++s;
    }
}

void ksmallest(int* a, int n, int k)
{
    priority_queue<int> pq;
    /*
    for (int i = 0; i < k; ++i)
        pq.push(a[i]);

    for (int i = k; i < n; ++i)
    {
        if (a[i] < pq.top())
        {
            pq.pop();
            pq.push(a[i]);
        }
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    */

    for (int i = 0; i < n; ++i)
    {
        pq.push(a[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
