/*
Boris and Nursik are playing the card game “drunkard”. All the cards are divided equally between the two players. On every move both players reveal the top card of their deck, and the one whose card is higher takes both revealed cards and puts them at the bottom of their own deck. The player who is left without cards loses.

The winner of a move first puts Boris’s card at the bottom of the deck and then Nursik’s card, so Nursik’s card ends up lowest.

The game is played with 
 cards with values from 
 to 
. A larger card beats a smaller one, with a single exception: the card 
 beats the card 
.

Write a program that simulates the game and determines the winner.

Input
The first line contains 
 integers separated by spaces — Boris’s cards. The second line contains Nursik’s 
 cards in the same format.

Every card value is an integer between 
 and 
, and all 
 values are distinct. The cards are listed from top to bottom, that is, each line starts with the card that will be revealed first.

Output
Print the word Boris or Nursik — the name of the winner — followed by the number of moves made before the win.

It can be shown that with 
 distinct cards the game always ends: no deal leads to an infinite loop.

Note
In the example Boris holds 
 and Nursik holds 
. Nursik wins the first four moves (
, 
, 
, 
), and on the fifth move Boris’s last card 
 loses to 
 by the special rule. Boris is left without cards, so Nursik wins after 
 moves.

Examples
Input 1
1 3 5 7 9
2 4 6 8 0
Output 1
Nursik 5
*/