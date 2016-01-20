# Column 2 (binary search)

## Problems

a. See _bsmissing.c_.

b. See _rotatevec.c_.

c. See _findanagrams.py_. For each word in the dictionary we reduce it to a _canonical form_. Our form is simply the word sorted alphabetically. We could then sort the list of sorted words, and all sets of anagrams will be next to each other. We can maintain a mapping from the sorted word to the original to print out each in turn. Instead, though, we create a dictionary of <string>:<set<string>> pairs: Every time a signature shows up, I add the original value to a set keyed by the signature. To print out all the anagrams I simple iterate the dictonary, printing the set of words in any case where the cardinality is greater than one.

1. Given the word and the dictionary, we would need to compute the worlds signature (sort the word alphabetically in our case), and then iterate the entire dictionary, computing the signature for each word and then determining whether the word signature matches our word. If we have the opportunity to process the dictionary, then we can compute the signature of each word, and then sort the signatures. This would allow us to do a binary search on the result to find the matches in log(N) time where N is the size of the dictionary.
