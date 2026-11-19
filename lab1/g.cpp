/*
You are given a string 
 consisting of lowercase Latin letters. Determine whether it is balanced.

A string is balanced if and only if it can be built by the following rules:

the empty string is balanced;

if the strings 
 and 
 are balanced, then their concatenation 
 is also balanced;

if the string 
 is balanced, then the string 
 is balanced for any lowercase Latin letter 
.

For example, the string abba is balanced, but the string abbb is not.

Input
The only line contains the string 
 (
).

Output
Print “YES” if the string is balanced, and “NO” otherwise.

Note
In the first example sbaabsss is the concatenation of sbaabs and ss. Here sbaabs is built as 
 with s
 around the balanced string baab, and ss is built as 
 with s
 around the empty string.

In the third example baab is built as 
 with b
 around the balanced string aa.

The strings sbabasss and abpa of the second and fourth examples cannot be built by these rules.

Examples
Input 1
sbaabsss
Output 1
YES
Input 2
sbabasss
Output 2
NO
Input 3
baab
Output 3
YES
Input 4
abpa
Output 4
NO
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    string n;
    cin>>n;
    vector<char> b;
    for(char c:n) b.push_back(c);
    vector<char> a;
    for(int i=0;i<b.size();i++){
        if(a.empty() && a[-1]==b[i]) a.pop();
        else a.push_back(b[i]);
    }
    if(b.size()==0) cout<<"YES";
    else cout<<"NO";
}