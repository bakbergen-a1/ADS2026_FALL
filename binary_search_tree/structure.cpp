#include <iostream>
using namespace std;
struct Node{
    int v;
    Node *l,*r;
    Node (int x): v(x),l(0),r(0) {}
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
Node * search(Node* root,int x) {
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
void show(Node*root){
    if(!root) return;
    show(root->l);
    cout<<root->v<<" ";
    show(root->r);
}
int main(){
    int n;
    cin>>n;
    Node*root=0;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        insert(root,x);
    }
    show(root);
}