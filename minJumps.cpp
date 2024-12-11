int minJumps(vector<int> &vec){
    int n = vec.size();
    int steps = 0, curr = 0, farthest = 0;
        for(int i = 0; i<n; i++){
            farthest = max(farthest, i+vec[i]);
            
            if(i == curr){
                steps++;
                curr = farthest;
                if(curr >=n)
                    break;
            }
        }
        if(curr < n)
            return -1;
        return steps;
}