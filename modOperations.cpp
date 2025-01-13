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