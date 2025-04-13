class FenwickTree {
    // range queries and updates (binary, identity, inverse):
    // https://cp-algorithms.com/data_structures/fenwick.html Don’t forget to
    // build the tree with updates, not with assignments Change update and query
    // accordingly Change initial value of carry Change type if needed Index
    // from 0 if needed
   private:
    int size;
    vector<int> tree;

   public:
    FenwickTree(int curSize, int value) {
        this->size = curSize;
        tree.resize(curSize + 1, value);
    }

    void update(int pos, int value) {
        while (pos <= this->size) {
            this->tree[pos] += value;
            pos += pos & -pos;
            // pos |= pos + 1;
        }
    }

    int query(int rightBound) {
        int carry = 0;
        while (rightBound > 0) {
            carry += this->tree[rightBound];
            rightBound -= rightBound & -rightBound;
            // rightBound = (rightBound & (rightBound + 1)) - 1;
        }
        return carry;
    }
};
