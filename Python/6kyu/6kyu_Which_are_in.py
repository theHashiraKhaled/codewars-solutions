def in_array(array1, array2):
    # your code
    from collections import OrderedDict
    result = []
    for i in array1:
            for k in array2:
                if i in k:
                    result.append(i)
    return sorted(list(OrderedDict.fromkeys(result)))
