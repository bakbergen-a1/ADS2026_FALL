/*
Given the root of a binary search tree with distinct keys. Replace the key of each node with the sum of the keys over the nodes that has greater than or equal key. Print new keys in increasing order.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node’s key.

The right subtree of a node contains only nodes with keys greater than the node’s key.

Both the left and right subtrees must also be binary search trees.

Input
The first line contains a single integer 
 (
) — the number of nodes.

The second line contains 
 pairwise distinct integers 
 (
) — the keys, inserted one by one, in this order, into an initially empty binary search tree.

Output
In a single line print 
 integers — the new keys in increasing order, separated by single spaces.

Note
NOTE: Solve with BST! image

Examples
Input 1
9
4 1 6 0 2 3 5 7 8
Output 1
8 15 21 26 30 33 35 36 36
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

void change(Node* root,int& sum){
    if(!root) {
        return;
    }
    change(root->r,sum);
    sum+=root->v;
    root->v=sum;
    change(root->l,sum);
}

void inorder(Node* root){
    if(!root){
        return;
    }
    inorder(root->r);
    cout<<root->v<<" ";
    inorder(root->l);
    
}
int main() {
    int n;
    cin>>n;
    Node* root=0;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        insert(root,x);
    }
    int sum=0;
    change(root,sum);
    inorder(root);
    return 0;
}