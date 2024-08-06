#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;


int maxSum(int arr[], int n, int k)
{
    if (n <= k)
    {
        cout << "Invalid k \n";

        return -1;
    }

    int max_sum = 0;
    /* calculate sum of first window */
    for (int i = 0; i < k; i++)
        max_sum += arr[i];
    

    int window_sum = max_sum;
    /* calculate sum of sliding window and replace max if needed */
    for (int i = k; i < n; i++)
    {
        window_sum = arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }


    return max_sum;

}

int main()
{
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};

    int k = 4;

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxSum(arr, n, k);

    return 0;
}