void prefixSum(vi &vec){
    vec.insert(vec.begin(), 0);
    partial_sum(vec.begin(), vec.end(), vec.begin());
}