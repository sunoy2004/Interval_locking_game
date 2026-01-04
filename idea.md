### Initial Concept
The initial idea was to combine interval covering with weighted penalties.
A naïve greedy approach (locking segments with maximum negative sum) seemed tempting.

### Rejected Variants
- Independent interval selection (fails due to overlaps).
- Greedy on segment sums (fails when overlapping intervals interact).
- DP over intervals (state explosion).

### Final Insight
Observe that locking an index is always beneficial **iff its value is positive**.
However, locking happens only via whole intervals.

Thus:
- We want to cover as many positive A[i] as possible
- Without being forced to cover large negative values

This transforms into:
**Choose intervals to lock, minimizing sum of uncovered positives minus forced negatives**

The dual formulation:
> Maximize total locked sum.

This becomes a weighted interval covering problem solved via:
- Line sweep
- Priority over interval endings
- Greedy with rollback using a multiset

### Algorithm Details
The optimal solution uses a greedy line sweep algorithm:
1. Process positions from left to right
2. Maintain a multiset of active intervals (intervals that start before or at current position and haven't ended)
3. For each position i, if there's an active interval covering it, consider "locking" this position
4. Use a greedy strategy with rollback: add A[i] to locked sum if the cumulative gain remains non-negative
5. The final answer is (total_array_sum - max_locked_sum)

This greedy approach works because we want to maximize the sum of locked elements, and we make locally optimal decisions at each position that contribute to the global optimum.