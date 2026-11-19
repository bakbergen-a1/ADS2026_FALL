/*
The ICPC finals will be held soon, so Yergeldi and his team needs your help. While they were preparing for the competition, they faced an interesting task. You have a list of length 
 which consists of arrays of given lengths. You have one single operation, you can take any two arrays and merge them into one, the cost of the operation is equal to the sum of their lengths. As a result, you will have a list of 
 - 1 arrays. The process repeats until there is only one final array left. Find out for what minimum cost it is possible to combine all arrays.

Input
The first line contains an integer 
 (
), the size of the list 
. The next line contains 
 positive integers 
, 
, ..., 
 (
), representing the sizes of arrays in the list 
.

Output
Print a single integer - the minimum cost of operations.

Note
Explanation for the first test case:

[6, 5, 3, 9] –> First, merge arrays of lengths 5 and 3 that will cost 8.

[6, 8, 9] –> Next, merge arrys of lengths 6 and 8 that will cost 14.

[14, 9] –> Finally, merge the remaining two arrays that will cost 23.

Therefore, the total cost for merging all arrays is 8 + 14 + 23 = 45.

Examples
Input 1
4
6 5 3 9
Output 1
45
Input 2
10
42 18 63 26 19 15 11 29 26 24
Output 2
869
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
            if(a[p]<=a[i]){
                break;
            }
            long long t=a[p];
            a[p]=a[i];
            a[i]=t;
            i=p;
        }
    }
    void heapify(int i) {
        while (2*i+1<n) {
            int c=2*i+1;
            if(c+1<n && a[c+1]<a[c]) c++;
            if (a[i]<=a[c]) break;
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
        if (n>0) {
            a[0]=a[n];
            heapify(0);
        }
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
    long long ans=0;
    while (h.size() >1){
        long long x=h.pop();
        long long y=h.pop();
        long long sum=x+y;
        ans+=sum;
        h.push(sum);
    }
    cout<<ans<<endl;
    return 0;
}