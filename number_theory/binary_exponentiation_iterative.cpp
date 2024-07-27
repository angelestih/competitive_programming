#include <bit>
#include <iostream>
using namespace std;

long long power(long long a, long long b){
    long long result = 1;
    cout << "value of A=" << a << "\n";
    cout << "value of B=" << b << "\n";
    cout << "value of Result=" << result << "\n";

    while(b){
        cout << "Values of variables before operations:"<<"\n";
        cout << "value of A=" << a << "\n";
        cout << "value of B=" << b << "\n";
        cout << "value of Result=" << result << "\n";
        if (b & 1)
            result = result * a;

        a = a*a;
        b >>= 1;

        cout << "Values of variables AFTER operations:"<<"\n";
        cout << "value of A=" << a << "\n";
        cout << "value of B=" << b << "\n";
        cout << "value of Result=" << result << "\n";
    }
    return result;
}


int main(){ 
    cout << power(2,12) << "\n";
    return 0;
}
