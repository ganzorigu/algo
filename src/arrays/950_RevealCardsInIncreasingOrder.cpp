// 950. Reveal Cards In Increasing Order

// In a deck of cards, every card has a unique integer.  You can order the deck
// in any order you want.

// Initially, all the cards start face down (unrevealed) in one deck.

// Now, you do the following steps repeatedly, until all cards are revealed:

//     Take the top card of the deck, reveal it, and take it out of the deck.
//     If there are still cards in the deck, put the next top card of the deck
//     at the bottom of the deck. If there are still unrevealed cards, go back
//     to step 1.  Otherwise, stop.

// Return an ordering of the deck that would reveal the cards in increasing
// order.

// The first entry in the answer is considered to be the top of the deck.

// Solution: sort the array.
// do reverse operation above.
// vector.back() -> last element of vector
// vector.insert(it, val);

#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
	vector<int> deckRevealedIncreasing(vector<int> &deck)
	{

		// first sort the decks in increasing order
		sort(deck.begin(), deck.end());

		// reorder them in way, that it is revealed in increasing order.
		// create the result vector

		vector<int> response;
		std::vector<int>::iterator it;
		it = response.begin();
		response.insert(it, deck[deck.size() - 1]);
		for (int i = deck.size() - 2; i >= 0; i--)
		{
			it = response.begin();
			response.insert(it, response.back());
			response.pop_back();
			it = response.begin();
			response.insert(it, deck[i]);
		}
		return response;
	}
};
