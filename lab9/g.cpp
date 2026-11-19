/*
The string 
 was written many times in a row, after which a substring was taken from the resulting string and given to you. Your task is to determine the minimum possible length of the original string 
.

Input
The only line contains string 
 (
), consisting of uppercase and lowercase Latin letters.

Output
Print one integer — the minimum possible length of the original string.

Note
The answer is the smallest period of the given string, and the prefix function gives it directly: for a string of length 
 the period equals 
.

Examples
Input 1
zzz
Output 1
1
Input 2
bcabcab
Output 2
3
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