#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
using namespace std;


long int pow(long int b, long int exp, long int mod)
{
    /* binary exponentiation for power of large number and % mod */
    long int res = 1;
    while(exp > 0)
    {
        if(exp & 1)
        {
            res = (res * b) % mod;
        }

        b = (b * b) % mod;
        exp >>= 1;
    }
    return res;
}

int nCr(int n, int r)
{
    /* base case */
    if (r > n)
    {
        return 0;
    }

    /* using property c(n,r) = c(n, n-r) */
    /* n-r < r means less operations */

    if (n-r < r)
    {
        r = n - r;
    }

    /* store smallest prime factors for each number from 1 to n */
    int SPF[n+1];

    for (int i = 1; i <= n; i++)
    {
        /* initialized to itself */
        SPF[i] = i;
    }

    for (int i = 4; i <= n; i+= 2)
    {
        SPF[i] = 2;
    }

    for (int i = 3; i*i < n; i+= 2)
    {
        /* check if i is prime */
        if (SPF[i] == i)
        {
            /* all multiples of i have i as a divisor, */
            /* so add i to their prime factorization */
            for (int j = i * i; j < n; j += i)
            {
                if (SPF[j] == j)
                {
                    SPF[j] = i;
                }
            }
        }
    }

    /* hash map to store exponent of each prime in c(n, r) */

    map< int, int> prime_pow;

    /* c(n ,r) = n!/( (n-r)!*r! ) then c(n, r) = (r + 1)*...*n / (n-r)! */
    /* just note r! was cancelled on both numerator and denominator */

    /* for numerator, add exponent of each same SPF */
    for  (int i = r + 1; i < n + 1; i++)
    {
        int t = i;
        
        /* here we can find the factorizatio of i */
        while (t > 1)
        {
            if (!prime_pow[SPF[t]])
            {
                prime_pow[SPF[t]] = 1;
            }
            else
                prime_pow[SPF[t]]++;
            
            /* divide number by its factor */
            t /= SPF[t];
        }
    }

    /* for denominator, subtract the exponent of each prime factor */
    for  (int i = 1; i < n - r + 1; i++)
    {
        int t = i;
        
        /* here we can find the factorizatio of i */
        while (t > 1)
        {
            if (!prime_pow[SPF[t]])
            {
                prime_pow[SPF[t]] = 1;
            }
            else
                prime_pow[SPF[t]]--;
            
            /* divide number by its factor */
            t /= SPF[t];
        }
    }    

    long int res = 1, mod = 1e9 + 7;

    /* c(n , r) is the product of all factors */
    /* to the power of their respective exponents */
    for (auto it : prime_pow)
    {
        res = (res * pow(it.first, prime_pow[it.first], mod)) % mod;
    }

    return (int)res;

}


int main()
{
    int n = 5, r = 2;

    cout << "Value of C(" << n << " , " << r << ") is "
        << nCr(n, r);

    return 0;
}