/*
Alimzhan wanted to check his students for cheating and he added the parasite word to his exam. He believes that students cheat if the parasite word occurs in the same place in two different results of two students. Alimzhan heard that two of his most beloved students were copied from each other. Help Alimzhan know how many times the parasite word is repeated in the same position in his beloved students’ results.

Input
The first line contains string 
 (
), consisting of lowercase Latin letters — the result of the first student.

The second line contains string 
 (
), consisting of lowercase Latin letters — the result of the second student.

The third line contains string 
 (
), consisting of lowercase Latin letters — the parasite word.

Output
Print one integer — the number of positions 
 such that the parasite word 
 occurs in 
 starting at position 
 and occurs in 
 starting at the same position 
.

Note
The strings are long, so comparing 
 with every position directly is too slow. Compute the hashes of all substrings of the needed length with the Rabin–Karp technique (prefix hashes and one precomputed power table) and compare hashes instead of strings.

A single hash can collide on adversarial data; a pair of hashes with two different moduli is the usual remedy.

Examples
Input 1
kbtuutbkkbtu
utbkkbtukbtu
kbtu
Output 1
1
Input 2
aaaaa
aaaaa
a
Output 2
5
Input 3
abracadabra
abacabaabac
ab
Output 3
2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<char> match(const string& s,const string& t){
    string c=t+'#'+s;
    int n=c.size(),m=t.size();
    vector<int> z(n,0);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<r) z[i]=min(r-i,z[i-l]);
        while(i+z[i]<n && c[z[i]]==c[i+z[i]]) z[i]++;
        if(i+z[i]>r) l=i,r=i+z[i];
    }
    vector<char> res(s.size(),0);
    for(size_t i=0;i<s.size();i++){
        if(z[m+1+i]>=m) res[i]=1;
    }
    return res;
}
int main(){
    string a,b,t;
    cin>>a>>b>>t;
    auto x=match(a,t);
    auto y=match(b,t);
    size_t k=min(x.size(),y.size());
    long long s=0;
    for(size_t i=0;i<k;++i){
        if(x[i] && y[i]) s++;
    }
    cout<<s<<endl;
}