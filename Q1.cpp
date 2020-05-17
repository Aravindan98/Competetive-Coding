#include<iostream>
#include<stack>
using namespace std;

stack<int> s;

void insert_at_Bottom(int n)
{
  if(s.empty())
  {
    s.push(n);
  }
  else
  {
    int popped=s.top();
    s.pop();
    insert_at_Bottom(n);
    s.push(popped);
  }
};

void reverse()
{
    if(!s.empty())
    {
      int d=s.top();
      s.pop();
      reverse();
      insert_at_Bottom(d);
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
  for(int i=0;i<5;i++)
    s.push(i*100);

  print_stack(s);
  reverse();
  cout<<"\n\tAfter reversal\n"<<endl;
  print_stack(s);

  return 0;
};
