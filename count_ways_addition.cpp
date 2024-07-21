#include <bit>
#include <iostream>
using namespace std;


int mod = 1e9 + 7;

void multiply(int a[4][4], int b[4][4]){
    int mul[4][4];

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++ ){
            mul[i][j]=0;

            for (int k=0; k<4; k++){
                mul[i][j] = ((a[i][k] * b[k][j])%mod + mul[i][j])%mod;
            }
        }
    }
    for (int i=0; i<4; i++)
        for(int j=0;j<4; j++)
            a[i][j] = mul[i][j];
}


int power(int f[4][4], int n)
{
    int m[4][4] = {{1,0,1,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};

    while(n){
        if (n & 1){
            multiply(f, m);
        }
        multiply(m,m);

        n >>=1;
    }
    return f[0][0] +f[2][0]+f[3][0];
    

}


int countWays(int n)
{
    int f[4][4] = {{4,0,0,0},{2,0,0,0},{1,0,0,0},{1,0,0,0}};

    if (n==0){
        return 0;
    }
    if (n==1 || n==2){
        return 1;
    }
    if (n==3){
        return 2;   
    }
    if (n==4){
        return 4;
    }   

    return power(f, n-5);
}
int main(){
    int n1=1;
    int n2=2;
    int n3=3;
    int n4=4;
    int n5=5;
    int n6=6;
    int n7=7;
    int n8=8;
    int n9=9;
    int n10=10;
    cout << "countWays(1) = " << countWays(n1) <<"\n";
    cout << "countWays(2) = " << countWays(n2)<<"\n";
    cout << "countWays(3) = " << countWays(n3)<<"\n";
    cout << "countWays(4) = " << countWays(n4)<<"\n";
    cout << "countWays(5) = " << countWays(n5)<<"\n";
    cout << "countWays(6) = " << countWays(n6)<<"\n";
    cout << "countWays(7) = " << countWays(n7)<<"\n";
    cout << "countWays(8) = " << countWays(n8)<<"\n";
    cout << "countWays(9) = " << countWays(n9)<<"\n";
    cout << "countWays(10) = " << countWays(n10)<<"\n";

    return 0;
}

