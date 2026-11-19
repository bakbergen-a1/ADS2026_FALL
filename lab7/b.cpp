/*
You are given two arrays of integers, 
 and 
. Both of them are already sorted in non-decreasing order.

Merge them into one sorted array that contains all elements of 
 and all elements of 
.

Input
The first line contains one integer 
 (
) — the size of 
.

The second line contains 
 integers 
 (
) separated by single spaces. The array is sorted: 
.

The third line contains one integer 
 (
) — the size of 
.

The fourth line contains 
 integers 
 (
) separated by single spaces. The array is sorted: 
.

Output
Print 
 integers separated by single spaces — all elements of both arrays in non-decreasing order.

Note
Both arrays are already sorted, so there is no need to sort anything. Walk along the two arrays with two indices and always take the smaller of the two current elements. This is exactly the merge step of merge sort, and it works in 
.

Do not forget the tail: when one array runs out, all remaining elements of the other one still have to be printed.

The answer always contains exactly 
 numbers.

Examples
Input 1
5
4 5 6 7 10
5
2 4 6 7 8
Output 1
2 4 4 5 6 6 7 7 8 10
Input 2
3
1 4 7
1
6
Output 2
1 4 6 7
*/
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &a,int l,int m,int r){
    vector<int> L,R;
    for(int i=l;i<=m;++i) L.push_back(a[i]);
    for(int i=m+1;i<=r;i++) R.push_back(a[i]);
    int i=0,j=0,k=l;
    while(i<L.size() && j<R.size()){
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
    vector<int> c;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
        c.push_back(a[i]);
    }
    int m;
    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;++i){
        cin>>b[i];
        c.push_back(b[i]);
    }
    ms(c,0,n+m-1);
    for(int x=0;x<n+m;x++) cout<<c[x]<<" ";
}