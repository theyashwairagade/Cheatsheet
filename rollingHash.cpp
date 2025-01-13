class rollingHash{
    private:
        int mod, base;
        vector<int> hash, pow;
    public:
        rollingHash(vector<int> &vec, int base, int mod = 1e9+7) : mod(mod){
            hash.push_back(0);
            pow.push_back(1);
            
            for(auto &num: nums){
                pow.push_back(1LL * pow.back() * base % mod);
                hash.push_back((1LL * hash.back() * base + num) % mod);
            }
        }
        rollingHash(string &str, int mod = 1e9+7, int base = 31){
            hash.push_back(0);
            pow.push_back(1);
            
            for(auto &c: str){
                pow.push_back(1LL * pow.back() * base % mod);
                hash.push_back((1LL * hash.back() * base + c-'a') % mod);
            }
        }
        int getHashByStartLen(int start, int len) {
            if (start < 0 || start + len > hash.size() - 1 || len < 0)
                throw out_of_range("Invalid start or length");
            return (hash[start + len] - (1LL * hash[start] * pow[len]) % mod + mod) % mod;
        }
        // Both start and end is including
        int getHashByStartEnd(int start, int end)
            {return getHashByStartLen(start, end-start+1);}
        int getEntireStringHash() 
            {return hash.back();}
};


class rollingHash{
    private:
        int mod, base;
        vector<int> hash, pow;
    public:
        rollingHash(string &str, int mod = 1e9+7, int base = 31){
            hash.push_back(0);
            pow.push_back(1);
            
            for(auto &c: str){
                pow.push_back(1LL * pow.back() * base % mod);
                hash.push_back((1LL * hash.back() * base + c-'a') % mod);
            }
        }
        int getHashByStartLen(int start, int len) {
            if (start < 0 || start + len > hash.size() - 1 || len < 0)
                throw out_of_range("Invalid start or length");
            return (hash[start + len] - (1LL * hash[start] * pow[len]) % mod + mod) % mod;
        }
        // Both start and end is including
        int getHashByStartEnd(int start, int end)
            {return getHashByStartLen(start, end-start+1);}
        int getEntireStringHash() 
            {return hash.back();}
        void printHash(){
            cout<<"Hash: ";
            for(auto &i: hash)
                cout<<i<<" ";
            cout<<endl;
        }
        void printPow(){
            cout<<"Pow: ";
            for(auto &i: pow)
                cout<<i<<" ";
            cout<<endl;
        }
};


int getStringHash(string &str){
    int base = 31,
        mod = 1e9+7;
    
    int hash = 0;
    for(auto &c: str)
        hash = (1LL * hash * base + c - 'a') % mod;
    return hash;
}