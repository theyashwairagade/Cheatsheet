#include<bits/stdc++.h>
using namespace std;

int modAddition(int a, int b, int mod = 1e9+7){
    a %= mod;
    b %= mod;
    return (0LL + a + b) % mod;
}
int modSubtraction(int a, int b, int mod = 1e9+7){
    a %= mod;
    b %= mod;
    return (0LL + a + mod - b) % mod;
}
int modMultiplication(int a, int b, int mod = 1e9+7){
    a%=mod;
    b%=mod;
    return (1LL * a * b)%mod;
}
int coPrimeModDivide(int a, int b, int m) {
    // returns (a/b) % m;
    int m0 = m, x = 1, y = 0;
    int g = b, temp = m;

    // Extended Euclidean Algorithm
    while (temp) {
        int q = g / temp;
        int t = temp;
        temp = g % temp;
        g = t;

        t = y;
        y = x - q * y;
        x = t;
    }

    // Check if inverse exists
    if (g != 1) {
        if (a % g != 0) throw runtime_error("Can't divide");
        // Reduce a, b, and m by gcd
        return modDivide(a / g, b / g, m / g);
    }

    int b_inv = (x % m + m) % m;
    return (1LL * a * b_inv) % m;
}
int modExponentiation(int base, int exp, int mod = 1e9+7) {
    if(mod == 1)
        return 0;
    if(!exp || base == 1)
        return 1;

    int half = modExponentiation(base, exp / 2, mod);
    long long halfSquared = (1LL * half * half) % mod;
    return exp % 2 ? (int)((halfSquared * base) % mod) : (int)halfSquared;
}

// use only if mod is odd
int modInverse(int a, int mod = 1e9+7)
    {return modExponentiation(a, mod-2, mod);}

int nonPrimeModExpo(int base, int exp, int mod){
    if (mod == 1) return 0;
    if (exp < 0) {
        base = modInverse(base, mod);
        exp = -exp;
    }

    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (1LL * result * base) % mod;
        base = (1LL * base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int modFactorial(int n, int mod = 1e9+7){
    int ans = 1;
    for(int i = 2; i<=n; i++)
        ans = modMultiplication(ans, i, mod);
    return ans;
}

int modCombination(int n, int r, int mod = 1e9+7){
    if(r>n || r<0)
        return 0;
    
    int num = modFactorial(n, mod),
        denum1 = modFactorial(r, mod),
        denum2 = modFactorial(n-r, mod);
    
    int denum = modMultiplication(denum1, denum2, mod);
    denum = modInverse(denum, mod);

    return modMultiplication(num, denum, mod);
}







// n is included
vector<int> modFactorials(int n, int mod = 1e9+7){
    vector<int> ans = {1};
    for(int i = 1; i<=n; i++)
        ans.push_back((1LL * ans.back() * i) % mod);
    return ans;
}

// n is included
vector<int> modInverses(int n, int mod) {
    vector<int> ans(n + 1, 0);
    ans[1] = 1;

    for (int i = 2; i <= n; ++i)
        ans[i] = (mod - (mod / i) * ans[mod % i] % mod) % mod;

    return ans;
}






vector<vector<int>> getCombinations(int n, int m, int mod = 1e9+7) {
    vector<vector<int>> combination(n+1, vector<int>(m+1, 0));
    combination[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        combination[i][0] = 1;
        if (i <= m) 
            combination[i][i] = 1;
        
        for (int j = 1; j < i && j <= m; j++) {
            combination[i][j] = (combination[i-1][j] + combination[i-1][j-1]) % mod;
        }
    }
    return combination;
}





int ncr(int n, int r, int limit = INT_MAX-1){
    long long ans = 1;
    for(int i = 1; i<=r; i++){
        ans *= n-i+1;
        ans /= i;
        if(ans > (long long)limit) return limit + 1;
    }
    return ans;
}

int coPrimeModInverse(int n, int m) {
    // returns (1/n) mod m;
    int m0 = m, x = 1, y = 0;
    while (n > 1) {
        if (m == 0) throw runtime_error("Inverse doesn't exist");
        int q = n / m;
        int t = m;
        m = n % m, n = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    return (x % m0 + m0) % m0;
}