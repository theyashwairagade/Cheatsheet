vector<int> nextGreaterElementIndex(vector<int> &vec){
    int n = vec.size();
    vector<int> nextGreater(n, -1);
    stack<int> stk;

    for(int i=0; i<n; i++){
        while(!stk.empty() && vec[stk.top()]<vec[i]){
            nextGreater[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    return nextGreater;
}