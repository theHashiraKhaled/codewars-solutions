def decodeMorse(morse_code):
    # ToDo: Accept dots, dashes and spaces, return human-readable message
    morse_code = morse_code.replace('   ', '  ')
    morse_code = morse_code.split(' ')
    result = ""
    for x in morse_code:
        if x == "":
            result += " "
        else:
            result += MORSE_CODE[x]
    while result[0] == " ":
        result = result[1:]
    while result[len(result)-1] == " ":
        result = result[:len(result)-1]
    return result
