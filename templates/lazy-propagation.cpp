int const M = 998244353;

int add(ll a, ll b) {
    a %= M;
    b %= M;
    return (a + b) % M;
}

int mul(ll a, ll b) {
    a %= M;
    b %= M;
    return 1LL * a * b % M;
}

struct Node {
    int sumA, sumB;
    int prod, cnt;
    Node(): sumA(0), sumB(0), prod(0), cnt(0) {}
};

class LazySegmentTree {
private:
    vector<Node> tree;
    vector<ii> lazy;

    void updateNode(int node, ii diffs) {
        int term1 = mul(diffs.second, tree[node].sumA), term2 = mul(diffs.first, tree[node].sumB);
        int term3 = mul(tree[node].cnt, mul(diffs.first, diffs.second));
        tree[node].prod = add(tree[node].prod, add(term1, add(term2, term3)));
        tree[node].sumA = add(tree[node].sumA, mul(diffs.first, tree[node].cnt));
        tree[node].sumB = add(tree[node].sumB, mul(diffs.second, tree[node].cnt));
    }

    void addPairs(ii &a, ii &b) {
        a = {add(a.first, b.first), add(a.second, b.second)};
    }

    void lazyPush(int v) {
        addPairs(lazy[2 * v], lazy[v]);
        updateNode(2 * v, lazy[v]);
        addPairs(lazy[2 * v + 1], lazy[v]);
        updateNode(2 * v + 1, lazy[v]);
        lazy[v] = {0, 0};
    }

public:
    LazySegmentTree(int n) {
        tree.resize(4 * n + 4);
        lazy.resize(4 * n + 4);
    }
    void update(int node, int l, int r, ii value, int st, int fi) {
        if (r < l or fi < l or r < st) {
            return;
        }
        if (st == l and r == fi) {
            tree[node].cnt = r - l + 1;
            updateNode(node, value);
            addPairs(lazy[node], value);
            return;
        }
        lazyPush(node);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, value, st, min(fi, mid));
        update(2 * node + 1, mid + 1, r, value, max(mid + 1, st), fi);
        tree[node].prod = add(tree[2 * node].prod, tree[2 * node + 1].prod);
        tree[node].sumA = add(tree[2 * node].sumA, tree[2 * node + 1].sumA);
        tree[node].sumB = add(tree[2 * node].sumB, tree[2 * node + 1].sumB);
        tree[node].cnt = r - l + 1;
    }
    Node query(int node, int l, int r, int st, int fi) {
        if (st <= l and r <= fi) {
            return tree[node];
        }
        lazyPush(node);
        int mid = (l + r) / 2;
        Node ans1, ans2;
        if (st <= mid) {
            ans1 = query(2 * node, l, mid, st, fi);
        }
        if (fi > mid) {
            ans2 = query(2 * node + 1, mid + 1, r, st, fi);
        }
        Node comb;
        comb.prod = add(ans1.prod, ans2.prod);
        comb.sumA = add(ans1.sumA, ans2.sumA);
        comb.sumB = add(ans1.sumB, ans2.sumB);
        comb.cnt = r - l + 1;
        return comb;
    }
};
