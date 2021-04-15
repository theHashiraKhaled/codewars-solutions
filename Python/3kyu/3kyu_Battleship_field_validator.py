def validate_battlefield(field):
    
    # Check if there are additional/missing ships
    if sum(i.count(1) for i in field) != 20:
        return False
        
    ships = [0,0,0,0] # battleship, cruisers, destroyers, submarines

    for line in range(10):
        for col in range(10):
            if field[line][col] == 1:
                pos = [i for i in [[line-i, col-1] for i in (1,0,-1)] + [[line-i, col] for i in (1,0,-1)] + [[line-i, col+1] for i in (1,0,-1)] if 9 >= i[0] >= 0 and 9 >= i[1] >= 0 and (i[0], i[1]) != (line, col)]
                corner = [[line-1,col-1], [line-1,col+1], [line+1,col-1], [line+1, col+1]]
                for i in corner:
                    if i in pos:
                        if field[i[0]][i[1]] == 1:
                            return False
    for line in range(10):
        for col in range(10):
            if field[line][col] == 1:
                # Create a list of position to check
                pos = [i for i in [[line-i, col-1] for i in (1,0,-1)] + [[line-i, col] for i in (1,0,-1)] + [[line-i, col+1] for i in (1,0,-1)] if 9 >= i[0] >= 0 and 9 >= i[1] >= 0 and (i[0], i[1]) != (line, col)]
                # First, we check if two ships are colinding by edge
                if sum(field[cell[0]][cell[1]] for cell in pos) > 2:
                    return False
                # Now, we check if they are straight lined
                # and we count every type of ship
                count = int()
                for cell in pos:
                    if field[cell[0]][cell[1]] == 1:
                        a,b = cell[0]-line, cell[1]-col
                        field[line][col], last, length = 0, 1, 1
                        l,c = line, col
                        while last == 1:
                            l,c = l+a, c+b
                            if 9>=l>=0 and 9>=c>=0:
                                if field[l][c] == 1:
                                    length += 1
                                else:
                                    last = 0
                                field[l][c] = 0
                            else:
                                last = 0
                        if length > 4:
                            return False
                        if length == 4:
                            ships[0] += 1
                        elif length == 3:
                            ships[1] += 1
                        elif length == 2:
                            ships[2] += 1
                    else:
                        count += 1
                if count == len(pos):
                    ships[3] += 1
    if ships == [1,2,3,4]:
        return True
    return False
