vector<vector<int>> getIntervals(vector<int> &nums){
    int n = nums.size();
    unordered_map<int, pair<int,int>> mp;
    
    REP(i, 0, n)
        if(mp.find(nums[i])!=mp.end())
            mp[nums[i]].second = i;
        else
            mp[nums[i]].first = mp[nums[i]].second = i;
    
    vector<vector<int>> ans;
    for(auto &i, mp)
        ans.push_back({i.second.first, i.second.second});
    return ans;
}

int countNonOverlappingIntervals(vector<vector<int>> intervals){
    asort(intervals);
    int end = -1,
        ans = 0;

    AREP(interval, intervals){
        if(interval[0]>end)
            ans++;
        end = max(end, interval[1]);
    }
    return ans;
}