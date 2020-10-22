#include<bits/stdc++.h>

using namespace std;

class Graph
{
  int V;
  list<int>* adj;
  bool** tc;
public:
  Graph(int V);
  void addEdge(int u,int v);
  void transitiveClosure();
  void TC_util(int u,int v);
};

Graph::Graph(int V)
{
  this->V=V;
  adj=new list<int>[V];
  tc= new bool*[V];
  for(int i=0;i<V;i++)
  {
    tc[i]=new bool[V];
    memset(tc[i],0,V*sizeof(bool));
  }
};

void Graph::addEdge(int u,int v)
{
  adj[u].push_back(v);
};

void Graph::TC_util(int u,int v)
{
tc[u][v]=1;
list<int>::iterator i;
for(i=adj[v].begin();i!=adj[v].end();i++)
  if(!tc[u][*i])
    TC_util(u,*i);
};

void Graph::transitiveClosure()
{
  for(int i=0;i<V;i++)
    TC_util(i,i);

  for(int i=0;i<V;i++)
  {
    for(int j=0;j<V;j++)
      cout<<tc[i][j]<<" ";
    cout<<endl;
  }
};

int main()
{
  Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Transitive closure matrix is \n";
    g.transitiveClosure();
  return 0;
}
