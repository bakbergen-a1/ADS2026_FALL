/*
You have string 
 and 
 queries. Each query given a pair of integers 
 and 
; the answer for a query is number of times substring from 
 to 
 appears in 
 as substring.

Input
In first line given string 
 
.

In second line given integer 
 
.

Then next 
 lines contains queries, each query is two integer 
 and 
 (
), substring you must to check.

Output
Print 
 lines with one single integer, answer for each query.

Examples
Input 1
abracadabra
5
1 1
1 2
3 4
1 5
1 4
Output 1
5
2
2
1
2
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long m1 = 1000000007, m2 = 1000000009, p = 31;
int main() {
    string s; int q; cin >> s >> q;
    int n = s.size();
    vector<long long> h1(n+1, 0), h2(n+1, 0), p1(n+1, 1), p2(n+1, 1); 
    for(int i = 0; i < n; i++) {
        int x = s[i] - 'a' + 1;
        h1[i+1] = (h1[i] * p + x) % m1;
        h2[i+1] = (h2[i] * p + x) % m2;
        p1[i+1] = p1[i] * p % m1;
        p2[i+1] = p2[i] * p % m2;
    }
    while(q--) {
        int l, r; cin >> l >> r;
        l--;
        int len = r - l;
        long long a = (h1[r] - h1[l] * p1[len] % m1 + m1) % m1;
        long long b = (h2[r] - h2[l] * p2[len] % m2 + m2) % m2;
        int ans = 0;
        for(int i = 0; i + len <= n; i++) {
            long long x = (h1[i + len] - h1[i] * p1[len] % m1 + m1) % m1;
            long long y = (h2[i + len] - h2[i] * p2[len] % m2 + m2) % m2;
            if(x == a && y == b) ans++;
        }
        cout << ans << '\n';
    }
}