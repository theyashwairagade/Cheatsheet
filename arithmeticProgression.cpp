int sumOfAP(int first, int last, int n) {
    int d = (last - first) / (n - 1);
    int sum = (n / 2.0) * (first + last);
    return sum;
}



int sumOfAP(int first, int last, int commonDifference = 1) {
    if(last < first)
        return 0;
    int n = static_cast<int>((last - first) / commonDifference) + 1;
    int sum = (n / 2.0) * (first + last);
    return sum;
}





int sumOfAP(int a, int n, int commonDifference = 1) {
    int left = (2 * a + (n-1) * commonDifference);
    int numerator = left * n;
    int ans = numerator / 2;
    return ans;
}





// (a) square + (a+1) square ... (an) square
ll sumOfSequence(int a, int an) {
    ll left = 1LL * an * (an + 1) * (2*an + 1);
    ll right = 1LL * a * (a - 1) * (2*a - 1);
    ll numerator = left - right;
    return numerator / 6;
}