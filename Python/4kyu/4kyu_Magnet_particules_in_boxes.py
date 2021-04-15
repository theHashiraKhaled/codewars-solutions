def doubles(maxk, maxn):
    return sum(1/k*(1/(n+1))**(2*k) for k in range(1,maxk+1) for n in range(1,maxn+1))
