#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        int minXvalue( vector<int>& arr, int H)
        {
            int X = *max_element(arr.begin(), arr.end());
            int low = 0, high = X;

            while (low <= high)
            {
                int temp = (low + high) / 2;

                int required_time = 0;

                /* calculate required time to eat all fruits */
                for (auto value : arr)
                {
                    /* using ceiling value by adding max remainder */
                    required_time += (value + temp - 1) / temp;
                }

                if (required_time <= H)
                {
                    X = temp;

                    high = temp - 1; // less eating speed --> more hours to eat all fruits
                }

                else
                {
                    low = temp + 1; // more eating speed --> less hours to eat all fruits
                }
            }
            return X;
        }
};


int main()
{
    Solution solution;
    vector<int> arr = {8, 11, 18, 20};

    int H = 10;
    int result = solution.minXvalue(arr, H);
    cout << "Minimum value of X will be : " << result << endl;

    return 0;
}