/*
You are in a casino and the croupier offers you a game. There is a deck of 
 cards numbered from 
 to 
, and the croupier shows you a trick:

take the top card and put it at the bottom of the deck;

take the new top card — it turns out to be the card numbered 
 — and put it aside;

take the top two cards and move them to the bottom of the deck, one by one;

take the new top card — it turns out to be the card numbered 
 — and put it aside;

…

repeat until no cards are left.

In other words, at step 
 the croupier moves 
 cards from the top to the bottom one by one and then puts the new top card aside, and that card must be the card numbered 
.

Note that at step 
 the deck may contain fewer than 
 cards. In that case some cards are moved to the bottom several times, see the notes.

You are asked to repeat the trick. Find an initial arrangement of the deck that makes it work.

Input
The first line of the input contains the number of test cases 
 (
). Each of the next 
 lines contains a single integer 
 (
) — the size of the deck for that test case.

Output
For each test case print 
 space-separated integers on a separate line — the order of the deck from the top card to the bottom one.

It can be shown that such an arrangement always exists, so you never have to report that the trick is impossible.

Note
In the first test case of the example the deck 
 is processed as follows:

the initial deck is 
;

move one card to the bottom: 
;

put the card 
 aside: 
;

move two cards to the bottom, one by one: 
;

put the card 
 aside: 
;

move three cards to the bottom, one by one: 
;

put the card 
 aside: 
;

move four cards to the bottom — the only remaining card just returns to its place — and put the card 
 aside: the deck is empty.

Examples
Input 1
2
4
5
Output 1
2 1 4 3 
3 1 4 5 2 
Input 2
3
5
6
6
Output 2
3 1 4 5 2 
4 1 6 3 2 5 
4 1 6 3 2 5 
*/

