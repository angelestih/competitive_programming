#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <stack>

using namespace std;

class Queue 
{
    int front, rear, capacity;
    int* queue;
public:
    Queue (int c)
    {
        /* constructor */
        front = -1;
        rear = -1;
        capacity = c;
        queue = new int[c];
    }

    void queueEnqueue(int data);
    int queueDequeue();
    void queueDisplay();
};


    void Queue::queueEnqueue(int data)
    {
        if ((front == 0 && rear == capacity - 1) || ((rear + 1) % capacity == front))
        {
            cout << "\nQueue is Full\n";
            return ;
        }
        else if (front == -1)
        {
            front = rear = 0; // first element
            queue[rear] = data;
        }
        else if (rear == capacity - 1 && front != 0)
        {
            rear = 0;
            queue[rear] = data;
        }
        else
        {
            rear++;
            queue[rear] = data;
        }
    }

    int Queue::queueDequeue()
    {
        if (front == -1)
        {
            cout << "\nQueue is Empty\n";
            return INT_MIN;
        }
        int data = queue[front];
        queue[front] = -1;
        
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == capacity - 1)
            front = 0;
        else
            front++;
        
        return data;
    }

    void Queue::queueDisplay()
    {
        if ( front == -1)
        {
            cout << "\n Queue is Empty \n";
            return ;
        }
        cout << "\n Elements in Circular Queue are: \n";

        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout <<" "<< queue[i] << " <-- ";
            }
            cout << "\n";
        }
        else
        {
            for (int i = front; i < capacity; i++)
                cout << " "<< queue[i] << " <-- ";
            for (int i = 0; i<= rear; i++)
                cout << " "<< queue[i] << " <-- ";
        }

        
    }

int main(void)
{
    Queue q(5);
 
    // Inserting elements in Circular Queue
    q.queueEnqueue(14);
    q.queueEnqueue(22);
    q.queueEnqueue(13);
    q.queueEnqueue(-6);
 
    // Display elements present in Circular Queue
    q.queueDisplay();
    
    // Deleting elements from Circular Queue
    cout << "\nDeleted element : " << q.queueDequeue() << "\n";
    cout << "\nDeleted element : " << q.queueDequeue() << "\n";
    
    q.queueEnqueue(9);
    q.queueEnqueue(20);
    q.queueEnqueue(5);
 
    q.queueDisplay();
 
    q.queueEnqueue(20);
    return 0;
}




