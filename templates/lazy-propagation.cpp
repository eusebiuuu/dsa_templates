template <typename T>
class LazySegmentTree
{
  // Change push logic depending on update type (assignment, addition etc.)
  // Change return value from query function
  // Change last line of update function
  // Change type of update (assign, add etc.)
  // Change variables in query
  // Change l and r for both functions if it is the case
  // Don’t assign 0 to node in update and query
private:
  vector<T> tree, lazy;
  void lazyPush(int v)
  {
    lazy[2 * v] += lazy[v];
    tree[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
    tree[2 * v + 1] += lazy[v];
    lazy[v] = 0;
  }

public:
  LazySegmentTree(int n)
  {
    tree.resize(4 * n + 4);
    lazy.resize(4 * n + 4);
  }
  void update(int node, int l, int r, T value, int st, int fi)
  {
    if (r < l or fi < l or r < st)
    {
      return;
    }
    if (st == l and r == fi)
    {
      tree[node] += value;
      lazy[node] += value;
      return;
    }
    lazyPush(node);
    int mid = (l + r) / 2;
    update(2 * node, l, mid, value, st, min(fi, mid));
    update(2 * node + 1, mid + 1, r, value, max(mid + 1, st), fi);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
  }
  T query(int node, int l, int r, int st, int fi)
  {
    if (r < l)
    {
      return 0;
    }
    if (st <= l and r <= fi)
    {
      return tree[node];
    }
    lazyPush(node);
    int mid = (l + r) / 2;
    T ans1, ans2;
    if (st <= mid)
    {
      ans1 = query(2 * node, l, mid, st, fi);
    }
    if (fi > mid)
    {
      ans2 = query(2 * node + 1, mid + 1, r, st, fi);
    }
    return max(ans1, ans2);
  }
};
