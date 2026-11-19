/*
Aisha is writing a music player. The playlist is stored as a singly linked list: every song knows only which song comes after it, and nothing about the song before it.

She has just added a Play in reverse button. The player cannot step backwards — it can only follow 
 pointers — so pressing the button has to rebuild the list itself, turning every 
 pointer around.

Given a playlist, print it the way the player will see it after the button is pressed.

Input
The first line contains one integer 
 — the number of songs in the playlist (
).

The second line contains 
 integers 
 — the identifiers of the songs, listed from the head of the list to its tail (
).

Output
Print 
 integers separated by single spaces — the identifiers of the songs from the head of the reversed list to its tail.

Note
In the first example the list 
 becomes 
.

In the second example the playlist holds a single song, so reversing it changes nothing.

Examples
Input 1
5
1 2 3 4 5
Output 1
5 4 3 2 1
Input 2
1
-7
Output 2
-7
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
    Node*prev=nullptr;
    Node*current=head;
    Node*next=nullptr;
    while(current!=nullptr){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    Node*current2=head;
    while(current2!=nullptr){
        cout<<current2->data<<" ";
        current2=current2->next;
    }
    return 0;
}