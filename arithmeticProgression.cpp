int sumOfAP(int first, int last, int n) {
    int d = (last - first) / (n - 1);
    int sum = (n / 2.0) * (first + last);
    return sum;
}



int sumOfAP(int first, int last, int commonDifference = 1) {
    int n = static_cast<int>((last - first) / commonDifference) + 1;
    int sum = (n / 2.0) * (first + last);
    return sum;
}