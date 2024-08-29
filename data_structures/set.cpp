#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <math.h>
#include <bits/stdc++.h>
#include <set>

using namespace std;

int main()
{

    set<int> set1; // Declaring set

    // inserting elements in set
    set1.insert(10);
    set1.insert(5);
    set1.insert(12);
    set1.insert(4);

    // printing elements of set
    for (auto i : set1) 
    {
        cout << i << ' ';
    }
    cout << endl;

    // check if 10 present inside the set
    if (set1.count(10) == 1) {
        cout << "Element is present in the set:" << endl;
    }

    // erasing 10 from the set
    set1.erase(5);

    // printing element of set
    for (auto it : set1) {
        cout << it << " ";
    }
    cout << endl;

    cout << "Minimum element: " << *set1.begin()
         << endl; // Printing maximum element
    cout << "Maximum element: " << *(--set1.end())
         << endl; // Printing minimum element

    cout << "Size of the set is: " << set1.size()
         << endl; // Printing the size of the set

    return 0;
}