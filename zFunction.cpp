#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Time complexity is O(n)
vector<int> zFunction(string str)
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
int main()
{
    string s;
    cin >> s;
    auto vec = zFunction(s);
    for (auto &i : vec)
        cout << i << " ";
}