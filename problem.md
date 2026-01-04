# Interval Locking Game

You are given an array `A` of length `N` and `Q` operations.

Each operation gives you a segment `[L, R]` (1-indexed).  
When you apply an operation, **all indices in `[L, R]` become locked**.

You may apply operations in **any order**, but **once an index is locked, it cannot be unlocked**.

After applying some subset of operations, define the score as:

```
Score = sum of A[i] over all unlocked positions i
```

Your task is to **minimize the final score**.

---

## Input

```
N Q
A1 A2 ... AN
L1 R1
L2 R2
...
LQ RQ
```

---

## Output

```
Minimum possible score
```

---

## Constraints

- 1 ≤ N ≤ 2×10⁵
- 1 ≤ Q ≤ 2×10⁵
- −10⁹ ≤ Ai ≤ 10⁹
- 1 ≤ Li ≤ Ri ≤ N

---

## Notes

- You may choose **any subset** of the operations.
- Operations may overlap.
- Locking an index removes its value from the score.