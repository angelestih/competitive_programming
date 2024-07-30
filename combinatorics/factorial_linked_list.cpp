#include <bit>
#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node(int n)
        {
            data = n;
            prev = NULL;
        }
};

void multiply(Node* head, int i)
{
    /* need pointers to next and previous nodes*/
    Node *temp = head,
        *prevPtr = head; 

    int carry = 0;
    while(temp != NULL)
    {
        /* multiply each digit in linked list by value of i */
        int prod = temp->data * i + carry;
        temp->data = prod % 10;
        carry = prod / 10;
        prevPtr = temp;
        temp = temp->prev;
    }

    while(carry != 0)
    {
        /* create nodes for remaining digits of carry */
        prevPtr->prev = new Node((int)(carry % 10));
        carry = carry / 10;
        prevPtr = prevPtr->prev;
    }
}

void print(Node* head)
{
    if (head == NULL)
        return;
    print(head->prev);
    cout << head->data;
}

int main()
{
    int n = 100;
    Node *head = new Node(1);

    for (int i = 2; i <= n; i++)
    {
        multiply(head, i);
    }

    cout << "Factorial of " << n << " is : \n";
    print(head);
    cout << endl;

    return 0;

}
