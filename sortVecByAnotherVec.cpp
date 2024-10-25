void customSort(vector<int> &vec1, vector<int> &vec2){
    // Function used to sort vec2 accourding to vec1
    if(vec1.size()!=vec2.size()){
        cout<<"Both vectors have different size"<<endl;
        return;
    }
    
    int n = vec1.size();
    vector<size_t> index(n);
    
    for(size_t i=0; i<n; i++)
        index[i]=i;

    sort(index.begin(), index.end(), 
    [&](size_t i, size_t j) {
        if (vec1[i] != vec1[j])
            return vec1[i] < vec1[j];
        return i < j;  // Tie-breaking condition: index order
    });

    // If you want to do other vectors then can do here
    vector<int> dummyVec2(n);
    for(int i=0; i<n; i++)
        dummyVec2[i] = vec2[i];
    
    for(size_t i=0; i<n; i++)
        vec2[i] = dummyVec2[index[i]];

    // If you want to sort vec1
    // sort(vec1.begin(), vec1.end());
    
    return;
}