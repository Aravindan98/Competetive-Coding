#include<iostream>
#include<climits>

using namespace std;

void swap(int *i,int *j)
{
    int temp;
    temp=*i;
    *i=*j;
    *j=temp;
};

class Max_Heap
{
private:
    int *heap;
    int capacity;
    int heap_length;
public:
    Max_Heap(int capacity);
    int parent(int i){return (i-1)/2;}
    int right(int i){return 2*i+1;}
    int left(int i){return 2*i+2;}
    void maxHeapify(int loc);
    void buildMaxHeap();
    void increaseKey(int loc,int key);
    void heapsort();
    void heapInsert(int key);
    void heapDelete(int loc);
    void print();
};

Max_Heap::Max_Heap(int cap)
{
    heap=new int[cap];
    capacity=cap;
    heap_length=0;
}

void Max_Heap::maxHeapify(int loc)
{
    //the working assumption is that the left and right child are max-heaps
    int r=right(loc);
    int l=left(loc);
    int largest=loc;

    if(l<heap_length && heap[l]>heap[largest])
        largest=l;
    if(r<heap_length && heap[r]>heap[largest])
        largest=r;

    if(largest!=loc)
    {
        swap(&heap[largest],&heap[loc]);
        maxHeapify(largest);
    }
}

void Max_Heap::buildMaxHeap()
{
    int i=(heap_length-1)/2;
    while(i>=0)
    {
        maxHeapify(i);
        i--;
    }
}

void Max_Heap::increaseKey(int loc,int key)
{
    heap[loc]=key;
    // this action might destroy the Max-Heap property, hence we move up the heap towards the root to check for failure and correct it.
    while(loc>0 && heap[parent(loc)]<heap[loc])
    {
        swap(&heap[parent(loc)],&heap[loc]);
        loc=parent(loc);
    }
}

void Max_Heap::heapDelete(int loc)
{
    if(heap_length==0)
    {
    return;
    }
    else if(heap_length==1 && loc==0)
    {
        heap_length--;
    }
    else
    {
        swap(&heap[heap_length-1],&heap[loc]);
        heap_length--;
        maxHeapify(loc);
    }
}

void Max_Heap::heapInsert(int key)
{
    if(heap_length>capacity)
        return;
    else
    {
        heap_length++;
        heap[heap_length-1]=INT_MIN;
        increaseKey(heap_length-1,key);
    }
}

void Max_Heap::heapsort()
{
    int temp=heap_length;
    int i=heap_length-1;
    //buildMaxHeap();
    while(i>0)
    {
        cout<<"Heap Length:"<<heap_length<<endl;
        swap(&heap[0],&heap[i]);
        print();
        heap_length--;
        maxHeapify(0);
        print();
        i--;
    }
    heap_length=temp;
}

void Max_Heap::print()
{
  for(int i=0;i<heap_length;i++)
  {
    cout<<heap[i]<<" ";
  }
  cout<<endl;
}

int main()
{
    Max_Heap h(10);
    h.heapInsert(1);
    h.heapInsert(7);
    h.heapInsert(2);
    h.heapInsert(6);
    h.heapInsert(4);
    h.print();
    h.heapsort();
    h.print();
    h.buildMaxHeap();
    h.print();
    return 0;
}
