#include<bits/stdc++.h>
using namespace std;

class BinaryLifter{
    vector<vector<int>> table;
    int n;
    int tableSize;

public:
    BinaryLifter(int tableSize, vector<int> initializer){
        if(tableSize < 1)
            throw invalid_argument("Invalid table size");

        table.resize(tableSize);
        table[0] = initializer;
        n = initializer.size();
        this->tableSize = tableSize;

        for(int i = 1; i < tableSize; i++){
            table[i].resize(n);
            for(int j = 0; j < n; j++)
                table[i][j] = table[i-1][table[i-1][j]];
        }
    }

    int getValue(int index, int k) {
        if (k >= 1<<tableSize || k < 0)
            throw invalid_argument("Invalid k: " + to_string(k));
        if(index < 0 || index >= n)
            throw invalid_argument("Invalid index" + to_string(index));
        
        int ans = index;
        for(int i = 0; i < tableSize; i++)
            if(k & (1<<i))
                ans = table[i][ans];
        return ans;
    }
};





class BinaryLiftingLCA {
    int n, LOG;
    vector<vector<pair<int, int>>> adj; 
    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> distFromRoot;

public:
    int getMaxDistance() {
        ll ans = 0;
        AREP(dist, distFromRoot)
            ans = max(ans, dist);
        return ans;
    }
    
    BinaryLiftingLCA(int nodes) {
        n = nodes;
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        adj.resize(n);
        up.assign(n, vector<int>(LOG, -1));
        depth.resize(n);
        distFromRoot.resize(n);
    }

    void addEdge(int u, int v, int w = 1) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    void build(int root = 0) {
        dfs(root, -1, 0, 0);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        u = lift(u, depth[u] - depth[v]);
        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    long long distance(int u, int v) {
        int ancestor = lca(u, v);
        return distFromRoot[u] + distFromRoot[v] - 2 * distFromRoot[ancestor];
    }

private:
    void dfs(int v, int p, int d, long long dist) {
        depth[v] = d;
        distFromRoot[v] = dist;
        up[v][0] = p;

        for (int i = 1; i < LOG; ++i) {
            if (up[v][i - 1] != -1)
                up[v][i] = up[up[v][i - 1]][i - 1];
        }

        for (auto &[u, w] : adj[v]) {
            if (u != p) {
                dfs(u, v, d + 1, dist + w);
            }
        }
    }

    int lift(int v, int k) {
        for (int i = 0; i < LOG; ++i) {
            if (k & (1 << i)) {
                v = up[v][i];
                if (v == -1) break;
            }
        }
        return v;
    }
};