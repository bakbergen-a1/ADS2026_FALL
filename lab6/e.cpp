/*
You are given matrix with 
 rows and 
 columns.

You have to sort each column of matrix in descending order.

Input
The first line consists of two integers 
 and 
 (
) — the number of rows and columns of the matrix respectively.

Each of the next 
 lines contains 
 integers 
 (
) — elements of the matrix at the intersection of the 
-th row and the 
-th column.

Output
Print this matrix after sorting.

Examples
Input 1
4 3
1 2 3
4 5 6
6 7 8
9 8 7
Output 1
9 8 8 
6 7 7 
4 5 6 
1 2 3 
*/
#include <iostream>
#include <vector>
using namespace std;
void qs(vector<int> &a,int l,int r){
    int i=l,j=r;
    int p=a[(l+r)/2];
    while(i<=j){
        while(a[i]>p) i++;
        while(a[j]<p) j--;
        if(i<=j) swap(a[i++],a[j--]);
    }
    if(l<j) qs(a,l,j);
    if(i<r) qs(a,i,r);
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
        }
    }
    for(int j=0;j<m;++j){
        vector<int> c(n);
        for(int i=0;i<n;++i) c[i]=a[i][j];
        qs(c,0,n-1);
        for(int i=0;i<n;++i) a[i][j]=c[i];
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}