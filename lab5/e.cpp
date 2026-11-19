/*
Nurdana loves cookies! She stores all the cookies in separate boxes, but mom allows her to store only 
 boxes. Her dad is an assistant in this matter. He gives her a box in which there are 
 cookies. Help her calculate how many cookies she can have?

Input
The first line contains two integers 
 and 
 (1 
 
, 
 
 
). Each of the following 
 lines contains one command.

There are two types of commands:

insert 
 - dad gives a box with 
 cookies (
)

print - print the maximum number of cookies Nurdana can have

Output
For each query of type print output, on a separate line, the sum of the 
 largest of the numbers inserted so far.

If fewer than 
 numbers have been inserted, output the sum of all of them; if nothing has been inserted yet, output 
.

Equal values are counted separately: if the value 
 was inserted three times and 
, all three copies contribute to the sum.

Note
This problem must be solved using a heap.

Use long long type for the sum of elements.

Since 
 is fixed, you don’t need to store all numbers, only 
 largest elements.

The answer can be as large as 
, so a 
-bit integer is not enough.

Examples
Input 1
6 4
print
insert 9
insert 6
print
insert 10
print
Output 1
0
15
25
Input 2
7 2
insert 2
insert 6
insert 3
print
print
insert 1
print
Output 2
9
9
9
*/
#include <iostream>
using namespace std;
struct Heap{
    long long *a;
    int n;
    int cap;

    Heap(int size){
        a=new long long [size+5];
        n=0;
        cap=size;
    }
    void push(long long x){
        int i=n;
        a[n]=x;
        n++;
        while (i>0){
            int p=(i-1)/2;
            if(a[p]<=a[i]) break;
            long long t=a[p];
            a[p]=a[i];
            a[i]=t;
            i=p;
        }
    }
    void heapify(int i){
        while (2*i+1<n){
            int c=2*i+1;
            if(c+1<n && a[c+1]<a[c]) c++;
            if(a[i]<=a[c]) break;
            long long t=a[i];
            a[i]=a[c];
            a[c]=t;
            i=c;
        }
    }
    long long pop(){
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
    int q,k;
    cin>>q>>k;
    Heap h(k);
    long long sum=0;
    for(int i=0;i<q;++i) {
        string s;
        cin>>s;
        if(s=="insert") {
            long long x;
            cin>>x;
            if(h.size()<k) {
                h.push(x);
                sum+=x;
            }else if(x>h.a[0]) {
                sum-=h.pop();
                h.push(x);
                sum+=x;
            }
        }else if (s=="print") cout<<sum<<endl;
    }
    return 0;
}