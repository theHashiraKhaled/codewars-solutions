// Returns number of complete beeramid levels
int beeramid(double bonus, double price) {
    double k = 6 * bonus / price;
    int n = 0;
    while (n * (n + 1) * (2 * n + 1) <= k)
        n++;
    return n == 0 ? 0 : n - 1;
}
