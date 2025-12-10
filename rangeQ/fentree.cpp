// If operations = sum / point updates → Fenwick



struct Fenwick {
    int n;
    vector<long long> bit1, bit2;

    Fenwick(int n): n(n), bit1(n + 1), bit2(n + 1) {}

    void update(vector<long long>& bit, int i, long long val) {
        for (++i; i <= n; i += i & -i)
            bit[i] += val;
    }

    long long query(vector<long long>& bit, int i) {
        long long sum = 0;
        for (++i; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }

    void rangeAdd(int l, int r, long long val) {
        update(bit1, l, val);
        update(bit1, r + 1, -val);
        update(bit2, l, val * (l));
        update(bit2, r + 1, -val * (r + 1));
    }

    long long prefixSum(int i) {
        return query(bit1, i) * (i + 1) - query(bit2, i);
    }

    long long rangeSum(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }
};
