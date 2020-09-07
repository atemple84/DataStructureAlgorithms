#include "HashMapLesson.h"

vector<int> removeDuplicatesHM(int* arr, int n)
{
    vector<int> output;
    unordered_map<int, bool> m;

    for (int i = 0; i < n; ++i)
    {
        if (m.find(arr[i]) == m.end())
        {
            output.push_back(arr[i]);
            m[arr[i]] = true;
        }
    }
    return output;
}

template <typename V>
V HashMap<V>::getValue(string key) const
{
    int bucketIndex = getBucketIndex(key);
    MapNode<V>* head = buckets[bucketIndex];
    while (head)
    {
        if (head->key == key)
            return head->value;

        head = head->next;
    }

    return 0;
}

template <typename V>
void HashMap<V>::insert(string key, V value)
{
    int bucketIndex = getBucketIndex(key);
    MapNode<V>* head = buckets[bucketIndex];
    while (head)
    {
        if (head->key == key)
        {
            head->value = value;
            return;
        }
        head = head->next;
    }

    MapNode<V>* node = new MapNode<V>(key, value);
    node->next = buckets[bucketIndex];
    buckets[bucketIndex] = node;
    ++count;

    double loadFactor = double(count) / numBuckets;
    if (loadFactor > 0.7)
        rehash();
}

template <typename V>
V HashMap<V>::remove(string key)
{
    int bucketIndex = getBucketIndex(key);
    MapNode<V>* head = buckets[bucketIndex];
    MapNode<V>* prev = nullptr;
    while (head)
    {
        if (head->key == key)
        {
            if (!prev)
                buckets[bucketIndex] = head->next;
            else
                prev->next = head->next;
            V value = head->value;
            head->next = nullptr;
            delete head;
            --count;
            return value;
        }
        prev = head;
        head = head->next;
    }

    return 0;
}

template <typename V>
int HashMap<V>::getBucketIndex(string key) const
{
    int hashcode = 0;
    int base = 1;
    int p = 37;
    for (int i = key.size() - 1; i >= 0; --i)
    {
        hashcode += +key[i] * base;
        base *= p;

        hashcode = hashcode % numBuckets;
        base = base % numBuckets;
    }

    return hashcode % numBuckets;
}

template<typename V>
void HashMap<V>::rehash()
{
    MapNode<V>** tmp = buckets;
    buckets = new MapNode<V>* [numBuckets * 2];
    for (int i = 0; i < numBuckets * 2; ++i)
        buckets[i] = nullptr;

    int oldBucketSize = numBuckets;
    numBuckets *= 2;
    count = 0;

    for (int i = 0; i < oldBucketSize; ++i)
    {
        MapNode<V>* head = tmp[i];
        while (head)
        {
            insert(head->key, head->value);
            head = head->next;
        }

        delete tmp[i];
    }

    delete []tmp;
}

template class HashMap<int>;
