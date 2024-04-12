class DSU {
private:
    vector<int> root, height;
public:
    DSU(int n) {
        root.resize(n + 1);
        height.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            root[i] = i, height[i] = 1;
        }
    }
    int getRoot(int x) {
        int node = x;
        while (root[node] != node) {
            node = root[node];
        }
        while (root[x] != x) {
            int aux = root[x];
            root[x] = node;
            x = aux;
        }
        return node;
    }
    void unite(int x, int y) {
        x = root[x], y = root[y];
        if (height[x] > height[y]) {
            root[y] = x;
            height[x] += height[y];
        } else {
            root[x] = y;
            height[y] += height[x];
        }
    }
};

tree.unite(tree.getRoot(a), tree.getRoot(b));

