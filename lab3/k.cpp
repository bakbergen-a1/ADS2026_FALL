/*
Write a program that, for several given values, prints their coordinates in a snake array of size 
.

A snake array is filled like this:

every column strictly decreases from top to bottom: 
;

every even row strictly decreases from left to right: 
 for 
;

every odd row strictly increases from left to right: 
 for 
.

Rows are numbered from 
 to 
 from top to bottom, columns from 
 to 
 from left to right.

Here is an example of 3
 Snake array

25 23 20 19

13 15 17 18

12 10 9 8

Input
The first line of input contains a single integer 
 — the number of values whose coordinates you must find (
).

The next line contains 
 integers — the values themselves (
 each value 
).

The next line contains two integers 
 and 
 — the number of rows and the number of columns (
).

Each of the next 
 lines contains 
 integers — the snake array itself (
, 
, 
). It is guaranteed that the array really is a snake array.

Output
Print 
 lines, one per requested value, in the order the values are given.

For a value that occurs in the array print two integers — the number of its row and the number of its column. Rows and columns are numbered from zero. If the value does not occur in the array, print 
 instead.

Note
In the third example, the elements -2 and 7 is do not exist. Therefore, you should print -1.

In the first example the value 
 stands in row 
 and column 
: rows and columns are numbered from zero, so the top-left corner is 
.

Scoring
Group 1 (
 points): small arrays.

Group 2 (
 points): larger arrays.

Group 3 (
 points): the smallest array 
 and the largest array 
.

Examples
Input 1
5
10 15 13 8 23
3 4
25 23 20 19
13 15 17 18
12 10 9 8
Output 1
2 1
1 1
1 0
2 3
0 1
Input 2
8
1 7 17 12 6 15 18 20
5 5
25 24 23 22 21
16 17 18 19 20
15 14 13 12 11
6 7 8 9 10
5 4 3 2 1
Output 2
4 4
3 1
1 1
2 3
3 0
2 0
1 2
1 4
Input 3
4
-2 7 8 4
2 3
9 8 5
-1 3 4
Output 3
-1
-1
0 1
1 2
*/
#include <iostream>
#include <vector>
using namespace std;

int searchRow(const vector<long long>& row, long long target, bool isIncreasing) {
    int left = 0, right = row.size() - 1;

    while (left <= right) {
        int mid = (right + left) / 2; 

        if (row[mid] == target) return mid; 

        if (isIncreasing) {
            if (row[mid] < target) left = mid + 1;
            else right = mid - 1;
        } else {
            if (row[mid] > target) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int q, n, m;
    cin >> q;

    vector<long long> queries(q);
    for (int i = 0; i < q; i++) cin >> queries[i];

    cin >> n >> m;
    vector<vector<long long>> matrix(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> matrix[i][j];
    }

    for (long long target : queries) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            bool isIncreasing = (i % 2 == 1); 

            int col = searchRow(matrix[i], target, isIncreasing);

            if (col != -1) {
                cout << i << " " << col << '\n';
                found = true;
                break; 
            }
        }

        if (!found) cout << -1 << '\n';
    }

    return 0;
}