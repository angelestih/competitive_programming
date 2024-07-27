#include <iostream>
#include <bit>
#include <vector>
using namespace std;


int gcd(int a, int b){
    return (a%b==0) ? abs(b) : gcd(b, a%b);
}

bool isDiophantineEquation(int a, int b, int c){
    return (c%gcd(a,b) == 0);
}

int main(){
    int a=3, b=6, c=8;
    isDiophantineEquation(a, b, c) ? cout << "It is a Linear Diophantine equation\n" :
                                     cout << "It is not a Linear Diophantine equation\n"; 
    return 0;
}