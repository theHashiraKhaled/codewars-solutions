def differentiate(equation, point):
    # Create coefficent 1
    eq = equation
    added = 0
    for i in range(len(equation)):
        if equation[i] == "x":
            if i-1 < 0:
                eq = eq[:i] + "1" + eq[i:]
                added += 1
            elif equation[i-1] == "+" or equation[i-1] == "-":
                eq = eq[:i+added] + "1" + eq[i+added:]
                added += 1
    print(eq)
    # Isolate every (coefficient, power)
    eq_map = list()
    while eq:
        if "x" in eq:
            coeff = int(eq[:eq.index("x")]) # The first numbers must be the coeff, so we take them away
            eq = eq[eq.index("x"):] # We remove this from the equation
            eq = eq.replace("x", "", 1) # Thereafter, there must be a x, otherwise np
            if eq:
                pass
            else:
                power = 1
                eq_map.append([coeff, power])
                break
            if eq[0] == "^": # Thereafter, there must be a ^X
                eq = eq.replace("^", "", 1)
                try:
                    if "-" in eq:
                        if "+" in eq:
                            if eq.index("+") < eq.index("-"):
                                power = int(eq[:eq.index("+")])
                                eq = eq[eq.index("+") + 1:]
                            else:
                                power = int(eq[:eq.index("-")])
                                eq = eq[eq.index("-"):]
                        else:
                            power = int(eq[:eq.index("-")])
                            eq = eq[eq.index("-"):]
                    else:
                        power = int(eq[:eq.index("+")])
                        eq = eq[eq.index("+") + 1:]
                except:
                    power = int(eq)
                    eq = ""
            else: # It means that there isn't exponent ==> 
                power = 1
        else:
            coeff = int(eq.replace("+", ""))
            eq = False
            power = 0

        eq_map.append([coeff, power])

    # Apply the derivative
    result = 0
    for couple in eq_map:
        if couple[1] == 0:
            break
        else:
            result += (couple[0]*couple[1])*(point**(couple[1]-1))
    
    return result
