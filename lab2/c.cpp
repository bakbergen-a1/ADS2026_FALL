/*
The KBTU database has crashed and the list of all students came back damaged: some names got duplicated. The way the crash worked, all copies of the same name always ended up in consecutive positions. For instance, the name “Dana” may occupy positions 
, but it can never occupy positions 
, because those are not consecutive.

Help the teachers get rid of the duplicates: keep only the first record of every group of equal neighbours, without changing the order of the list.

Input
The first line contains one integer 
 — the number of records (
).

Each of the next 
 lines contains one name: a non-empty string of at most 
 Latin letters. Both uppercase and lowercase letters may occur, and they are considered different: “Aa” and “aA” are two different names.

All records of the same name are guaranteed to occupy consecutive positions.

Output
On the first line print one integer — how many students are left after the duplicates are removed.

Then print those names, one per line, in the same order in which they appear in the input.

Note
In the first example “Dana” occupies positions 
, so two of the three records are dropped and three students remain: Alice, Dana and Bob — in exactly that order.

In the second example there is nothing to remove.

In the third example the two copies of “wow” stand next to each other, so one of them is dropped.

Examples
Input 1
5
Alice
Dana
Dana
Dana
Bob
Output 1
3
Alice
Dana
Bob
Input 2
2
wow
kek
Output 2
2
wow
kek
Input 3
3
kek
wow
wow
Output 3
2
kek
wow
*/
#include <iostream>
using namespace std;
struct Node{
    string data;
    Node*next;
};
int main() {
    int n;
    cin>>n;
    Node*head=nullptr;
    Node*tail=nullptr;
    for(int i=0;i<n;++i){
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
    Node*current=head;
    while(current!=nullptr && current->next!=nullptr){
        if(current->data==current->next->data){
            Node*temp=current->next;
            current->next=temp->next;
            delete temp;
            n--;
        }else{
            current=current->next;
        }
    }
    cout<<n<<endl;
    current=head;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current=current->next;
    }
    return 0;
}