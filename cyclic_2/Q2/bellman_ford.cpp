// Dhruv Rajeshkumar Shah
// 21BCE0611

// Bellman Ford Algorithm

// Import
#include<bits/stdc++.h>
using namespace std;

struct edge
{
	int source,dest,wt;
};

// Main function
int main()
{
	int v,e,start;
	
	// Taking input from user
	cout<<"Enter the number of vertices: ";
	cin>>v;
	cout<<"Enter the number of edges: ";
	cin>>e;

	struct edge edges[e];
	float dist[v];
	cout<<"Enter the source,dest and weight of each edge: \n";
	for(int i=0;i<e;i++)
	  cin>>edges[i].source>>edges[i].dest>>edges[i].wt;

	cout<<"Enter the start node: ";
	cin>>start;

	for(int i=0;i<v;i++)
	  dist[i]=INT_MAX;
	dist[start-1]=0;
	for(int i=0;i<v-1;i++)
	{
		for(int j=0;j<e;j++)
		{
			int u=edges[j].source;
			int v=edges[j].dest;
			int w=edges[j].wt;
			if (dist[v-1]>dist[u-1]+w)
			   dist[v-1]=dist[u-1]+w;
		}
	}
	int flag=0; // this loop is to check if the graph contains any negative weight cycle
	for(int j=0;j<e;j++)
	{
			int u=edges[j].source;
			int v=edges[j].dest;
			int w=edges[j].wt;
			if (dist[v-1]>dist[u-1]+w)
			{ cout<<"the graph contains negative weight cycle; so no solution\n";
			  flag=1;
			  break;
		    } 
	}
	if(flag==0)
	cout<<"The shortest distance from the start node to all other nodes is: \n";
	cout<<0<<" "<<0<<endl;
	for(int i=1;i<v;i++)
	  cout<<i<<" "<<dist[i-1]<<endl;
	return 0;
}