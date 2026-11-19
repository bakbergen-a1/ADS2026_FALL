/*
Once upon a time, in one university, created a one organization called "House of love" in which friendship is the main value. So they created one test to know level of their friendship. Two person write some numbers and gives it to you, to check common numbers.

Input
The first line contains two integers 
 and 
 (
) — the sizes of the two arrays.

The second line contains 
 integers — the numbers of the first person, and the third line contains 
 integers — the numbers of the second person (
). If an array is empty, the corresponding line is empty or absent.

Output
Print the numbers that occur in both arrays, in non-decreasing order, separated by spaces.

A number that occurs 
 times in the first array and 
 times in the second one must be printed exactly 
 times. If there are no common numbers, print an empty line.

Examples
Input 1
4 2
1 2 2 1
2 2
Output 1
2 2 
Input 2
3 5
4 9 5
4 3 2 1 9
Output 2
4 9 
Input 3
0 1
1
Output 3

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
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    if(n) qs(a,0,n-1);
    if(m) qs(b,0,m-1);
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i]<b[j]) i++;
        else if(a[i]>b[j]) j++;
        else{
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }
}