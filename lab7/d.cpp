/*
Nurlan has an array of integers sorted in non-decreasing order. Some of the numbers may be negative.

He squares every element and wants to see the result sorted in non-decreasing order as well. Squaring breaks the order: 
 stands before 
, but 
 is greater than 
.

Print the squares of all elements in non-decreasing order.

Input
The first line contains one integer 
 (
) — the length of the array.

The second line contains 
 integers 
 (
) separated by single spaces. The array is sorted: 
 for every 
.

Output
Print 
 integers separated by single spaces — the squares of the elements in non-decreasing order.

Note
In the first example the array is 
, the squares are 
, and sorted they give 
.

Sorting the squares directly would work, but there is a faster way that uses merging. Split the array at the point where the sign changes. Squares of the negative part decrease from left to right, squares of the non-negative part increase. These are two sorted sequences, so they can be merged in 
 — the same merge step that merge sort is built from. It is convenient to take the largest square at each step, comparing the two ends of the array, and to fill the answer from the end.

Examples
Input 1
5
-4 -1 0 3 10
Output 1
0 1 9 16 100
Input 2
4
-7 -3 2 11
Output 2
4 9 49 121
*/
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &a,int l,int m,int r){
    vector<int> L,R;
    for(int i=l;i<=m;++i) L.push_back(a[i]);
    for(int i=m+1;i<=r;i++) R.push_back(a[i]);
    int i=0,j=0,k=l;
    while(i<L.size() && j<R.size()) {
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<L.size()) a[k++]=L[i++];
    while(j<R.size()) a[k++]=R[j++];
}
void ms(vector<int> &a,int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        ms(a,l,m);
        ms(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
        a[i]=a[i]*a[i];
    }
    ms(a,0,n-1);
    for(int x:a) cout<<x<<" ";
}