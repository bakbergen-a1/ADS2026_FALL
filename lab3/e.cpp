/*
You are given array 
 (
) of length 
 (
) and 
 queries (
). In query 
 you are given two pairs of segments 
 (
), find number of indices 
 (
) for which one of the following conditions is satisfied: 
 or 
.

Input
The first line contains two integers 
 and 
 (
, 
).

The second line contains 
 integers 
 (
) — the array itself, given in arbitrary order.

Each of the next 
 lines contains 4 integers 
 (
, 
) — one query.

Output
Output 
 lines — the answer to each query in the order they are given.

Note
The array 
 is given in arbitrary order. Sort it first — after that the answer to a query is found by binary search over the sorted array.

You do not have to implement a sorting algorithm yourself — use the one built into your language:

C++ — sort(a.begin(), a.end()); (header algorithm)

Python — a.sort()

Java — Arrays.sort(a); (package java.util)

Both segments are closed: the elements equal to 
 or 
 are counted too, and an element that falls into both segments is counted only once.

Examples
Input 1
7 3
21 1 2 3 5 8 13
1 5 13 21
1 1 2 3
1 3 2 8
Output 1
6
3
5
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lower(const vector<int>& a, int x) {
    int l = 0, r = a.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}
int upper(const vector<int>& a, int x) {
    int l = 0, r = a.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] <= x) l = m + 1;
        else r = m;
    }
    return l;
}
int countRange(const vector<int>& a, int l, int r) {
    return l > r ? 0 : upper(a, r) - lower(a, l);
}
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int ans = countRange(a, l1, r1) + countRange(a, l2, r2);
        ans -= countRange(a, max(l1, l2), min(r1, r2));
        cout << ans << '\n';
    }
}