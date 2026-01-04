# Interval Locking Game

This repository contains an original competitive programming problem suitable for Codeforces Div1/Div2 level.

## Problem Summary

You are given an array A of length N and Q operations. Each operation gives you a segment [L, R] (1-indexed). When you apply an operation, all indices in [L, R] become locked. You may apply operations in any order, but once an index is locked, it cannot be unlocked.

After applying some subset of operations, define the score as: Score = sum of A[i] over all unlocked positions i

Your task is to minimize the final score.

## Solution Approach

The optimal solution uses a line sweep approach with a multiset to maintain active intervals, achieving O((N+Q)log Q) complexity.

## Test Cases

The test cases include:
- Basic cases with simple intervals
- Cases with overlapping intervals
- Edge cases with negative values
- Cases where no intervals should be selected
- Cases where all intervals should be selected
- Complex cases with multiple overlapping intervals
- Edge cases with single elements