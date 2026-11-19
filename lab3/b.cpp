/*
You are given array 
 (
) of length 
 (
) and 
 (
) queries. In query 
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
 is given in arbitrary order. Sort it first — after that the answer to a query is found by binary search over the sorted array: you need the position of the first element that is 
 and the position of the first element that is 
.

You do not have to implement a sorting algorithm yourself — use the one built into your language:

C++ — sort(a.begin(), a.end()); (header algorithm)

Python — a.sort()

Java — Arrays.sort(a); (package java.util)

Do not forget that both segments are closed: the elements equal to 
 or 
 are counted too, and the elements that fall into both segments are counted only once.

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
int count(vector<int> &a,int l,int r){
    int left=lower_bound(a.begin(),a.end(),l)-a.begin();
    int right=upper_bound(a.begin(),a.end(),r)-a.begin();
    return right-left;
}
int main() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    while(q--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int ans=count(a,l1,r1)+count(a,l2,r2);
        int l=max(l1,l2);
        int r=min(r1,r2);
        if(l<=r) ans-=count(a,l,r);
        cout<<ans<<endl;
    }
    return 0;
}