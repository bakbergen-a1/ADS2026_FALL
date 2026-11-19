#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
};
int main() {
    int n;
    cin>>n;
    Node*head=nullptr;
    Node*tail=nullptr;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        Node*p=new Node;
        p->data=x;
        p->next=nullptr;
        if(head==nullptr){
            head=p;
            tail=p;
        }else{
            tail->next=p;
            tail=p;
        }
    }
    Node*prev=nullptr;
    Node*current=head;
    Node*next=nullptr;
    while(current!=nullptr){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=tail;
    Node*current1=head;
    while(current1!=nullptr){
        cout<<current1->data<<" ";
        current1=current1->next;
    }

}