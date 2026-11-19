/*
After endterm Makima decided to do the problems for the final exam. Do you know what is the hardest thing in making a problem? It is the name of the task.

Makima has a task name draft 
. The name of the task must contain a given string as a substring at least 
 times. But she has a limitation: the name of the task cannot be very long, and she wants to find the shortest one. Help Makima to find the length of the shortest task name satisfying desired condition.

Input
The first line contains a single integer 
 — the number of testcases. Each of the next 
 lines contains string 
 consisting of only lowercase letters and a number 
(
). The sum of lengths of strings over all testcases will not exceed 

Output
For each test case print answer in separate line.

Examples
Input 1
3
asas 3
aaa 1
b 2
Output 1
8
3
2
Input 2
5
anime 666
violetevergarden 898
mononoke 24
evangelion 4
nugman 7
Output 2
3330
14368
192
40
36
*/
#include <iostream>
#include <vector>
#include <string>
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
    int t;
    cin>>t;
    while(t--){
        string s;
        long long k;
        cin>>s>>k;
        long long n=s.size();
        long long p=prefix(s).back();
        cout<<n+(k-1)*(n-p)<<endl;
    }
    return 0;
}