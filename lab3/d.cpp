/*
Mark is going to fight for Fight Club. There were 
 competitors with powers. There will be 
 rounds to fight and in each round Mark’s power will be changed. With power 
, Mark can kill all the competitors whose power is equal to or less than his. Round by round, all the competitors who are dead in the previous round will be reborn. Such that in each round there will be 
 competitors to fight. As Mark is tired, please, help him to count the number of competitors that he can win in each round and the total sum of their powers.

Input
The first line contains an integer 
 (1 
 
 
 
) - the number of competitors without Mark. Next line contains 
 integers 
 (1 
 
 
 
) - powers of these competitors. The third line contains one integer 
 (1 
 
 
 
) — the number of rounds. Each of the next 
 lines contains an integer 
 (1 
 
 
 
) — power of Mark at each round.

Output
On each of the 
 lines print two integers — how many competitors Mark beats in this round and the total sum of their powers.

Examples
Input 1
7
7 9 1 8 2 6 2
2
4
8
Output 1
3 5
6 26
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countbeaten(const vector<int>& a, int target) {
    int left = 0;
    int right = a.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (a[mid] <= target) left = mid + 1;
        else right = mid;
    }
    
    return left;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + a[i]; 

    int q, power;
    cin >> q;
    while (q--) {
        cin >> power;

        int count = countbeaten(a, power);
        long long sum = prefix[count];

        cout << count << " " << sum << "\n";
    }
    return 0;
}