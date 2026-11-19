/*
Jonathan almost finished his project by Object-Oriented Programing course. His code consists of 
 consecutive blocks, each of them consists of a certain amount of lines. Unfortunately, Jonathan made a lot of mistakes. Compiler showed that Jonathan made 
 mistakes, each of them is described by the number of line where this mistake was made. To debug his project faster, Jonathan wants to define number of block in which he made a mistake. Please, help Jonathan debug his project before deadline will expire.

Input
First line consists of integers 
 and 
 - number of blocks and mistakes (1 
 
, 
 
 2 
 
).

The second line contains 
 integers 
 - number of lines in the 
 block (1 
 
 
 
).

Each of the next 
 lines contains one integer 
 - number of line where the 
 mistake was made (1 
 
 
 
). In other words, every mistake is guaranteed to fall inside the code, so the answer always exists.

Output
Print 
 lines, the 
 line must contain the number of block in which the 
 mistake was made.

Note
In the first sample lines [1, 3] belong to the first block and lines [4, 7] to the second. So, Jonathan will find mistake at the fifth line at the second block.

In the second sample lines [1, 5], [6, 12], [13, 18] belong to the first, second and third blocks respectively. So, the fifth line is inside first block, the tenth line is inside second block and the fifteenth line is inside third block.

Hint: Think about inplementing binary search function to solve this problem.

Hint: Build a new array 
, where 
 is the line at which 
 block ends. You can notice, that this array is sorted.

Examples
Input 1
2 1
3 4
5
Output 1
2
Input 2
3 3
5 7 6
5
10
15
Output 2
1
2
3
*/
#include <iostream>
#include <vector>
using namespace std;
int findb(const vector<int>&a,int n){
    int l=0,r=a.size()-1;
    while(l<r){
        int m=(l+r)/2;
        if(a[m]>=n) r=m;
        else l=m+1;
    }
    return l+1;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    int s=0;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        s+=x;
        a[i]=s;
    }
    for(int i=0;i<m;++i){
        int q;
        cin>>q;
        cout<<findb(a,q)<<"\n";
    }
    return 0;
}