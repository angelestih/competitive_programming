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
    int M[3][3] = {{0,1,1},{1,0,0},{0,1,0}};

    while(n){
        if (n & 1){
            multiply(F, M);
        }
        multiply(M,M);

        n >>=1;
    }
    return F[0][0]+F[0][1];

}


int findNthTerm(int n)
{
    int F[3][3] = {{1,0,0},{1,0,0},{1,0,0}};

    if (n==0){
        return 1;
    }
    if (n==1 || n==2){
        return 1;
    }
    

    return power(F, n-2);
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
    cout << "F(1) = " << findNthTerm(n1) <<"\n";
    cout << "F(2) = " << findNthTerm(n2)<<"\n";
    cout << "F(3) = " << findNthTerm(n3)<<"\n";
    cout << "F(4) = " << findNthTerm(n4)<<"\n";
    cout << "F(5) = " << findNthTerm(n5)<<"\n";
    cout << "F(6) = " << findNthTerm(n6)<<"\n";
    cout << "F(7) = " << findNthTerm(n7)<<"\n";
    cout << "F(8) = " << findNthTerm(n8)<<"\n";
    cout << "F(9) = " << findNthTerm(n9)<<"\n";
    cout << "F(10) = " << findNthTerm(n10)<<"\n";

    return 0;
}

