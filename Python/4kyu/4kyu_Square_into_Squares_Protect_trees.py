def decompose(n):
    # your code
    result = [n]
    count = 0
    while result:
        n = result.pop()
        count += n**2
        for t in reversed(range(1, n)):
            if count - t**2 >= 0:
                count -= t**2
                result.append(t)
                if count == 0:
                    result.sort()
                    return result
    return None
