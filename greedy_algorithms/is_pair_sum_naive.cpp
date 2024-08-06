#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;


bool isPairSum(vector<int>& a, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            {
                if (i==j)
                    continue; //cannot return same index for both

                if (a[i] + a[j] == x)
                    return true;
                
                if (a[i] + a[j] > x)
                    break; // not gonna find pair since numbers will be larger
            }
    }

    return false;
}


int main()
{
    vector<int> arr = {2, 3, 5, 8, 9, 10, 11};

    int val = 17;

    int arrSize = arr.size();

    sort(arr.begin(), arr.end());

    cout << isPairSum(arr, arrSize, val);





    return 0;
}