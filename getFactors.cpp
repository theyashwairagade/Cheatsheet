vector<int> getFactors(int n) {
    vector<int> factors;
    for (int i = 1; i <= sqrt(n); ++i) 
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i)
                factors.push_back(n / i);
        }
    sort(factors.begin(), factors.end());
    return factors;
}




vector<int> getPrimeFactors(int n) {
    vector<int> factors;

    while (n % 2 == 0)
        factors.push_back(2),
        n /= 2;

    for (int i = 3; i <= sqrt(n); i += 2)
        while (n % i == 0) 
            factors.push_back(i),
            n /= i;

    if (n > 2)
        factors.push_back(n);

    return factors;
}





vector<int> getUniquePrimeFactors(int n) {
    unordered_set<int> st;

    while (n % 2 == 0)
        st.insert(2),
        n /= 2;

    for (int i = 3; i <= sqrt(n); i += 2)
        while (n % i == 0) 
            st.insert(i),
            n /= i;

    if (n > 2)
        st.insert(n);
        
    vector<int> factors;
    for(auto &i: st)
        factors.push_back(i);
    return factors;
}