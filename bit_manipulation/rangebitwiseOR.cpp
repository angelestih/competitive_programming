#include <bit>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> prefixsumBit(vector<int>& nums)
{
    int n = nums.size();

    vector<vector<int>> temp(n+1, vector<int>(32, 0));
    for (int i = 1; i <= n; ++i)
    {
        /* storing bit info in temp */
        int num = nums[i-1];

        for (int j = 0; j < 32; ++j)
        {
            if (((1 << j) & num) != 0)
            {
                temp[i][j] = 1;
            }
            
        }
        
    }

    vector<vector<int>> psum(n+1, vector<int>(32, 0));
    for (int j = 0; j < 32; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            psum[i][j] = psum[i-1][j] + temp[i][j];
        }
        
    }
    return psum;
    
    
}


int rangeBitwiseOR(vector<vector<int>>& psum, int l, int r)
{
    int result = 0;
    for (int j = 0; j < 32; ++j)
    {
        /* calculate the count of elements with jth bit set in range[l, r] */
        int count = psum[r][j] - psum[l-1][j];

        if (count > 0)
        {
            /* if count of elements is greater than 0, add to result */
            result = result + (1<<j);
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {13, 11, 2, 3, 6};

    int l =2, r = 4;

    vector<vector<int>> psum = prefixsumBit(nums);

    cout << "Bitwise OR of range [2,4] is :"
         << rangeBitwiseOR(psum, l, r);
    
    return 0;
}