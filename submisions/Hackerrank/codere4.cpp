// C++ program to find value of f(n) where f(n)
// is defined as
//    F(n) = F(n-1) + F(n-2) + F(n-3), n >= 3
// Base Cases :
//    F(0) = 0, F(1) = 1, F(2) = 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
ll fstmtrx[3][3]={{3,1,1}, {0,0,0}, {0,0,0}};
long long M[3][3] = {{8/3,-2/3,2/3}, {0,0,0}, {0,0,0}};

// A utility function to multiply two matrices
// a[][] and b[][].  Multiplication result is
// stored back in b[][]

void multiply(ll a[3][3], ll b[3][3])
{
    // Creating an auxiliary matrix to store elements 
    // of the multiplication matrix
    ll mul[3][3];
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
int power(ll F[3][3], ll n)
{
    
    if (n==1)
        return (8*fstmtrx[0][0] + 2*fstmtrx[0][1] - 2*fstmtrx[0][2])/3;
 
 	//dicari akar ke 2
    power(F, n/2);
 	//dikuadratkan , biar gak kali berulang2
    multiply(F, F);
    
    //di titik ini F sudah bentuk x^2
 
 	//jaga2 kalau n-2 bukan bil genap
    if (n%2 != 0)
        multiply(F, M);
 
    // Multiply it with initial values i.e with
    // F(0) = 0, F(1) = 1, F(2) = 1
    multiply(F, fstmtrx);
    
    return (8*F[0][0] + 2*F[0][1] - 2*F[0][2])/3 ;
}
 
// Return n'th term of a series defined using below
// recurrence relation.
// f(n) is defined as
//    f(n) = f(n-1) + f(n-2) + f(n-3), n>=3
// Base Cases :
//    f(0) = 0, f(1) = 1, f(2) = 1

int findNthTerm(ll n)
{
    ll F[3][3] = {{8/3,-2/3,2/3}, {0,0,0}, {0,0,0}} ;
 
    return power(F, n-2);
}
 
// Driver code
int main()
{
   int n = 5;
 
   cout << "F(5) is " << findNthTerm(n);
 
   return 0;
}
