def longest_consec(strarr, k):
    # your code
    if len(strarr) == 0 or k > len(strarr) or k <= 0:
        return ""
    return max(["".join(strarr[i:i+k]) for i in range(len(strarr))], key = len)
