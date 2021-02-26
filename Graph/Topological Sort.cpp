//O(E) no-base
int n, m, deg[MAX_N];//deg[v] = deg out(v)
vector<int>g[MAX_N], g1[MAX_N];
vector<int>tSort;
bool mark[MAX_N];
set<int>s;
void topologicalSort(int v) {
    mark[v] = true;
    for(int u:g[v])
        if(!mark[u])
            topologicalSort(u);
    tSort.push_back(v);
}
//O(E log n) 1-base
for(int i = 1 ; i <=  n ; i++) 
	if(deg[i] == 0)
		s.insert(i);
while(s.size() > 0) {
	int v = *s.begin();
	s.erase(s.begin());
	tSort.push_back(v);
	for(int u:g1[v]) {
		deg[u]--;
		if(deg[u] == 0)
			s.insert(u);
	}
}
