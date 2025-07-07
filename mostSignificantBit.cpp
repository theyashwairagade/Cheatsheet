int mostSignificantBit(int n) {
    if (n == 0) return -1;
    int ans = 0;
    while (n > 1) {
        n >>= 1;
        ans++;
    }
    return ans;
}

int minimumSignificantBit(int n) {
    if(n == 0)
        return -1;
    int ans = 0;
    while(n%2 == 0) {
        n/=2;
        ans++;
    }
    return ans;
}