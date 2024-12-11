void print(unordered_map<int, int> &mp){
    for(auto &pr: mp)
        cout<<pr.first<<"->"<<pr.second<<endl;
}

void print(unordered_map<int, unordered_set<int>> &mp){
    for(auto &pr: mp){
        cout<<pr.first<<": ";
        for(auto &i: pr.second)
            cout<<"i ";
        cout<<endl;
    }
}