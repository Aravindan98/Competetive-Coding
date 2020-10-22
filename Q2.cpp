#include<iostream>
#include<stack>

using namespace std;
stack<int> s;

void sortedInsert(int n)
{
  if(s.empty() || s.top()<=n)
  {
    // base case
    s.push(n);
  }
  else
  {
    int popped=s.top();
    s.pop();
    sortedInsert(n);
    s.push(popped);
  }
};

void sortStack()
{
  if(!s.empty())
  {
    int d=s.top();
    s.pop();
    sortStack();
    sortedInsert(d);
  }
};

void print_stack(stack<int> s)
{

    if(!s.empty())
    {
      int d=s.top();
      s.pop();
      cout<<d<<endl;
      print_stack(s);
      s.push(d);
    }
    else
    {
        cout<<"BOTTOM"<<endl;
    }
};

int main(void)
{
  s.push(3);
  s.push(2);
  s.push(6);
  s.push(1);
  s.push(9);

  print_stack(s);
  sortStack();
  cout<<"\n\tSorted stack\n"<<endl;
  print_stack(s);
  return 0;
}
