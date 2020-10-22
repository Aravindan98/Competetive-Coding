#include<bits/stdc++.h>
using namespace std;
#define V 9

int getMinimum(vector<int>& distance, vector<bool>& visited)
{
  int min=INT_MAX, min_index=-1;
  for(int i = 0; i < V; i++)
  {
    if(!visited[i] && distance[i]<min) { min=distance[i]; min_index=i; }
  }
  return min_index;
};

void printSolution(vector<int>& dist)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
};

void dijkstra(int g[V][V], int start_vertex)
{
  vector<int> distance(V,INT_MAX);
  vector<int> parent(V,-1);
  vector<bool> visited(V,0);
  distance[start_vertex]=0;
  for(int i=0;i<V-1;i++)
  {
  int v=getMinimum(distance,visited);
  visited[v]=1;
  for(int i=0;i<V;i++)
  {
    if(g[v][i] && !visited[i] && g[v][i]+distance[v]<distance[i])
    {
      distance[i]=g[v][i]+distance[v];
      parent[i]=v;
    }
  }
  }
  printSolution(distance);
  return;
};

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    cout<<"Enter the starting vertex"<<endl;
    int src;
    cin>>src;
    dijkstra(graph, src);
    return 0;
}
