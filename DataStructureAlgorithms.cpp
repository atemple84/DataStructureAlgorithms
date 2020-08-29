// DataStructureAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <unordered_map>
#include <stack>
#include <queue>

#include "BinarySortTree.h"

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SumOfArrays(vector<int> array)
{
    int sum = 0;
    for (auto val : array)
    {
        sum += val;
    }

    cout << sum << endl;
}

void LargestNum(vector<int> array)
{
    int largestNum = INT_MIN;
    int smallestNum = INT_MAX;
    for (auto val : array)
    {
        if (val > largestNum)
            largestNum = val;

        if (val > smallestNum)
            smallestNum = val;
    }

    cout << largestNum << endl;
    cout << smallestNum << endl;
}

void ReverseArray(vector<int> array)
{
    int i = 0;
    int j = array.size() - 1;
    while (i < j)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        ++i;
        --j;
    }

    for (auto num : array)
    {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> SpiralOrder(vector<vector<int> > matrix)
{
    vector<int> ret;

    if (matrix.empty() || matrix[0].empty())
        return ret;
    int sr = 0;
    int er = matrix.size() - 1;
    int sc = 0;
    int ec = matrix[0].size() - 1;

    int matrixSize = er * ec;
    int spiralCount = 0;

    while (sr < er && sc < ec)
    {
        for (int i = sc; i <= ec; ++i)
        {
            ret.push_back(matrix[sr][i]);
            ++spiralCount;
        }

        ++sr;
        if (spiralCount == matrixSize)
        {
            return ret;
        }

        for (int i = sr; i <= er; ++i)
        {
            ret.push_back(matrix[i][ec]);
            ++spiralCount;
        }
        --ec;
        if (spiralCount == matrixSize)
        {
            return ret;
        }

        for (int i = ec; i >= sc; --i)
        {
            ret.push_back(matrix[er][i]);
            ++spiralCount;
        }
        --er;
        if (spiralCount == matrixSize)
        {
            return ret;
        }

        for (int i = er; i >= sr; --i)
        {
            ret.push_back(matrix[i][sc]);
            ++spiralCount;
        }
        ++sc;
    }

    return ret;
}

void selectionSort(vector<int> a, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int smallest = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[smallest])
            {
                smallest = j;
            }
        }

        swap(a[i], a[smallest]);
    }
}

vector<int> bubbleSort(vector<int> a, int n)
{
    for (int count = 1; count < n; ++count)
    {
        bool sorted = true;
        for (int i = 0; i < n - 1; ++i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                sorted = false;
            }
        }

        if (sorted)
            break;
    }

    return a;
}

int BinarySearch(vector<int> a, int val)
{
    vector<int> sorted = bubbleSort(a, a.size());
    int n = sorted.size() - 1;
    int i = 0;

    while (i <= n)
    {
        int mid = i + (n - i) / 2;

        if (sorted[mid] == val)
        {
            return mid;
        }
        else if (sorted[mid] > val)
        {
            n = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }

    return -1;
}

int BinarySearch(vector<int> a, int i, int n, int val)
{
    if (i > n)
        return -1;

    int mid = i + (n - i) / 2;

    if (a[mid] == val)
    {
        return mid;
    }
    else if (a[mid] > val)
    {
        return BinarySearch(a, i, mid - 1, val);
    }
    else
    {
        return BinarySearch(a, mid + 1, n, val);
    }
}

int Fibonacci(int index)
{
    // base
    if (index == 0)
        return 0;
    else if (index == 1)
        return 1;

    int fib = Fibonacci(index - 1);
    int fib2 = Fibonacci(index - 2);

    return fib2 + fib;
}

int Power(int val, int power)
{
    if (power == 0)
        return 1;

    int pow = Power(val, power - 1);

    return val * pow;
}

void printNums(vector<int> a, int n)
{
    if (n == 0)
    {
        cout << a[0] << endl;
        return;
    }

    printNums(a, n - 1);

    cout << a[n] << endl;
}

void printNums2(vector<int> a, int n)
{
    if (n == 0)
    {
        cout << a[0] << endl;
        return;
    }

    cout << a[n] << endl;

    printNums2(a, n - 1);
}

int Multiply(int m, int n)
{
    if (n == 0)
        return 0;

    int mult = Multiply(m, n - 1);

    return mult + m;
}

int CountZeros(int n)
{
    if (n == 0)
        return 0;

    int count = CountZeros(n / 10);

    int lastDigit = n % 10;
    if (lastDigit == 0)
        return count + 1;
    else
        return count;
}

double GeoSum(int k)
{
    if (k == 0)
        return 1;

    double smallAnsw = GeoSum(k - 1);

    return smallAnsw + 1.0 / pow(2, k);
}

bool checkSortedArray(vector<int> a, int n)
{
    if (n == 0 || n == 1)
        return true;

    bool smallerSorted = checkSortedArray(a, n - 1);

    return smallerSorted && a[n - 2] < a[n - 1];
}

int SumOfArray(vector<int> a, int n)
{
    if (n == 0)
        return 0;

    return a[n - 1] + SumOfArray(a, n - 1);
}

int firstIndex(vector<int> a, int i, int x)
{
    int n = a.size();
    if (i == n)
        return -1;

    if (x == a[i])
        return i;

    return firstIndex(a, i + 1, x);
}

int lastIndex(vector<int> a, int i, int x)
{
    if (i < 0)
        return -1;

    if (x == a[i])
        return i;

    return lastIndex(a, i - 1, x);
}

void count(vector<int> a, int x, int i, int& ans)
{
    if (i == a.size())
        return;

    if (a[i] == x)
        ++ans;

    count(a, x, i + 1, ans);
}

int count(vector<int> a, int x, int i)
{
    if (i == a.size())
        return 0;

    if (a[i] == x)
        return 1 + count(a, x, i + 1);
    else
        return count(a, x, i + 1);
}

bool palindrome(string str, int i, int n)
{
    if (i > n)
        return true;

    if (str[i] == str[n])
        return palindrome(str, i + 1, n - 1);
    else
        return false;
}

void printCharArray(char input[])
{
    if (input[0] == '\0')
        return;

    cout << input[0];
    printCharArray(input + 1);
}

int length(char input[])
{
    if (input[0] == '\0')
        return 0;

    return 1 + length(input + 1);
}

void removeConsecDupes(char input[])
{
    if (input[1] == '\0' || input[0] == '\0')
        return;

    if (input[0] != input[1])
        removeConsecDupes(input + 1);
    else
    {
        for (int i = 0; input[i] != '\0'; ++i)
        {
            input[i] = input[i + 1];
        }

        removeConsecDupes(input);
    }
}

void printSubs(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    printSubs(input.substr(1), output + input[0]);
    printSubs(input.substr(1), output);
}

int convertStringToInt(char str[], int n)
{
    if (n == 0)
        return 0;

    int smallAns = convertStringToInt(str, n - 1);
    int lastDigit = str[n - 1] - '0';
    return smallAns * 10 + lastDigit;
}

void printPermutations(char input[], int i)
{
    if (input[i] == '\0')
    {
        cout << input << endl;
        return;
    }

    for (int j = i; j < input[j] != '\0'; ++j)
    {
        char tmp = input[i];
        input[i] = input[j];
        input[j] = tmp;
        printPermutations(input, i + 1);
        tmp = input[i];
        input[i] = input[j];
        input[j] = tmp;
    }
}

int staircase(int n)
{
    if (n == 0 || n == 1)
        return 1;

    if (n < 0)
        return 0;

    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}

int TowerOfHanoi(int n)
{
    if (n == 0)
        return 0;

    return TowerOfHanoi(n - 1) + 1 + TowerOfHanoi(n - 1);
}

void printTOHSteps(int n, char s, char d, char h)
{
    if (n == 0)
        return;

    printTOHSteps(n - 1, s, h, d);
    cout << "Moving " << n << " from " << s << " to " << d << endl;
    printTOHSteps(n - 1, h, d, s);
}

void mergeSort(vector<int>& a)
{
    if (a.size() <= 1)
        return;

    int halfPoint = a.size() / 2;
    vector<int> firstHalf(a.begin(), a.begin() + halfPoint);
    vector<int> secondHalf(a.begin() + halfPoint, a.end());
    mergeSort(firstHalf);
    mergeSort(secondHalf);

    int j = 0, k = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (k == secondHalf.size())
        {
            a[i] = firstHalf[j];
            ++j;
        }
        else if (j == firstHalf.size() || firstHalf[j] > secondHalf[k])
        {
            a[i] = secondHalf[k];
            ++k;
        }
        else
        {
            a[i] = firstHalf[j];
            ++j;
        }
    }
}

int partition(vector<int>& a, int s, int e)
{
    int pivot = s;
    for (int i = s; i < e; ++i)
    {
        if (a[i] < a[e])
            ++pivot;
    }

    swap(a[e], a[pivot]);

    int i = s;
    int j = e;
    while (i <= pivot && pivot <= j)
    {
        if (a[i] < a[pivot])
        {
            ++i;
            continue;
        }
        if (a[j] > a[pivot])
        {
            --j;
            continue;
        }
        swap(a[j], a[i]);

        ++i;
        --j;
    }

    return pivot;
}

void quickSort(vector<int>& a, int s, int e)
{
    if (s >= e)
        return;

    // partition
    int p = partition(a, s, e);
    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e);
}

int binaryFirstOrLast(vector<int>& nums, int target, bool findFirst = true)
{
    int ret = -1;
    if (nums.empty())
        return ret;

    int s = 0;
    int e = nums.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target)
        {
            ret = mid;
            if (findFirst)
                e = mid - 1;
            else
                s = mid + 1;
        }
        else if (nums[mid] < target)
            s = mid + 1;
        else
            e = mid - 1;
    }

    return ret;
}

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> ret(2, -1);
    ret[0] = binaryFirstOrLast(nums, target);
    if (ret[0] == -1)
        return ret;
    ret[1] = binaryFirstOrLast(nums, target, false);
    return ret;
}

int binaryHalfSearch(vector<int> nums, int target, int s, int e)
{
    if (s > e)
        return -1;

    int mid = s + (e - s) / 2;
    if (nums[mid] == target)
        return mid;
    if (nums[s] <= nums[mid])
    {
        if (target >= nums[s] && target <= nums[mid])
            return binaryHalfSearch(nums, target, s, mid - 1);
        else
            return binaryHalfSearch(nums, target, mid + 1, e);
    }
    else
    {
        if (target <= nums[e] && target >= nums[mid])
            return binaryHalfSearch(nums, target, mid + 1, e);
        else
            return binaryHalfSearch(nums, target, s, mid - 1);
    }
}

int searchRotated(vector<int>& nums, int target)
{
    return binaryHalfSearch(nums, target, 0, nums.size() - 1);
}

int majorityElement(vector<int>& nums)
{
    int cand = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); ++i)
    {
        if (cand == nums[i])
            ++count;
        else
        {
            --count;
            if (count == 0)
            {
                cand = nums[i];
                count = 1;
            }
        }
    }

    return cand;
    /*
    unordered_map<int, int> numCount;
    int majorityCount = nums.size() / 2;
    for (auto num : nums)
    {
        numCount[num]++;
        if (numCount[num] > majorityCount)
            return num;
    }

    return nums[0];
    */
}

template<typename T>
class Node
{
public:
    Node(T d) : data(d), next(NULL) {}
    T data;
    Node* next;
};

class Node2
{
public:
    Node2(int d) : data(d), next(NULL), prev(NULL) {}
    int data;
    Node<int>* next;
    Node<int>* prev;
};

void printLL(Node<int>* head)
{
    Node<int>* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteLL(Node<int>*& head)
{
    Node<int>* temp = head;
    while (temp != NULL)
    {
        Node<int>* next = temp->next;
        delete temp;
        temp = next;
    }
    head = temp;
}

Node<int>* takeInputNode(bool atHead = false)
{
    int data;
    cin >> data;
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    while (data != -1)
    {
        Node<int>* n = new Node<int>(data);
        if (!head)
        {
            head = n;
            tail = n;
        }
        else
        {
            if (atHead)
            {
                n->next = head;
                head = n;
            }
            else
            {
                tail->next = n;
                tail = n;
            }
        }
        cin >> data;
    }
    return head;
}

template<typename T>
int lengthLL(Node<T>* head)
{
    Node<T>* temp = head;
    int count = 0;
    while (temp)
    {
        ++count;
        temp = temp->next;
    }

    return count;
}

int NodeAt(Node<int>* head, int i)
{
    Node<int>* temp = head;
    int val = -1;
    int count = i;
    while (temp && count >= 0)
    {
        --count;
        if (count < 0)
            val = temp->data;
        temp = temp->next;
    }

    return val;
}

void InsertNodeAt(Node<int>*& head, int i, int val)
{
    Node<int>* temp = head;
    int count = i;
    Node<int>* prev = NULL;

    if (!temp)
    {
        head = new Node<int>(val);
        return;
    }

    while (temp && count >= 0)
    {
        --count;
        if (count < 0)
        {
            Node<int>* n = new Node<int>(val);
            if (!prev)
                head = n;
            else
                prev->next = n;
            n->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    // Insert at tail
    if (count == 0)
    {
        Node<int>* n = new Node<int>(val);
        if (!prev)
            head = n;
        else
            prev->next = n;
        n->next = temp;
    }
}

void DeleteNode(Node<int>*& head, int i)
{
    Node<int>* temp = head;
    int count = i;
    Node<int>* prev = NULL;

    if (!temp)
        return;

    while (temp)
    {
        --count;
        if (count < 0)
        {
            Node<int>* next = temp->next;
            if (!prev)
                head = next;
            else
                prev->next = next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

int LengthLLRecurse(Node<int>* head)
{
    if (!head)
        return 0;
    return 1 + LengthLLRecurse(head->next);
}

bool isPresentInLL(Node<int>* head, int val)
{
    if (!head)
        return false;

    if (head->data == val)
        return true;
    return isPresentInLL(head->next, val);
}

bool isPresentInLL2(Node<int>* head, int val)
{
    Node<int>* temp = head;
    while (temp)
    {
        if (val == temp->data)
            return true;
        temp = temp->next;
    }

    return false;
}

Node<int>* middleNode(Node<int>* head)
{
    if (!head)
        return head;
    Node<int>* slow = head;
    Node<int>* fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast)
        return slow->next;
    return slow;
}
// 1 2 3
Node<int>* reverseLL(Node<int>* head)
{
    Node<int>* prev = NULL;
    Node<int>* cur = head;

    while (cur)
    {
        Node<int>* n = cur->next;
        cur->next = prev;
        prev = cur;
        cur = n;
    }

    return prev;
}

Node<int>* removeNthFromEnd(Node<int>* head, int n)
{
    Node<int>* end = head;
    Node<int>* k = head;

    for (int i = 0; i < n; ++i)
    {
        end = end->next;
    }

    if (!end)
    {
        head = k->next;
        delete k;
        return head;
    }

    while (end && end->next)
    {
        end = end->next;
        k = k->next;
    }

    Node<int>* next = k->next->next;
    delete k->next;
    k->next = next;

    return head;
}

Node<int>* mergeTwoLists(Node<int>* l1, Node<int>* l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    Node<int>* head = NULL;
    if (l1->data < l2->data)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }

    Node<int>* current = head;
    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            current->next = l1;
            l1 = l1->next;
        }
        else
        {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    if (!l1)
        current->next = l2;

    else
        current->next = l1;

    return head;
}

Node<int>* mergeTwoListsR(Node<int>* l1, Node<int>* l2)
{
    if (!l1 && !l2)
        return NULL;

    else if (!l1)
        return l2;
    else if (!l2)
        return l1;

    Node<int>* head = NULL;
    if (l1->data < l2->data)
    {
        head = l1;
        head->next = mergeTwoListsR(l1->next, l2);
    }
    else
    {
        head = l2;
        head->next = mergeTwoListsR(l1, l2->next);
    }

    return head;
}

Node<int>* sortList(Node<int>* head)
{
    if (!head || !head->next)
        return head;

    Node<int>* slow = head;
    Node<int>* fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node<int>* n = slow->next;
    slow->next = NULL;
    Node<int>* leftHalf = sortList(head);
    Node<int>* rightHalf = sortList(n);

    if (leftHalf->data < rightHalf->data)
    {
        head = leftHalf;
        leftHalf = leftHalf->next;
    }
    else
    {
        head = rightHalf;
        rightHalf = rightHalf->next;
    }

    Node<int>* current = head;
    while (leftHalf && rightHalf)
    {
        if (leftHalf->data < rightHalf->data)
        {
            current->next = leftHalf;
            leftHalf = leftHalf->next;
        }
        else
        {
            current->next = rightHalf;
            rightHalf = rightHalf->next;
        }
        current = current->next;
    }

    if (!leftHalf)
        current->next = rightHalf;
    else
        current->next = leftHalf;

    return head;
}

int JosephusCircle(int m, int n)
{
    Node<int>* head = new Node<int>(1);
    Node<int>* prev = head;
    for (int i = 2; i <= n; ++i)
    {
        prev->next = new Node<int>(i);
        prev = prev->next;
    }

    prev->next = head;

    Node<int>* p1 = head;
    Node<int>* p2 = head;
    while (p1->next != p1)
    {
        int count = m;
        for (int i = 1; i < m; ++i)
        {
            p2 = p1;
            p1 = p1->next;
        }

        p2->next = p1->next;
        delete p1;
        p1 = p2->next;
    }

    return p1->data;
}

template<typename T>
class StackLL
{
    Node<T>* head;
    int mySize;
public:
    StackLL() : mySize(0), head(NULL) {}
    int size() const { return mySize; }
    bool isEmpty() const { return mySize == 0; }

    void push(const T ele)
    {
        Node<T>* newHead = new Node<T>(ele);
        newHead->next = head;
        head = newHead;
        ++mySize;
    }

    void pop()
    {
        if (isEmpty())
            return;
        Node<T>* next = head->next;
        delete head;
        head = next;
        --mySize;
    }

    T top() const
    {
        if (!head)
            return 0;
        return head->data;
    }
};

int evalRPN(vector<string>& tokens)
{
    stack<int> nums;
    for (auto token : tokens)
    {
        if (token == "+" ||
            token == "-" ||
            token == "*" ||
            token == "/")
        {
            int bottom = nums.top();
            nums.pop();
            int top = nums.top();
            nums.pop();
            if (token == "+")
                nums.push(top + bottom);
            else if (token == "-")
                nums.push(top - bottom);
            else if (token == "*")
                nums.push(top * bottom);
            else if (token == "/")
                nums.push(top / bottom);
        }
        else
            nums.push(atoi(token.c_str()));
    }

    return nums.top();
}

string removeDuplicates(string S)
{
    stack<char> st;
    for (auto c : S)
    {
        if (st.empty() || c != st.top())
            st.push(c);
        else
            st.pop();
    }

    string ret(st.size(), 'x');
    int count = st.size() - 1;
    while (!st.empty())
    {
        ret[count] = st.top();
        st.pop();
        --count;
    }

    return ret;
}

template<typename T>
class TreeNode2
{
public:
    T data;
    vector<TreeNode2*> children;

    TreeNode2(T d) : data(d) {}
    virtual ~TreeNode2()
    {
        for (int i = 0; i < children.size(); ++i)
        {
            delete children[i];
            children[i] = NULL;
        }
        children.clear();
    }
};

template<typename T>
void deleteTree(TreeNode2<T>*& root)
{
    if (!root)
        return;

    for (auto child : root->children)
        deleteTree(child);
    root->children.clear();

    delete root;
    root = NULL;
}

template<typename T>
void printTree(TreeNode2<T>* root)
{
    if (!root)
        return;
    cout << root->data << ": ";
    for (auto node : root->children)
        cout << node->data << ", ";
    cout << endl;

    for (auto node : root->children)
        printTree(node);
}

TreeNode2<int>* takeInputLvl()
{
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    TreeNode2<int>* root = new TreeNode2<int>(rootData);
    queue<TreeNode2<int>*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode2<int>* front = q.front();
        q.pop();

        cout << "Enter num of children of " << front->data << ": ";
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i)
        {
            cout << "Enter child " << i << " of parent " << front->data << ": ";
            int childData;
            cin >> childData;
            TreeNode2<int>* child = new TreeNode2<int>(childData);
            front->children.push_back(child);
            q.push(child);
        }
    }
    cout << endl;

    return root;
}

TreeNode2<int>* takeInput()
{
    int rootData;
    cout << "Enter data: ";
    cin >> rootData;
    TreeNode2<int>* root = new TreeNode2<int>(rootData);
    int n;
    cout << "Enter number of children of " << rootData << ": ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        root->children.push_back(takeInput());
    }

    return root;
}

template<typename T>
void printTreeLvl(TreeNode2<T>* root)
{
    if (!root)
        return;

    queue<TreeNode2<T>*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode2<T>* front = q.front();
        q.pop();

        cout << front->data << ": ";
        for (auto node : front->children)
        {
            cout << node->data << ", ";
            q.push(node);
        }
        cout << endl;
    }
}

int countTreeNodes(TreeNode2<int>* root)
{
    if (!root)
        return 0;

    int count = 1;
    for (auto child : root->children)
    {
        count += countTreeNodes(child);
    }

    return count;
}

int heightOfTree(TreeNode2<int>* root)
{
    if (!root)
        return 0;

    int maxHeight = 0;
    for (auto child : root->children)
    {
        maxHeight = max(heightOfTree(child), maxHeight);
    }

    return maxHeight + 1;
}

void depthOfNode(TreeNode2<int>* root, int k)
{
    if (!root)
        return;

    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    for (auto child : root->children)
    {
        depthOfNode(child, k - 1);
    }
}

int countLeafNodes(TreeNode2<int>* root)
{
    if (!root)
        return 0;

    if (root->children.empty())
        return 1;

    int childLeafNodes = 0;
    for (auto child : root->children)
    {
        childLeafNodes += countLeafNodes(child);
    }
    return childLeafNodes;
}

void preOrder(TreeNode2<int>* root)
{
    if (!root)
        return;

    cout << root->data << " ";
    for (auto child : root->children)
    {
        preOrder(child);
    }
}

void postOrder(TreeNode2<int>* root)
{
    if (!root)
        return;

    for (auto child : root->children)
        postOrder(child);

    cout << root->data << " ";
}

/// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

template<typename T>
class BTNode
{
public:
    T data;
    BTNode* left;
    BTNode* right;

    BTNode(T data) : data(data), left(NULL), right(NULL) {}
    virtual ~BTNode()
    {
        delete left;
        delete right;
    }
};

template<typename T>
void printBTree(BTNode<T>* root)
{
    if (!root)
        return;

    cout << root->data << ": ";
    if (root->left)
        cout << "L" << root->left->data;

    if (root->right)
        cout << "R" << root->right->data;
    cout << endl;
    printBTree(root->left);
    printBTree(root->right);
}

template<typename T>
BTNode<T>* takeInputBTree()
{
    cout << "Enter data:" << endl;
    T data;
    cin >> data;
    if (data == -1)
        return NULL;

    BTNode<T>* root = new BTNode<T>(data);
    root->left = takeInputBTree<T>();
    root->right = takeInputBTree<T>();

    return root;
}

BTNode<int>* takeInputBTTreeLevel()
{
    cout << "Enter data:" << endl;
    int data;
    cin >> data;
    if (data == -1)
        return NULL;

    BTNode<int>* root = new BTNode<int>(data);
    queue<BTNode<int>*> q;
    q.push(root);

    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        cout << "Enter left:" << endl;
        cin >> data;
        if (data != -1)
        {
            BTNode<int>* left = new BTNode<int>(data);
            top->left = left;
            q.push(left);
        }

        cout << "Enter right:" << endl;
        cin >> data;
        if (data != -1)
        {
            BTNode<int>* right = new BTNode<int>(data);
            top->right = right;
            q.push(right);
        }
    }

    return root;
}

vector<vector<int>> levelOrder(BTNode<int>* root)
{
    vector<vector<int>> ret;
    if (!root)
        return ret;

    queue<BTNode<int>*> q;
    q.push(root);
    q.push(NULL);

    ret.push_back(vector<int>());
    int i = 0;
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        if (!top)
        {
            if (!q.empty())
            {
                ret.push_back(vector<int>());
                ++i;
                q.push(NULL);
            }
            continue;
        }

        ret[i].push_back(top->data);
        if (top->left)
            q.push(top->left);
        if (top->right)
            q.push(top->right);
    }

    return ret;
}

void levelOrderTraverse(BTNode<int>* root)
{
    if (!root)
        return;

    queue<BTNode<int>*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        if (!top)
        {
            if (!q.empty())
                q.push(NULL);
            continue;
        }

        cout << top->data << " ";
        if (top->left)
            q.push(top->left);
        if (top->right)
            q.push(top->right);
    }
}

int countNodes(BTNode<int>* root)
{
    if (!root)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inOrder(BTNode<int>* root, vector<int>& ans)
{
    if (!root)
        return;
    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

vector<int> inorderTraversal(BTNode<int>* root)
{
    vector<int> ret;
    inOrder(root, ret);
    return ret;
}

void preorder(BTNode<int>* root, vector<int>& ans)
{
    if (!root)
        return;

    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

vector<int> preorderTraversal(BTNode<int>* root)
{
    vector<int> ret;
    preorder(root, ret);
    return ret;
}

void postorder(BTNode<int>* root, vector<int>& ans)
{
    if (!root)
        return;

    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->data);
}

vector<int> postorderTraversal(BTNode<int>* root)
{
    vector<int> ret;
    postorder(root, ret);
    return ret;
}

int maxDepth(BTNode<int>* root)
{
    if (!root)
        return 0;

    int maxTreeDepth = max(maxDepth(root->left), maxDepth(root->right));
    return maxTreeDepth + 1;
}

bool checkSymmetric(BTNode<int>* left, BTNode<int>* right)
{
    if (!left && !right)
        return true;
    else if (!left && right ||
        !right && left)
        return false;

    if (left->data != right->data)
        return false;

    bool leftSym = checkSymmetric(left->left, right->right);
    bool rightSym = checkSymmetric(left->right, right->left);
    return leftSym && rightSym;
}

bool isSymmetric(BTNode<int>* root)
{
    if (!root)
        return true;

    return checkSymmetric(root->left, root->right);
}

bool findNode(BTNode<int>* root, int key)
{
    if (!root)
        return false;
    else if (root->data == key)
        return true;

    return findNode(root->left, key) || findNode(root->right, key);
}

int minValue(BTNode<int>* root)
{
    if (!root)
        return INT_MAX;

    int minVal = root->data;
    int minChildVal = min(minValue(root->left), minValue(root->right));
    return min(minVal, minChildVal);
}

void maxValue(BTNode<int>* root, int& ans)
{
    if (!root)
        return;

    ans = max(ans, root->data);
    maxValue(root->left, ans);
    maxValue(root->right, ans);
}

int countLeafNodes(BTNode<int>* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
// preOrder [root,left,right]
// inOrder  [left,root,right]
BTNode<int>* buildTreeRecurse(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE)
{
    if (inS > inE || preS > preE)
        return NULL;

    int rootData = preorder[preS];

    BTNode<int>* root = new BTNode<int>(rootData);
    int rootIndex = -1;
    int leftPreS = preS + 1;
    int leftInS = inS;

    for (int i = inS; i <= inE; ++i)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInE = rootIndex - 1;
    int leftPreE = (leftInE - leftInS) + leftPreS;


    int rightPreE = preE;
    int rightInE = inE;
    int rightInS = rootIndex + 1;
    int rightPreS = leftPreE + 1;

    root->left = buildTreeRecurse(preorder, inorder, leftPreS, leftPreE, leftInS, leftInE);
    root->right = buildTreeRecurse(preorder, inorder, rightPreS, rightPreE, rightInS, rightInE);

    return root;
}

BTNode<int>* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if (inorder.empty())
        return NULL;

    return buildTreeRecurse(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

// postOrder [left,right,root]
// inOrder  [left,root,right]
BTNode<int>* buildTreeHelper(vector<int> inorder, vector<int> postorder, int inS, int inE, int postS, int postE)
{
    if (inS > inE)
        return NULL;

    int rootData = postorder[postE];

    BTNode<int>* root = new BTNode<int>(rootData);

    int rootIndex = -1;
    for (int i = inS; i <= inE; ++i)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftPostS = postS;
    int leftPostE = (leftInE - leftInS) + leftPostS;


    int rightInS = rootIndex + 1;
    int rightInE = inE;
    int rightPostS = leftPostE + 1;
    int rightPostE = postE - 1;

    root->left = buildTreeHelper(inorder, postorder, leftInS, leftInE, leftPostS, leftPostE);
    root->right = buildTreeHelper(inorder, postorder, rightInS, rightInE, rightPostS, rightPostE);

    return root;
}

BTNode<int>* buildTree2(vector<int>& inorder, vector<int>& postorder)
{
    if (inorder.empty())
        return NULL;

    return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

pair<int, int> treeHeight(BTNode<int>* root)
{
    if (!root)
        return make_pair(0, 0);

    pair<int, int> leftPair = treeHeight(root->left);
    pair<int, int> rightPair = treeHeight(root->right);

    int lh = leftPair.first;
    int ld = leftPair.second;
    int rh = rightPair.first;
    int rd = rightPair.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    return make_pair(height, diameter);
}

int diameterOfBinaryTree(BTNode<int>* root)
{
    if (!root)
        return 0;

    pair<int, int> p = treeHeight(root);
    return p.second;
}

bool rootToNode(BTNode<int>* root, int val, vector<int>& ans)
{
    if (!root)
        return false;

    ans.push_back(root->data);
    if (root->data == val)
        return true;

    bool found = rootToNode(root->left, val, ans);
    if (!found)
        found = rootToNode(root->right, val, ans);
    if (!found)
        ans.pop_back();

    return found;
}

// 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    BST b;
    b.insert(4);
    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(6);
    b.insert(5);
    b.insert(7);

    b.print();

    TreeNode* head = b.convertToLL();
    TreeNode* tmp = head;
    while (tmp)
    {
        cout << tmp->val << "->";
        tmp = tmp->right;
    }
    
    return 0;
    /*
    int value,power;
    cin >> value;
    cin >> power;
    cout << Power(value, power);
    return 0;
    */

    string line;
    getline(cin, line);

    vector<int> a;
    int split = line.find(' ');
    if (split != string::npos)
        a.push_back(stoi(line.substr(0, split)));

    while (split != string::npos)
    {
        int nextSplit = line.find(' ', split + 1);
        a.push_back(stoi(line.substr(split + 1, nextSplit - split)));
        split = nextSplit;
    }

    printNums(a, a.size() - 1);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
