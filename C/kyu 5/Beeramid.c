// https://www.codewars.com/kata/51e04f6b544cf3f6550000c1

int beeramid(double bonus, double price) {
    double k = 6 * bonus / price;
    int n = 0;
    while (n * (n + 1) * (2 * n + 1) <= k)
        n++;
    // checking
    return n == 0 ? 0 : n - 1;
}
