// Dhruv Rajeshkumar Shah
// 21BCE0611

// N Queens Problem

// Import
#include <bits/stdc++.h>
using namespace std;


bool isSafe(int v, int c, int adj[][5], int color[])
{
    for (int i = 0; i < 5; i++)
        if (adj[v][i] && c == color[i])
            return false;
    return true;
}

bool solve(int v, int m, int adj[][5], int color[])
{
      if (v ==5)
        return true;
    for (int i = 1; i <= m; i++)  //try coloring vertex v with different colors
    {
        if (isSafe(v,i, adj, color)) {
            color[v] = i;
            if (solve( v + 1, m, adj, color) == true)
                return true;
            color[v] = 0; //backtrack
        }
    }  
    return false;
}
  
void print(int color[])
{
    cout << "assigned colors are \n";
    for (int i = 0; i < 5; i++)
        cout << "vertex "<<i <<" -> " <<color[i] << "\n "; 
}
int main()
{
    // Take input from user
    int m;
    cout << "Enter number of colors: ";
    cin >> m;

    // Initialize the adjacency matrix
    int adj[5][5];
    cout << "Enter the adjacency matrix: ";
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> adj[i][j];
    
    // Initialize the color array
    int color[5];

    for (int i = 0; i < 5; i++)
        color[i] = 0;
    if (solve(0, m, adj, color) == false)
        cout << "Solution does not exist";
    else
      print(color);
    return 0;
}
