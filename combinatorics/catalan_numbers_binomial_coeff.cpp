#include <bit>
#include <iostream>
#include <vector>
using namespace std;




unsigned long int binomialCoeff(unsigned int n, unsigned int r)
{
    unsigned long int res = 1;
    /* c(n, r) = c(n, n-r) */
    if (r > n - r)
    {
        r = n - r;
    }

    /* c(n , r) = n!/((n-r)!r!) = (n-r+1)*...*n /r!*/
    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;

}



unsigned long int catalan( unsigned int n)
{
    /* using formula Cn = (1/(n+1))*c(2n, n) */
    unsigned long int c = binomialCoeff(2*n, n);

    return c / (n + 1);

}



int main()
{
    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";


    return 0;
}