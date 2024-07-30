#include <bit>
#include <iostream>
#include <vector>
using namespace std;

int binomialCoefficient(int n, int k)
{
    /* known cases */
    if (k > n)
        return 0;

    if (k == 0 || k == n)
        return 1;
    /* recursive formula */
    return binomialCoefficient(n-1, k-1) + binomialCoefficient(n-1, k);
}

int main()
{
    int n = 5, k = 2;

    cout << "Value of C(" << n << " , " << k << ") is "
        << binomialCoefficient(n, k);

    return 0;
}