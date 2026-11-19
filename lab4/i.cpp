/*
You are given a permutation of size 
. Create an empty BST, and insert the values 
 into it in this order, one by one, using the usual binary search tree insertion (no balancing). Find the number of leaves in the resulting BST.

Input
The first line contains a single integer 
 (
) — the size of the permutation.

The second line contains 
 distinct integers from 
 to 
 — the permutation 
.

Output
Output one integer — the number of leaves in the BST after all 
 insertions.

Note
A vertex is called a leaf if it has no children.

In the second sample the BST looks like this.

image

The answer is 
 (vertices 
 and 
).

Examples
Input 1
1
1
Output 1
1
Input 2
5
4 3 5 1 2
Output 2
2
*/
#include <iostream>
using namespace std;
struct Node{
    int v;
    Node *l,*r;
    Node(int x): v(x),l(0),r(0) {};
};
void insert(Node*& root,int x){
    if (!root){
        root=new Node(x);
        return;
    }
    if(x<root->v){
        insert(root->l,x);
    }else if(x>root->v){
        insert(root->r,x);
    }
}
//int ans=0; 

void check(Node* root,int& ans){
    if (!root){
        return;
    }
    if (root->l==0 && root->r==0) {
        ans++;
    }
    check(root->l,ans);
    check(root->r,ans);
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
    int ans=0;
    check(root,ans);
    cout<<ans;
    return 0;
}