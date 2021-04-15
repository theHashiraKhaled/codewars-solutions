def permutations(string):
    #your code here
    import itertools
    return ["".join(i) for i in list(set(itertools.permutations(string)))]
