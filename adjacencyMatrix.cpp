vector<vector<int>> undirectedMultiweightedAdjacencyMatrix(int n, vector<vector<int>> &edges){
    vector<vector<int>> matrix(n, vector<int> (n,INT_MAX));
    for(auto &edge: edges){
        int u = edge[0],
            v = edge[1],
            w = edge[2];
        matrix[u][v] = min(matrix[u][v], w);
        matrix[v][u] = min(matrix[v][u], w);
    }
    for(int i = 0; i<n; i++)
        matrix[i][i] = 0;
    return matrix;
}