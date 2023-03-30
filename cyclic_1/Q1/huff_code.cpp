// Dhruv Rajeshkumar Shah
// 21BCE0611

// Huffman coding

// Import
#include <bits/stdc++.h>
using namespace std;


// Queue node
struct Node {
    char letter;
    int freq;
    struct Node *left, *right;
    Node (char letter, int freq)
    {
        left = right = NULL;
        this->letter = letter;
        this->freq = freq;
    };
};

// Function to compare two nodes
struct compare {
    bool operator()(Node* l, Node* r)
    {
        return (l->freq > r->freq);
    }
};


// Function to print the huffman code
void printCode(struct Node* root, string str)
{
    if (!root)
        return;
    if (root->letter != '*')
        cout << root->letter << ": " << str << "\n";
    printCode(root->left, str + "0");
    printCode(root->right, str + "1");
}

// Hoofman coding function
void huff(char a[], int f[], int n){
    // Create a min heap
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    // Insert all the characters
    for (int i = 0; i < n; ++i)
        minHeap.push(new Node(a[i], f[i]));

    struct Node *left, *right, *top;

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new Node('*', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    // Print the huffman code
    printCode(minHeap.top(), "");
}


// Main function
int main()
{
    // Taking input from the user
    int n;
    cout<<"Enter the number of characters: ";
    cin>>n;
    char a[n];
    int f[n];
    cout<<"Enter the characters: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the frequencies: ";
    for(int i=0;i<n;i++)
        cin>>f[i];
    

    // Printing the huffman code
    huff(a, f, n);
    return 0;
}

