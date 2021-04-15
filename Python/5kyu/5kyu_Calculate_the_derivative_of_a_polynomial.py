import re
splitter = re.compile("([+-])")

def parse(eq):
    term = list()
    sign, exp = 1, 1
    
    for i in splitter.split(eq):
        if not(i):
            continue
        if i == "+":
            sign = 1
        elif i == "-":
            sign = -1
        else:
            coeff, switch, power = i.partition("^")
            val = "".join(d for d in coeff if d.isdigit())
            if switch:
                exp = int(power)
            else:
                exp = 1
            if not("x" in coeff):
                exp = 0
            if val:
                val = int(val)
            else:
                val = 1
            val *= sign
            term.append((val, exp))
    return term

def diff(poly):
    term = list()
    for val, exp in poly:
        if exp == 0:
            continue
        term.append((val*exp, exp - 1))
    return term
    
def derivative(eq):
    if "x" not in eq:
        return "0"
    # Parse the polynomial and diffrentiate each term
    res = ""
    der = diff(parse(eq))
    for coeff, power in der:
        if res:
            if coeff > 0:
                if not(power):
                    res += "+{}".format(coeff)
                elif power == 1:
                    res += "+{}x".format(coeff)
                else:
                    res += "+{}x^{}".format(coeff, power)
            else:
                if not(power):
                    res += "{}".format(coeff)
                elif power == 1:
                    res += "{}x".format(coeff)
                else:
                    res += "{}x^{}".format(coeff, power)
        else:
            if not(power):
                res += "{}".format(coeff)
            elif power == 1:
                res += "{}x".format(coeff)
            else:
                res += "{}x^{}".format(coeff, power)
    return res
