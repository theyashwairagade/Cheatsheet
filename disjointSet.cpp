class DisjointSetByRank {
    vector<int> parent, rank;
public:
    DisjointSetByRank(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }
    
    int findParent(int x) {
        if (parent[x] != x) 
            parent[x] = findParent(parent[x]); // Path compression
        
        return parent[x];
    }

    void connect(int x, int y) {
        int rootX = findParent(x);
        int rootY = findParent(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else
                parent[rootY] = rootX,
                rank[rootX]++;
        }
    }
    
    bool isConnected(int x, int y)
        {return findParent(x) == findParent(y);}
    
    // Default startingIndex is zero
    bool isFullyConnected(int startingIndex = 0){
        for(int i=startingIndex+1; i<parent.size(); i++)
            if(!isConnected(startingIndex,i))
                return false;
        return true;
    }

    void clear(){
        for (int i = 0; i < parent.size(); i++) 
            parent[i] = i,
            rank[i] = 0;
    }
};





class DisjointSetBySize {
    vector<int> parent, size;
public:
    DisjointSetBySize(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }

    int findParent(int x) {
        if (parent[x] != x)
            parent[x] = findParent(parent[x]); // Path compression

        return parent[x];
    }

    void connect(int x, int y) {
        int rootX = findParent(x);
        int rootY = findParent(y);
        if (rootX != rootY)
            if (size[rootX] > size[rootY]) 
                parent[rootY] = rootX,
                size[rootX] += size[rootY];
            else 
                parent[rootX] = rootY,
                size[rootY] += size[rootX];
    }
    
    int disjointComponenets(){
        int ans = 0;
        for(int i = 0; i<parent.size(); i++){
            if(findParent(i) == i)
                ans++;
        }
        return ans;
    }
};