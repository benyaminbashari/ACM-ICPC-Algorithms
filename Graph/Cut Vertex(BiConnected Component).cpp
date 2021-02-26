//O(E) no-base
ll n,m, par[MAX_N],low[MAX_N], height[MAX_N] ,markV[MAX_N],cnt;
vector<ll>v[MAX_N];
vector<pair<ll,ll> >bcc[MAX_N], tmp_find;
bool mark[MAX_N];
vector<ll>articulationPoints;
set<ll>what;

void CLEAR() {
    tmp_find.clear();
    cnt  = 1;
    bridge.clear();
    for(int i = 0 ; i < MAX_N ; i++) {
        bcc[i].clear();
        v[i].clear();
        low[i] = par[i] = height[i] = mark[i] = markV[i] =  0;
    }
}
void FIND(pair<ll,ll>x) {
    while(tmp_find.size() > 0) {
        pair<ll,ll>y = tmp_find[tmp_find.size()-1];
        tmp_find.pop_back();
        bcc[cnt].push_back(y);
        if(y == x || (y.first == x.second && y.second == x.first))
            break;
    }
    cnt++;
}
void dfs(int u, int h) {
    mark[u] = true;
    low[u] = h;
    height[u] = h;
    int childCount = 0;
    bool isArticulation = false;
    for(int i = 0 ; i < v[u].size() ; i++) {
        int node = v[u][i];
        if(!mark[node]) {
            tmp_find.push_back(make_pair(u,node));
            par[node] = u;
            dfs(node, h+1);
            childCount++;
            if(low[node] >= height[u]) {
                FIND(make_pair(u,node));
                isArticulation = true;
            }
            low[u] = min(low[u], low[node]);
        }
        else if(node != par[u] && height[node] < height[u]) {
            tmp_find.push_back(make_pair(u,node));
            low[u] = min(low[u], height[node]);
        }

    }
    if((par[u] != 0 && isArticulation) || (par[u] == 0 && childCount > 1)) {
        articulationPoints.push_back(u);
        markV[u] = true;
    }
}