const long long MOD = 1e9 + 7;
// --------------------------------------------
// Fast Modular Inverse using Fermat's Theorem
// --------------------------------------------
long long modInverse(long long a, long long mod){
    long long res = 1;
    long long power = mod - 2;  // a^(mod-2) % mod

    while (power){
        if (power & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        power >>= 1;
    }

    return res;
}

// ----------------------------
// nCr using multiplicative DP
// ----------------------------
long long nCr(long long n, long long r){
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    // symmetry: C(n,r) = C(n,n-r)
    if (r > n - r) r = n - r;

    long long res = 1;

    for (long long i = 1; i <= r; i++){
        res = res * (n - r + i) % MOD;        // multiply numerator
        res = res * modInverse(i, MOD) % MOD; // divide by i using inverse
    }

    return res % MOD;
}


// if mod not required n ≤ 60
long long nCr(long long n, long long r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    if (r > n - r) r = n - r;  // symmetry C(n,r)=C(n,n-r)

    long long res = 1;

    for (long long i = 1; i <= r; i++) {
        res = res * (n - r + i);
        res = res / i;   // EXACT division (always divisible)
    }

    return res;
}


// When n is large (up to 1e6) --> Pascal DP
long long nCr(int n, int r) {
    long long C[r + 1] = {0};
    C[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--) {
            C[j] = C[j] + C[j - 1];
        }
    }

    return C[r];
}
