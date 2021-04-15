def snail(array):
    result = []
    while array:
        if len(array[0]) == 2:
            result.extend(array[0])
            array[-1].reverse()
            result.extend(array[-1])
            del array[0], array[-1]
        
        elif len(array) == 1:
            result.extend(array[0])
            del array[0]
        else:
            n = len(array[0])
            result.extend(array[0])
            for i in range(n-2):
                result.append(array[1+i][-1])
                del array[1+i][-1]
            array[-1].reverse()
            result.extend(array[-1])
            for i in range(n-2):
                result.append(array[n-2-i][0])
                del array[n-2-i][0]
            del array[0], array[-1]
    return result
