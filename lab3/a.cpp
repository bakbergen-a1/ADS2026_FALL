/*
You are given a sorted array and a number 
. Determine whether 
 occurs in the array.

This is the warm-up for the technique: the array here is small, but write the search so that it halves the range at every step rather than scanning the elements one by one — the same code will be needed later on arrays where scanning is far too slow.

Input
The first line contains one integer 
 — the size of the array (
).

The second line contains 
 integers 
 — the elements of the array in non-decreasing order (
). Equal elements are allowed.

The third line contains one integer 
 — the number to look for (
).

Output
Print Yes if 
 occurs in the array, and No otherwise.

Note
In the first example 
 is the very first element of the array, so the answer is Yes.

In the third example 
 is greater than every element, so the answer is No.

Examples
Input 1
5
1 2 3 4 5
1
Output 1
Yes
Input 2
5
1 2 3 4 5
2
Output 2
Yes
Input 3
5
1 2 3 4 5
7
Output 3
No
Input 4
5
1 2 3 4 5
10
Output 4
No
Input 5
5
1 2 3 4 5
5
Output 5
Yes
*/
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int x):data(x),left(nullptr),right(nullptr) {};
};
Node*insert(Node*root,int data){
    if(root==nullptr){
        return new Node(data);
    }
    if(data<root->data) root->left=insert(root->left,data);
    else root->right=insert(root->right,data);
    return root;
}
bool search(Node*root,int n){
    if(root==nullptr) return false;
    if(root->data>n) return search(root->left,n);
    else if(root->data<n) return search(root->right,n);
    else return true;
}
int main() {
    int n;
    cin>>n;
    Node*root=nullptr;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        root=insert(root,x);
    }
    int k;
    cin>>k;
    if(search(root,k)) cout<<"Yes";
    else cout<<"No";
    return 0;
}