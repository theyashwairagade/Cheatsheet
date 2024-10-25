#include<iostream>
#include<vector>
using namespace std;
class FenwickTree{
    private:
        vector<int> tree;
        int n;
    public:
        void update(int index, int val)
        {
            index++;
            while(index<=n)
            {
                tree[index]+=val;
                index += (index & -index);
            }
        }
        int query(int index)
        {
            int ans=0;
            index++;

            while(index>0)
            {
                ans+=tree[index];
                index-= (index & -index);
            }
            return ans;
        }
        int rangeQuery(int left, int right)
        {
            return query(right)-query(left-1);
        }
        FenwickTree(vector<int> &vec)
        {
            n=vec.size();
            tree.resize(n+1, 0);
            for(int i=0; i<n; i++)
                update(i, vec[i]);
        }
};
int main()
{
    vector<int> vec={5, 3, 7, 6, 5, 4, 2, 1, 3, 2};
    FenwickTree f(vec);
    // It includes both 2 and 8 index 
    cout<<f.rangeQuery(2,8);
    return 0;
}