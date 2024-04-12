int const N = 2e5 + 5, M = 5e5 + 5;
vector<pair<int, int>> graph[N];
vector<int> cycle;
bitset<M> seen;
stack<int> nodes;

void find_eulerian_cycle()
{
  nodes.push(1);
  while (!nodes.empty())
  {
    int node = nodes.top();
    if (graph[node].size())
    {
      int dest = graph[node].back().first, num = graph[node].back().second;
      graph[node].pop_back();
      if (!seen[num])
      {
        seen[num] = true;
        nodes.push(dest);
      }
    }
    else
    {
      nodes.pop();
      cycle.push_back(node);
    }
  }
}
