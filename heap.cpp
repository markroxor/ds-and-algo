#include<stdio.h>
#include<iostream>
#include<limits.h>

using namespace std;
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MinHeap
{
    int cap;
    int *arr;
    int size;
    public:
    MinHeap(int CAP){cap = CAP;arr = new int[cap];size=0; };
    void insertKey(int key);
    int extractMin();
    void decreaseKey(int i,int new_val);
    void deleteKey(int i);
    void minHeapify(int i);
    int getMin();
    bool isEmpty();
};

void MinHeap:: minHeapify(int i)
{
    int mini = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left<size and arr[left]<arr[i])
        mini = left;
    if(right<size and arr[right]<arr[i])
        mini = right;

    if(mini!=i)
    {
        swap(&arr[mini],&arr[i]);
        minHeapify(mini);
    }
}

void MinHeap::insertKey(int key)
{
    if(size==cap)
    {
        printf("cant insert, min heap full.\n");
        return;
    }
    size++;
    arr[size-1] = key;
    int i=size-1;
    int parent = (i-1)/2;
    while(i>=0 and arr[parent]>arr[i] )
    {
        swap(&arr[parent],&arr[i]);
        i = parent;
        parent = (i-1)/2;
    }
}

void MinHeap:: decreaseKey(int i,int new_val)
{
    arr[i] = new_val;
    int parent = (i-1)/2;

    while(i>=0 and arr[parent]>arr[i])
    {
        swap(&arr[i],&arr[parent]);
        i = parent;
        parent = (i-1)/2;
    }
}

int MinHeap:: extractMin()
{
    int mini = arr[0];
    arr[0] = arr[size-1];
    size--;
    minHeapify(0);
    return mini;
}

void MinHeap:: deleteKey(int i)
{
    decreaseKey(i,INT_MIN);
    extractMin();
}

int MinHeap:: getMin()
{return arr[0];}

bool MinHeap:: isEmpty()
{return size==0;}
int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    //h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    //cout << h.extractMin() << " ";
    //cout << h.getMin() << " ";
   // h.decreaseKey(2, 1);
    while(!h.isEmpty())
    cout << h.extractMin()<<"\n";
    return 0;
}
