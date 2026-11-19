/*
You have N strings s ^ s consisting of digits and hashes h ^ i of these strings, where hash of string equal to h ^ i But one day You noticed that hashes and strings were mixed. You need to determine which of the numbers are hashes and which are strings consisting of digits. Also map each string to its hash. Hash should be calculated by formula below. All operations must be performed modulo 1 e9+7: s ^ i
h = (sum i = 0 to |d| - 1 (s_{i} - 47) * 11 ^ i) mod (10 ^ 9 + 7)
Input
Given the number N - number of strings (1 <= N <= 10 ^ 4) Following 2N lines consist from strings and hashes. The length of each string does not exceed 100. It is guaranteed that for each string there is a corresponding hash.
Output
In each line print string with corresponding hash like in example below in order their input.
Note
In first example, hash of string #111 was calculated as follows:
+ ((49 - 47) * 11 ^ 2) mod(1e9+7))mod(1e9+7)=2+22+242=266 h=(( ((49 - 47) * 11 ^ 9) mod(1e9+7)+((49-47)*11^ 1 )mod(1e9+7))mod(1e9+7)+
Note, that the resulting number should be positive.
Examples 
Input 1
3
334368200
111
100000
266
123456789
93085
Output 1
Hash of string "111" is 266
Hash of string "123456789" is 334368200
Hash of string "93085" is 100000
Input 2
3
13903
3383080447314675044643313
9839
813695185
425675346
3461762860035486
Output 2
Hash of string "3383080447314675044643313" is 425675346
Hash of string "9839" is 13903
Hash of string "3461762860035486" is 813695185
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

const long long mod = 1000000007LL;
string hashing(const string& s) {
    long long h = 0, p = 1;
    for(char c : s) {
        h = (h + ((c - 47) * p) % mod) % mod;
        p = (p * 11) % mod;
    }
    return to_string(h);
}
int main() {
    int n; cin >> n;
    vector<string> v;
    unordered_map<string, int> mp;
    v.reserve(2*n); mp.reserve(4*n);
    for(int i = 0; i < 2*n; i++) {
        string s; cin >> s;
        v.push_back(s);
        mp[s]++;
    }
    int cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        if(cnt == n) break;
        string hs = hashing(v[i]);
        if(mp.count(hs)) {
            cout << "Hash of string \"" << v[i] << "\" is " << hs << '\n';
            cnt++; 
        }
    }
    return 0;
}