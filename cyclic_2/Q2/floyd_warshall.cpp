// Dhruv Rajeshkumar Shah
// 21BCE0611

// Floyd Warshall Algorithm

// Import
#include <bits/stdc++.h>
using namespace std;

#define MAX 20

struct path
{
    char a[MAX];
    int len;
} route[MAX][MAX]; // route matrix uses this structure
int cost[MAX][MAX];
int n;

// Main function
int main()
{
    int i, j, k, c, x, y;
    int max_edges, origin, destin;
    cout << "Enter number of nodes : ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            route[i][j].len = 0;
            cost[i][j] = 999999; // initialize all entries in cost[][] to 0
        }
    }
    max_edges = n * (n - 1);
    for (i = 1; i <= max_edges; i++)
    {
        cout << "Enter edge ( 0 0 to quit ) : " << endl;
        cin >> origin >> destin;
        if ((origin == 0) && (destin == 0))
            break;
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            cout << "Invalid edge!\n";
            i--;
        }
        else
        {
            cout << "\nEnter the cost: ";
            cin >> c;                 // only for a valid edge, read its cost 'c' and store it in the appropriate
            cost[origin][destin] = c; // index of cost[ ][ ]
            route[origin][destin].a[route[origin][destin].len++] = origin + 48;
            route[origin][destin].a[route[origin][destin].len++] = destin + 48; // for storing origin node & route[origin][destin].a[route[origin][destin].len]='\0';                     //destination as characters in route[][]
        }
    }
    // display
    cout << "\nInitial Cost Matrix\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << cost[i][j] << " ";
        cout << "\n";
    }
    for (i = 1; i <= n; i++)     // 'i' index generates the intermediate vertex
    {                            // 'j' index generates the row number of the matrices
        for (j = 1; j <= n; j++) // 'j' index generates the row number of the matrices
        {
            for (k = 1; k <= n; k++) // 'k' index generates the column number of the matrices
            {
                if (cost[j][k] > cost[j][i] + cost[i][k]) // if the route via vertex 'i' is shorter, update the cost of that route
                {
                    cost[j][k] = cost[j][i] + cost[i][k]; // in the cost matrix.
                    for (x = 0; x < route[j][i].len; x++)
                        route[j][k].a[x] = route[j][i].a[x]; // first copy contents of route[j][i] to route[j][k]
                    for (y = 1; y < route[i][k].len; y++)
                        route[j][k].a[x - 1 + y] = route[i][k].a[y]; // next append contents of route[i][k] to route[j][k]
                    route[j][k].a[x - 1 + y] = '\0';
                    route[j][k].len = route[j][i].len + route[i][k].len - 1;
                }
            }
        }
    }
    cout << "\nFinal Cost Matrix\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << cost[i][j] << "   ";
        cout << "\n";
    }
    cout << "\nFinal Route Matrix\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << route[i][j].a << "  ";
        cout << "\n";
    }
    return 0;
}