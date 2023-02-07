***Bulls and Cows*** is a decoding game played between two (or more) players, which (originally) was played with 4 digits. The two players write down two 4-digit numbers, and they must ***must*** be different. The players then take turns trying to decode their opponent's numbers, each time "figuring out"
4-digit number. If the matching digits are in the same positions, they are bulls, and if they are in different positions, they are cows, with the opponent reporting the quantities of bulls and cows corresponding to their opponent's number. For example:
```
- Player 1's secret number: 8405
- Player 2's guess: 1203
- Player 1's answer: 1 Bull and 0 Cows (i.e. 0 is in the same position as the secret number and the other digits are not contained in it);
```
Or
```
- Player 1's secret number: 9502
- Player 2's number: 9320
- Player 1's answer: 1 Bull, 2 cows (i.e. 9 is in the same position as the secret number, and 2 and 0 are contained in it, but in the wrong positions);
```
That is, play continues until one player reaches 4 Bulls and 0 Cows.  
  
Let's write a simulation of the game, with the following modification for simplicity - initially a 4-digit number is set. The user then makes successive attempts to "decode" the number in the above-described manner - after each attempt, the amount of Bulls and Cows are printed on the screen and the game continues until the number is decoded.
