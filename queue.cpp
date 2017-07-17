#include<stdio.h>
using namespace std;

class Queue
{
    int front,rear, size;
    int *array;
    int capacity;
public:
    Queue(int capacity);
    bool isFull();
    bool isEmpty();
    void enqueue(int item);
    int dequeue();
    int Front();
    int Rear();

};
Queue::Queue(int cap)
{
    capacity = cap;
    front = size = 0;
    rear = capacity-1;
    array = new int[capacity];
}

bool Queue::isFull()
{
    return size==capacity;
}

bool Queue::isEmpty()
{
    return not size;
}

void Queue::enqueue(int item)
{
    if(isFull())
        return;
    size++;
    ++rear%=capacity;
    array[rear] = item;
}

int Queue::dequeue()
{
    if(isEmpty())
        return -1;
    size--;
    int item = array[front];
    ++front%=capacity;
    return item;
}

int Queue::Front()
{
    if(isEmpty())
        return -1;
    return array[front];
}

int Queue::Rear()
{
    if(isEmpty())
        return -1;
    return array[rear];
}

int main()
{
    Queue queue(1000);
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    
    printf("%d dequeued from queue\n", queue.dequeue());
    
    printf("Front item is %d\n", queue.Front());
    printf("Rear item is %d\n", queue.Rear());
    
    return 0;
}
