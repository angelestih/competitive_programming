#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <stack>

using namespace std;

class MaxHeap 
{
    int* arr;
    int maxSize;
    int heapSize; // current size
public:
    MaxHeap(int totSize);

    void MaxHeapify(int i);

    int parent(int i)
    {
        return (i- 1) / 2;
    }

    int lChild(int i)
    {
        return (2 * i + 1);
    }
    
    int rChild(int i)
    {
        return (2 * i + 2);
    }

    int removeMax();

    void increaseKey(int i, int x);

    int getMax()
    {
        return arr[0];
    }

    int currentSize()
    {
        return heapSize;
    }

    void deleteKey(int i);

    void insertKey(int x);

};

MaxHeap::MaxHeap(int totSize)
{
    heapSize = 0;
    maxSize = totSize;
    arr = new int[maxSize];
}

void MaxHeap::MaxHeapify(int i)
{
    int l =lChild(i);
    int r = rChild(i);
    int largest = i;
    /* base cases */
    if (l < heapSize && arr[l] > arr[largest])
        largest = l;
    if (r < heapSize && arr[r] > arr[largest])
        largest = r;
    /* recursion */
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(largest);
    }
}

int MaxHeap::removeMax()
{
    if (heapSize <= 0)
        return INT_MIN;
    if (heapSize == 1)
    {
        heapSize--;
        return arr[0];
    }
    int root = arr[0]; //variable to save this value and return it later
    arr[0] = arr[heapSize - 1];
    heapSize--;
    MaxHeapify(0);

    return root;
}

void MaxHeap::increaseKey(int i, int x)
{
    arr[i] = x;
    /* swapping with parent, that's why it only works for increasing a key */
    while (i != 0 && arr[parent(i)] < arr[i])
    {
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

void MaxHeap::deleteKey(int i)
{
    increaseKey(i, INT_MAX);
    removeMax();
}

void MaxHeap::insertKey(int x)
{
    if (heapSize == maxSize)
    {
        cout << "\nOverflow: Can not insert new value\n";
        return ;
    }

    heapSize++;
    int i = heapSize - 1;
    arr[i] = x; // inserting value at bottom rightmost leave
    /* swap if with parent if needed */
    while (i != 0 && arr[parent(i)] < arr[i])
    {
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }

    
}

int main() 
{ 
    // Assuming the maximum size of the heap to be 15. 
    MaxHeap h(15); 
  
    // Asking the user to input the keys: 
    int k, i, n = 6, arr[10]; 
    cout << "Entered 6 keys: 3, 10, 12, 8, 2, 14 \n"; 
    h.insertKey(3); 
    h.insertKey(10); 
    h.insertKey(12); 
    h.insertKey(8); 
    h.insertKey(2); 
    h.insertKey(14); 
  
    // Printing the current size 
    // of the heap. 
    cout << "The current size of the heap is "
         << h.currentSize() << "\n"; 
  
    // Printing the root element which is 
    // actually the maximum element. 
    cout << "The current maximum element is " << h.getMax() 
         << "\n"; 
  
    // Deleting key at index 2. 
    h.deleteKey(2); 
  
    // Printing the size of the heap 
    // after deletion. 
    cout << "The current size of the heap is "
         << h.currentSize() << "\n"; 
  
    // Inserting 2 new keys into the heap. 
    h.insertKey(15); 
    h.insertKey(5); 
    cout << "The current size of the heap is "
         << h.currentSize() << "\n"; 
    cout << "The current maximum element is " << h.getMax() 
         << "\n"; 
  
    return 0; 
}