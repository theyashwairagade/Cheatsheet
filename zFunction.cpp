#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Time complexity is O(n)
// Can be runned independently
vector<int> zFunction(string &str)
{
    int n = str.size();
    vector<int> zIndex(n, 0);

    for (int i = 1, left = 0, right = 0; i < n; i++)
    {
        if (i <= right)
            zIndex[i] = min(right - i + 1, zIndex[i - left]);
        while (i + zIndex[i] < n && str[zIndex[i]] == str[i + zIndex[i]])
            zIndex[i]++;
        if (i + zIndex[i] - 1 > right)
            left = i,
            right = i + zIndex[i] - 1;
    }
    return zIndex;
}

vector<int> zFunction(string &str, string &pattern){
    string temp = pattern + "#" + str;
    // Change accourdingly
    bool returnOnlyString = false;

    auto ans = zFunction(temp);
    if(returnOnlyString){
        int n = pattern.size();
        return vector<int>(ans.begin()+n+1, ans.end());
    }
    return ans;
}


int main()
{
    string s;
    cin >> s;
    auto vec = zFunction(s);
    for (auto &i : vec)
        cout << i << " ";
}