#include <bit>
#include <iostream>
#include <vector>
using namespace std;

int binomialCoefficient(int n, int r)
{
    /* base case */
    if (r > n)
        return 0;
    /* mod has to be a large number so that there's no overflow */
    /* it also needs to be a prime number to use the mod inverse property */
    long long int mod = 1e9 + 7;
    long long int inv[r + 1] = {0};
    inv[0] = 1;
    if (r + 1 >= 2)
        inv[1] = 1;
    for (int i = 2; i <= r; i++)
    {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }

    int res = 1;

    /* multiply all inv[i] using mod product property to find (1/r!) */

    for (int i = 2; i <= r; i++)
    {
        res = ((res % mod) * (inv[i] % mod)) % mod;
    }

    /* for numerator, mulitply factors using mod product proerty */

    for (int i = n - r + 1; i <= n; i++)
    {
        res = ((res % mod) * (i % mod)) % mod;
    }
    return res;

}

int main()
{
    int n = 5, r = 2;

    cout << "Value of C(" << n << " , " << r << ") is "
        << binomialCoefficient(n, r);

    return 0;
}