#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iomanip>

using namespace std;

double f(double x)
{
    return 2 * ( x * x ) - 10 * x + 2;
}

int main()
{
    double l = -1e5, r = 1e5;
    while((r - l) >= 1e-9)
    {
        double mid1 = l + (r - l) / 3.0;
        double mid2 = r - (r - l) / 3.0;

        double f_mid1 = f(mid1), f_mid2 = f(mid2);

        if (f_mid1 < f_mid2)
        {
            r = mid2;
        }
        else if (f_mid1 > f_mid2)
        {
            l = mid1;
        }
        else if (f_mid1 = f_mid2)
        {
            l = mid1;
            r = mid2;
        }
    }

    cout << setprecision(9) << l << "\n";

    return 0;
}