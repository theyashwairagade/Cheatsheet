// To check can we reach from a give node to another node in that exact target steps
bool search(int target, int from, int &to, vector<bool> &visited, vector<vector<int>> &adjacencyList){
    if(visited[from])
        return false;
    if(!target)
        return from == to;
    visited[from]=true;
    for(auto node: adjacencyList[from])
        if(search(target-1, node, to, visited, adjacencyList))
            return true;
    return visited[from] = false;
}