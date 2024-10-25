// To get maximum subarray sum in an array
void kadanesAlgo(vector<int> &vec, int &ans){
    int currentSum = 0;
    for(auto &i: vec){
        currentSum+=i;
        ans = max(currentSum, ans);
        currentSum = max(0, currentSum);
    }
}





// To get maximum subarray sum less than k in an array
void kadanesAlgo(vector<int> &vec, int &n, int &ans, int &k){
    int currentSum = 0;
    set<int> st={0};
    for(auto &i: vec){
        currentSum += i;
        auto it = st.lower_bound(currentSum-k);
        if(it!=st.end())
            ans = max(ans, currentSum - *it);
        st.insert(currentSum);
    }
}