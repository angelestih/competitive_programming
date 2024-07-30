#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int nCr(int n, int r)
{
    /* base case */
    if (r > n)
        return 0;
    
    /* use property c(n, r) = c(n, n-r) */
    if (r > n - r)
        r = n - r;
    
    int mod = 1e9 + 7;
    /* to store elements from (n-r+1) all the way to n*/
    int arr[r];
    /* later on we will use the fact that c(n , r) = n! /((n-r)! * r!) */
    /*                                             = n * (n-1) * ... * (n-r+1)/r! */

    for (int i = n-r+1; i <= n; i++)
    {
        /* these are in the numerator */
        arr[i+r-n-1] = i; 
        /* the denominator is simply 1 to r*/
    }
    

    long int ans = 1;
    for (int k = 1; k < r + 1; k++)
    {
        int j = 0, i = k;

        while(j < r)
        {
            int x = gcd(i, arr[j]);
            /* get gcd with elements from numerator and denominator */
            /* if gcd > 1 then divide both elements by same gcd */
            if (x > 1)
            {
                arr[j] /= x;
                i /= x;
            }
            if (i == 1)
            {
                break;
            }
            j++;
        }
    }

    /* just multiply elements in numerator */
    for(int i : arr)
    {
        ans = (ans * i) % mod;
    }

    return (int) ans;

}


int main()
{
    int n = 5, r = 2;

    cout << "Value of C(" << n << " , " << r << ") is "
        << nCr(n, r);

    return 0;
}