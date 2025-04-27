// Time complexity of O(2*n)

// if want for ending just reverse the string then reverse the ans
vector<int> longestPalindromeFromIndex(string &s) {
    int n = s.size();
    string t = "@"; // sentinel to avoid bounds
    for (char c : s) {
        t += "#";
        t += c;
    }
    t += "#$"; // end sentinel

    int m = t.size();
    vector<int> p(m, 0); // radius array
    int center = 0, right = 0;

    for (int i = 1; i < m - 1; ++i) {
        int mirror = 2 * center - i;
        if (i < right)
            p[i] = min(right - i, p[mirror]);

        while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
            p[i]++;

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    vector<int> res(n, 1); // default min length is 1
    for (int i = 1; i < m - 1; ++i) {
        int len = p[i];
        int start = (i - len) / 2;
        if (start < n)
            res[start] = max(res[start], len);
    }

    return res;
}