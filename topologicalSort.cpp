// Requires directed acyclic adjacency list
void dfs(int node, vector<int> &ans, vector<bool> &visited, vector<vector<int>> &directedAcyclicAdjacencyList) {
    if(visited[node])
        return;
    visited[node]=true;

    for(auto &child: directedAcyclicAdjacencyList[node])
        dfs(child, ans, visited, directedAcyclicAdjacencyList);
        
    ans.push_back(node);
}

vector<int> topologicalSort(vector<vector<int>> &directedAcyclicAdjacencyList) {
    int n = directedAcyclicAdjacencyList.size();

    vector<int> ans;
    vector<bool> visited(n);

    for(int i=0; i<n; i++)
        dfs(i, ans, visited, directedAcyclicAdjacencyList);
    
    reverse(ans.begin(), ans.end());
    return ans;
}





// Try using khan's algo as it also checks whether given adjacency list is acyclic or not