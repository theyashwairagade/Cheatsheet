#include<iostream>
#include<vector>
using namespace std;
class PrefixSum{
    vector<long long> vec;
    int n;
    public:
        PrefixSum(vector<int> temp){
            n = temp.size();
            if(!n){
                cout<<"Invalid size"<<endl;
                return;
            }
            vec.resize(n);
            vec[0] = temp[0];
            for(int i=1; i<n; i++)
                vec[i]=vec[i-1]+temp[i];
        }
        // It's inclusive on right and exlusive on left
        int findSum(int leftIndex, int rightIndex){
            if(rightIndex >= n){
                cout<<"Invalid right index"<<endl;
                return -1;
            }
            return (leftIndex < 0) ? (int)vec[rightIndex] : (int)(vec[rightIndex]-vec[leftIndex]);
        }
};