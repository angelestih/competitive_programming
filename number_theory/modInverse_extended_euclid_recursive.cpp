#include <bit>
#include <iostream>

using namespace std;


int gcdExtended(int a, int b, int* x, int* y);


void modInverse(int a, int m){
    int x;
    int y;

    int g=gcdExtended(a, m, &x, &y);
    if (g != 1){
        cout << "Inverse doesn't exist"<<endl;
    }
    else{
        int res = (x%m + m)%m;
        cout <<"Modular multiplicative inverse is: "<< res <<endl;
    }
}


int gcdExtended (int a, int b, int* x, int* y){
    if (a==0){
        *x = 0;
        *y = 1;
        return b;
    }

    int x1;
    int y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    *x = y1-(b/a)*x1;
    *y = x1;

    return gcd;
}



int main(){
    int a=3, m=11;

    modInverse(a, m);

    return 0;
}