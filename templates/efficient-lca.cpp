class LCA
{
private:
  vector<vector<int>> tree, parent;
  vector<int> depth;
  int sz, maxPw;

public:
  LCA(vector<vector<int>> graph, int n, int root = 1)
  {
    this->sz = n;
    this->tree = graph;
    this->maxPw = log2(2 * n);
    this->depth.resize(n + 1);
    this->parent.assign(n + 1, vector<int>(maxPw + 1));
    precalcAncestors(root, 0);
  }

  void precalcAncestors(int node, int par)
  {
    parent[node][0] = par;
    depth[node] = depth[par] + 1;
    for (int i = 1; i <= maxPw; ++i)
    {
      parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }
    for (int dest : tree[node])
    {
      if (dest != par)
      {
        precalcAncestors(dest, node);
      }
    }
  }

  int getLCA(int a, int b)
  {
    if (depth[a] > depth[b])
    {
      swap(a, b);
    }
    for (int i = maxPw; i >= 0; --i)
    {
      if (depth[parent[b][i]] >= depth[a])
      {
        b = parent[b][i];
      }
    }
    if (a == b)
    {
      return a;
    }
    for (int i = maxPw; i >= 0; --i)
    {
      if (parent[a][i] != parent[b][i])
      {
        a = parent[a][i];
        b = parent[b][i];
      }
    }
    return parent[a][0];
  }

  int getDist(int a, int b)
  {
    return depth[a] + depth[b] - 2 * depth[getLCA(a, b)];
  }
};
