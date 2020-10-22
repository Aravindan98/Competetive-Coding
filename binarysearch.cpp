#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> A, int key)
{
int start = 0;
int end = A.size()-1;
int mid;
while(start+1<end)
{
  mid = (start+end)/2;
  if(A[mid]==key) return mid;
  else if(key<A[mid]) end=mid;
  else start=mid;
}
cout<<start<<" "<<end<<endl;
mid = (start+end)/2;
if(start!=mid){cout<<start<<" "<<end<<endl;}
if(A[mid]==key) return mid;
else return -1;
};

int main(void)
{
    vector<int> A;
    for(int i =0; i<10;i++)
    {
      A.push_back(3*i+4);
      cout<<i<<":"<<A.back()<<" ";
    }
    cout<<endl;
    cout<<"enter the no:"<<endl;
    int n;
    cin>>n;
    cout<<binary_search(A,n);
    cout<<endl;
    return 0;
};
