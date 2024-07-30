#include <bit>
#include <iostream>
#include <vector>
using namespace std;



unsigned long int catalan( unsigned int n)
{
    /* using formula Cn = (Cn-1)*(4n-2)/(n+1) */

    unsigned long int res = 1;

    for (int i = 1; i <= n; i++)
    {
        res = (res * (4 * i - 2)) / (i + 1);
    }
    return res;
}



int main()
{
    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";


    return 0;
}