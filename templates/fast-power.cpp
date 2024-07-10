int const mod = 998244353, N = 1e6 + 6;
int fact[N];

int mul(int a, int b) {
    if (a < 0) a += mod;
    if (b < 0) b += mod;
    return 1LL * a * b % mod;
}

int add(int a, int b) {
    if (a < 0) a += mod;
    if (b < 0) b += mod;
    return (a + b) % mod;
}

int fastPow(int base, int exp) {
    int ans = 1;
    while (exp > 0) {
        if (exp & 1) {
            ans = mul(ans, base);
        }
        base = mul(base, base);
        exp >>= 1;
    }
    return ans;
}

int inv(int num) {
    return fastPow(num, mod - 2);
}

int nCr(int n, int r) {
   return mul(fact[n], mul(inv(fact[r]), inv(fact[n - r])));
}


