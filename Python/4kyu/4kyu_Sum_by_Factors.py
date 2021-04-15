def sum_for_list(lst):
    prime_lst = list()
    for n in lst:
        for p in primes(n):
            if p not in prime_lst:
                prime_lst.append(p)
    prime_lst.sort()
    print(prime_lst)
    result = list()
    for p in prime_lst:
        temp = [p]
        count = 0
        for n in lst:
            if n % p == 0:
                count += n
        temp.append(count)        
        result.append(temp)
    return result

def primes(n):
    divisors = [ d for d in range(2,abs(n)//2 + 1) if abs(n) % d == 0 ]
    temp = [ d for d in divisors if \
             all( d % od != 0 for od in divisors if od != d ) ]
    if len(temp) > 0:
        return temp
    else:
        return [abs(n)]
