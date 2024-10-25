#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class SegmentTree{
    private:
        vector<int> tree;
        int n;
        int findMid(int a, int b)
            {return a+(b-a)/2;}
        void build(vector<int> &vec, int index, int left, int right)
        {
            if(left==right)
            {    
                tree[index]= vec[left];
                return;
            }
            int mid=findMid(left, right);
            build(vec, 2*index+1, left, mid);
            build(vec, 2*index+2, mid+1, right);

            // Need to change below accourding to question
            tree[index]=min(tree[2*index+1], tree[2*index+2]);
        }
        int query(int index, int currentLeft, int currentRight, int findLeft, int findRight)
        {
            bool noOverlap= (findRight<currentLeft || currentRight<findLeft);
            // Need to change below accourding to question
            if(noOverlap)
                return INT_MAX;
            bool completeOverlap= (findLeft <= currentLeft && currentRight <= findRight);
            if(completeOverlap)
                return tree[index];
            // If partial overlap
            int mid=findMid(currentLeft,currentRight);
            int left= query(2*index+1, currentLeft, mid, findLeft, findRight);
            int right= query(2*index+2, mid+1, currentRight, findLeft, findRight);
            // Need to change below accourding to question
            return min(left, right);
        }
        void update(int index, int left, int right, int findIndex, int val)
        {
            if(left==right)
            {
                // Need to change below accourding to question
                tree[index]=val;
                return;
            }
            // If partial overlap
            int mid=findMid(left, right);
            if(left<=findIndex && findIndex<=mid)
                update(2*index+1, left, mid, findIndex, val);
            else
                update(2*index+2, mid+1, right, findIndex, val);
            int leftTree=tree[2*index+1];
            int rightTree= tree[2*index+2];
            // Need to change below accourding to question
            tree[index]=min(leftTree, rightTree);
        }
    public:
        SegmentTree(vector<int> vec)
        {
            n=vec.size();
            tree.resize(4*n+1);
            build(vec,0,0,n-1);
        }
        void update(int index, int val)
            {update(0, 0, n-1, index, val);}
        // Including right index
        int query(int left, int right)
            {return query(0, 0, n-1, left, right);}
};
int main()
{
    vector<int> data={2, 4, 1, 5, 3, 8, 7, 9, 6};
    SegmentTree seg(data);
    cout<<seg.query(1, 4)<<endl;

    seg.update(2,10);
    cout<<seg.query(1,3);
}