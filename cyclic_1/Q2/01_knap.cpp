// Dhruv Rajeshkumar Shah
// 21BCE0611

// A dynamic programming based

// Import
#include <bits/stdc++.h>
using namespace std;
 

// Function to return maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;

    vector<vector<int> > dp(n + 1, vector<int>(W + 1));

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}
 

// Main function
int main()
{
    // Taking input from user
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    int weight[n], profit[n];
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cout << "Enter the profits of the items: ";
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    // Printing the maximum profit
    cout << "The maximum profit is: ";
    cout << knapSack(W, weight, profit, n) << endl;


    return 0;
}

