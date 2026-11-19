/*
You are going to hike in the mountains. You have written directions (left or right) on a piece of paper, in which direction you need to turn on each of the branches of the path, following which you can reach the peak. In the mountains there are several peaks and you have recorded the path to each peak. Since you are a guide, you need to check the day before the hike which of the recorded paths is available. All paths start at one point at the foothills.

The path is presented in the form of 
, which means to reach the peak you need to turn right at the beginning, then right again, then left, left, right, left, right. Peak located after last turn and it is possible that it does not exist. You are given all the paths in the mountains that are available in the form of a Binary Search Tree and the paths to the peaks that are written on a piece of paper. You need to tell which of the paths written on the piece of paper is available.

image

Input
The first line contains two integers 
 and 
 (
, 
) — the number of nodes of the tree and the number of paths written on the piece of paper.

The second line contains 
 integers 
 (
) — the values that are inserted one by one, in this order, into an initially empty binary search tree. A value equal to the value of the current node goes to the left subtree.

Each of the next 
 lines contains one path 
 (
) — a string consisting only of the characters ’L’ and ’R’. The total length of all paths does not exceed 
.

Output
Print 
 lines, in the same order as the paths are given. The 
 line should contain 
 if the path 
 leads to an existing node of the tree, and 
 otherwise.

Examples
Input 1
9 4
7 10 12 8 5 6 2 1 4
LLL
LRR
RL
RR
Output 1
YES
NO
YES
YES
*/
#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int v;
    Node *l,*r;
    Node(int x): v(x),l(0),r(0) {};
};
void insert(Node*& root,int x) {
    if (!root) {
        root=new Node(x);
        return;
    }
    if (x<=root->v) 
        insert(root->l,x);
    else insert(root->r,x);
}
bool check(Node* root,string s) {
    for (char c:s) {
        if (!root) 
            return false;
        root=(c=='L' ? root->l:root->r);

    }
    return root!=nullptr;
}
int main() {
    int n,m;
    cin>>n>>m;
    Node* root=0;
    while (n--) {
        int x;
        cin>>x;
        insert(root,x);
    }
    while (m--) {
        string s;
        cin>>s;
        cout<<(check(root,s) ? "YES\n" : "NO\n");

    }
    return 0;
}