/*
Nurlan is helping his younger brother with a homework problem: given two positive integers 
 and 
, find their greatest common divisor — the largest positive integer that divides both of them.

His brother wrote a straightforward program: check every integer from 
 down to 
 and stop at the first common divisor. For 
 it works fine — at most 
 checks. For 
 it already has to check about a billion numbers, and for the values in this problem it would never finish at all.

Help Nurlan and write a program that is fast enough.

Input
The only line contains two integers 
 and 
 (
).

Output
Print a single integer — the greatest common divisor of 
 and 
.

Note
In the first example both numbers are prime, so their only common divisor is 
.

In the second example 
 and 
, so the largest common divisor is 
.

Examples
Input 1
1000000007 1000000009
Output 1
1
Input 2
12 18
Output 2
6
*/


#include <iostream>
using namespace std;
int main() {
    long long a,b;
    cin>>a>>b;
    while(b!=0){
        long long s=a%b;
        a=b;
        b=s;
    }
    cout<<a;
    return 0;
}