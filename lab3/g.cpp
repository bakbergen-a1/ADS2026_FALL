/*
Aisha is preparing decorations for the university open day. She has 
 ropes; the 
-th of them is 
 centimetres long.

For the decoration she needs exactly 
 pieces of rope, and all of them must be of the same length. A piece is always cut out of a single rope — ropes may not be tied together. Whatever is left over after cutting is simply thrown away, and it is fine to leave a whole rope untouched.

Aisha wants the pieces to be as long as possible. Find that length.

Note that the answer does not have to be an integer number of centimetres: the rope may be cut at any point.

Input
The first line contains two integers 
 and 
 — the number of ropes and the number of pieces Aisha needs (
, 
).

The second line contains 
 integers 
 — the lengths of the ropes in centimetres (
).

Output
Print one real number — the greatest length such that 
 pieces of that length can be cut out of the ropes.

Your answer is accepted if its absolute or relative error does not exceed 
.

Print the answer with at least 
 digits after the decimal point (printf("%.9f", ans) in C++, print(f"{ans:.9f}") in Python): the default output of cout « ans keeps only 
 significant digits and is not enough.

Note
In the first example the ropes are 
, 
, 
 and 
 centimetres long and 
 pieces are needed. With length 
 they give 
 pieces, which is exactly enough. Any greater length yields fewer than 
 pieces.

In the second example three ropes of length 
 give exactly three pieces of length 
.

In the third example four pieces are needed. A length of 
 would give only three pieces, so the ropes have to be cut in half: at length 
 each rope yields two pieces, six in total, and no greater length works.

Scoring
Group 1 (
 points): 
.

Group 2 (
 points): no additional constraints.

Examples
Input 1
4 11
802 743 457 539
Output 1
200.500000000
Input 2
3 3
5 5 5
Output 2
5.000000000
Input 3
3 4
5 5 5
Output 3
2.500000000
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<double> ropes(n);
    double right = 0;
    for (double& x : ropes) {
        cin >> x;
        if (x > right) right = x;
    }
    double left = 0;
    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        long long pieces = 0;
        for (double x : ropes) pieces += (long long)(x / mid);
        if (pieces >= k) left = mid;
        else right = mid;
    }
    cout << fixed << setprecision(9) << left << '\n';
}