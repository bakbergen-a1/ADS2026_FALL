/*
You’re given 
 dates in format 
. Sort them in ascending and print in te same format.

Input
The first line contains one integer 
 
. Next 
 lines contain dates in format 
 
. Every date is a valid calendar date.

Output
Print sorted dates in the same format as the input.

Examples
Input 1
3
01-12-2000
01-11-2000
31-10-2000
Output 1
31-10-2000
01-11-2000
01-12-2000
Input 2
4
01-12-1999
12-11-2002
20-02-1900
31-01-1999
Output 2
20-02-1900
31-01-1999
01-12-1999
12-11-2002
*/
#include <iostream>
#include <vector>
using namespace std;
struct Date{
    int d,m,y,x;
};
void qs(vector<Date> &a,int l,int r){
    int i=l,j=r;
    int p=a[(l+r)/2].x;
    while(i<=j){
        while(a[i].x<p) i++;
        while(a[j].x>p) j--;
        if(i<=j) swap(a[i++],a[j--]);
    }
    if(l<j) qs(a,l,j);
    if(i<r) qs(a,i,r);
}
int main(){
    int n;
    cin>>n;
    vector<Date> a(n);
    for(auto& x:a){
        string s;
        cin>>s;
        x.d=stoi(s.substr(0,2));
        x.m=stoi(s.substr(3,2));
        x.y=stoi(s.substr(6,4));
        x.x=x.y*10000+x.m*100+x.d;
    }
    qs(a,0,n-1);
    for(auto x:a){
        if (x.d<10) cout<<"0";
        cout<<x.d<<"-";
        if(x.m<10) cout<<"0";
        cout<<x.m<<"-"<<x.y<<endl;
    }
    return 0;
}