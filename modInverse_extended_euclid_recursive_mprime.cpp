#include <bit>
#include <iostream>

using namespace std;


int gcd(int a, int b);

int power(int x, unsigned int y, unsigned int m);


void modInverse(int a, int m){

    int g=gcd(a, m);
    if (g != 1){
        cout << "Inverse doesn't exist"<<endl;
    }
    else{
        cout <<"Modular multiplicative inverse is: "<< power(a, m-2, m) <<endl;
    }
}




int power(int x, unsigned int y, unsigned int m){
    if (y == 0){
        return 1;
    }
    long long p = power(x, y/2, m) %m;

    p = (p*p)%m;

    if (y%2 == 1){
        p = (x * p)%m;
    }
    return p;
}


int gcd(int a, int b){
    if (a == 0){
        return b;
    }

    return gcd(b%a, a);

}



int main(){
    int a=3, m=11;

    modInverse(a, m);

    return 0;
}