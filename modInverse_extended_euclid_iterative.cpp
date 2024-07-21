#include <bit>
#include <iostream>

using namespace std;


int modInverse(int a, int m){

    int m0=m;

    int x=0;
    int y=1;

    if (m==1){
        return 0;
    }

    while (m > 1){
        int q = a/m;

        int t = m;

        m = a%m;
        a = t;

        t = x;

        x = y - q*x;
        y = t;


    
    }

    if (x<0){
        x += m0;
    }
    return x;

}


int main(){
    int a=7, m=4;

    cout << "Modular multiplicative inverse is: " << modInverse(a, m);

    return 0;
}