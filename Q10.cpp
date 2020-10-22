//reversing a queue
#include<bits/stdc++.h>
using namespace std;

void QueueReverse(deque<int> *q)
{
  if(q->empty()) return;

  int a=q->front();
  q->pop_front();
  QueueReverse(q);
  q->push_back(a);
  return;
};

void print(deque<int> q)
{
  cout<<"Printing"<<endl;
  for(auto it=q.begin();it!=q.end();it++)
    cout<<*it<<" ";
  cout<<endl;
};

int main()
{
deque<int> q;
q.push_back(1);
q.push_back(2);
q.push_back(3);
q.push_back(4);
q.push_back(12);
q.push_back(13);
q.push_back(11);

print(q);
QueueReverse(&q);
print(q);
return 0;
}
