def decodeBits(bits):
    # ToDo: Accept 0's and 1's, return dots, dashes and spaces
    import re
    bits = bits.strip("0")
    print(bits)
    
    try:
        first_char_len = bits.index("0")
        print(first_char_len)
        if first_char_len == 3:
            first_pause_len = bits.index("1", bits.index("0")) - bits.index("0")
            
            if re.search("1010", bits):
                unit = 1
            elif first_pause_len % 3 == 0 or re.search("111000111", bits):
                unit = 3
            elif first_pause_len % 3 == 0 and first_pause_len % 2 != 0:
                unit = first_char_len / 3
            else:
                unit = 1
                
        elif first_char_len % 3 == 0 and first_char_len % 2 != 0:
            unit = first_char_len / 3 
        elif first_char_len % 3 == 0:
            unit = bits.index("1", bits.index("0")) - bits.index("0")
        else:
            unit = first_char_len
        print(unit)
        table = {'1' * 3 * unit: '-',
                   '1' * unit: '.',
                   '0' * unit * 7: '   ',
                   '0' * unit * 3: ' ',
                   '0' * unit: ''}
        pattern = '1'*3*unit+'|'+'1'*unit+'|'+'0'*unit*7+'|'+'0'*unit*3+'|'+'0'*unit
        return "".join(table[x] for x in re.findall(pattern, bits))
        
    except ValueError:
        first_char_len = len(bits)
        if first_char_len == 3:
            unit = first_char_len
        elif first_char_len % 3 == 0 and first_char_len % 2 != 0:
            unit = first_char_len / 3    
        else:
            unit = first_char_len
        table = {'1' * 3 * unit: '-',
                   '1' * unit: '.',
                   '0' * unit * 7: '   ',
                   '0' * unit * 3: ' ',
                   '0' * unit: ''}
        pattern = '1'*3*unit+'|'+'1'*unit+'|'+'0'*unit*7+'|'+'0'*unit*3+'|'+'0'*unit
        return "".join(table[x] for x in re.findall(pattern, bits))

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
