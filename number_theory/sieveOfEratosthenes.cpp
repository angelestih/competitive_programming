#include <bit>
#include <iostream>
#include <cstring>

using namespace std;

void sieveOfEratosthenes(int n){
    bool prime[n+1];


    //for (int p = 0; p < n+1; p++){
    //    prime[p] = true;
    //}
    memset(prime, true, sizeof(prime));

    for (int p = 2; p*p <=n; p++){
        if (prime[p] == true){

            for (int i = p*p; i <= n; i = i + p){
                prime[i] = false;
            }


        }
    }

    for (int p=2; p <=n; p++){
        if(prime[p])
            cout << p << " ";
    }

}


int main(){
    int n = 30;
    cout << "Prime numbers smaller than or equal to " << n << endl;
    sieveOfEratosthenes(n); 
    return 0;
}