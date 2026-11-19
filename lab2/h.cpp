/*
Thor keeps a chronicle of the days before Ragnarok. Every day is written down as a number: a good day is a positive number, a bad day is a negative one. The chronicle is stored as a singly linked list — each day only knows which day comes after it.

Thor wants to find the best stretch of the chronicle: a non-empty run of consecutive days whose numbers add up to the largest possible sum. Print that sum.

Input
The first line contains one integer 
 — the number of days in the chronicle (
).

The second line contains 
 integers 
 — the days in the order they are stored in the list, from its head to its tail (
).

Output
Print one integer — the largest sum over all non-empty runs of consecutive days.

Note
In the first example the best run is the whole chronicle: 
.

In the second example every day is bad, so the best you can do is take a single day: 
. Note that the run must be non-empty — the answer is never 
 here.

In the third example the best run is 
.

Examples
Input 1
5
1 2 -1 4 5
Output 1
11
Input 2
3
-1 -1 -1
Output 2
-1
Input 3
10
5 1 2 -10 5 3 9 -5 10 10
Output 3
32
*/
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
};
int main(){
    int n;
    cin>>n;
    Node*head=nullptr;
    Node*tail=nullptr;
    for(int i=0;i<n;i++){
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
    int sum=current->data;
    int best=current->data;
    current=current->next;
    while(current!=nullptr){
        if(sum+current->data > current->data) sum+=current->data;
        else sum=current->data;
        if(sum>best) best=sum;
        current=current->next;
    }
    cout<<best;
    return 0;
}