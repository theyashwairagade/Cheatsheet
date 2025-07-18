// NOTE: This is adjacency list not adjacency matrix
vector<vector<int>> directedAdjacencyList(int n, vector<vector<int>>& edges){
    // Zero indexing
    vector<vector<int>> vec(n);
    for(auto &edge: edges)
        vec[edge[0]].push_back(edge[1]);
    return vec;
}





// NOTE: This is adjacency list not adjacency matrix
vector<vector<int>> undirectedAdjacencyList(int n, vector<vector<int>>& edges){
    // Zero indexing
    vector<vector<int>> vec(n);
    for(auto &edge: edges)
        vec[edge[0]].push_back(edge[1]),
        vec[edge[1]].push_back(edge[0]);
    return vec;
}





// undirected Adjacency list for multiple edge weight 
vector<unordered_map<int,int>> undirectedMultipleWeightedAdjacencyList(const int &n,const vector<vector<int>> &edges){
    vector<unordered_map<int,int>> ans(n);
    for(const auto &edge: edges){
        int u = edge[0], v = edge[1], wght = edge[2];
        if(ans[u].find(v)!=ans[u].end())
            ans[u][v] = wght;
        else
            ans[u][v] = min(ans[u][v], wght);
        
        if(ans[v].find(u)!= ans[v].end())
            ans[v][u] = wght;
        else
            ans[v][u] = min(ans[v][u], wght);
    }
}

vector<vector<pair<int,int>>> getAdjacencyListInVec(vector<unordered_map<int,int>> temp){
    vector<vector<pair<int,int>>> ans;

    for(auto &i: temp){
        vector<pair<int,int>> vec;
        for(auto &j: i)
            vec.push_back(j);
        ans.push_back(vec);
    }
    return ans;
}





vector<vector<pair<int,int>>> undirectedWeightedAdjacencyList(const int &n, const vector<vector<int>> &edges){
    vector<vector<pair<int,int>>> adjacencyList(n);
    for(auto &edge: edges)
        adjacencyList[edge[0]].push_back({edge[1], edge[2]}),
        adjacencyList[edge[1]].push_back({edge[0], edge[2]});
    
    return adjacencyList;
}





vector<vector<pair<int,int>>> directedWeightedAdjacencyList(const int &n, const vector<vector<int>> &edges){
    vector<vector<pair<int,int>>> adjacencyList(n);
    for(auto &edge: edges)
        adjacencyList[edge[0]].push_back({edge[1], edge[2]});
    
    return adjacencyList;
}





vector<vector<pair<int,int>>> directedWeightedReverseAdjacencyList(const int &n, const vector<vector<int>> &edges){
    vector<vector<pair<int,int>>> adjacencyList(n);
    for(auto &edge: edges)
        adjacencyList[edge[1]].push_back({edge[0], edge[2]});
    
    return adjacencyList;
}





void printWeightedAdjacencyList(vector<vector<pair<int,int>>> &adjacencyList){
    int n = adjacencyList.size();
    for(int i=0; i<n; i++){
        cout<<"For i: "<<i<<" adjacent are: ";
        for(auto &edge: adjacencyList[i])
            cout<<"("<<edge.first<<","<<edge.second<<")  ";
        cout<<endl;
    }
}




// Tree adjacency list
vector<vector<int>> undirectedAdjacencyList(vector<vector<int>>& edges){
    int n = edges.size()+1;
    // Zero indexing
    vector<vector<int>> vec(n);
    for(auto &edge: edges)
        vec[edge[0]].push_back(edge[1]),
        vec[edge[1]].push_back(edge[0]);
    return vec;
}
void solve(int node, int parent, vector<vector<int>> &adj, vector<vector<int>> &normalAdj){
    for(auto &child: normalAdj)
        if(child != parent){
            adj[node].push_back(child);
            solve(child, node, adj, normalAdj);
        }
}
vector<vector<int>> treeAdjacencyList(vector<vector<int>>& edges, int root = 0){
    int n= edges.size()+1;
    
    vector<vector<int>> adj(n);
    auto normalAj = undirectedAdjacencyList(edges);

    solve(root, -1, adj, normalAj);
    return adj;
}