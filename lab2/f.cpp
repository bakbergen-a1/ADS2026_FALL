/*
Two ticket offices at a railway station keep their own waiting lists. Each list is a singly linked list of ticket numbers, and inside each list the numbers already go in non-decreasing order.

The offices are being merged into one. The new waiting list must contain every ticket from both lists and must again be in non-decreasing order.

The station manager refuses to pay for extra memory: the merged list has to be built out of the nodes that already exist, only by re-linking their 
 pointers. No new node may be created.

Input
The first line describes the first list. It starts with the length 
 (
), followed by 
 integers in non-decreasing order — the ticket numbers from the head of the list to its tail (
). If 
, the line contains just the single number 
.

The second line describes the second list in exactly the same way: its length 
 (
) followed by 
 integers in non-decreasing order (
).

Output
Print 
 integers in non-decreasing order, separated by single spaces — the merged waiting list from its head to its tail.

If both lists are empty, print an empty line.

Note
In the first example the two lists interleave completely.

In the second example the first list is empty, so the answer is the second list unchanged. Watch this case: a solution that starts by reading 
 without first checking that the list is non-empty will crash here.

In the third example both lists are empty and the output is empty.

Examples
Input 1
3 1 3 5
3 2 4 6
Output 1
1 2 3 4 5 6
Input 2
0
3 2 4 6
Output 2
2 4 6
Input 3
0
0
Output 3

*/
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
};
void add(Node*&head,Node*& tail,int x){
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
int main() {
    int n,m;
    cin>>n;
    Node*head1=nullptr;
    Node*tail1=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        add(head1,tail1,x);
    }
    cin>>m;
    Node*head2=nullptr;
    Node*tail2=nullptr;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        add(head2,tail2,x);
    }
    Node*head=nullptr;
    Node*tail=nullptr;
    while(head1!=nullptr && head2!=nullptr){
        Node*p;
        if(head1->data <= head2->data){
            p=head1;
            head1=head1->next;
        }else{
            p=head2;
            head2=head2->next;
        }
        if(head==nullptr){
            head=p;
            tail=p;
        }else{
            tail->next=p;
            tail=p;
        }
    }
    if(head1!=nullptr){
        if(head==nullptr) head=head1;
        else tail->next=head1;
    }
    if(head2!=nullptr){
        if(head==nullptr) head=head2;
        else tail->next=head2;
    }
    Node*current=head;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current=current->next;
    }
    return 0;
}