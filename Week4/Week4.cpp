// Week4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <ctime>
#include <queue>
#include <thread>

using namespace std;

struct Node {
    int value;
    Node* right;
    Node* left;
};


void ChallengeOne();
uint32_t GetTime();
uint32_t TimeDiff(uint32_t start, uint32_t end);
void BubbleSort(int ArrayToSort[], int SizeOfArray);

void ChallengeTwo();
Node* BuildTree();
Node* BuildRandomNode();
void BuildBranch(Node* currentNode, int currentDepth);
bool SearchTree(Node* root, int searchValue);

constexpr int MAX_DEPTH = 4;
constexpr bool DEBUG = true;

int main()
{
    //ChallengeOne();
    //ChallengeTwo();
   
    return 0;
}


void ChallengeOne()
{
    int DataSet[]{ 5,6,8,6249846,8,6,2,18,9,7,5,9,74,651,3,18,1,87,435,138,3,84,35,138,18,73,8,861,358,1,84 };
    cout << "List pre-sort: [";
    for (auto i : DataSet) {
        cout << i << " ";
    }
    cout << "]" << endl;


    auto StartTime = GetTime();
    BubbleSort(DataSet, 31);
    auto EndTime = GetTime();

    cout << "List pre-sort: [";
    for (auto i : DataSet) {
        cout << i << " ";
    }
    cout << "]" << endl;

    cout << "Time taken: " << TimeDiff(StartTime, EndTime);
}

uint32_t GetTime()
{
    using namespace chrono;
    return static_cast<uint32_t>(duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count());
}

uint32_t TimeDiff(uint32_t start, uint32_t end)
{
    return end - start;
}

void BubbleSort(int ArrayToSort[], int SizeOfArray)
{
    // Loop to control the number of pass
    for (int pass = 0; pass < SizeOfArray; pass++)
    {
        // Loop to control the number of comparisons per pass
        for (int i = 0; i < SizeOfArray - 1; i++)
        {
            // Compare adjacent element values
            if (ArrayToSort[i] > ArrayToSort[i + 1])
            {
                // Store the current integer in a temporary variable
                int temp = ArrayToSort[i];

                // Shift the next element to teh current position
                ArrayToSort[i] = ArrayToSort[i + 1];

                // Assign the next value to the value held in temp
                ArrayToSort[i + 1] = temp;
            }
        }
    }
}

void ChallengeTwo()
{
    //srand(time(0)); randomness
    Node* root = BuildTree();
    bool found = SearchTree(root, 491);
    cout << "We " << (found ? "" : "un") << "successfully found the value" << endl;
}

Node* BuildTree()
{
    Node* root = BuildRandomNode();
    BuildBranch(root, 1);
    return root;
}

void BuildBranch(Node* currentNode, int currentDepth)
{
    if (currentDepth >= MAX_DEPTH) { return; }

    int rightProb = rand() % 4;
    int leftProb = rand() % 4;
    if (rightProb == 1 || DEBUG)
    {
        Node* right = BuildRandomNode();
        currentNode->right = right;
        BuildBranch(right, currentDepth + 1);
    }
    if (leftProb == 3 || DEBUG)
    {
        Node* left = BuildRandomNode();
        currentNode->left = left;
        BuildBranch(left, currentDepth + 1);
    }

}

Node* BuildRandomNode()
{
    Node* node = new Node();
    node->value = rand() % 2000;
    node->right = nullptr;
    node->left = nullptr;
    return node;
}

bool SearchTree(Node* root, int searchValue) {
    queue<Node*> q;
    q.push(root);
    while (q.empty() == false) {
        Node* node = q.front();
        if (node->value == searchValue)
        {
            return true;
        }
        q.pop();
        if (node->left != NULL)
        {
            q.push(node->left);
        }
        if (node->right != NULL)
        {
            q.push(node->right);
        }
    }
    return false;
}