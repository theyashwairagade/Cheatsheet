#include <unordered_map>

// Syntax for declaring unordered map with hash function
unordered_map<pair<int,int>,int, pair_hash> mp;
// initializing hash function for unordered map of <pair,int>
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};





// For unordered_set<int, HashSetHash, HashSetEqual>
struct HashSetHash {
    size_t operator()(const unordered_set<int>& s) const {
        size_t hash = 0;
        for (int elem : s) {
            hash ^= hash<int>()(elem);
        }
        return hash;
    }
};
struct HashSetEqual {
    bool operator()(const unordered_set<int>& s1, const unordered_set<int>& s2) const {
        return s1 == s2;
    }
};





// For unordered_map<vector<int>,int,VectorHash> mp;
struct VectorHash {
    size_t operator()(const vector<int>& vec) const {
        size_t seed = vec.size();
        
        for (int num : vec) 
            seed ^= hash<int>{}(num) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};