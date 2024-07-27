#include <bit>
#include <iostream>

using namespace std;

int modInverse(int a, int m){
    for (int x=0; x<m; x++){
        if (((a%m)*(x%m)) % m == 1){
            return x;
        }
    }
}



int main(){
    int a=3, m=11;

    cout<<"Modular multiplicatibe of 3 mod 11 is: "<< modInverse(a, m) <<"\n";

    return 0;
}