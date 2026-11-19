/*
You have one letter. Your task is to find "balanced" char in array. "Balanced" char is the smallest in array, but more than your letter.

Input
The first line contains one integer 
 (
) — the number of letters in the array.

The second line contains 
 lowercase Latin letters separated by single spaces, given in non-decreasing order.

The third line contains one lowercase Latin letter 
.

Output
Print the “balanced” letter — the smallest letter of the array that is greater than 
.

If the array contains no letter greater than 
, the search wraps around and the answer is the first (that is, the smallest) letter of the array.

Note
Size of array should be more than 1;

Examples
Input 1
3
c f g
a
Output 1
c
*/
#include <iostream>
#include <vector>
using namespace std;
void qs(vector<char> &a,int l,int r){
    int i=l,j=r;
    char p=a[(l+r)/2];
    while(i<=j){
        while(a[i]<p) i++;
        while(a[j]>p) j--;
        if(i<=j) swap(a[i++],a[j--]);
    }
    if(l<j) qs(a,l,j);
    if(i<r) qs(a,i,r);
}
int main() {
    int n;
    cin>>n;
    vector<char> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    char x;
    cin>>x;
    qs(a,0,n-1);
    for(int i=0;i<n;++i){
        if(a[i]>x){
            cout<<a[i];
            return 0;
        }
    }
    cout<<a[0];
    return 0;
}