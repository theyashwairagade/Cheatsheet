int findGCD(int a, int b) 
    {return b ? findGCD(b, a%b) : a;}

int findLCM(int a, int b) 
    {return (a / findGCD(a, b)) * b;}