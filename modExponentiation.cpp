int modExponentiation(int base, int exp, int mod) {
    if(!exp || base == 1)
        return 1;

    int half = modExponentiation(base, exp / 2, mod);
    long long halfSquared = (1LL * half * half) % mod;
    return exp % 2 ? (int)((halfSquared * base) % mod) : (int)halfSquared;
}