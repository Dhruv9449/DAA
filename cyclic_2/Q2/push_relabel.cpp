// Dhruv Rajeshkumar Shah
// 21BCE0611

// Push Relabel Algorithm

// Import
#include <bits/stdc++.h>
using namespace std;

struct Vertex
{
    int h;
    int eflow;
};

int v, e;
int **cap, **flow;
struct Vertex *vert;

// Function to find the active node
int getactivenode(int source, int sink)
{
    for (int i = 1; i < v - 1; i++)
    {
        if (vert[i].eflow > 0)
        {
            for (int j = 0; j < v; j++)
            {
                if (cap[i][j] != 0 || flow[i][j] != 0)
                {
                    if (cap[i][j] != flow[i][j])
                        return i;
                }
            }
        }
    }
    return -1;
}

// Function to find the preflow
void preflow(int s)
{
    vert[s].h = v;
    for (int i = 0; i < v; i++)
    {
        if (i != s && cap[s][i] != 0)
        {
            flow[s][i] = cap[s][i];
            flow[i][s] = -cap[s][i];
            vert[i].eflow += cap[s][i];
        }
    }
}

// Function to push the flow
bool push(int u)
{
    for (int i = 0; i < v; i++)
    {
        if (cap[u][i] != 0 || flow[u][i] != 0)
        {
            if (flow[u][i] == cap[u][i])
                continue;
            if (vert[u].h > vert[i].h)
            { // minimum of residual capacity[u][i] and eflow(u)
                int Flow = cap[u][i] - flow[u][i] < vert[u].eflow ? cap[u][i] - flow[u][i] : vert[u].eflow;
                vert[u].eflow -= Flow;
                vert[i].eflow += Flow;
                flow[u][i] += Flow;
                flow[i][u] -= Flow;
                return true;
            }
        }
    }
    return false;
}

// Function to relabel the nodes
void relabel(int u)
{
    int minh = INT_MAX;
    for (int i = 0; i < v; i++)
    {
        if (cap[u][i] != 0 || flow[u][i] != 0)
        {
            if (cap[u][i] == flow[u][i])
                continue;
            if (vert[i].h < minh)
            {
                minh = vert[i].h;
            }
        }
    }
    vert[u].h = minh + 1;
}

// Function to find the maximum flow
int maxFlow(int source, int sink)
{
    preflow(source);
    cout << "\nInitial capacity\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << cap[i][j] << " ";
        cout << "\n";
    }
    int u = getactivenode(source, sink);
    while (u != -1)
    {
        if (!push(u))
            relabel(u);
        u = getactivenode(source, sink);
    }
    return vert[sink].eflow;
}

// Main function
int main()
{
    // Taking input from user
    cout << "Enter no. of vertices : ";
    cin >> v;
    // v=6;
    cout << "Enter no. of edges : ";
    cin >> e;
    // e=10;

    vert = new Vertex[v];
    cap = new int *[v];
    for (int i = 0; i < v; i++)
        cap[i] = new int[v];
    flow = new int *[v];
    for (int i = 0; i < v; i++)
        flow[i] = new int[v];
    cout << "Enter edges and their capacity : \n";
    for (int i = 0; i < v; i++)
    {
        vert[i].h = 0;
        vert[i].eflow = 0;
        for (int j = 0; j < v; j++)
        {
            flow[i][j] = 0;
            cap[i][j] = 0;
        }
    }
    int x, y, c;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> c;
        cap[x][y] = c;
    }

    // Taking source and sink
    cout << "Enter source and sink : ";
    int source, sink;
    cin >> source >> sink;

    // Finding the maximum flow
    int max_flow = maxFlow(source, sink);
    cout << "MaxFlow : " << max_flow << endl;
    cout << "Final flow\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << flow[i][j] << " ";
        cout << endl;
    }
    return 0;
}