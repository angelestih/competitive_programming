#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <stack>

using namespace std;

vector<int> monotonicIncreasing(vector<int>& nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && st.top() > nums[i])
        {
            st.pop();
        }

        st.push(nums[i]);

    }

    while (!st.empty())
    {
        result.insert(result.begin(), st.top());
        st.pop();
    }
    return result;

}

int main()
{
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    vector<int> result = monotonicIncreasing(nums);

    cout << "Monotonic increasing stack: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}