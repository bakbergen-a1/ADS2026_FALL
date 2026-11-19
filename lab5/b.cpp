/*
We have a collection of rocks, each rock has a positive integer weight.

With each turn, we choose the two heaviest rocks and smash them together. Suppose the stones have weights 
 and 
 with 
. If 
, both stones are totally destroyed. If 
, the stone of weight 
 is totally destroyed, and the stone of weight 
 has a new weight 
.

At the end, there is at most 1 stone left. Output the weight of this stone (or 0 if there are no stones left).

Input
The first line contains integer 
 (
) - the number of stones.

The second line contains 
 integers 
 (
) - the weights of each stone.

Output
Print the weight of the remaining stone, or 0 if no one left.

Note
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then, we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then, we combine 2 and 1 to get 1 so the array converts to [1,1,1] then, we combine 1 and 1 to get 0 so the array converts to [1] then that’s the value of last stone.

Examples
Input 1
6
2 7 4 1 8 1
Output 1
1
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
        while (i>0){
            int p=(i-1)/2;
            if(a[p]>=a[i]) break;
            long long t=a[p];
            a[p]=a[i];
            a[i]=t;
            i=p;
        }
    }
    void heapify(int i) {
        while (2*i+1<n) {
            int c=2*i+1;
            if(c+1<n && a[c+1]>a[c]) c++;
            if(a[i]>=a[c]) break;
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
};
int main() {
    int n;
    cin>>n;
    Heap h(n+5);
    for(int i=0;i<n;++i) {
        long long x;
        cin>>x;
        h.push(x);

    }
    while (h.size()>1){
        long long x=h.pop();
        long long y=h.pop();
        if(x!=y) {
            h.push(x-y);
        }
    }
    if(h.size()==0) cout<<0<<endl;
    else cout<<h.pop()<<endl;
    return 0;
}