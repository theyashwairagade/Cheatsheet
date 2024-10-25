// For undirected acyclic graph
// distance, node
pair<int,int> extremeEnd(vector<vector<int>> &undirectedAcyclicGraphAdjacencyList, vector<bool> &visited, int node){
        visited[node]=true;
        pair<int, int> ans={0,-1};

        for(auto &child: undirectedAcyclicGraphAdjacencyList[node])
                if(!visited[child])
                maximum(ans, extremeEnd(undirectedAcyclicGraphAdjacencyList, visited, child));

        if(!ans.first)
                return {1,node};
        ans.first++;
        return ans;
}