struct Data {
    int a, b, c;
};
struct Compare {
    bool operator()(const Data& d1, const Data& d2) {
        long long product1 = (long long)d1.a * d1.b;
        long long product2 = (long long)d2.a * d2.b;
        
        // 1st priority: minimum (a * b)
        if (product1 != product2) {
            return product1 > product2; // min-heap for a * b
        }
        
        // 2nd priority: maximum b
        return d1.b < d2.b; // max-heap for b
    }
};