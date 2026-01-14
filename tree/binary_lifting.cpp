const int N = 200000 + 5;     // max nodes
const int LOG = 20;           // ~ log2(N)

vector<int> adj[N];
int depth[N];
int up[N][LOG];

// ---------------- DFS BUILD ----------------
void dfs(int v, int p) {
    up[v][0] = p;
    for(int i = 1; i < LOG; i++)
        up[v][i] = up[ up[v][i-1] ][i-1];

    for(int u : adj[v]) {
        if(u == p) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
}

void build(int root) {
    depth[root] = 0;
    dfs(root, root);
}

int lca(int a, int b) {
    if(depth[a] < depth[b])
        swap(a, b);

    // 1. Lift a to same depth as b
    int diff = depth[a] - depth[b];
    for(int i = 0; i < LOG; i++)
        if(diff & (1 << i))
            a = up[a][i];

    if(a == b)
        return a;

    // 2. Lift both until their parents differ
    for(int i = LOG - 1; i >= 0; i--) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    // 3. Parent is LCA
    return up[a][0];
}

int dist(int u, int v) {
    int w = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
}

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     for(int i = 1; i < n; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     // preprocess from node 1 (or any root)
//     build(1);

//     int q;
//     cin >> q;
//     while(q--) {
//         int u, v;
//         cin >> u >> v;
//         cout << "LCA = " << lca(u, v) << ", ";
//         cout << "Dist = " << dist(u, v) << "\n";
//     }
// }
