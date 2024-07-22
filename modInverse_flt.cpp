#include <iostream>
#include <bit>
#include <vector>
using namespace std;


int power(int x, unsigned int y, unsigned int m);

int gcd(int a, int b);


void modInverse(int a, int m){
    if(gcd(a, m)!= 1){
        cout << "Inverse doesn't exist" << endl;
    }
    else{
        cout << "Modular multiplicative inverse is " << power(a, m-2, m);
    }
}

int gcd(int a, int b){
    if (a==0){
        return b;
    }
    return gcd(b%a,a);

}


int power(int x, unsigned int y, unsigned int m){
    if (y == 0){
        return 1;
    }
    int p = power(x, y/2, m)%m;

    p = (p*p)%m;

    return (y%2 == 0) ? p : (x*p)%m;
}


int main(){
    int a=3, m =11;

    modInverse(a, m);

    return 0;
}