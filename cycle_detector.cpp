//detect cycle in a Graph

#include<iostream>
#include<vector>
using namespace std;
class Graph{
private:
  int V;
  vector<int> *adj;
public:
  Graph(int V)
  {
    this->V = V;
    adj=new vector<int>[V];
  }
  void addEdge(int i, int f)
  {
    adj[i].push_back(f);
  }
  bool isCyclicUtil(int v, vector<bool> &visited,vector<bool> stack)
  {
    if(!visited[v])
    {
      visited[v] = 1;
      stack[v]=1;
      cout<<v<<endl;
      for(int i=0; i<adj[v].size(); i++)
      {
          if(stack[adj[v][i]] || isCyclicUtil(adj[v][i],visited,stack)) return 1;
      }
    }
    return 0;
  }
  bool isCyclic()
  {
    vector<bool> visited(V,0);
    vector<bool> stack(V,0);
    for(int i=0;i<V;i++)
    {
      if(!visited[i])
        if(isCyclicUtil(i,visited,stack)) {cout<<"cycle"<<endl; return 1;}
    }
    cout<<"No cycle"<<endl;
    return 0;
  }
};
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal\n";
    g.isCyclic();
    cout<<endl;
    return 0;
}
