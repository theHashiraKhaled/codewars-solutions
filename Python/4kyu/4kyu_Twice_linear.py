def dbl_linear(n):
    u = [1]
    for i in u:
        u.append(2 * i + 1)
        u.append(3 * i + 1)
        if len(u)>n*10:
            break
    return sorted(list(set(u)))[n]
