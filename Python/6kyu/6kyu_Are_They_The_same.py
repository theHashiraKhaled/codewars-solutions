def comp(array1, array2):
    # your code
    import math
    if array1 == None or array2 == None:
        return False
    else:
        array1 = [x*x for x in array1]
        array1.sort()
        array2.sort()
        
    if array1 == [] or array2 == []:
        return True
        
    if array1 == array2:
        return True
    else:
        return False
