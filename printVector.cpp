void print(vector<int> &vec){
    for(auto &i: vec)
        cout<<i<<" ";
    cout<<endl;
}
// If needed to print 2D vector
void print(vector<vector<int>> &vec){
    for(auto &i: vec)
        print(i);
    cout<<endl;
}





// For long long
void print(vector<long long> &vec){
    for(auto &i: vec)
        cout<<i<<" ";
    cout<<endl;
}
// If needed to print 2D vector
void print(vector<vector<long long>> &vec){
    for(auto &i: vec)
        print(i);
    cout<<endl;
}
void print(vector<vector<long long>> &vec) {
    for(auto &i: vec)
        print(i);
}






// print unordered_set<int>
void print(unordered_set<int> &st){
    for(auto &i: st)
        cout<<i<<" ";
    cout<<endl;
}