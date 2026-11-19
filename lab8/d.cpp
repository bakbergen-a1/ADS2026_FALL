/*
Jonathan tried to write Rabin-Karp algorithm. He had a string S and he used the following formula to calculate hash of string:
S-1 Σ(5-97) - 2 1-0
Thus, he has written hashes of all prefixes of string S. Unfortunately, Jonathan forgot his string S. So, he asked your help in restoring this string.
Input
The first line of the input contains the only integer N - the length of string S (1 ≤ N ≤50).
The second line contains N integers p₁ - hashes of all prefixes of string S.
It is guaranteed that each hash does not exceed 2-1018.
Output
Print the string S.
Note
Use larger integer data structures (like "long long" In C++).
Examples
Input 1
5
7 15 59 147
371
Output 1
hello
Input 2
5
22 50 118 206 254
Output 2
world
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    long long prev=0;
    for(int i=0;i<n;++i){
        long long p;
        cin>>p;
        long long d=p-prev;
        prev=p;
        s+=char(97+(d>>i));
    }
    cout<<s<<endl;
}