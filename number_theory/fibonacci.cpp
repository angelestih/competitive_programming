#include <bit>
#include <iostream>
using namespace std;

void multiply(int a[3][3], int b[3][3]){
    int mul[3][3];

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++ ){
            mul[i][j]=0;

            for (int k=0; k<3; k++){
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i=0; i<3; i++)
        for(int j=0;j<3; j++)
            a[i][j] = mul[i][j];
}


int power(int F[3][3], int n)
{
    int M[3][3] = {{1,1,0},{1,0,0},{0,1,0}};

    while(n){
        if (n & 1){
            multiply(F, M);
        }
        multiply(M,M);

        n >>=1;
    }
    return F[0][0] + F[0][1];

}


int findNthTerm(int n)
{
    int F[3][3] = {{1,0,0},{1,0,0},{0,0,0}};

    if (n==0){
        return 0;
    }
    if (n==1 || n==2){
        return 1;
    }

    return power(F, n-2);
}
int main(){
    int n=4;

    cout << "F(4) = " << findNthTerm(n);

    return 0;
}

