/*
Recall that a prime number is an integer greater than 
 that has exactly two positive divisors: 
 and the number itself. Written in increasing order, the prime numbers form the sequence 

Given an integer 
, print the 
-th number of this sequence.

Input
The only line contains a single integer 
 (
).

Output
Print a single integer — the 
-th prime number.

Note
The prime numbers in increasing order are 
, so the 
-th of them is 
.

Do not confuse the index with the value: the 
-th prime number is 
 and the 
-th is 
. Every answer fits into a 32-bit integer.

Examples
Input 1
5
Output 1
11
*/


#include <iostream>
#include <vector>
using namespace std;
bool prime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    int s=6;
    vector<int> a{2,3,5};
    if(a.size()>=n) cout<<a[n-1];
    else{
        while(a.size()<n){
            if(prime(s)) a.push_back(s);
            s+=1;
        }
        cout<<a[n-1];
    }
}