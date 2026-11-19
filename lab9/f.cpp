/*
Given two strings 
 and 
, find whether 
 is a substring of 
 and print indices of occurrences.

Input
Next two lines contain strings 
 (
) and 
 (
).

Output
In the first line print a single integer - the number of occurrences of string 
 in string 
. In the second line print indices of occurrences.

Note
Solve this task using Knuth-Morris-Pratt algorithm.

Examples
Input 1
abacaba
aba
Output 1
2
1 5 
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
vector<int> kmp(const string &s,const string &p){
    vector<int> a=prefix(p);
    vector<int> b;
    int j=0;
    for(int i=0;i<s.size();++i){
        while(j>0 && s[i]!=p[j]) j=a[j-1];
        if(s[i]==p[j]) j++;
        if(j==p.size()){
            b.push_back(i-p.size()+1);
            j=a[j-1];
        }
    }
    return b;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    vector<int> a=kmp(s1,s2);
    cout<<a.size()<<endl;
    for(int i=0;i<a.size();i++) cout<<a[i]+1<<" ";
    cout<<endl;
    return 0;
}