def last_digit(n1, n2):
    if n2 == 0:
        return 1
        
    if n1%10 == 0:
        return 0
        
    if n1%10 == 1:
        return  1
    
    if n1%10 == 2:
        cycle = [2, 4, 8, 6]
        return cycle[n2%4 -1]
        
    if n1%10 == 3:
        cycle = [3, 9, 7, 1]
        return cycle[n2%4 -1]
    
    if n1%10 == 4:
        cycle = [4, 6]
        return cycle[n2%2 -1]
        
    if n1%10 == 5:
        return 5
        
    if n1%10 == 6:
        return 6
    
    if n1%10 == 7:
        cycle = [7, 9, 3, 1]
        return cycle[n2%4 -1]
    
    if n1%10 == 8:
        cycle = [8, 4, 2, 6]
        return cycle[n2%4 -1]
    
    if n1%10 == 9:
        cycle = [1, 9]
        return cycle[n2%2]
