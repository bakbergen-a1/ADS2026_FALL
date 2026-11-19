/*
Asman is very curious and likes to check whether a number is prime or not.

Recall that a prime number is an integer greater than 
 that has exactly two positive divisors: 
 and the number itself. In particular, 
 is not prime, because it has only one positive divisor.

Given an integer 
, determine whether it is prime.

Input
The only line of the input contains one integer 
 (
).

Output
Print “YES” (without quotes) if 
 is prime, and “NO” (without quotes) otherwise.

Note
In the first example 
. It has only one positive divisor, so it is not prime.

In the second example 
 is composite.

In the third and fourth examples 
 and 
 are prime.

Examples
Input 1
1
Output 1
NO
Input 2
10
Output 2
NO
Input 3
2
Output 3
YES
Input 4
97
Output 4
YES
*/


#include <iostream>
using namespace std;
bool prime(int n){
    int s=0;
    for(int i=2;i<=n;++i){
        if(n%i==0) s+=1;
    }
    if(n==1) return false;
    else if(s==1) return true;
    else return false; 
}
int main() {
    int n;
    cin>>n;
    if(prime(n)) cout<<"YES";
    else cout<<"NO";
    return 0;
}