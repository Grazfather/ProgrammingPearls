# Column 1 (sort phone numbers)

## Problems

1. See _sort.c_
2. See _bitvecs.c_
3. See _bitvecs.c_
4. 
5. 10'000'000 numbers takes up 1'250'000 bytes, over a megabyte (8 numbers per byte). We can solve this by running in two passes, each focusing on a subset of the numbers available. That will easily allow us to fit within our memory constraint. Another possible solution is to look into the problem domain: These are phone numbers, and phone numbers can't start with 0 or a 1. Just by starting at 2'000'000 we eliminate enough numbers to fit into exactly 1'000'000 bytes, which is less than a megabyte.
6. This would make the problem more complicated. Instead of a single bit for each number, we would need enough bits to story the quantity. If this max was 10, then we would need log_2(10) = 4 bits per number, quadrupling our memory usage. We could mitigate this by making four passes.
7.  
  * We could detect if a number appeared more than once by adding a check in `setbit` that would check the value of the bit before setting it, and call the error function if it had.
  * Numbers out of range would probably cause segmentation faults, as there are no bounds checking.
  * The program would crash if the input is non numeric in `scanf`.
  * If any of these cases were to happen, the program should fail _safely_ and tell the user that the input is not acceptable.
8. While you could just increase the number of digits to 10 to incorporate the area codes, it would be simpler to just sort it separately for each of the three toll-free codes that are present.
9. 
10. Assuming that the number is a safe enough primary key, then a simple hash lookup should be fine. Each number is given its own 'slot', determined by a hash function (which could just return the number itself). Lookup is done by hashing the number and then looking to see if anything is in that slot. Because it is likely wasteful to use 10'000'000 slot per area code, we could shrink the backing store, with greater risk of collisions. This can be simply mitigated by doing something like putting all collisions in a list (requiring a traversal on lookup, through hopefully of a short list) or hashing again until there is no collision (which also makes traversal a bit slower and makes removing numbers a bit more difficult.
11. 
12. A well known urban legend. The Fisher Space Pen is used in space, and actually is better than a pencil because graphite shavings flying around can cause problems with electronics.
