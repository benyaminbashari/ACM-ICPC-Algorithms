//O(E) no-base
int n, height[MAX_N], par[MAX_N];
vector<int>g[MAX_N];
bool mark[MAX_N];

void dfs(int v) {
    mark[v] = true;
    for(int u:g[v])
        if(!mark[u]) {
            par[u] = v;
            height[u] = height[v]+1;
            dfs(u);
        }
}
