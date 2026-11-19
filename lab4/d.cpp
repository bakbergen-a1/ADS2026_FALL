/*
You are given a permutation of size 
. Create an empty BST, and insert into BST values 
 in this order. You need to find how many levels are there and the sum of values for each level.

Input
In the first line there is a single integer 
 size of permutation. Second line contains 
 distinct numbers from 
 to 
 - the permutation.

Output
In the first line output 
 — the number of levels in the resulting BST. In the second line output 
 integers — the sum of values on each level, in order of increasing level, starting from level 
 (the root).

Note
Level of vertex is defined as:

Level of root is 0, and level of each non-root vertex is (level of it’s parent) + 1.

In second testcase, BST looks like this.

image

There are 4 levels, and sum for each level is 4, 3 + 5, 1, 2.

Examples
Input 1
1
1
Output 1
1
1
Input 2
5
4 3 5 1 2
Output 2
4
4 8 1 2
*/
#include <iostream>
using namespace std;
struct Node{
    int v;
    Node *l,*r;
    Node(int x): v(x),l(0),r(0) {}
};
void insert(Node*& root,int x) {
    if (!root) {
        root=new Node(x);
        return;
    }
    if (root->v>x){
        insert(root->l,x);
    }else{
        insert(root->r,x);
    }
}
void go(Node* root,int lev,int *sum) {
    if (!root) {
        return;
    }
    sum[lev]+=root->v;
    go(root->l,lev+1,sum);
    go(root->r,lev+1,sum);
}
int main() {
    int n;
    cin>>n;
    Node* root=0;
    for (int i=0;i<n;++i) {
        int x;
        cin>>x;
        insert(root,x);
    }
    int* sum=new int[n]();
    go(root,0,sum);
    int le=0;
    for(int i=0;i<n;++i) {
        if(sum[i]!=0) {
            le++;
        }
    }
    cout<<le<<endl;
    for(int i=0;i<le;++i) {
        cout<<sum[i]<<" ";
    }
    //delete[] sum;
    return 0;
}