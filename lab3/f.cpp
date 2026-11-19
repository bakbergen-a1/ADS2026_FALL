/*
Robin Hood wants to steal the golden bars from the bank of High Sheriff aiming to distribute them to poor local people. There are 
 bags of golden bars, the 
-th bag has 
 bars. Sheriff has gone and will return in 
 hours.

Robin can steal 
 bars per hour. Each hour, he chooses a single bag of golden bars, and steals 
 bars from that bag. If there are less than 
 bars in the bag, he steals them all, and won’t steal any more during this hour.

Robin Hood wants to steal all of the golden bars before the Sheriff comes back.

Return the minimum number 
 such that Robin can steal ALL of the golden bars within 
 hours.

Input
The first line of the input contains two space-separated integers 
, the number of bags of golden bars and the number of hours for which Sheriff has gone. The next line contains 
 space-separated integers 
 denoting the number of golden bars in each bag.

Output
Print the minimum number 
 such that Robin Hood can steal all of the 
 golden bars within the limit of 
 hours.

Note
In the first example there are four bags with 
, 
, 
 and 
 bars and the Sheriff returns in 
 hours. With 
 Robin needs 
 hours — exactly enough. With 
 he would need 
 hours, which is too much, so 
 is the smallest suitable speed.

In the second example there are five bags and exactly five hours, so Robin gets one hour per bag and has to empty the largest bag in a single hour: the answer is 
.

In the third example he has one spare hour, which is enough to split the largest bag over two hours, and the answer drops to 
.

Examples
Input 1
4 8
3 6 7 11
Output 1
4
Input 2
5 5
30 11 23 4 20
Output 2
30
Input 3
5 6
30 11 23 4 20
Output 3
23
*/
#include <iostream>
#include <vector>
using namespace std;

bool canFinish(const vector<long long>& bags, long long h, long long k) {
    long long hours = 0;
    for (long long x : bags) {
        hours += (x + k - 1) / k;
        if (hours > h) return false;
    }
    return true;
}

int main() {
    int n;
    long long h;
    cin >> n >> h;
    vector<long long> bags(n);
    long long right = 0;
    for (long long& x : bags) {
        cin >> x;
        if (x > right) right = x;
    }
    long long left = 1;
    while (left < right) {
        long long mid = (left + right) / 2;
        if (canFinish(bags, h, mid)) right = mid;
        else left = mid + 1;
    }
    cout << left << '\n';
}