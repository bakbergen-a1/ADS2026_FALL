/*
Almas loves to sort numbers with specific rules that he comes up with himself. Today he wants to sort rows, each row contain m integer elements. He decided to sort rows in decreasing order of their sum, i.e. the row with larger sum will be the first. In case the sums are equal, then he order rows lexicographically, i.e. The row with least first element will be the first, if first elements are equal, then compare second element, third element, etc. He successfully finished sorting. He wanted to put the result in the closet, but accidentally put it in the shredder and divided everything into rows again. Help him sort it again.

Input
The first line contains two numbers, n and m the number of rows and number of elements in a row. The next n lines contain m numbers, elements of each row.



Output
Print rows in desired sorted order.

Examples
Input 1
5 3
1 2 3
1 2 4
1 3 2
6 0 0
2 3 2
Output 1
1 2 4 
2 3 2 
1 2 3 
1 3 2 
6 0 0 
Input 2
2 3
16 3 18
5 10 8
Output 2
16 3 18 
5 10 8 
*/
#include <iostream>
#include <vector>
using namespace std;
bool lessrow(vector<int> &a,vector<int> &b){
    int x=0,y=0;
    for(int i=0;i<a.size();i++) {
        x+=a[i];
        y+=b[i];
    }
    if(x!=y) return x>y;
    for(int i=0;i<a.size();i++) {
        if(a[i]!=b[i]) return a[i]<b[i];
    }
    return false;
}
void merge(vector<vector<int>> &a,int l,int m,int r){
    vector<vector<int>> L,R;
    for(int i=l;i<=m;i++) L.push_back(a[i]);
    for(int i=m+1;i<=r;++i) R.push_back(a[i]);
    int i=0,j=0,k=l;
    while(i<L.size() && j<R.size()){
        if(lessrow(L[i],R[j])) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<L.size()) a[k++]=L[i++];
    while(j<R.size()) a[k++]=R[j++];
}
void ms(vector<vector<int>> &a,int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        ms(a,l,m);
        ms(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int> (m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
        }
    }
    ms(a,0,n-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}