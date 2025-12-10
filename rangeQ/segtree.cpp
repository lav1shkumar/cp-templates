// If operations = range update/ min / max / xor → Segment Tree

class SegmentTree {
    // 1. CONFIGURATION SECTION

    // Query Identity: The neutral value that doesn't affect the result
    // (e.g., 0 for Sum, INT_MAX for Min).
    long long ID_VAL = 0;

    // Update Identity: The value indicating "no pending update" (e.g., 0
    // for Add, -1 for Set, 0 for XOR).
    long long ID_LAZY = 0;

    // How do we merge two child nodes? (e.g., Sum, Max, Min)
    long long merge(long long leftVal, long long rightVal) {
        return leftVal + rightVal;
    }

    // How does a lazy tag change a node's value?
    // 'len' is the size of the range covered by this node
    void applyTag(int node, long long tagVal, int len) {
        tree[node] += tagVal * len; // For Range Sum with Range Add
        lazy[node] += tagVal;       // Stack the lazy tag

        // Example for Range Set + Range Min:
        // tree[node] = tagVal;
        // lazy[node] = tagVal;
    }

    // 2. INTERNAL LOGIC (Rarely needs changing)

    int n;
    vector<long long> tree;
    vector<long long> lazy;

    void push(int node, int start, int end) {
        if (lazy[node] == ID_LAZY)
            return;

        int mid = (start + end) / 2;
        int leftNode = 2 * node;
        int rightNode = 2 * node + 1;

        // Apply the tag to children
        applyTag(leftNode, lazy[node], mid - start + 1);
        applyTag(rightNode, lazy[node], end - mid);

        // Clear tag from current node
        lazy[node] = ID_LAZY;
    }

    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
            return;
        }
        int mid = (start + end) / 2;
        build(data, 2 * node, start, mid);
        build(data, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (l > end || r < start)
            return;
        if (l <= start && end <= r) {
            applyTag(node, val, end - start + 1);
            return;
        }
        push(node, start, end); // Push old tags down before going deeper
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    long long query(int node, int start, int end, int l, int r) {
        if (l > end || r < start)
            return ID_VAL;
        if (l <= start && end <= r)
            return tree[node];
        push(node, start,
                end); // Push tags down to ensure children are correct
        int mid = (start + end) / 2;
        return merge(query(2 * node, start, mid, l, r),
                        query(2 * node + 1, mid + 1, end, l, r));
    }

public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, ID_LAZY);
        // build(data, 1, 0, n - 1);
    }

    // Range Update: Add 'val' to [l, r]
    void rangeUpdate(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    // Range Query: Get answer for [l, r]
    long long rangeQuery(int l, int r) { return query(1, 0, n - 1, l, r); }
};