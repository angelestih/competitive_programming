#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;




int binomialCoefficientMemoizationUtil(int n, int k, int** dp)
{
    /* return valid stored value */
    if (dp[n][k] != -1)
        return dp[n][k];

    /* base cases */
    if (k == 0 || k == n)
    {
        dp[n][k] = 1;
        return dp[n][k];
    }

    /* recursive formula */
    dp[n][k] = binomialCoefficientMemoizationUtil(n - 1, k - 1, dp) +
                binomialCoefficientMemoizationUtil(n - 1, k, dp);
    return dp[n][k];
}




int binomialCoefficientMemoization(int n, int k)
{
    /* create LUT */
    int** dp;
    dp = new int*[n+1];

    for (int i = 0; i < (n + 1); i++)
    {
        dp[i] = new int[k + 1];
    }
    /* initialize with -1 value for all elements */
    for (int i = 0; i < (n + 1); i++)
    {
        for (int j = 0; j < (k + 1); j++)
        {
            dp[i][j] = -1;
        }
    }
    return binomialCoefficientMemoizationUtil(n, k, dp);

}


int main()
{
    int n = 5, k = 2;

    cout << "Value of C(" << n << " , " << k << ") is "
        << binomialCoefficientMemoization(n, k);

    return 0;
}