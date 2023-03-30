// Dhruv Rajeshkumar Shah
// 21BCE0611

// Fractional Knapsack Problem

// Import
#include <bits/stdc++.h>
using namespace std;


// Defining node
typedef struct node {
    int w;
    int v;
    float r;
} Item;


// Function to initialize the nodes
void init(Item a[], int n){
    // Taking weight and value of each item as input
    // and calculating the ratio
    for (int i = 0; i < n; i++){
        cout << "Enter weight and value of item " << i + 1 << ": ";
        cin >> a[i].w >> a[i].v;
        a[i].r = (float)a[i].v / a[i].w;
    }

    // Sorting the items in descending order of ratio
    sort(a, a + n, [](Item a, Item b){
        return a.r > b.r;
    });
}


// Function to calculate fractional knapsack
void fractKnap(Item a[], int n, int cap){
    float amt = 0;
    for (int i = 0; i < n; i++){
        if (a[i].w <= cap){
            cap -= a[i].w;
            amt += a[i].v;
        }
        else {
            amt += a[i].r * cap;
            cap = 0;
            break;
        }
    }

    // Printing the maximum amount
    cout << "Maximum amount: " << amt << endl;
}


// Main function
int main(){
    // Taking number of items and capacity of knapsack as input
    int n, cap;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> cap;

    // Initializing the nodes
    Item a[n];
    init(a, n);

    // Calculating the maximum amount
    fractKnap(a, n, cap);

    return 0;
}

