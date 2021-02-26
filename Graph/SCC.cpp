//O(E) 1-base
int n,m,cnt,verticesScc[MAX_N];
vector<int>g[MAX_N],g1[MAX_N],scc[MAX_N];
vector<int>tSort;
bool mark[MAX_N];
void topologicalSort(int v) {
    mark[v] = true;
    for(int u:g[v])
        if(!mark[u])
            topologicalSort(u);
    tSort.push_back(v);
}

void dfs(int v) {
    mark[v] = true;
    scc[cnt].push_back(v);
    verticesScc[v] = cnt;
    for(int u:g1[v])
        if(!mark[u])
            dfs(u);
}

void SCC() {
    for(int i = 1 ; i <= n ; i++)
        if(!mark[i])
            topologicalSort(i);
    reverse(tSort.begin(), tSort.end());
    memset(mark, false, sizeof mark);
    for(int v:tSort) 
        if(!mark[v]) {
            cnt++;
            dfs(v);
        }
}
