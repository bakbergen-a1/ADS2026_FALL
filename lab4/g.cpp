/*
While Gon is surviving on the Greed Island, Killua, after the first unsuccessful attempt to pass the hunter exam, decides to test himself again. This time one of his tasks is to find the maximum distance between any two vertices in a binary search tree. Since Killua is pretty bad at algorithms, he asks for your help.

Input
In the first line you will be given single number 
 
. Next line consists of N numbers, where 
 
 represents the i-th number inserted to a binary search tree.

If 
 is already present in the tree, it is not inserted again — the tree never contains two nodes with equal values.

Subtasks

(30%) 
.

(30%) 

(40%) No additional constraints.

Every test is scored separately; the percentages above show the total weight of each group of tests.

Output
Print one single number — the maximum distance between any two vertices of the binary search tree. The distance between two vertices is the number of vertices on the path between them, so for a tree of one vertex the answer is 
.

Note
In the first test, the answer is the distance between nodes 1 and 8.

Examples
Input 1
9
11 5 3 2 1 7 9 8 13
Output 1
7
Input 2
5
1 2 4 3 5
Output 2
4
Input 3
7
4 2 6 5 1 3 7
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
int ans=1;
int h(Node* root){
    if(!root){
        return 0;
    }
    int lh=h(root->l);
    int rh=h(root->r);
    int d=lh+rh+1;
    if(d>ans){
        ans=d;
    }
    if(lh>rh){
        return lh+1;
    }else{
        return rh+1;
    }
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
    h(root);
    cout<<ans;
    return 0;
}