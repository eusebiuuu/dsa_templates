int const N = 3e2 + 2;
int timer;
vector<int> graph[N], timeIn(N), low(N), seen(N), root(N), subtreeSz(N);

void findBridges(int node, int comp, int par = -1) {
    timeIn[node] = low[node] = timer++;
    seen[node] = true;
    subtreeSz[node] = 1;
    for (int dest : graph[node]) {
        if (dest == par) {
            continue;
        }
        if (timeIn[dest] == 0) {
            findBridges(dest, comp, node);
            subtreeSz[node] += subtreeSz[dest];
            low[node] = min(low[node], low[dest]);
            if (low[dest] > timeIn[node]) {
                // this is a bridge
            }
        } else {
            low[node] = min(low[node], timeIn[dest]);
        }
    }
}
