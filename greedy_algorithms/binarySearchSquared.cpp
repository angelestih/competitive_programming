#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int binarySearchSquared( int x)
{
    int low = 0;
    int high = x;
    int mid;
    int answer = -1;

    while (low <= high)
    {
        mid = (high + low) / 2;

        if (mid * mid < x)
        {
            low = mid + 1;
            answer = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << answer;
    return answer;
}


int main()
{
    int x = 101;

    binarySearchSquared(x);

    return 0;
}