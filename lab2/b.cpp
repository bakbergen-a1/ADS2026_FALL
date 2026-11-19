/*
Kuanyshbek has been studying how multithreading works in operating systems. He wrote a program that starts a single thread which writes to a single file. Being careless, he actually launched two threads with different parameters writing into the same file. The OS lets only one thread write at a time, so the two threads took turns: the first record came from thread one, the second from thread two, the third from thread one again, and so on.

Kuanyshbek only needs the data of the first thread. Help him throw away everything the second thread wrote — that is, every element standing at an even position, counting from 
.

Solve this problem with a linked list: build the list, then delete every second node.

Input
The first line contains one integer 
 — how many records ended up in the file (
).

The second line contains 
 integers separated by single spaces — the records in the order they were written (
).

Output
Print the values that are left in the list after every second one has been deleted, separated by single spaces — that is, the records at positions 

Note
In the example the records at positions 
 and 
 — the values 
 and 
 — came from the second thread and are deleted. The values 
, 
 and 
 are left.

Examples
Input 1
5
1 2 3 4 5
Output 1
1 3 5 
*/
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
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
    Node*current=head;
    while(current!=nullptr && current->next!=nullptr) {
        Node*temp=current->next;
        current->next=temp->next;
        delete temp;
        current=current->next;
    }
    current=head;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current=current->next;
    }
    return 0;
}