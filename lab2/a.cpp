/*
Jojo is watching a stream of lowercase Latin letters arrive one by one.

After every single letter that arrives, he wants to know the first letter of the stream so far that has occurred exactly once — “first” meaning the leftmost one among all letters that are still unique. If at that moment every letter seen so far has occurred more than once, the answer is 
.

Help Jojo answer this after each arrival.

Input
The first line contains one integer 
 — the number of test cases (
).

Each test case is given on two lines. The first of them contains one integer 
 — the length of the stream (
). The second contains 
 lowercase Latin letters separated by single spaces — the letters in the order they arrive.

Output
For each test case print one line with 
 answers separated by single spaces: the 
-th of them is the first non-repeating letter of the stream after the first 
 letters have arrived, or 
 if at that moment there is no such letter.

Note
In the first test case the stream is 
:

after “a” the only letter is 
 and it is unique — the answer is 
;

after the second “a” the letter 
 has occurred twice, and there is nothing else — the answer is 
;

after “b” the unique letters are 
 only — the answer is 
;

after “c” the unique letters are 
 and 
, and 
 came first — the answer is 
.

In the second test case the stream is 
, and the answers are 
, 
, 
, 
, 
, 
.

Examples
Input 1
2
4
a a b c
3
a a c
Output 1
a -1 b b 
a -1 c 
Input 2
1
6
a d b c a a
Output 2
a a a a d d 
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        map<char,int> m;
        vector<char> c;
        int s=0;
        for(int i=0;i<n;++i){
            char x;
            cin>>x;
            m[x]++;
            if(m[x]==1) c.push_back(x);
            while(s<c.size() && m[c[s]]>1) s++;
            if(s<c.size()) cout<<c[s]<<" ";
            else cout<<-1<<" ";
        }
        cout<<endl;
    }
}
