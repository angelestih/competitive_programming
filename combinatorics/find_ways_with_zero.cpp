#include <bit>
#include <iostream>
#include <vector>
using namespace std;


int c(int n, int r){
    /* define binomial coefficient */
    /* c(n, r) = n!/(r!*(n-r)!)*/
    r = min(r, n-r);
    int ans = 1;

    for (int i = 0; i < r; i++)
    {
        ans = ans * (n-i);
        ans = ans / (i+1);
    }

    return ans;

}

int getWaysWithZero(int n, int k){
    return c(n+k-1, k-1);
}


int main(){
    int n = 4, k = 2;

    cout << "Ways to divide " << n << " objects among " 
        << k << " groups such that a group can have 0 objects are " 
        << getWaysWithZero(n, k) << endl;
    return 0;
}
