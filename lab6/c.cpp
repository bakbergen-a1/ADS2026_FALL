/*
You are given a list of integer points in a line. Find the pair of points with the least absolute difference. If there are more than one pairs output them all.

Input
The first line contains an integer 
, number of points. The next line represents 
 integer numbers 
 denoting the points in a line.

Output
Sort the points. Print all pairs of neighbouring points of the sorted sequence whose difference is the smallest one, in non-decreasing order: for every such pair print its two points one after another. All numbers are printed in one line, separated by single spaces.

If several points are equal, each neighbouring pair of them is printed separately.

Examples
Input 1
6
-20 -3916237 -357920 -362060 30 6246457
Output 1
-20 30
*/
#include <iostream>
#include <vector>
using namespace std;
void qs(vector<int> &a,int l,int r){
    int i=l,j=r;
    int p=a[(l+r)/2];
    while(i<=j){
        while(a[i]<p) i++;
        while(a[j]>p) j--;
        if(i<=j) swap(a[i++],a[j--]);
    }
    if(l<j) qs(a,l,j);
    if(i<r) qs(a,i,r);
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &x:a) cin>>x;
    qs(a,0,n-1);
    long long m=1LL<<60;
    for(int i=1;i<n;++i) m=min(m,(long long)a[i]-a[i-1]);
    for(int i=1;i<n;++i) {
        if((long long)a[i]-a[i-1]==m) cout<<a[i-1]<<" "<<a[i]<<" ";
    }
    return 0;
}