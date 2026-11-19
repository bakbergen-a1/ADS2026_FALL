/*
he archaeologists are going to decipher a very mysterious “language”. Now, they know many language patterns. Each pattern can be treated as a string of lowercase Latin letters. There is a large text they want to analyze. What matters most is that which patterns are the dominating patterns. Frequency of the pattern is the number of its appearances in the text as a substring. Pattern is dominating if the frequency the pattern is is not less than the frequency of any other pattern. It is your job to find all dominating patterns.

Input
The input consists of multiple test cases.

The first line of each test case is an integer 
 (
) - the number of patterns. Each of the following 
 lines contain single string of length in range 
 - patterns. The next line contains a single string of length in range 
 - text.

At the end of the input file there is a 
 indicating the end of an input file.

Output
For each test case, output the dominating patterns. If there are several dominating patterns, output them in order they appear in the input.

Note
In the first test case, the frequency of pattern 
 is 
, and of pattern 
 is 
.

In the second test case, the frequency of patterns 
 and 
 is 
, and all other patterns has frequency not exceeding 
.

Examples
Input 1
2
aba
bab
ababababac
6
beta
alpha
haha
delta
dede
tata
dedeltalphahahahototatalpha
0
Output 1
4
aba
2
alpha
haha
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const long long mod = 1000000007, p = 31;
int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<string> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        string s; cin >> s;
        int len = s.size();
        vector<long long> h(len + 1, 0), pw(len + 1, 1);
        for(int i = 1; i <= len; i++) {
            pw[i] = pw[i-1] * p % mod;
            h[i] = (h[i-1] * p + s[i-1] - 'a' + 1) % mod;
        }
        vector<int> cnt(n, 0);
        int best = 0;
        for(int j = 0; j < n; j++) {
            int m = a[j].size();
            long long target = 0;
            for(char c : a[j]) 
                target = (target * p + c - 'a' + 1) % mod;
            for(int i = 0; i + m <= len; i++) {
                long long cur = (h[i + m] - h[i] * pw[m] % mod + mod) % mod;
                if(cur == target) cnt[j]++;
            }
            best = max(best, cnt[j]);
        }
        cout << best << '\n';
        for(int i = 0; i < n; i++) {
            if(cnt[i] == best) cout << a[i] << '\n';
        }
    }
}