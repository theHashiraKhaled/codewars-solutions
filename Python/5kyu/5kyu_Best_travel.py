def choose_best_sum(t, k, ls):
    import itertools
    try:
        return max(sum(item) for item in itertools.combinations(ls, k) if sum(item)<=t)
    except:
        return None
