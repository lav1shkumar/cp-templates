vector<int> lvl, dp;
vector<bool> vis;
vector<int> arti_points;
vector<vector<int>> adj, bridges;

void dfstree(int node, int parent) {
    vis[node] = true;
    dp[node] = lvl[node];  
    int children = 0;     
    bool isArt = false; 

    for (int child : adj[node]) {
        if (child == parent) continue;

        if (vis[child]) {
            // back edge
            dp[node] = min(dp[node], lvl[child]);
        } else {
            lvl[child] = lvl[node] + 1;
            children++;
            dfstree(child, node);

            dp[node] = min(dp[node], dp[child]);

            //  bridge condition 
            if (dp[child] > lvl[node]) {
                bridges.push_back({node, child});
            }

            // articulation (non-root)
            if (parent != -1 && dp[child] >= lvl[node]) {
                isArt = true;
            }
        }
    }

    // articulation (root case)
    if (parent == -1 && children > 1) {
        isArt = true;
    }

    if (isArt) arti_points.push_back(node);
}

int main(){
  lvl.assign(n, 0);
  dp.assign(n, 0);
  vis.assign(n, false);
  adj.assign(n, {});
  bridges.clear();
  arti_points.clear();

  // handle disconnected graph
  for (int i = 0; i < n; i++) {
      if (!vis[i]) {
          dfstree(i, -1);
      }
  }
}
