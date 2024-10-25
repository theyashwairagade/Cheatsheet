int mostSignificantBit(int n) {
    if (n == 0) return -1;
    int msb = 0;
    while (n > 1) {
        n >>= 1;
        msb++;
    }
    return msb;
}