/*
This is a continuation of the story about the Aslan and Password task from the last quiz. The story is that Nurbol successfully hacked Aslan’s Steam account. Aslan was of course upset, but he doesn’t give up. He decided to restore his Steam account. To do this, he wrote in support of Steam. Aslan gave them the nickname of his account. But it is possible for Nurbol to change the nickname of the account. And now Steam employees must understand what the new nickname is. Employees have logs of changing nicknames, the logs consist of n lines. The line itself consists of two words, the old nickname, and the new one. Help employees to display all original nicknames and new nicknames next to them.

Input
The first line is number n (1
n
1000) the number of requests to change the nickname. Next n lines consist of two strings, old nickname and new nickname.

Every nickname is a non-empty string of at most 
 Latin letters and digits; nicknames are case-sensitive, and the old nickname always differs from the new one.

It is guaranteed that a nickname belongs to one user forever: once some user has used a nickname, no other user can ever take it.

Output
The first line is the number 
 — the number of users who changed their nicknames.

Each of the next 
 lines contains two strings: the original nickname of a user and his current nickname. Print these lines sorted by the original nickname in lexicographical order.

Note
In the first test nickname "Aslan" was changed to nickname "Nurbol". Then this nickname was changed to "HackMachine". As a result, the original nickname "Aslan" became "HackMachine".

Examples
Input 1
2
Aslan Nurbol
Nurbol HackMachine
Output 1
1
Aslan HackMachine
Input 2
6
Sens3i Danya
S1mple Papa
M9snoyPovar AWPMaster
IAmNoob IAmPro
Papa Sanya
IAmPro IAmNoob
Output 2
4
IAmNoob IAmNoob
M9snoyPovar AWPMaster
S1mple Sanya
Sens3i Danya
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct User{
    string first,last;
};
bool check(User a,User b){
    return a.first<b.first;
}
void qs(vector<User> &a,int l,int r){
    int i=l,j=r;
    User p=a[(l+r)/2];
    while(i<=j){
        while(check(a[i],p)) i++;
        while(check(p,a[j])) j--;
        if(i<=j) swap(a[i++],a[j--]);
    }
    if(l<j) qs(a,l,j);
    if(i<r) qs(a,i,r);
}
int main(){
    int n;
    cin>>n;
    map<string,string> c;
    map<string,string> o;
    for(int i=0;i<n;++i){
        string old,now;
        cin>>old>>now;
        if(o.count(old)){
            string orig=o[old];
            c[orig]=now;
            o.erase(old);
            o[now]=orig;
        }else{
            c[old]=now;
            o[now]=old;
        }
    }
    vector<User> ans;
    for(auto& [old,now]:c) ans.push_back({old,now});
    qs(ans,0,ans.size()-1);
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x.first<<" "<<x.last<<endl;
    return 0;
}