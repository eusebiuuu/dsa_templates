int const M = 998244353, N = 1e6 + 6;
int fact[N], invFact[N];

int mul(int a, int b) {
    if (a < 0) a += M;
    if (b < 0) b += M;    
    return 1LL * a * b % M;
}

int add(int a, int b) {
    if (a < 0) a += M;
    if (b < 0) b += M;
    return (a + b) % M;
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
    return fastPow(num, M - 2);
}

int nCr(int n, int r) {
    if (n < 0 or n < r or r < 0) {
        return 0;
    }
   return mul(fact[n], mul(invFact[r], invFact[n - r]));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = mul(fact[i - 1], i);
        invFact[i] = inv(fact[i]);
    }
    return 0;
}
