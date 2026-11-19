/*
Given two strings A and B. Your task is to find the minimum number of times A has to be repeated such that B is a substring of it. If B cannot be found in A after it’s extension, return 
. If A already contains B, the number of repetitions is equal to one by default.

Input
Input contains two lines: the first line contains the string 
, the second line contains the string 
. Both strings consist of lowercase and uppercase Latin letters, and their lengths are between 
 and 
.

Output
Print the minimum number of repetitions of 
 such that 
 is a substring of the result. If 
 can never be a substring, no matter how many times 
 is repeated, print 
.

Note
For the first test case, answer is 
, because by repeating A three times 
, B is a substring of it. For the second case, we do not extend the string A and B is a substring of A. Number of repetitions of A is 
.

Examples
Input 1
abcd
cdabcdab
Output 1
3
Input 2
aaa
a
Output 2
1
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
vector<int> kmp(const string &s,string &p){
    vector<int> pi=prefix(p);
    vector<int> pos;
    int j=0;
    for(int i=0;i<s.size();i++){
        while(j>0 && s[i]!=p[j]) j=pi[j-1];
        if(s[i]==p[j]) j++;
        if(j==p.size()){
            pos.push_back(i-p.size()+1);
            j=pi[j-1];
        }
    }
    return pos;
}
int main(){
    string a,b;
    cin>>a>>b;
    int k=(b.size()+a.size()-1)/a.size();
    string s="";
    for(int i=0;i<k;i++) s+=a;
    if(!kmp(s,b).empty()) cout<<k;
    else{
        s+=a;
        if(!kmp(s,b).empty()) cout<<k+1;
        else cout<<-1;
    }
}