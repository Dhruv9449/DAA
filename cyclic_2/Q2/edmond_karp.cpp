// Dhruv Rajeshkumar Shah
// 21BCE0611

// Edmond Karp Algorithm

// Import
#include <bits/stdc++.h>
using namespace std;

int n;
typedef struct Node
{
  int id, state, prev;
} node;

int res[100][100];

// Function to find the path
bool DFS(node vert[], node source, node sink)
{
  node u;
  stack<node> s;
  for (int i = 0; i < n; i++)
  {
    vert[i].state = 0;
  }
  vert[source.id].state = 0;
  vert[source.id].prev = -1;

  s.push(source);

  while (!s.empty())
  {
    u = s.top();
    s.pop();

    for (int i = 0; i < n; i++)
    {
      if (res[u.id][i] && !vert[i].state)
      {
        s.push(vert[i]);
        vert[i].state = 1;
        vert[i].prev = u.id;
      }
    }
  }

  return (vert[sink.id].state == 1);
}

// Main function
int main()
{
  // Taking input from user
  cout << "Enter number of nodes: ";
  cin >> n;
  cout << "Enter the adjacency Matrix: "
       << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> res[i][j];
    }
  }

  node vert[n], source, sink;

  for (int i = 0; i < n; i++)
  {
    vert[i].id = i;
  }

  source.id = 0;
  sink.id = n - 1;

  int maxFlow = 0;

  while (DFS(vert, source, sink))
  {
    int augFlow = INT_MAX;
    for (int v = sink.id; v != source.id; v = vert[v].prev)
    {
      int u = vert[v].prev;
      augFlow = augFlow < res[u][v] ? augFlow : res[u][v];
    }
    for (int v = sink.id; v != source.id; v = vert[v].prev)
    {
      int u = vert[v].prev;
      res[u][v] -= augFlow;
      res[v][u] += augFlow;
    }
    maxFlow += augFlow;
  }

  cout << "Maxflow : " << maxFlow << endl;

  return 0;
}