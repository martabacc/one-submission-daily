#include<bits/stdc++.h>
using namespace std;
#define llf long long float
 
llf fstmtrx[3][3]={{3.0,1.0,1.0}, {0.0,0.0,0.0}, {0.0,0.0,0.0}};
long long float M[3][3] = {{0.0,0.0,0.0}, {1.0,0.0,0.0}, {0.0,1.0,0.0}};

void multiply(llf a[3][3], llf b[3][3])
{
    // Creating an auxiliary matrix to store elements 
    // of the multiplication matrix
    llf mul[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
                mul[i][j] += a[i][k]*b[k][j];
        }
    }
 
    // storing the muliplication resul in a[][]
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] = mul[i][j];  // Updating our matrix
}
 
// Function to compute F raise to power n-2.
int power(llf F[3][3], llf n)
{
    
    if (n==1)
        return F[0][0]+F[0][1];
 
 	//dicari akar ke 2
    power(F, n/2);
 	//dikuadratkan , biar gak kali berulang2
    multiply(F, F);
    
    //di titik ini F sudah bentuk x^2
 
 	//jaga2 kalau n-2 bukan bil genap
    if (n%2 != 0)
        multiply((llf)F, M);
 
    // Multiply it with initial values i.e with
    // F(0) = 0, F(1) = 1, F(2) = 1
    multiply(F, fstmtrx);
    
    return M[0][0]*(llf)F[0][0] + M[0][1]*(llf)F[0][1] - M[0][2]*(llf)F[0][2] ;
}
 
// Return n'th term of a series defined using below
// recurrence relation.
// f(n) is defined as
//    f(n) = f(n-1) + f(n-2) + f(n-3), n>=3
// Base Cases :
//    f(0) = 0, f(1) = 1, f(2) = 1

llf findNthTerm(llf n)
{
    llf F[3][3] = {{8/3,-2/3,2/3}, {1,0,0}, {0,1,0}} ;
 
    return power(F, n-2);
}
 
// Driver code
int main()
{
   llf n = 5;
 	M[0][0] = 8/3;
 	M[0][1] = -2/3;
 	M[0][2] = 2/3;
   cout << "F(5) is " << findNthTerm(n);
 
   return 0;
}
