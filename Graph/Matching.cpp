//O(VE) 1-base
int n1,n2,match[MAX_N];
bool mark[MAX_N];
vector<int>g[MAX_N];
bool dfs(int v) {
    if(mark[v]) return false;
    mark[v] = true;
    for(int u:g[v]) {
        if(match[u] == -1 || dfs(match[u])) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}
void optimize() {
    for(int i = 1 ; i <= n1 ; i++) {
        for(int v:g[i]) {
            if(match[v] == -1) {
                match[i] = v;
                match[v] = i;
                break;
            }
        }
    }
}
void MATCH() {
	memset(match, -1, sizeof match);
    optimize();
    for(int i = 1 ; i <= n1 ; i++) {
        if(match[i] != -1) continue;
        memset(mark, false, sizeof mark);
        dfs(i);
    }
}


