/*
Implement a doubly linked list that stores the titles of books, and run a sequence of commands on it.

The list must support the following commands:

add_front <title> — add a book to the beginning of the list. Print ok.

add_back <title> — add a book to the end of the list. Print ok.

erase_front — remove the first book. Print the title of the removed book.

erase_back — remove the last book. Print the title of the removed book.

front — print the title of the first book, without removing it.

back — print the title of the last book, without removing it.

clear — remove every book from the list. Print ok.

exit — print goodbye and stop.

If the list is empty when erase_front, erase_back, front or back is called, there is nothing to report — print error instead and leave the list as it is. The commands clear and exit always work, even on an empty list.

Input
Each line of the input contains one command from the list above. The commands add_front and add_back are followed on the same line, after a single space, by the title of the book: a non-empty string of at most 
 characters, each of them a Latin letter, a digit or an underscore.

The last command of the input is always exit, and it is the only occurrence of exit. The total number of commands does not exceed 
.

Output
For each command print its answer on a separate line, as described above.

Note
Let us follow the first example step by step:

add_front Harry_Potter — the list becomes [Harry_Potter], print ok;

add_back Light — [Harry_Potter, Light], print ok;

erase_front — removes Harry_Potter, print Harry_Potter;

erase_back — removes Light, print Light;

erase_front — the list is already empty, print error;

add_front Happy — [Happy], print ok;

back — print Happy;

add_back Autumn, add_front Alchemy — [Alchemy, Happy, Autumn], print ok twice;

clear — the list becomes empty, print ok;

front — the list is empty, print error;

exit — print goodbye.

Examples
Input 1
add_front Harry_Potter
add_back Light
erase_front
erase_back
erase_front
add_front Happy
back
add_back Autumn
add_front Alchemy
clear
front
exit
Output 1
ok
ok
Harry_Potter
Light
error
ok
Happy
ok
ok
ok
error
goodbye
*/
#include <iostream>
using namespace std;
struct Node{
    string data;
    Node*prev;
    Node*next;
};
int main() {
    Node*head=nullptr;
    Node*tail=nullptr;
    string s;
    while(cin>>s){
        if(s=="add_front"){
            string x;
            cin>>x;
            Node*p=new Node;
            p->data=x;
            p->prev=nullptr;
            p->next=head;
            if(head!=nullptr) head->prev=p;
            else tail=p;
            head=p;
            cout<<"ok"<<endl;
        }else if(s=="add_back"){
            string x;
            cin>>x;
            Node*p=new Node;
            p->data=x;
            p->next=nullptr;
            p->prev=tail;
            if(tail!=nullptr) tail->next=p;
            else head=p;
            tail=p;
            cout<<"ok"<<endl;
        }else if(s=="erase_front") {
            if(head==nullptr) cout<<"error"<<endl;
            else{
                Node*temp=head;
                cout<<temp->data<<endl;
                head=head->next;
                if(head!=nullptr) head->prev=nullptr;
                else tail=nullptr;
                delete temp;
            }
        }else if(s=="erase_back"){
            if(tail==nullptr) cout<<"error"<<endl;
            else{
                Node*temp=tail;
                cout<<temp->data<<endl;
                tail=tail->prev;
                if(tail!=nullptr) tail->next=nullptr;
                else head=nullptr;
                delete temp;
            }
        }
        else if(s=="front"){
            if(head==nullptr) cout<<"error"<<endl;
            else cout<<head->data<<endl;
        }else if(s=="back"){
            if(tail==nullptr) cout<<"error"<<endl;
            else cout<<tail->data<<endl;
        }else if(s=="clear"){
            while(head!=nullptr){
                Node*temp=head;
                head=head->next;
                delete temp;
            }
            tail=nullptr;
            cout<<"ok"<<endl;
        }else if(s=="exit"){
            cout<<"goodbye"<<endl;
            break;
        }
    }
    return 0;
}