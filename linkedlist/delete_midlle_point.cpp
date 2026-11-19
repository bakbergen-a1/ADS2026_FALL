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
    Node*slow=head;
    Node*fast=head;
    Node*prev=nullptr;
    while(fast!=nullptr && fast->next!=nullptr){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev!=nullptr){
        prev->next=slow->next;
        delete slow;
    }
    Node*current1=head;
    while(current1!=nullptr){
        cout<<current1->data<<" ";
        current1=current1->next;
    }

}