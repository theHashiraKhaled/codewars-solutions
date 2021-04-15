typedef long long unsigned ull;

ull choose(ull n, ull k) 
{
    if (k > n) return 0;
    if (k == 0) return 1;
    if (k > n / 2) return choose(n, n- k);
    return n * choose(n - 1, k - 1) / k;
}
