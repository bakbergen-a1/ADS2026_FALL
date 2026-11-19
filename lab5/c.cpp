/*
Kakyoin loves football and he goes to the final of the World Cup. At the stadium, he noticed that there are 
 rows, each can accommodate a distinct number of people. The price of the ticket depends on the row. If there are 
 (
 > 0) free seats in the row, then the price of one ticket will be equal to k. What is the maximum amount of money stadium management can get if there are 
 people in line for a ticket?

Input
The first line consists of 
 and 
 (
). 
 denotes the number of seating rows in the stadium and 
 denotes the number of football fans waiting in line to get a ticket for the match.

Next line consists of 
 space separated integers 
, 
, 
, ..., 
 where 
 (
) denotes the number of empty seats initially in the 
-th row.

It is guaranteed that there are enough free seats for all visitors.

Output
Print one integer - the maximum amount of money the stadium can earn.

Note
The answer may exceed the maximum value of a 
-bit integer — use 
-bit integers.

Examples
Input 1
3 10
6 8 9
Output 1
67
Input 2
1 2
5
Output 2
9
*/
#include <iostream>
using namespace std;
struct Heap{
    long long *a;
    int n;

    Heap(int size){
        a=new long long[size+5];
        n=0;
    }

    void push(long long x){
        int i=n;
        a[n]=x;
        n++;
        while(i>0){
            int p=(i-1)/2;
            if(a[p]>a[i]) break;
            swap(a[p],a[i]);
            i=p;
        }
    }
    void heapify(int i){
        while(2*i+1<n){
            int c=2*i+1;
            if(c+1<n && a[c+1]>a[c]) c++;
            if(a[i]>=a[c]) break;
            swap(a[i],a[c]);
            i=c;
        }
    }
    long long pop() {
        long long x=a[0];
        a[0]=a[n-1];
        n--;
        if(n>0) heapify(0);
        return x;
    }
    int size() {
        return n;
    }
};
int main() {
    int n,m;
    cin>>n>>m;
    Heap h(n+m);
    for(int i=0;i<n;++i) {
        long long x;
        cin>>x;
        h.push(x);
    }
    long long ans=0;
    for(int i=0;i<m;++i) {
        long long x=h.pop();
        ans+=x;
        if(x>1) h.push(x-1);
    }
    cout<<ans;
    return 0;
}