#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


int etf(int n)
{
    int phi_n = n;

    for (int i = 2; i*i <= n; i++)
    {
        /* if n is divisible by i */
        if (n % i == 0)
        {
            /* keep decreasing phi_n by each divisor of i that also divides n  */
            while (n % i == 0)
            {
                n /= i;
            }
            phi_n -= phi_n / i;
        }
    }
    /* subtract all numbers from 1 to n that can divide n*/
    if (n > 1)
        phi_n -= phi_n/n;

    return phi_n;
}



int main()
{
    cout << etf(12);
    return 0;
}