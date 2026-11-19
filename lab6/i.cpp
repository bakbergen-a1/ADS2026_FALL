/*
Azat is a perfectionist and he likes everything to be perfect. Help Azat sort letters alphabetically. good luck!

Input
The only line contains the string 
 of lowercase Latin letters (
).

Output
Print the letters of 
 in non-decreasing alphabetical order.

Note
Try to sort the letters yourself instead of calling the library sort — at the defence you will be asked to do exactly that.

Examples
Input 1
qwertyuioplkjvbn
Output 1
beijklnopqrtuvwy
*/
#include <iostream>
using namespace std;
void qs(string &a,int l,int r){
    int i=l,j=r;
    char p=a[(l+r)/2];
    while(i<=j){
        while (a[i]<p) i++;
        while (a[j]>p) j--;
        if(i<=j) swap(a[i++],a[j--]);
    }
    if(l<j) qs(a,l,j);
    if(i<r) qs(a,i,r);
}
int main() {
    string s;
    cin>>s;
    qs(s,0,s.size()-1);
    cout<<s;
}