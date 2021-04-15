def move_zeros(array):
    #your code here
    l = []
    counter = 0
    for x in array:
        if x == 0 and x is not False:
            counter += 1
        else:
            l.append(x)
    for i in range(counter):
        l.append(0)
    return l
