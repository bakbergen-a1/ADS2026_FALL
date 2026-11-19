/*
Jonathan the Poet has just finished a new poem, but something about the rhyme feels off. He is convinced that shifting the poem cyclically by 
 positions will fix it.

The poem is stored as a singly linked list of words: every word knows only which word comes after it. A cyclic shift by 
 moves the first 
 words to the very end, keeping their order, so the poem

      

turns into

      

Jonathan is tired. Help him and print the shifted poem.

Input
The first line contains two integers 
 and 
 — the number of words in the poem and the size of the shift (
).

The second line contains 
 words separated by single spaces. Every word is a non-empty string of lowercase Latin letters, and the total length of all words does not exceed 
.

Output
Print the 
 words of the shifted poem, separated by single spaces.

Note
In the first example 
 and 
: the first two words, “the” and “show”, move to the end.

In the second example 
, so “another one bites” moves to the end and the poem starts with “the dust”.

Examples
Input 1
5 2
the show must go on
Output 1
must go on the show 
Input 2
5 3
another one bites the dust
Output 2
the dust another one bites 
*/
#include <iostream>
#include <string>
using namespace std;
struct Node{
    string data;
    Node*next;
};
int main(){
    int n,k;
    cin>>n>>k;
    Node*head=nullptr;
    Node*tail=nullptr;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        Node*p=new Node;
        p->data=s;
        p->next=nullptr;
        if(head==nullptr){
            head=p;
            tail=p;
        }else{
            tail->next=p;
            tail=p;
        }
    }
    k=k%n;
    if(k>0){
        Node*current=head;
        for(int i=1;i<k;i++) current=current->next;
        Node*newhead=current->next;
        current->next=nullptr;
        tail->next=head;
        head=newhead;
    }
    Node*current=head;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current=current->next;
    }
    return 0;
}