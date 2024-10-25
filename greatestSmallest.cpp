int findGreatest(vector<int> &vec){
    int ans = INT_MIN;
    for(auto &i: vec)
        ans = max(ans, i);
    return ans;
}





int findSmallest(vector<int> &vec){
    int ans = INT_MAX;
    for(auto &i: vec)
        ans = min(ans, i);
    return ans;
}





int findGreatestIndex(vector<int> &vec){
    int ans = 0;
    int n = vec.size();
    for(int i=1; i<n; i++)
        if(vec[i]>vec[ans])
            ans = i;
    return ans;
}





int findSmallestIndex(vector<int> &vec){
    int ans = 0;
    int n = vec.size();
    for(int i=1; i<n; i++)
        if(vec[i]<vec[ans])
            ans = i;
    return ans;
}