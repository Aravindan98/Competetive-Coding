#include<iostream>
#include<unordered_map>

using namespace std;

int max(int a,int b){return (a>b)?a:b;};

int cutRod(int length,unordered_map map<int, int>)
{
  if(length>=3)
  {
  return max(cutRod(length-1)+map[1],cutRod(length-2)+map[2]),cutRod(length-3)+map[3]);
  }
  else
  {
    return 0;
  }
};

int main()
{
  unordered_map<int, int> map;
  map[1]=1;
  map[2]=5;
  map[3]=8;
  //map[4]=9;
  //map[5]=10;
  //map[6]=17;
  //map[7]=17;
  //map[8]=20;

  int rod_length;
  cout<<"Enter the length of the rod"<<endl;
  cin>> rod_length;

  int answer;
  answer=cutRod(rod_length,map);

  return 0;
}
