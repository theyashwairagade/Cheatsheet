vector<int> uniqueElements(vector<int> &sortedVec){
    int n= sortedVec.size();
    if(!n)
        return {};

    vector<int> ans;
    ans.push_back(sortedVec.front());
    int prev = sortedVec.front();

    for(int i=1; i<n; i++)
        if(sortedVec[i]!=prev)
            ans.push_back(prev = sortedVec[i]);
    
    return ans;
}