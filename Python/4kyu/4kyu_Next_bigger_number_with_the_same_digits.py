# 1. Find largest index i such that str[i – 1] < str[i].
# 2. Find largest index j such that j >= i and str[j] > str[i – 1].
# 3. Swap str[j] and str[i – 1].
# 4. Reverse the sub-array starting at str[i].
def next_bigger(n):
    if sorted(str(n), reverse = True) == list(str(n)):
        return -1
    sequence = list(str(n))
    # Identify pivot
    pivot = max(i for i in range(1, len(sequence)) if sequence[i - 1] < sequence[i])
    # Find rightmost successor to pivot in the suffix
    successor = max(j for j in range(pivot, len(sequence)) if sequence[j] > sequence[pivot - 1])
    # Swap the pivot
    sequence[successor], sequence[pivot - 1] = sequence[pivot - 1], sequence[successor]
    # Reverse the suffix
    sequence[pivot:] = reversed(sequence[pivot:])
    return int(''.join(sequence))
