/*
You are given 
 integers. Insert them one by one, in the given order, into an initially empty binary search tree, and then print the 
-th smallest element of the tree.

For example, if the values are 
 and 
, then the in-order traversal of the tree visits them in sorted order 
, so the answer is 
; for 
 the answer is 
.

Input
The first line contains two integers 
 and 
 (
, 
).

The second line contains 
 pairwise distinct integers 
 (
) — the values inserted into the tree, in this order.

Output
Print the 
-th smallest element of the tree.

If 
, print 
.

Examples
Input 1
7 3
20 8 22 4 12 10 14
Output 1
10
Input 2
7 5
20 8 22 4 12 10 14
Output 2
14
*/
#include <iostream>
using namespace std;
struct Node{
    int v;
    Node *l,*r;
    Node(int x): v(x),l(0),r(0) {};
};
void insert(Node*& root ,int x) {
    if(!root){
        root=new Node(x);
        return;
    }
    if(x<root->v){
        insert(root->l,x);
    }else{
        insert(root->r,x);
    }
}
void inorder(Node* root,int k,int& count,int& ans){
    if(!root){
        return;
    }
    inorder(root->l,k,count,ans);
    count++;
    if(count==k) {
        ans=root->v;
        return;
    }
    inorder(root->r,k,count,ans);
}
int main() {
    int n,k;
    cin>>n>>k;
    Node* root=0;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        insert(root,x);
    }
    int count=0;
    int ans=-1;
    if(k>n){
        cout<<-1;
    }else{
        inorder(root,k,count,ans);
        cout<<ans;
    }
    return 0;
}