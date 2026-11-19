/*
Mark is making an experiment with mixtures of different densities. For his experiment he wants all of the mixtures to have a density 
.

He uses the following formula to obtain a combined mixture: 
 = 
 +  
, where 
 is the density of the new mixture, 
 is the smallest density among all mixtures and  
 is the second smallest density among all mixtures.

Mark repeats the mixing until he gets all the mixtures with the density 
.

You are given the densities of mixtures. How many times Mark should mix his mixtures to get the densities of all mixtures 
?

Input
The first line consists of integers 
 and 
 (
, 
), the number of mixtures and the minimum required density correspondingly.

The next line contains 
 space-separated integers 
 (
) describing the densities of mixtures.

Output
Print the number of operations that are needed to make all the densities 
. If it is impossible, print 
.

Note
The density of a combined mixture can reach about 
, which does not fit into a 
-bit integer type — use 
-bit integers.

Examples
Input 1
3 10
1 1 1
Output 1
-1
Input 2
6 7
1 2 3 9 10 12
Output 2
2
*/
#include <iostream>
using namespace std;
struct Heap{
    long long *a;
    int n;

    Heap(int size){
        a=new long long [size+5];
        n=0;
    }
    void push(long long x){
        int i=n;
        a[n]=x;
        n++;
        while (i>0){
            int p=(i-1)/2;
            if(a[p]<=a[i]) break;
            long  long t=a[p];
            a[p]=a[i];
            a[i]=t;
            i=p;
        }
    }
    void heapify(int i){
        while (2*i+1<n) {
            int c=2*i+1;
            if(c+1<n && a[c+1]<a[c]){
                c++;
            }
            if(a[i]<=a[c]) break;
            long long t=a[i];
            a[i]=a[c];
            a[c]=t;
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
    long  long top() {
        return a[0];
    }
};
int main() {
    int n;
    long long k;
    cin>>n>>k;
    Heap h(n+5);
    for(int i=0;i<n;++i) {
        long long x;
        cin>>x;
        h.push(x);
    }
    int ans=0;
    while (h.size()>0 && h.top()<k) {
        if(h.size()<2){
            cout<<-1<<endl;
            return 0;
        }
        long long x=h.pop();
        long long y=h.pop();
        long long z=x+2*y;
        h.push(z);
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}