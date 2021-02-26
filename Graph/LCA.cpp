const int MAX_N = 1e5+10;
const int MAX_LOG = 20;

int n,q,par[MAX_N][MAX_LOG],h[MAX_N];
vector<int>v[MAX_N];
bool mark[MAX_N];
// all parents are -1

void dfs(int u,int parent){
    mark[u] = true;
    par[u][0] = parent;
    if(parent != -1)
        h[u] = h[parent]+1;
    for(int i = 1 ; i < MAX_LOG ; i++)
        if(par[u][i-1] != -1)
            par[u][i] = par[par[u][i-1]][i-1];

    for(int i = 0 ; i < v[u].size() ; i++) {
        if(!mark[v[u][i]]) {
            dfs(v[u][i],u);
        }
    }
}
int LCA(int x,int y) {
    if(h[x] < h[y])
        swap(x,y);
    for(int i = MAX_LOG -1 ; i >= 0 ; i--)
        if(par[x][i] != -1 && h[par[x][i]] >= h[y])
            x = par[x][i];
    if(x == y)
        return x;
    for(int i = MAX_LOG-1 ; i >= 0 ; i--)
        if(par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    return par[x][0];
}





//O(n log n) no-base
//dfs(0, 0)
const int MAXN=1e5+10,MAXL=20;
vector<int> g[MAXN];
int par[MAXN][MAXL],h[MAXN];
void dfs(int v,int p) {
  par[v][0]=p;
  for(int i=1;i<MAXL;i++)
    par[v][i]=par[par[v][i-1]][i-1];
  for(int u:g[v])
    if(u!=p) {
      	h[u]=h[v]+1;
	      dfs(u,v);
    }
}
int get_par(int v,int h) {
  for(int i=0;i<MAXL;i++)
    if(h&(1<<i))
      v=par[v][i];
  return v;
}

int LCA(int v,int u) {
  if(h[v]>h[u])
    swap(v,u);
  u=get_par(u,h[u]-h[v]);
  if(v==u)
    return v;
  for(int i=MAXL-1;i>=0;i--)
    if(par[v][i]!=par[u][i]) {
	     v=par[v][i];
	     u=par[u][i];
    }
  return par[v][0];
}