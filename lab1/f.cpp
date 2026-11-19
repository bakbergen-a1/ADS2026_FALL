/*
You are given two strings typed on a keyboard. Each string consists of lowercase English letters and the # symbol, where # means that the backspace key was pressed: it deletes the last character typed so far. If backspace is pressed when nothing has been typed yet, nothing happens.

Determine whether the two strings produce the same text.

Input
The first line contains the string 
 and the second line contains the string 
 (
).

Both strings consist of lowercase English letters and the # symbol.

Output
Print “Yes” if the two strings produce the same text, and “No” otherwise.

Note
In the first example abc## becomes a, and a#b#a also becomes a, so the answer is Yes.

In the second example ab#c becomes ac and ad#c becomes ac.

In the third example a#c becomes c, while bb## becomes the empty text, so the answer is No.

Examples
Input 1
abc##
a#b#a
Output 1
Yes
Input 2
ab#c
ad#c
Output 2
Yes
Input 3
a#c
bb##
Output 3
No
*/


#include <iostream>
using namespace std;
string check(string s){
    string r="";
    for(char c:s){
        if(c=='#'){
            if(!r.empty()) r.pop_back();
        }else r.push_back(c);
    }
    return r;
}
int main() {
    string n,m;
    cin>>n>>m;
    if(check(n)==check(m)) cout<<"Yes";
    else cout<<"No";
    return 0;
}