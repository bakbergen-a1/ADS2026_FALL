/*
Given a binary tree, write a program to get the width of the given tree.

The level of a node is the number of vertices on the path from this node to the root. The width of a level 
 is the number of vertices with level 
. The width of a tree is the maximal width over the levels.

Vertex number 1 always will be root.

Input
The first line contains an integer 
 (
) — the number of vertices.

Each of the next 
 lines contains 
 integers 
 (
, 
) — vertex 
 is a son of vertex 
; if 
 it is the left son, if 
 it is the right son. Vertex 
 is never a son. Every vertex except vertex 
 is a son of exactly one vertex, a vertex has at most one left and at most one right son, and the edges form a tree rooted at vertex 
. For 
 there are no such lines.

The 
 lines are given in arbitrary order: a son may be described before its parent.

Output
Print one integer maximum width.

Note
In the first sample the widest level is the third one, it holds 
 vertices (
, 
, 
).

In the second sample the widest level is the third one as well, it holds 
 vertices (
, 
).

Examples
Input 1
6
1 2 1
1 3 0
3 5 0
3 6 1
2 4 1
Output 1
3
Input 2
4
1 2 0
2 3 0
2 4 1
Output 2
2
*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int* l=new int[n+1]();
    int* r=new int[n+1]();
    for(int i=0;i<n-1;++i) {
        int p,c,s;
        cin>>p>>c>>s;
        if(s==0) 
            l[p]=c;
        else
            r[p]=c;
    }
    int* q=new int[n];
    int start=0;
    int end=0;
    q[end]=1;
    end++;
    int mx=0;
    while(start<end){
        int size=end-start;
        if (size>mx)
            mx=size;
        for(int i=0;i<size;++i) {
            int current=q[start];
            start++;
            if(l[current]!=0){
                q[end]=l[current];
                end++;
            }
            
            if(r[current]!=0){ 
                q[end]=r[current];
                end++;
            }
            
        }
    }
    cout<<mx;
    return 0;

}