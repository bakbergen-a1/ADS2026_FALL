/*
Albert does not agree with the basic English alphabet. He thinks, that in the alphabet, first, we need to print vowel letters first and then consonants, and both vowels and consonants are ordered alphabetically. So he asks us to sort string according to his own alphabet.

Input
The first line contains one integer 
 (
) — the length of the string.

The second line contains the string 
 of exactly 
 lowercase Latin letters.

Output
Print the letters of 
 rearranged according to Albert’s alphabet: first all its vowels in alphabetical order, then all its consonants in alphabetical order.

Note
Vowel letters are a, e, i, o and u.

Examples
Input 1
41
hqghumeaylnlfdxfircvscxggbwkfnqduxwfnfozv
Output 1
aeiouubccddfffffggghhkllmnnnqqrsvvwwxxxyz
*/
#include <iostream>
#include <algorithm>
using namespace std;
bool isvowel(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
void qs(char a[],int l,int h){
    int i=l;
    int j=h;
    char p=a[(l+h)/2];

    while(i<=j){
        while(a[i]<p) i++;
        while(a[j]>p) j--;

        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(l<j) qs(a,l,j);
    if(i<h) qs(a,i,h);
}

int main() {
    int n;
    cin>>n;
    char s[100005];
    cin>>s;
    char v[100005];
    char c[100005];
    int k=0,g=0;
    for(int i=0;i<n;++i){
        if(isvowel(s[i])){
            v[k++]=s[i];
        }else{
            c[g++]=s[i];
        }
    }

    qs(v,0,k-1);
    qs(c,0,g-1);

    for(int i=0;i<k;++i) cout<<v[i];
    for(int i=0;i<g;++i) cout<<c[i];
    cout<<endl;
    return 0;
}