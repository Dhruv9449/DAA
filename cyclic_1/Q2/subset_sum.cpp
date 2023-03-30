// Dhruv Rajeshkumar Shah
// 21BCE0611

// Subset sum problem

// Import
#include <bits/stdc++.h>
using namespace std;

stack<int> stck;
bool found = false;

// Function to print the stack
void print()
{
    stack<int> temp;
    while (!stck.empty())
    {
        temp.push(stck.top());
        stck.pop();
    }
    while (!temp.empty())
    {
        cout << temp.top() << "\n";
        stck.push(temp.top());
        temp.pop();
    }
}

// Function to solve the problem
void solve(int curr, int ind, int a[], int n, int tar)
{
    if (curr > tar)
        return ;
    if (curr == tar)
    {
        found = true;
        print();
        return ;
    }
    for (int i = ind; i < n; i++)
    {
        stck.push(a[i]);
        solve(curr + a[i], i + 1, a, n, tar);
        stck.pop();
    }
    return;
}

int main()
{
    // Taking input from user
    int n, tar;
    int a[n];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the target sum: ";
    cin >> tar;


    // Printing the solution
    solve(0, 0, a, n, tar);
    if (found == false)
        cout << "No solution";
    return 0;
}


