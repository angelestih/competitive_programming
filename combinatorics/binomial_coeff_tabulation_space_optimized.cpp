#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int binomialCoefficientTabulation(int n, int k)
{
    /* create array */
    int c[k + 1];
    memset(c, 0, sizeof(c));
    
    c[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, k); j > 0; j--)
        {
            /* recursive formula using stored values */
            c[j] = c[j - 1] + c[j];
        }
        
    }

    return c[k];    

}


int main()
{
    int n = 5, k = 2;

    cout << "Value of C(" << n << " , " << k << ") is "
        << binomialCoefficientTabulation(n, k);

    return 0;
}