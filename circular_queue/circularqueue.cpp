#include <iostream>
using namespace std;

// (rear+1) % size == front   (others)

// (rear == size - 1 && front == 0) || (rear == (front - 1) % (size - 1))


// initially front and rear at same beginning
// when entry is added rear shifts by one but front remains same

// when an element is deleted front shifts one place
struct Queue
{
    int rear,front;
    int size;
    int *arr;

    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void EnQueue(int data);
    int DeQueue();
};

void Queue::EnQueue(int data)
{
    if((front == 0 && rear == size - 1) || (rear == (front - 1)%(size - 1)))
    {
        cout << "queue is already full";
        return;
    }
    else if(front == -1)
    {
        front = rear = 0;
        arr[rear] = data;
    }
    else
    {
        rear++;
        arr[rear] = data;   
    }
}

int Queue::DeQueue()
{
    // if queue is empty
    if(front == -1)
    {
        cout << "queue is empty";
        return;
    }
    int data = arr[rear];
    // data stored for later keeping
    arr[front] = -1;

    // replace the popped value with -1

    // if queue has only one element
    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == size - 1)
    {
        front = 0;
        // front got looped back since it is a circular queue
    }
    else
    {
        front++;
    }
}

int main()
{



}