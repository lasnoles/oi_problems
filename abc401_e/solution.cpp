#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }
    
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (u < v) {
           parent[v] = u;
           size[u] += size[v];
        } else {
           parent[u] = v;
           size[v] += size[u];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    DSU dsu(n);
    vector<int> occ(n + 1);
    int nonZeros = 0;
    
    for (int u = 1; u <= n; ++u) {
        // Remove u from tracked deletions (if it was previously counted)
        if (occ[u] > 0) nonZeros--;
        occ[u] = 0;
        
        // Process all edges of u
        for (int v : adj[u]) {
            if (v > u) {
                // Track nodes >u connected to current component
                if (occ[v]++ == 0) nonZeros++;
            } else {
                // Merge with smaller nodes
                dsu.unite(u, v);
            }
        }
        
        // Check if component of 1 includes exactly u nodes
        int root = dsu.find(1);
        if (dsu.size[root] == u) {
            cout << nonZeros << '\n';
        } else {
            cout << "-1\n";
        }
    }
}