#include <bit>
#include <iostream>
#include <vector>
using namespace std;

unsigned long int catalan( unsigned int n)
{
    /* create array with n+1 elements */
    unsigned long int catalan[n+1];
    /* base cases */
    catalan[0] = catalan[1] = 1;

    for (int i = 2; i<=n; i++)
    {
        catalan[i] = 0; // initialized to 0
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j]*catalan[i-j-1]; // use recursive formula


    }

    return catalan[n];

}



int main()
{
    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";


    return 0;
}