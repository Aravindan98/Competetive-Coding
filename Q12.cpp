#include<bits/stdc++.h>
using namespace std;


int main()
{
  deque<int> q;
  q.push_back(1);
  q.push_back(2);
  q.push_back(3);
  q.push_back(4);
  q.push_back(5);
  q.push_back(6);

  stack<int> s;
  for(auto i=q.begin();i!=q.end();i++)
  {
    cout<<*i<<" ";
  }
  cout<<endl;
  int a;
    while(!q.empty())
    {
      a=q.front();
      s.push(a);
      q.pop_front();
    }
  while(!s.empty())
  {
    a=s.top();
    q.push_back(a);
    s.pop();
  }


  cout<<endl;

  int count=3;
  int size=q.size();
  int d=size-count;
  while(d>0)
  {
    a=q.front();
    s.push(a);
    q.pop_front();
    d--;
  }

  while(!s.empty())
  {
    a=s.top();
    q.push_back(a);
    s.pop();
  }
  for(auto i=q.begin();i!=q.end();i++)
  {
    cout<<*i<<" ";
  }
  cout<<endl;
return 0;
}
