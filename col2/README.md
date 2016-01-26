# Column 2 (binary search)

## Problems

a. See _bsmissing.c_.

b. See _rotatevec.c_.

c. See _findanagrams.py_. For each word in the dictionary we reduce it to a _canonical form_. Our form is simply the word sorted alphabetically. We could then sort the list of sorted words, and all sets of anagrams will be next to each other. We can maintain a mapping from the sorted word to the original to print out each in turn. Instead, though, we create a dictionary of <string>:<set<string>> pairs: Every time a signature shows up, I add the original value to a set keyed by the signature. To print out all the anagrams I simple iterate the dictionary, printing the set of words in any case where the cardinality is greater than one.

1. Given the word and the dictionary, we would need to compute the worlds signature (sort the word alphabetically in our case), and then iterate the entire dictionary, computing the signature for each word and then determining whether the word signature matches our word. If we have the opportunity to process the dictionary, then we can compute the signature of each word, and then sort the signatures. This would allow us to do a binary search on the result to find the matches in log(N) time where N is the size of the dictionary.

2. See _bsextra.c_. This can be solved in nearly the same way and Problem a: Split the set of numbers across each bit, finding the imbalance. The difference is that instead of chasing the smaller set, we chase the larger set. The base case is also changed, as we never get beyond two matching numbers (the repeated number twice), but we know that at this point the other set should be empty.

3. See _slow_rotate.c_. The first solution, where we juggle elements unit-by-unit, works by juggling the units forward carefully. The _gcd_ comes into play because it determines the number of shuffle forwards must be done. For example, if both the size of the array and the amount we want to rotate by is prime, then we only need to shuffle forward once. This process will hit each index. On the other hand, if the greatest common divisor is more than one, than means that we will 'miss' some indices. We can mitigate this by re-running the shuffle _x_ times where x = gcd(rot, size).
