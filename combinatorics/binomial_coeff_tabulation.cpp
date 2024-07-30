#include <bit>
#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b);

int binomialCoefficientTabulation(int n, int k)
{
    /* create array */
    int c[n + 1][k + 1];
    int i, j;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j==i)
                c[i][j] = 1;

            else
                /* recursive formula using stored values */
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
        
    }

    return c[n][k];    

}



int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int n = 5, k = 2;

    cout << "Value of C(" << n << " , " << k << ") is "
        << binomialCoefficientTabulation(n, k);

    return 0;
}