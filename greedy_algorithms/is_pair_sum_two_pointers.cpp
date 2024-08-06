#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;


bool isPairSum(vector<int>& a, int n, int x)
{
    int i = 0;

    int j = n - 1;

    while(i < j)
    {
        if (a[i] + a[j] == x)
            return true;

        else if (a[i] + a[j] < x)
            i++;
        else
            j--;
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