#pragma once

#include <unordered_map>

using namespace std;

vector<int> removeDuplicatesHM(int* arr, int n);

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode* next;

    MapNode(string inKey, V inValue) : key(inKey), value(inValue), next(nullptr) {}
    virtual ~MapNode() { delete next; }
};

template <typename V>
class HashMap
{
private:
    MapNode<V>** buckets;
    int count;
    int numBuckets;

public:
    HashMap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>* [numBuckets];
        for (int i = 0; i < numBuckets; ++i)
            buckets[i] = nullptr;
    }
    virtual ~HashMap()
    {
        for (int i = 0; i < numBuckets; ++i)
            delete buckets[i];
        delete [] buckets;
    }

    int size() { return count; }
    V getValue(string key) const;
    void insert(string key, V value);
    V remove(string key);
    double getLoadFactor() { return double(count) / numBuckets; }

private:
    int getBucketIndex(string key) const;
    void rehash();
};
