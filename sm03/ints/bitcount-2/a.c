int bitcount(STYPE value) {
    UTYPE bits = (UTYPE) value;
    int result = 0;
    while (bits != 0) {
        result += 1 & bits;
        bits >>= 1;
    }
    return result;
}

