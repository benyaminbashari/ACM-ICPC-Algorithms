//O(E) 1-base
//if you want use SCC only ignore last method
// booleans are 1 to n
//~i = i+n
//if u want to add an edge by itself 
//you should add inverse of it too
//a -> b == ~b -> ~a
int n,m,cnt = 1,verticesScc[MAX_N];
vector<int>g[MAX_N],g1[MAX_N],scc[MAX_N];
vector<int>tSort;
bool mark[MAX_N],ans[MAX_N],satisfy = true;

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
    cnt--;
}

int inverse(int t) {
    if(t <= n)
        return t+n;
    return t-n;
}

bool check() {
    for(int i = 1 ;  i<= n ; i++)
        if(verticesScc[i] == verticesScc[i+n])
            return false;
    return true;
}
//one of the expressions are (x or y)
void addExpresion(int x,int y) {
    g[inverse(x)].push_back(y);
    g[inverse(y)].push_back(x);
    g1[y].push_back(inverse(x));
    g1[x].push_back(inverse(y));
}

void sat() {
    n *= 2;
    SCC();
    n/=2;
    if(!check()) {
        satisfy = false;
        return;
    }
    memset(mark, false, sizeof mark);
    reverse(tSort.begin(),tSort.end());
    for(int v:tSort) {
        if(v <= n && !mark[v]) {
            mark[v] = true;
            ans[v] = true;
        }
        if(v > n && !mark[v-n])
            mark[v-n] = true;
    }
}
