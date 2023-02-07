## Linear Search vs Binary Search

 ![enter image description here](https://i.imgur.com/Z38eSAZ.gif)

## Erathostenes Sieve
The Erathostenes Sieve is an algorithm for generating all prime numbers that are less than a predefined ***N***. It works as follows:
1. Generate all natural numbers n greater than 1 and less than ***N*** by ordering them (in the same sequence in a list/array), i.e. ``α = {2,3,4,...,N-1}```;
2. Let p be the smallest prime number in the list (i.e. at the 0th iteration p = 2);
3. We iterate over 2p,3p,4p,...,r*p (where r is the largest prime, i.e. r*p < ***N***) and color each of these numbers;
4. We find the smallest ***uncolored*** number in the series ``α`` and go to 2. If none exists, we go to 5;
5. The algorithm finishes execution, and the simple numbers are those numbers from ``α`` that are left uncoloured (unmarked)

 ![enter image description here](https://upload.wikimedia.org/wikipedia/commons/b/b9/Sieve_of_Eratosthenes_animation.gif)
