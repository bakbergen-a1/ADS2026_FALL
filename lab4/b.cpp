/*
You are given Binary Search Tree. Your task is to calculate the size of the subtree of the node 
.

Remember, that the subtree of node 
 is the set of all nodes whose ancestor is node 
, including it. The size of the subtree is the size of such set.

Input
The first line of the input contains an integer 
 — number of nodes in Binary Search Tree (
).

The second line contains 
 pairwise distinct integers 
 (
) — values of nodes in order of insertion to the Binary Search Tree.

The third line contains a single integer 
 (
) — the value of the node whose subtree size you must calculate. It is guaranteed that 
 occurs among 
.

Output
Print the size of the subtree of the given node.

Examples
Input 1
7
4 2 6 1 3 5 7
4
Output 1
7
*/
#include <iostream>
using namespace std;
struct Node {
    int v;
    Node *l,*r;
    Node(int x): v(x),l(0),r(0) {}
};
void insert(Node*& root,int x) {
    if (!root) {
        root=new Node(x);
        return;
    }
    if (x<=root->v) {
        insert(root->l,x);
    }else{
        insert(root->r,x);
    }
}
Node* search(Node* root ,int x) {
    if(root==nullptr) {
        return nullptr;
    }
    if (root->v==x) {
        return root;
    }
    if (x<root->v) {
        return search(root->l,x);
    }else{
        return search(root->r,x);
    }
}
int Size(Node* root) {
    if(root==nullptr) {
        return 0;
    }
    return 1+Size(root->l)+Size(root->r);

}
int main() {
    int n;
    cin>>n;
    Node* root=0;
    for(int i=0;i<n;++i) {
        int x;
        cin>>x;
        insert(root,x);
    }
    int k;
    cin>>k;
    Node* node=search(root,k);
    cout<<Size(node);
    return 0;
}