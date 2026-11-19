#include <iostream>
#include <vector>
using namespace std;
bool search(vector<int> &a,int n,int x){
    int l=0,r=n-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(a[m]==x) return true;
        else if(a[m]<x) l=m+1;
        else r=m-1;
    }
    return false;
}
int lowerbound(vector<int> &a,int n,int x){
    int l=0,r=n;
    while(l<r){
        int m=l+(r-l)/2;
        if(a[m]>=x) r=m;
        else l=m+1;
    }
    return l;
}
int upperbound(vector<int> &a,int n,int x){
    int l=0,r=n;
    while(l<r){
        int m=l+(r-l)/2;
        if(a[m]>x) r=m;
        else l=m+1;
    }
    return l;
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        if(search(a,n,x)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        cout<<upperbound(a,n,x)-lowerbound(a,n,x)<<endl;
    }
}