from fractions import gcd
from functools import reduce

def solution(arr):
    return reduce(gcd, arr) * len(arr)
