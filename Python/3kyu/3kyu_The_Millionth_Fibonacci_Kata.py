fibs = {0: 0, 1: 1}
def fib(n):
    k = abs(n)
    if n in fibs:
        return fibs[n]
    if -n in fibs:
        return -fibs[k]
        
    if n % 2 == 0:
        fibs[k] = ((2 * fib((k / 2) - 1)) + fib(k / 2)) * fib(k / 2)
        if n<0:
            return -fibs[k]
        else:
            return fibs[n]
    else:
        fibs[k] = (fib((k - 1) / 2) ** 2) + (fib((k+1) / 2) ** 2)
    if n<0:
        return fibs[k]
    return fibs[n]

### An alternative

def fib_alt(n):
    if n == 0: return 0
    k = abs(n)
    v1, v2, v3 = 1, 1, 0    # initialise a matrix [[1,1],[1,0]]
    for rec in bin(k)[3:]:  # perform fast exponentiation of the matrix (quickly raise it to the nth power)
        calc = v2*v2
        v1, v2, v3 = v1*v1+calc, (v1+v3)*v2, calc+v3*v3
        if rec=='1':    v1, v2, v3 = v1+v2, v1, v2
    if abs(n) % 2 == 0 and n < 0:
        return -v2
    return v2
