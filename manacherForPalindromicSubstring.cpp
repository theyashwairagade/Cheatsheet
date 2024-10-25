// Time complexity of O(2*n)
vector<int> getManacherVector(string &s){
    // Generializing for both odd and even length palindromic subString
    string str = "#";
    for(auto &c: s)
        str = str + c + '#';
    
    int n = str.size();
    vector<int> ans(n);

    for(int i=0, center=0; i<n; i++){

        if(2*center-i >= 0 && center+ans[center]>i)
            ans[i] = min(ans[2*center-i], center+ans[center]-i);
        
        while(i-ans[i]>=0 && i+ans[i]<n && str[i-ans[i]]== str[i+ans[i]])
            ans[i]++;
        
        if(i+ans[i]>center+ans[center])
            center=i;
        
        ans[i]--;
    }

    return vector<int>(ans.begin()+1, ans.end()-1);
}





// Start and end index of substring both including
bool isPalindromicSubstring(int start, int end, vector<int> &manacherVector) {
  return manacherVector[start + end] >= end - start + 1;
}





int longestPalindromicSubstringLength(vector<int> &manacherVector){
    int ans = 0;
    for(auto &i: manacherVector)
        ans = max(ans, i);
    return ans;
}





int countAllPalindromicSubstrings(vector<int> &manacherVector){
    int ans = 0;
    for(auto &i: manacherVector)
        ans += (i+1)/2;
    return ans;
}





// To be created soon
vector<string> findAllPalindromicSubstring(int length, vector<int> &manacherVector, string str){
    
}