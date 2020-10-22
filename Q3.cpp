//Delete consecutive same words in a sequence
// Given a sequence of n strings, the task is to check if any two
// similar words come together then they destroy each other then
// print the number of words left in the sequence after this
// pairwise destruction.

#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;
int reduce_sequence(vector<string> v)
{
  int n;
  stack<string> s;
  string str;
  for(auto i=v.begin();i!=v.end();++i)
  {
    str=*i;
    if(!s.empty() && str.compare(s.top())==0)
    {
      s.pop();
    }
    else
      s.push(str);
  }
  return s.size();
}
int main(void)
{
  vector<string> v={ "tom", "jerry", "jerry", "tom", "tom"};
  cout<<"The string count after reduction: "<<reduce_sequence(v)<<endl;
  return 0;
}
