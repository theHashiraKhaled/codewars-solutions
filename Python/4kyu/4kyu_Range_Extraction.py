def solution(args):
    # your code here
    result = []
    temp = []
    
    for i in range(len(args)):
        try:
            if args[i] + 1 == args[i+1]:
                temp.append(args[i])     
            else:
                try:
                    if args[i] - 1 == temp[-1]:
                        temp.append(args[i])
                except IndexError:
                    result.append(str(args[i])) 
                
                
                if len(temp) >= 3:
                    result.append(str(temp[0]) + "-" + str(temp[-1]))
                else:
                    for x in temp:
                        result.append(str(x))
                temp = []
        except IndexError:
            try:
                if args[i] - 1 == temp[-1]:
                    temp.append(args[i])
            except IndexError:
                result.append(str(args[i])) 
                
                
            if len(temp) >= 3:
                result.append(str(temp[0]) + "-" + str(temp[-1]))
            else:
                for x in temp:
                    result.append(str(x))
            temp = []
            
    return ",".join(result)
