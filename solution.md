## Key Observation

Let `S = sum(A[i])`.

Locking a position removes its value from the score.
So minimizing final score ⇔ maximizing total locked value.

---

## Reformulation

We want to select any subset of intervals such that:

```
LockedSum = sum of A[i] for all i covered by ≥1 selected interval
```

is maximized.

Overlaps count only once.

---

## Algorithm

The optimal approach uses a greedy line sweep with a multiset to track active intervals:

1. Process positions from left to right
2. For each position `i`, add all intervals starting at `i` to an active set
3. Remove intervals from the active set that end before the current position
4. If there are active intervals covering position `i`, consider "locking" it
5. Maintain a greedy strategy: add A[i] to locked sum if the cumulative gain remains non-negative
6. If adding A[i] would make the cumulative gain negative, skip it (rollback)

This greedy approach works because we want to maximize the sum of locked elements, and we make locally optimal decisions that contribute to the global optimum.

The algorithm:
- Maintains a multiset of interval ending positions that are currently active
- For each position i, if there's an active interval covering it, considers including A[i] in the locked sum
- Uses a greedy strategy with rollback: only adds A[i] if the cumulative gain remains non-negative
- This ensures we lock positive values when beneficial while avoiding excessive negative impacts

---

## Complexity

- Time: **O((N+Q) log Q)**
- Space: **O(Q)**

---

## Correctness

The algorithm ensures:
- Every locked position contributes exactly once (due to overlap handling)
- The greedy selection maximizes the locked sum
- Intervals are implicitly chosen to achieve optimal locking
- The cumulative gain check prevents selecting intervals that would decrease the total locked value