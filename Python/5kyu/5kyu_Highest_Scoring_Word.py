def high(x):
    # Code here
    SENTENCE = list(x.split())
    ALPHABET = list("a b c d e f g h i j k l m n o p q r s t u v w x y z".split())
    score = list()
    for word in SENTENCE:
        temp = 0
        for letter in word:
            temp += ALPHABET.index(letter) + 1
        score.append(temp)
    
    return SENTENCE[score.index(max(score))]
