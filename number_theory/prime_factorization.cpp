#include <iostream>
#include <bit>
#include <vector>
using namespace std;


#define MAXN 100001

vector <int> spf(MAXN+1, 1);

void sieve(){
    spf[0]=0;
    for(int i = 2; i<=MAXN; i++){
        if (spf[i] == 1){

            for (int j = i; j<=MAXN; j +=i){
                if (spf[j]==1){
                    spf[j] = i;
                }
            }

        }
    }
}
vector<int> getFactorization(int n){
    vector<int> factors;
    while(n != 1){
        factors.push_back(spf[n]);
        n = n/spf[n];
    }
    
    return factors;
}

int main(int argc, char const* ){
    sieve();
    int n = 10000;
    cout << "Prime factorization of "<< n <<" is ";
    vector<int> factors = getFactorization(n);

    for (int i=0; i < factors.size(); i++){
        cout << factors[i] << " ";
    
    }
    cout << endl;
    return 0;
}