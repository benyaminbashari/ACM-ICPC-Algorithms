//O(E) no-base
int n, m, par[MAX_N], height[MAX_N];
vector<int>g[MAX_N];
bool mark[MAX_N];
queue<int>q;
void bfs(int s) {
    mark[s] = true;
    q.push(s);
    height[s] = 0;
    while(q.size() > 0) {
        int v = q.front();
        q.pop();
        for(int u:g[v]) {
            if(!mark[u]) {
                mark[u] = true;
                par[u] = v;
                height[u] = height[v] + 1;
                q.push(u);
            }
        }
    }
}
