/*
Christmas is coming! Everyone is preparing gifts for their families. The Damir’s family is also preparing for this. The Damir’s family has many children, so the parents decided to buy 
 various gifts. Parents decided to number these gifts - 
-th as 
. They hang them on Christmas tree in socks, following the form binary search tree. In particular, they insert 
-th gift with the value 
 following the rules of binary search tree.

As you know, Damir is the smallest among the whole family. Therefore, parents for the holiday allowed him to pick up his gift first. Damir knew that his gift has number 
, but he mistakenly assumed that all the gifts below his gift were also intended for him. Now, parents are confused and want to find out what gifts Damir wants to grab for himself.

Input
The first line contains one integer 
 (
) — the number of gifts.

The second line contains 
 pairwise distinct integers 
 (
) — the numbers of the gifts in the order they are hung.

The third line contains one integer 
 (
). It is guaranteed that the array contains the number 
.

Output
Print the numbers of the gifts of the subtree of 
 in pre-order: first the number of the current node, then the whole left subtree, then the whole right subtree. Print all the numbers in one line, separated by single spaces.

Note
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
void give(Node* root) {
    if(!root) {
        return;
    }
    cout<<root->v<<" ";
    give(root->l);
    give(root->r);
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
    give(node);
    return 0;
}