int findGCD(int a, int b) 
    {return b ? findGCD(b, a%b) : a;}

int findLCM(int a, int b) 
    {return (1LL * a * b / findGCD(a, b));}