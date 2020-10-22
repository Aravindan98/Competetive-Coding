#include<iostream>
#include<list>

using namespace std;

class Graph
{
  int V;
  list<int> *adj;
public:
  Graph(int V);
  void addEdge(int v,int w);
  void BFS(int s);
};

Graph::Graph(int V)
{
  this->V=V;
  adj=new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
  adj[v].push_back(w);
}

void Graph::BFS(int s)//s is the source node
{
  bool *visited=new bool[V];
  for(int i=0;i<V;i++)
  {
    visited[i]=0;
  }
  list<int> queue;
  visited[s]=1;
  queue.push_back(s);

  list<int>::iterator i;

  while(!queue.empty())
  {
    s=queue.front();
    cout<<s<<" ";
    queue.pop_front();
    for(i=adj[s].begin();i!=adj[s].end();++i)
    {
      if(!visited[*i])
      {
        visited[*i]=1;
        queue.push_back(*i);
      }
    }
  }
}
int main()
{
  Graph g(4);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,2);
  g.addEdge(2,0);
  g.addEdge(2,3);
  g.addEdge(3,3);

  cout<<endl<<" BFS with 2 as source "<<endl;
  g.BFS(2);
  cout<<endl<<endl;
}
