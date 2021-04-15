def isValidWalk(walk):
    #determine if walk is valid
    return len(walk) == 10 and walk.count("n") == walk.count("s") and walk.count("e") == walk.count("w")
