#include<bits/stdc++.h>
using namespace std;

class IterativeSegmentTree {
    int n;
    vector<int> tree;

    int merge(int a, int b) {
        int mod = 1e9+7;
        a %= mod;
        b %= mod;
        return (a+b) % mod;
    }

    int notFound()
        {return 0;}

    void build(vector<int> &vec) {
        for(int i = 0; i<n; i++)
            tree[i+n] = vec[i];
        
        for(int i = n-1; i; i--)
            tree[i] = merge(tree[i*2], tree[i*2+1]);
    }

public:
    IterativeSegmentTree(int n) : n(n)
        {tree.resize(2*n);}

    IterativeSegmentTree(vector<int> &vec) : IterativeSegmentTree(vec.size())
        {build(vec);}

    int query(int left, int right) {
        int ans = notFound();
        left += n;
        right += n;

        while(left < right) {
            if(left % 2)
                ans = merge(ans, tree[left++]);
            if(right % 2 == 0)
                ans = merge(ans, tree[right--]);
            
            left/=2;
            right/=2;
        }

        if (left == right)
            ans = merge(ans, tree[left]);

        return ans;
    }

    void update(int index, int value) {
        index += n;
        tree[index] = value;
        while(index > 1) {
            index /= 2;
            tree[index] = merge(tree[index*2], tree[index*2 + 1]);
        }
    }
};





class SegmentTree{
    private:
        vector<int> tree;
        int n;

        // Need to change below accourding to question
        int operation(int a, int b)
            {return min(a, b);}
        int notFound()
            {return INT_MAX;}
        
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
            
            tree[index] = operation(tree[2*index+1], tree[2*index+2]);
        }
        int query(int index, int currentLeft, int currentRight, int findLeft, int findRight)
        {
            bool noOverlap= (findRight<currentLeft || currentRight<findLeft);
            if(noOverlap)
                return notFound();
            bool completeOverlap= (findLeft <= currentLeft && currentRight <= findRight);
            if(completeOverlap)
                return tree[index];
            // If partial overlap
            int mid=findMid(currentLeft,currentRight);
            int left= query(2*index+1, currentLeft, mid, findLeft, findRight);
            int right= query(2*index+2, mid+1, currentRight, findLeft, findRight);
            return operation(left, right);
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
            tree[index] = operation(leftTree, rightTree);
        }
    public:
        SegmentTree(vector<int> vec)
        {
            n=vec.size();
            tree.resize(4*n+1);
            build(vec,0,0,n-1);
        }
        SegmentTree(int n){
            this->n = n;
            tree.resize(4*n+1);
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





class LazySegmentTree {
    vector<long long> tree, lazy;
    int size;

public:
    // Constructor from size
    LazySegmentTree(int n) {
        size = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    // Constructor from vector
    LazySegmentTree(const vector<int> &arr) {
        size = arr.size();
        tree.assign(4 * size, 0);
        lazy.assign(4 * size, 0);
        build(1, 0, size - 1, arr);
    }

    void rangeAdd(int l, int r, int val) {
        rangeAdd(1, 0, size - 1, l, r, val);
    }

    long long query(int a)
        {return query(a, a);}

    long long query(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }

private:
    // Change operation here (e.g., min, max, gcd, etc.)
    long long operation(long long a, long long b) {
        return a + b;
    }

    long long notFound() {
        return 0;  // Identity for sum
    }

    void build(int node, int l, int r, const vector<int> &arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);
        tree[node] = operation(tree[2 * node], tree[2 * node + 1]);
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (r - l + 1);
            if (l != r) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void rangeAdd(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        rangeAdd(2 * node, l, mid, ql, qr, val);
        rangeAdd(2 * node + 1, mid + 1, r, ql, qr, val);
        tree[node] = operation(tree[2 * node], tree[2 * node + 1]);
    }

    long long query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql) return notFound();
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return operation(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }
};