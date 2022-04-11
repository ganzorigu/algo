// 380. Insert Delete GetRandom O(1)
// Implement the RandomizedSet class:

// Follow up: Could you implement the functions of the class with each function
// works in average O(1) time?

// used hash map
// in order change the index of iterator.
// location = rand() % hashmap.size();
// advance(it, location) is used
// it->first;

#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet
{
	unordered_map<int, int> umap;

  public:
	/** Initialize your data structure here. */
	RandomizedSet()
	{
	}

	/** Inserts a value to the set. Returns true if the set did not already
	 * contain the specified element. */
	bool insert(int val)
	{
		if (umap.find(val) == umap.end())
		{
			umap[val] = 1;
			return true;
		}
		return false;
	}

	/** Removes a value from the set. Returns true if the set contained the
	 * specified element. */
	bool remove(int val)
	{
		if (umap.find(val) != umap.end())
		{
			umap.erase(val);
			return true;
		}
		return false;
	}

	/** Get a random element from the set. */
	int getRandom()
	{
		int size = umap.size();
		if (size == 0)
		{
			return 0;
		}
		int location = rand() % size;
		unordered_map<int, int>::iterator it = umap.begin();
		advance(it, location);
		return it->first;
	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
