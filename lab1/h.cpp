/*
One day Nugman was solving the problems of LAB1 and managed to finish almost all of them. Only one problem was left, and it would not give in — so Nugman asks for your help.

There are n
 people standing in a queue, and the 
-th of them is 
 years old. The queue starts at position 1
. Every person wants to know the age of the closest person standing before them who is strictly younger — that is, the nearest position to the left holding a strictly smaller age. If there is no such person, the answer is -1
.

Input
The first line contains a single integer 
 (
) — the number of people in the queue.

The second line contains 
 integers 
 (
) — the ages of the people, listed from the front of the queue to the back.

Output
Print 
 integers separated by spaces, where the 
-th of them is the answer for the 
-th person.

Note
In the first example the queue is 
. The first two people have nobody strictly younger before them. For the third person (age 
) the nearest smaller age to the left is 
; for the fourth (age 
) it is 
; for the fifth (age 
) the ages 
 and 
 are too large, so the answer is 
 again.

In the second example the ages increase, so every person sees the one standing directly in front of them.

Equal ages do not count. For the queue 
 the answer is 
: for the fourth person the third one has the same age, not a smaller one.

Examples
Input 1
5
2 1 5 8 3
Output 1
-1 -1 1 5 1 
Input 2
5
1 2 3 4 5
Output 2
-1 1 2 3 4 
*/


#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    vector<int> s;
    vector<int> b;
    for(int x:a){
        while(!s.empty() && s.back()>=x) s.pop_back();
        if(!s.empty()) b.push_back(s.back());
        else b.push_back(-1);
        s.push_back(x);
    }
    for(int x:b) cout<<x<<" ";
    return 0;
}