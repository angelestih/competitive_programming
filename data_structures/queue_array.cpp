#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <stack>

using namespace std;

struct Queue 
{
    int front, rear, capacity;
    int* queue;

    Queue (int c)
    {
        /* constructor */
        front = 0;
        rear = -1;
        capacity = c;
        queue = new int[c];
    }

    ~Queue()
    {
        /* destructor */
        delete[] queue;
    }

    void queueEnqueue(int data)
    {
        if (rear == capacity - 1)
        {
            cout << "\n Queue is full \n";
            return ;
        }
        /* add element to the back of queue */
        queue[++rear] = data;
    }

    void queueDequeue()
    {
        if (front > rear)
        {
            cout << "\nQueue is empty\n";
            return ;
        }
        /* shift all elements to the left */
        for (int i = 0; i < rear; i++)
        {
            queue[i] = queue[i + 1];
        }
        /* decrease rear */
        rear--;
    }

    void queueDisplay()
    {
        if ( front > rear)
        {
            cout << "\n Queue is Empty \n";
            return ;
        }
        for (int i = front; i <= rear; i++)
        {
            cout <<" "<< queue[i] << " <-- ";
        }
        cout << "\n";
    }

    void queueFront()
    {
        if ( rear == -1)
        {
            cout << "\n Queue is Empty \n";
            return ;
        }
        cout << "\n Front Element is: "<< queue[front] << "\n";
    }

};

int main(void)
{
    // Create a queue of capacity 4
    Queue q(4);

    // Print queue elements
    q.queueDisplay();

    // Insert elements in the queue
    q.queueEnqueue(20);
    q.queueEnqueue(30);
    q.queueEnqueue(40);
    q.queueEnqueue(50);

    // Print queue elements
    q.queueDisplay();

    // Insert element in the queue
    q.queueEnqueue(60);

    // Print queue elements
    q.queueDisplay();

    // Dequeue elements
    q.queueDequeue();
    q.queueDequeue();

    printf("\nAfter two node deletions\n");

    // Print queue elements
    q.queueDisplay();
    
    printf("\nAfter one insertion\n");
    q.queueEnqueue(60);
    
    // Print queue elements
    q.queueDisplay();

    // Print front of the queue
    q.queueFront();

    return 0;
}