/*
Every integer greater than 
 can be written as a product of prime numbers, and this representation is unique up to the order of the factors. For example, 
 and 
.

Given an integer 
, print its prime factorization.

Trying every divisor from 
 to 
 is far too slow for 
 up to 
. A much smaller bound is enough — but be careful: once you stop, what is left of 
 may still be a prime factor that has to be printed.

Input
The only line contains a single integer 
 (
).

Output
Print the prime factors of 
 in non-decreasing order, separated by single spaces. If a prime divides 
 several times, print it that many times.

Note
In the first example 
, and in the second one 
.

In the third example 
 is a prime number, so its factorization consists of 
 itself.

Examples
Input 1
60
Output 1
2 2 3 5
Input 2
210
Output 2
2 3 5 7
Input 3
999999999989
Output 3
999999999989
*/


#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long> a;
    long long s=2;
    while(s*s<=n){
        while(n%s==0){
            a.push_back(s);
            n=n/s;
        }
        s++;
    }
    if(n>1) a.push_back(n);
    for(long long x:a) cout<<x<<" ";
    return 0;
}