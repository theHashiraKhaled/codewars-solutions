def parse(data):
    # TODO: your code here
    result = list()
    value = 0
    for char in data:
        if char == "i":
            value += 1
        elif char == "d":
            value -= 1
        elif char == "s":
            value **= 2
        elif char == "o":
            result.append(value)
    return result
