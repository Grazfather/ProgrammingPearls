import collections

sigdict = collections.defaultdict(set)

with open("/usr/share/dict/words", "r") as f:
    for word in f:
        sigdict["".join(sorted(word))].add(word)

for value in sigdict.values():
    if len(value) > 1:
        print(value)
