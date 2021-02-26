//O(E) no-base
int n, m, par[MAX_N], low[MAX_N], height[MAX_N] ;
bool mark[MAX_N];
vector<int>g[MAX_N];
vector<pair<int,int> >cutEdges;
//dfs(1,0)
void dfs(int v, int h) {
    mark[v] = true;
    low[v] = h;
    height[v] = h;
    for(int u:g[v]) {
        if(!mark[u]) {
            par[u] = v;
            dfs(u, h+1);
            if(low[u] > height[v])
                cutEdges.push_back({v, u});
            low[v] = min(low[v], low[u]);
        }
        else if(u != par[v] && height[u] < height[v])
            low[v] = min(low[v], height[u]);
    }
}
