/*
There is only one road and 
 houses in the Tokyo, and all the houses are on this road. House numbered from 
 to 
 and appear in this order. There are 
 ghouls living in the 
 house. Due to the RC-cells infection, 
 roadblocks need to be installed between houses in Tokyo, so that 
 blocks of houses are detached. Kaneki Ken wants to divide ghouls so that the maximum number of ghouls over blocks (consecutive houses detached by roadblocks) is minimal. Help Kaneki find this number.

Subtasks

1. (
) 

2. (
) 

3. (
) other tests

Input
The first line contains integers 
 and 
 (
). The second line contains the elements of the array 
 (
).

Output
Print one integer — the minimum possible maximum number of ghouls in a block.

Note that the answer does not always fit into a 
-bit integer type.

Note
In the first example: (3+4+2+1), (3+4+5), (2+2+3)

Scoring
Group 1 (
 points): 
.

Group 2 (
 points): 
.

Group 3 (
 points): no additional constraints.

Examples
Input 1
10 3
3 4 2 1 3 4 5 2 2 3
Output 1
12
Input 2
10 4
3 1 2 4 10 8 4 2 5 3
Output 2
12
Input 3
2 1
399265 867718
Output 3
1266983
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDivide(const vector<long long>& a, int k, long long maxAllowedSum) {
    int subarraysCount = 1;
    long long currentSum = 0;

    for (long long x : a) {
        if (currentSum + x <= maxAllowedSum) currentSum += x;
        else {
            subarraysCount++;
            currentSum = x;
        }
    }

    return subarraysCount <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    long long left = 0;
    long long right = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        left = max(left, a[i]); 

        right += a[i];          
    }

    while (left < right) {
        long long mid = left + (right - left) / 2;

        if (canDivide(a, k, mid)) right = mid;
        else left = mid + 1;
    }

    cout << left << '\n';
    return 0;
}