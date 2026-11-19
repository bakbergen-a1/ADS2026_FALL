/*
Compute a^n mod m.

The straightforward way — multiply a
 by itself n
 times — needs O(n)
 operations. For 
 up to 
 that is hopeless: even at a billion multiplications per second it would take more than thirty years.

Binary exponentiation does the same job in O(logn)
 multiplications. It is based on a simple observation: if 
 is even, then a^n=(a^n/2)^2
, and if n
 is odd, then a^n=a*a^n-1
. For example, 
 — only four multiplications instead of ten.

Input
The only line contains three integers 
, 
 and 
 (
, 
, 
).

Output
Print a single integer — the value of 
.

Note
In the first example 
, and 
.

In the second example 
. Every integer is divisible by 
, so the remainder is 
 — this holds for 
 as well.

Examples
Input 1
2 10 1000000000
Output 1
1024
Input 2
5 0 1
Output 2
0
*/


#include <iostream>
using namespace std;
int main() {
    long long a,b,c;
    cin>>a>>b>>c;
    long long s=1%c;
    a=a%c;
    while(b>0){
        if(b%2==1) s*=a%c;
        a*=a%c;
        b/=2;
    }
    cout<<s;
    return 0;
}