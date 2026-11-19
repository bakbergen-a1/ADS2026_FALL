/*
Thomas received a new password from his employee. Since Thomas always checks the information, he asks you to check if the password is correct.

It is known that the password is correct only if it occurs at least 
 times on a piece of paper that the Bank Director gave to Thomas.

Input
The first line contains a string 
 and an integer 
 (
, 
), where 
 is a new password. The second line contains a string 
 (
), a string on a piece of paper.

Output
Print YES if password is correct, otherwise print NO

Examples
Input 1
hello 2
helloThomashelloArthurhelloJohnhello
Output 1
YES
Input 2
kbtu 4
kbtuIsTheBestPlaceInTheWorld
Output 2
NO
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int>prefix(const string &s){
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
vector<int> kmp(string &s,string &p){
    vector<int> a=prefix(p);
    vector<int> b;
    int j=0;
    for(int i=0;i<s.size();i++){
        while(j>0 && s[i]!=p[j]) j=a[j-1];
        if(s[i]==p[j]) j++;
        if(j==p.size()) {
            b.push_back(i-p.size()+1);
            j=a[j-1];
        }
    }
    return b;
}
int main(){
    string s,t;
    int n;
    cin>>s>>n>>t;
    if((int)kmp(t,s).size()>=n) cout<<"YES";
    else cout<<"NO";
    return 0;
}