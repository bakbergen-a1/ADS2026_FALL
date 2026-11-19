/*
Aidana is checking how messy a list of numbers is.

She calls a pair of positions 
 an inversion if 
 and 
 — that is, a larger number stands before a smaller one.

A sorted array has no inversions at all, and the more inversions an array has, the further it is from being sorted. Help Aidana count them.

Input
The first line contains one integer 
 (
) — the length of the array.

The second line contains 
 integers 
 (
) separated by single spaces.

Output
Print one integer — the number of inversions in the array.

Note
In the first example the pair 
 is an inversion, because 
.

In the second example the array is 
 and the inversions are 
, 
 and 
.

Note that equal elements do not form an inversion: the condition is strictly 
.

The intended solution is merge sort: while merging two sorted halves, every element taken from the right half is smaller than all remaining elements of the left half, which gives the number of inversions in 
. A straightforward double loop over all pairs is 
 and will not fit into the time limit.

The answer can be as large as 
, so a 32-bit integer type is not enough.

Examples
Input 1
2
2 1
Output 1
1
Input 2
5
3 1 4 1 5
Output 2
3
*/
#include <iostream>
#include <vector>
using namespace std;
long long merge(vector<int> &a,int l,int m,int r){
    vector<int> L,R;
    for(int i=l;i<=m;++i) L.push_back(a[i]);
    for(int i=m+1;i<=r;i++) R.push_back(a[i]);
    int i=0,j=0,k=l;
    long long s=0;
    while(i<L.size() && j<R.size()){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else {
            a[k++]=R[j++];
            s+=L.size()-i;
        }
    }
    while(i<L.size()) a[k++]=L[i++];
    while(j<R.size()) a[k++]=R[j++];
    return s;
}
long long ms(vector<int> &a,int l,int r){
    if(l>=r) return 0;
    int m=l+(r-l)/2;
    long long s=0;
    s+=ms(a,l,m);
    s+=ms(a,m+1,r);
    s+=merge(a,l,m,r);
    return s;
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    cout<<ms(a,0,n-1);

}