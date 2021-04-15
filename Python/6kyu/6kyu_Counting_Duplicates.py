def duplicate_count(text):
    # Your code goes here
    repetition = 0
    l = []
    while text:
        letter = text[0]
        text = text[1:]
        if letter.lower() in text.lower():
            if letter.lower() in l:
                pass
            else:
                repetition += 1
                l.append(letter.lower())
    return repetition
