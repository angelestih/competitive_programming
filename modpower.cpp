#include <bit>
#include <iostream>

using namespace std;

int modpower(int x, int n, int m){
    if(n==0){
        return 1;
    }
    long long  u = modpower(x, n/2, m);
    u = (x*x) % m;
    if (n & 1){
        u = (u*x) % m;
    }
    
    return u;

}

int main(){

    cout << modpower(5,2,7)<< "\n";
    return 0;
}