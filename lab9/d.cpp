/*
One day Olzhas was bored and he wanted to play the game Towns with friends. But the game has been slightly modified. In this game, each participant in his turn calls another real city of any country, the name of which begins with the maximum possible length of suffix, which ends with the name of the city of the previous participant. It was the turn of Olzhas and he should choose the name of the city. Help him with the choice of the name of the city.

Input
Given string 
 (
) - the name of the city of the previous participant.

In the next line given 
 (
) - the number of city names that Olzhas know.

Next 
 lines represent name 
 (
) of the cities. Each city name starts with an uppercase letter and other letters are lowercase.

Output
The first line should contain integer 
 - the number of possible names of the cities which could say Olzhas.

Each of the next 
 lines should consist of the possible names of the cities in the order of their input.

Examples
Input 1
Kokshetau
5
Astana
Tauemel
Tainan
Almaty
Budapest
Output 1
1
Tauemel
Input 2
Almaty
3
Yacuiba
Yurga
Moscow
Output 2
2
Yacuiba
Yurga
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> prefix(const string &s){
    int n=s.size();
    vector<int> p(n,0);
    for(int i=1;i<n;i++){
        int j=p[i-1];
        while(j>0 && s[i]!=s[j]) j=p[j-1];
        if(s[i]==s[j]) j++;
        p[i]=j;
    }
    return p;
}

string low(string s){
    for(char &c:s) c=tolower(c);
    return s;
}
int main(){
    string p;
    int n;
    cin>>p>>n;
    p=low(p);
    vector<string> a(n);
    vector<int> len(n);
    int mx=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        vector<int> b=prefix(low(a[i]+"#"+p));
        len[i]=b.back();
        if(len[i]>mx) mx=len[i];
    }
    if(mx==0){
        cout<<0<<endl;
        return 0;
    }
    int m=0;
    for(int i=0;i<n;i++) if(len[i]==mx) m++;
    cout<<m<<endl;
    for(int i=0;i<n;++i) if(len[i]==mx) cout<<a[i]<<endl;
    return 0;
}