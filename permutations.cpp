#include <bit>
#include <iostream>
#include <vector>

using namespace std;

void apply(vector<int>& s, vector<int>& p){
    vector<int> temp(s.size());
    for (int i=1; i<s.size(); i++){
        temp[i] = s[p[i]];
    }

    for(int i=1; i<s.size(); i++){
        s[i] = temp[i];
    }
}

void solve(vector<int>& s, vector<int>& p, int k){
    while(k){
        if(k&1){
            apply(s,p);
        }
        apply(p,p);
        k>>=1;
    }
}


int main(){
    vector<int> p{0,2,3,4,1};
    vector<int> s{0,2,1,3,4};
    int k = 2;
    solve(s,p,k);
    cout<< "New sequence is ";
    for(int i=1; i<s.size(); i++){
        cout<< s[i] <<" ";
    }
    return 0;
}