#include<bits/stdc++.h>
using namespace std;
class Graph {
private:
  int V;
  vector<int> *adj;
public:
  Graph(int V)
  {
    this->V=V;
    adj=new vector<int>[V];
  }
  void addEdge(int v, int w)
  {
    adj[v].push_back(w);
  }
  void topoUtil(int v, vector<bool>& visited,stack<int>& s)
  {
    if(!visited[v])
    {
      visited[v]=true;
      for(int i=0;i<adj[v].size();i++)
      {
        topoUtil(adj[v][i],visited,s);
      }
      s.push(v);
    }
    return;
  }
  void topologicalSort()
  {
    cout<<"------------TOPOLOGICAL SORT--------------\n";
    vector<bool> visited(V,0);
    stack<int> s;
    for(int i=0;i<V;i++)
    {
      if(!visited[i]) topoUtil(i,visited,s);
    }
    while(!s.empty())
    {
      cout<<s.top()<<" ";
      s.pop();
    }
    cout<<endl;
    return;
  }
};
int main()
{
  Graph g(6);
g.addEdge(5, 2);
g.addEdge(5, 0);
g.addEdge(4, 0);
g.addEdge(4, 1);
g.addEdge(2, 3);
g.addEdge(3, 1);

cout << "Following is a Topological Sort of the given graph \n";
g.topologicalSort();

return 0;
  return 0;
}
