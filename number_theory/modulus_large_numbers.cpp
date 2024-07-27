#include <bit>
#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int multiply_mod(int a, int b){
    int res = 0;
    while(b){
        if (b&1){
            res = (res + a) % mod;
        }

        a = (a*2) % mod;

        b>>=1;
    }


    return res;
}

int main(){
    int a = 1e9;
    int b =1e9;

    cout << multiply_mod(a, b) << "\n";

    return 0;
}

