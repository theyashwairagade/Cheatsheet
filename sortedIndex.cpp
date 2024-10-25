vector<int> getSortedIndex(const vector<int> &vec){
    int n = vec.size();

    vector<int> index(n);
    for(int i=0; i<n; i++)
        index[i]=i;
    
    sort(index.begin(), index.end(), 
    [&](int i, int j) {
        if (vec[i] != vec[j])
            return vec[i] < vec[j]; // Ascending order
        return i < j;  // Ascending order
    });
    return index;
}