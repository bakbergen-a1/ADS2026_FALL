/*
You are given 
 integers in order of their insertion to Binary Search Tree. You draw a set of horizontal lines, one through all the nodes of the same depth (the depth of the root is 
, and the depth of any other node is the depth of its parent plus one). After that you can see triangles with nodes instead of vertices and edges instead of sides. Your task is to calculate the number of the smallest triangles.

Input
The first line consists of an integer 
 - number of nodes in Binary Search Tree (1 
 
 
 10000).

The second line contains 
 integers 
 - value of each node in Binary Search Tree in order of their insertion (1 
 
 
 
).

It is guaranteed that there are no duplicates.

Output
Print the number of mini-triangles in resulting Binary Search Tree.

Note
A smallest triangle is formed by a node together with its left and its right son, so a node contributes a triangle exactly when both of its sons are present.

In the first sample the insertion order 
 makes 
 the root with sons 
 and 
, so there is exactly 
 triangle.

In the second sample the values 
 are inserted in increasing order, so the tree is a chain and no node has two sons — the answer is 
.

In the third sample the resulting tree contains 
 such triangles.

Examples
Input 1
3
2 3 1
Output 1
1
Input 2
3
1 2 3
Output 2
0
Input 3
16
13 9 3 7 6 16 1 11 12 10 4 2 14 5 8 15
Output 3
5
*/
#include <iostream>
using namespace std;
struct Node{
    int v;
    Node *l,*r;
    Node(int x): v(x),l(0),r(0) {};
};
void insert(Node*& root,int x) {
    if (!root) {
        root=new Node(x);
        return;
    }
    if(root->v>x) {
        insert(root->l,x);
    }
    if(root->v<x){
        insert(root->r,x);
    }
}
void count(Node* root, int& sum) {
    if (!root) {
        return;
    }
    if (root->l != 0 && root->r != 0) {
        sum++;
    }
    count(root->l, sum);
    count(root->r, sum);
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
    int sum=0;
    count(root,sum);
    cout<<sum;
}