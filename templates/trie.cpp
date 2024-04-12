class Trie
{
  struct Node
  {
    int pos = 0;
    int next[2] = {0, 0};
  };
  vector<Node> trie{1};

public:
  void add_number(int val, int pos)
  {
    int node = 0;
    for (int bit = 20; bit >= 0; bit--)
    {
      bool now = (val & (1 << bit));
      if (!trie[node].next[now])
      {
        trie[node].next[now] = trie.size();
        trie.emplace_back();
      }
      node = trie[node].next[now];
    }
    trie[node].pos = pos;
  }

  int search_complement(int val)
  {
    int node = 0;
    for (int bit = 20; bit >= 0; bit--)
    {
      bool now = (val & (1 << bit));
      if (!trie[node].next[!now])
      {
        node = trie[node].next[now];
      }
      else
      {
        node = trie[node].next[!now];
      }
    }
    return trie[node].pos;
  }
};

// ---------------------------------------------

class Trie
{
  struct Node
  {
    int cnt = 0;
    int lvs = 0;
    int next[26] = {};
  };
  vector<Node> trie{1};

public:
  void insert(const string &str)
  {
    int node = 0;
    for (char chr : str)
    {
      if (!trie[node].next[chr - 'a'])
      {
        trie[node].next[chr - 'a'] = trie.size();
        trie.emplace_back();
      }
      node = trie[node].next[chr - 'a'];
      trie[node].lvs++;
    }
    trie[node].cnt++;
  }

  void erase(const string &str)
  {
    int node = 0;
    for (char chr : str)
    {
      node = trie[node].next[chr - 'a'];
      trie[node].lvs--;
    }
    trie[node].cnt--;
    node = 0;
    for (char chr : str)
    {
      if (!trie[trie[node].next[chr - 'a']].lvs)
      {
        trie[node].next[chr - 'a'] = 0;
        return;
      }
      node = trie[node].next[chr - 'a'];
    }
  }

  int count(const string &str)
  {
    int node = 0;
    for (char chr : str)
    {
      if (!trie[node].next[chr - 'a'])
        return 0;
      node = trie[node].next[chr - 'a'];
    }
    return trie[node].cnt;
  }

  int lcp(const string &str)
  {
    int node = 0, len = 0;
    for (char chr : str)
    {
      if (!trie[node].next[chr - 'a'])
        return len;
      node = trie[node].next[chr - 'a'];
      len++;
    }
    return len;
  }
};
