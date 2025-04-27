string chanceBase(string &base10, int &newBase){
    reverse(base10.begin(), base10.end());
    while(!base10.empty() && base10.back() == '0')
        base10.pop_back();
    reverse(base10.begin(), base10.end());

    if(base10.empty())
        return "";
    
    string quotient;
    int number = 0;
    AREP(c, base10){
        number *= 10;
        number += c - '0';
        quotient += number / newBase + '0';
        number %= newBase;
    }
    return chanceBase(quotient, newBase) + (char)(number + '0');
}