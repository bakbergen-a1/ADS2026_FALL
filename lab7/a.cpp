/*
You are given 
 sets of strings. For every set print its strings ordered by length: shorter strings first. If two strings have the same length, they must keep their relative order from the input — the sorting must be stable.

Input
The first line contains one integer 
 (
) — the number of sets.

Each of the next 
 lines describes one set and contains 
 strings separated by single spaces (
). Every string consists of lowercase Latin letters and has length between 
 and 
 inclusive.

The total number of strings over all sets does not exceed 
, and the total length of all strings does not exceed 
.

Output
Print exactly 
 lines. The 
-th line must contain all 
 strings of the 
-th set separated by single spaces, ordered by non-decreasing length. Strings of equal length must be printed in the same relative order in which they occur in the input.

Note
The intended solution is merge sort — a stable 
 sorting algorithm. Note that quick sort is not stable, so it cannot be used here without an additional tie-breaking key.

Examples
Input 1
3
ab cd e j asd ljffg df
a a b b c c
xy yx zxy zx xzy xxx
Output 1
e j ab cd df asd ljffg 
a a b b c c 
xy yx zx zxy xzy xxx 
Input 2
4
aabc ddfd fbbe f baaad
fddf badcf aedbe cdb ae bbd
ada bc eaced dadab b aabc fbee
bedaf edde fcaa adbf beec
Output 2
f aabc ddfd fbbe baaad 
ae cdb bbd fddf badcf aedbe 
b bc ada aabc fbee eaced dadab 
edde fcaa adbf beec bedaf 
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void merge(vector<string> &a,int l,int m,int r){
    vector<string> L,R;
    for(int i=l;i<=m;i++) L.push_back(a[i]);
    for(int i=m+1;i<=r;i++) R.push_back(a[i]);
    int i=0,j=0,k=l;
    while(i<L.size() && j<R.size()){
        if(L[i].length()<=R[j].length()) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<L.size()) a[k++]=L[i++];
    while(j<R.size()) a[k++]=R[j++];
}
void ms(vector<string> &a,int l,int r){
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
    while(n--){
        vector<string> a;
        string s;
        while(cin.peek()==' ') 
            cin.get();
        while(cin>>s){
            a.push_back(s);
            if(cin.peek()=='\n') 
                break;
        }
        ms(a,0,(int)a.size()-1);
        for(int i=0;i<a.size();i++){
            if(i>0) 
                cout<<" ";
            cout<<a[i];
        }
        cout<<'\n';
    }
    return 0;
}