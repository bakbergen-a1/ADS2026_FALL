/*
Jonathan is the Farmer whose household was damaged by a huge hurricane. He lost majority of his cattle. One day he walked near his farm and observed that there are 
 sheeps on the field. Each sheep is always grazing inside some rectangular area. Jonathan remembered such areas for each sheep. When he came home, he decided to build a paddock to catch at least 
 sheeps (to catch a sheep Jonathan must cover sheep’s pasture fully). Jonathan prefers squares rather than usual rectangles, therefore he want to build square paddock with the corner at point 
. Material for paddock costs money, so Jonathan wants to minimize the length of paddock side. He is not very good at math, please help him find this length.

Input
The first line of the input contains two integers 
 and 
 (
) - number of sheeps grazing in the field and the number of sheeps Jonathan wants to catch.

Each of the next 
 lines contain four integers 
, 
, 
, 
 (
, 
) - coordinates of bottom-left and top-right corners of the 
 sheep’s pasture.

Output
Print one integer — the minimum length of the side of the square paddock such that at least 
 pastures fit inside it completely.

Note
In the first example a square with side 
 covers 
 pastures completely, which is exactly what Jonathan needs. A square with side 
 covers only 
 of them.

Examples
Input 1
10 7
5 1 7 8
1 3 5 4
5 8 8 10
7 1 8 5
9 1 10 5
4 4 7 5
1 6 7 7
5 7 9 10
4 8 5 9
4 2 5 3
Output 1
9
Input 2
10 2
7 4 8 9
7 7 8 8
4 3 6 7
4 1 8 6
4 2 10 5
1 3 2 10
6 8 7 9
7 5 8 6
4 4 8 5
4 1 5 2
Output 2
7
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> requiredSizes(n);
    
    for (int i = 0; i < n; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        requiredSizes[i] = max(x2, y2); 
    }

    sort(requiredSizes.begin(), requiredSizes.end());

    cout << requiredSizes[k - 1] << '\n';

    return 0;
}