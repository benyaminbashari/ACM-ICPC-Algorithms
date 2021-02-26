//O((min(f|E|, |V||E|^2)) 1-base
int n,m,s,t,c[MAX_N][MAX_N],cf[MAX_N][MAX_N],par[MAX_N],maxFlow;
bool mark[MAX_N];
queue<int>q;
bool bfs() {
    memset(mark, false, sizeof mark);
    while(q.size()) q.pop();
    q.push(s);
    mark[s] = true;
    par[s] = -1;
    while(q.size() > 0) {
        int a = q.front();
        q.pop();
        for(int i = 1 ; i <= n ; i++) {
            if(!mark[i] && cf[a][i] > 0) {
                par[i] = a;
                mark[i] = true;
                q.push(i);
            }
        }
    }
    return mark[t];
}

void EdmondsKarp() {
    while(bfs()) {
        vector<int>path;
        int tmp = t;
        while(tmp != -1) {
            path.push_back(tmp);
            tmp = par[tmp];
        }
        reverse(path.begin(),path.end());
        int MIN = INF;
        for(int i = 0 ; i < path.size() -1 ; i++) {
            int a = path[i];
            int b = path[i+1];
            MIN = min(MIN,cf[a][b]);
        }
        for(int i = 0 ; i < path.size() -1 ; i++) {
            int a = path[i];
            int b = path[i+1];
            cf[a][b] -= MIN;
            cf[b][a] += MIN;
        }
        maxFlow += MIN;
    }
}


void addDirectionalEdge(int u, int v, int cap) {
    c[u][v] += cap;
    cf[u][v] += cap;
}

void addBiDirectionalEdge(int u, int v, int cap) {
    c[u][v] += cap;
    c[v][u] += cap;
    cf[u][v] += cap;
    cf[v][u] += cap;
}

