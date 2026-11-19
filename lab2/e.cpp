/*
The scoreboard of a relay race is kept as a singly linked list of runners, in the order they crossed the finish line.

One of the runners turned out to be a pacemaker who was never part of the competition, and by the rules of this race the pacemaker always finishes exactly in the middle. If the scoreboard holds 
 runners, numbered 
 starting from the head of the list, the pacemaker is the runner with number 
.

Remove that runner from the list and print what is left of the scoreboard.

Input
The first line contains one integer 
 — the number of runners on the scoreboard (
).

The second line contains 
 integers 
 — the identifiers of the runners, listed from the head of the list to its tail (
).

Output
Print the 
 remaining identifiers separated by single spaces, from the head of the list to its tail.

If 
, the list becomes empty — print an empty line.

Note
In the first example 
, so the runner to remove is the one with number 
, that is the value 
.

In the second example 
 and 
, so the value 
 is removed. Note that for an even length the node to remove is the second of the two middle ones.

In the third example the scoreboard holds a single runner, who is removed, and the output is empty.

Examples
Input 1
5
10 20 30 40 50
Output 1
10 20 40 50
Input 2
4
1 2 3 4
Output 2
1 2 4
Input 3
1
42
Output 3

*/
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
        if(head==nullptr) {
            head=p;
            tail=p;
        }else{
            tail->next=p;
            tail=p;
        }
    }
    int pos=n/2+1;
    if(pos==1){
        Node*temp=head;
        head=head->next;
        delete temp;
    }else{
        Node*current=head;
        for(int i=1;i<pos-1;i++){
            current=current->next;
        }
        Node*temp=current->next;
        current->next=temp->next;
        delete temp;
    }
    Node* current=head;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
    return 0;
}