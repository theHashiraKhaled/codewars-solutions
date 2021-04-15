def sum_of_intervals(intervals):
    result = [list(cp) for cp in intervals]
    for _i in range(len(result)):
        for cp_1 in result:
            for cp_2 in result:
                if cp_1[0] == cp_2[0] and cp_1[1] == cp_2[1]:
                    pass

                elif cp_2[0] <= cp_1[0] and cp_1[1] <= cp_2[1]:
                    print(cp_1)
                    result.remove(cp_1)
                    break

                elif cp_1[0] <= cp_2[0] <= cp_1[1] and cp_1[1] <= cp_2[1]:
                    cp_1[1] = cp_2[1]
                    result.append(cp_1)
                    result.remove(cp_2)
    
                elif cp_2[0] <= cp_1[0] and cp_1[0] <= cp_2[1] <= cp_1[1]:
                    cp_1[0] = cp_2[0]
                    result.append(cp_1)
                    result.remove(cp_2)
    
                elif cp_1[0] <= cp_2[0] and cp_2[0] <= cp_1[0]:
                    result.remove(cp_2)

    final = list()
    for x in result:
        if x not in final:
            final.append(x)
    count = 0
    for cp in final:
        count += cp[1]-cp[0]
    return count
