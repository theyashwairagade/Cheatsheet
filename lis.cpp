// for integers
int lis(vector<int>& nums) {
    vector<int> temp;
    
    for (int num : nums) {
        auto it = lower_bound(temp.begin(), temp.end(), num);

        if (it == temp.end())
            temp.push_back(num);
        else 
            *it = num;
    }
    
    return temp.size();
}

// Used for pairs with strictly increasing
int lis(vector<pair<int,int>> &pairs){
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first < b.first) // sort by x in ascending
            return true;
        if(a.first == b.first)  // sort by y in descending
            return a.second > b.second;
        return false;
    });

    vector<int> temp;
    for(auto &pair: pairs){
        int y = pair.second;
        
        auto it = lower_bound(temp.begin(), temp.end(), y);
        if(it == temp.end())
            temp.push_back(y);
        else
            *it = y;
    }
    return temp.size();
}