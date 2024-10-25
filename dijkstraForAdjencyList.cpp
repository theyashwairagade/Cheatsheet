#include<vector>
#include<queue>

// Used to find shortest distance from one node
// Can be also used to find shortest distance between two nodes
// Adjency list with edge weight, node

// time complexity of O(N square)
// But can ask gpt for O(N + E logN)
vector<int> dijkstra(vector<vector<pair<int,int>>> &adjencyList, int source)
{
    int n=adjencyList.size();
    vector<int> shortestDistance(n,1e8);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, source});
    while(!q.empty())
    {
        int weight=q.top().first, node= q.top().second;
        q.pop();

        if(weight>shortestDistance[node])
            continue;
        
        shortestDistance[node]=weight;
        for(auto &entry: adjencyList[node])
        {
            int node2= entry.first, edgeWeight= entry.second;
            if(shortestDistance[node]+edgeWeight< shortestDistance[node2])
            {
                shortestDistance[node2]=shortestDistance[node]+edgeWeight;
                q.push({shortestDistance[node2],node2});
            }
        }
    }
    return shortestDistance;
}





// Without edge weight
// Adjency list with edge weight, node
vector<int> dijkstra(vector<vector<int>> &adjencyList, int source)
{
    int n=adjencyList.size();
    vector<int> shortestDistance(n,1e8);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, source});
    while(!q.empty())
    {
        int weight=q.top().first, node= q.top().second;
        q.pop();

        if(weight>shortestDistance[node])
            continue;
        
        shortestDistance[node]=weight;
        for(auto &entry: adjencyList[node])
        {
            int node2= entry;
            if(shortestDistance[node]+1< shortestDistance[node2])
            {
                shortestDistance[node2]=shortestDistance[node]+1;
                q.push({shortestDistance[node2],node2});
            }
        }
    }
    return shortestDistance;
}