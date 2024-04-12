void findBridges(int node, int par = -1)
{
  timeIn[node] = low[node] = timer++;
  for (ii curEdge : graph[node])
  {
    int dest = curEdge.first;
    if (dest == par)
    {
      continue;
    }
    if (timeIn[dest] == 0)
    {
      findBridges(dest, node);
      low[node] = min(low[node], low[dest]);
      if (low[dest] > timeIn[node])
      {
        isBridge[curEdge.second] = true;
      }
    }
    else
    {
      low[node] = min(low[node], timeIn[dest]);
    }
  }
}
