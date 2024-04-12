template <typename T> class SegmentTree {
// Query method: return statements, variables value
// Update method: set the operation for assignment (last line), set the type of update of tree[node]
// Don’t assign 0 to node in update and query
private:
  vector<T> tree;
public:
  SegmentTree(int n, int val = 0) {
      tree.resize(4 * n + 4, val);
  }

  void update(int node, int l, int r, int pos, T val) {
      if (l == r) {
          tree[node] = val;
          return;
      }
      int mid = (l + r) / 2;
      if (pos <= mid) {
          update(2 * node, l, mid, pos, val);
      } else {
          update(2 * node + 1, mid + 1, r, pos, val);
      }
      tree[node] = tree[2 * node] + tree[2 * node + 1];
  }

  T query(int node, int l, int r, int st, int fn) {
      if (st > fn) return 0;
      if (st <= l and r <= fn) {
          return tree[node];
      }
      int mid = (l + r) / 2;
      T ans1 = 0, ans2 = 0;
      if (st <= mid) {
          ans1 = query(2 * node, l, mid, st, fn);
      }
      if (fn > mid) {
          ans2 = query(2 * node + 1, mid + 1, r, st, fn);
      }
      return ans1 + ans2;
  }
};


