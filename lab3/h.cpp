/*
You are given an array of non negative integers and a number 
. Let’s define subarray as a non-empty consecutive elements of an array. Among all subarrays of the given array, find the one, such that sum of its elements is no less than 
 and such that this subarray would contain minimum possible number of elements.

Input
First line contains two space separated numbers 
 
 — number of elements in given array and number that was mentioned above, respectively 
, 
.

Second line contains 
 space separated numbers 
 — given array 
.

It is guaranteed that at least one subarray’s sum is not less than 
.

Output
Output a single integer 
 — the number of elements in the shortest subarray whose sum is not less than 
.

Note
In the first test case we have three elements. Subarrays are 
, 
, 
, 
, 
, 
. Only two subarrays have sum that is not less than 
: 
, 
. Out of these two subarrays, 
 has minimum possible length of 
.

Hint

For a fixed left end of subarray, sums of subarray increase, if we increase number of elements in it. So we can do binary search on right end of subarray for a fixed left end.

In order to quickly know sum of subarray we can calculate prefix sums. For example for the given array from the first test case prefix sums would be 
. In order to get sum of second and third element, from prefix sum at position 3 we subtract prefix sum at position 1: 
.

Scoring
Group 1 (
 points) and group 2 (
 points): random and adversarial tests.

Group 3 (
 points): corner cases (
, answer equal to 
, answer equal to 
).

Examples
Input 1
3 12
3 5 7
Output 1
2
Input 2
6 19
3 6 1 4 5 2
Output 2
5
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> p(n + 1);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        p[i + 1] = p[i] + x;
    }
    int ans = n + 1;
    for (int s = 0; s < n; s++) {
        int l = s, r = n - 1, e = -1;
        
        while (l <= r) {
            int m = (l + r) / 2;
            
            if (p[m + 1] - p[s] >= k) {
                e = m;
                r = m - 1;
            } else l = m + 1;
        }
        if (e != -1) {
            int len = e - s + 1;
            if (len < ans) ans = len;
        }
    }
    cout << (ans == n + 1 ? 0 : ans) << '\n';
}