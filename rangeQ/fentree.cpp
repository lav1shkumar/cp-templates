// If operations = sum / point updates → Fenwick



struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    // add 'val' to index i (0-indexed externally)
    void update(int i, long long val) {
        for (++i; i <= n; i += i & -i)
            bit[i] += val;
    }

    // prefix sum [0..i]
    long long prefixSum(int i) {
        long long sum = 0;
        for (++i; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }

    // range sum [l..r]
    long long rangeSum(int l, int r) {
        if (r < 0) return 0;
        return prefixSum(r) - (l ? prefixSum(l - 1) : 0);
    }
};
