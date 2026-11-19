/*
Given a string 
, calculate the number of ways to divide 
 into 3 non-empty strings 
 such that:
 and 

Input
You are given the string 
 (
), consisting of small Latin letters.

Output
Print the number of ways to partite string.

Note
String from the first testcase can be partitioned in two ways:
1. ab + ab + ababcx
2. abab + abab + cx

Examples
Input 1
ababababcx
Output 1
2
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> prefix(const string &s){
    int n=s.size();
    vector<int> p(n,0);
    for(int i=1;i<n;++i){
        int j=p[i-1];
        while(j>0 && s[i]!=s[j]) j=p[j-1];
        if(s[i]==s[j]) j++;
        p[i]=j;
    }
    return p;
}
int main(){
    string s;
    cin>>s;
    int n=s.size();
    cout<<n-prefix(s).back();
}