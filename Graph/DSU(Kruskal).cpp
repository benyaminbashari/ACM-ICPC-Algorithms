//O(E log*V) 1-base
//Weight , firstNode , seconddNode
vector<pair<int,pair<int,int> > > edges;
vector<pair<int,pair<int,int> > > ans;

int n, m, par[MAX_N], sz[MAX_N];

void create(int v) {
    par[v] = v;
    sz[v] = 1;
}

int find_par(int v) {
    if(par[v] == v)
        return v;
    par[v] = par[par[v]];
    return find_par(par[par[v]]);
}

void join(int v, int u) {
    u = find_par(u);
    v = find_par(v);
    if(u == v) 
        return;
    if(sz[v] < sz[u]) 
        swap(u, v);
    par[u] = v;
    sz[v] += sz[u];
}

void kruskal() {
    for(int i = 1 ; i <= n ; i++) 
    	create(i);
    sort(edges.begin(), edges.end());
    for(pair<int,pair<int,int> >e: edges) 
    	if(find_par(e.second.first) != find_par(e.second.second)) {
            join(e.second.first, e.second.second);
            ans.push_back(e);
    	}
}



 