/*
Given string 
. How many different substrings it contains?

Input
The only line contains string 
 (
), consisting of lowercase Latin letters. The string may be empty.

Output
Print one integer — the number of distinct substrings of 
. The empty substring is not counted.

Note
You can solve this problem using hashes. Naive 
 solutions must fail.

Examples
Input 1
aab
Output 1
5
Input 2
abcde
Output 2
15
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    while(!s.empty() && (s.back()=='\r' || s.back()=='\n' || s.back()==' ')) s.pop_back();
    int n=s.size();
    vector<int> a(n);
    for(int i=0;i<n;++i) a[i]=i;
    sort(a.begin(),a.end(),[&](int a,int b){
        return s.compare(a,string::npos,s,b,string::npos)<0;
    });
    long long ans=(long long)n*(n+1)/2;
    for(int i=1;i<n;++i){
        int g=a[i-1],b=a[i];
        int l=0;
        while(g+l<n && b+l<n && s[g+l]==s[b+l]) l++;
        ans-=l;
    }
    cout<<ans<<endl;
}