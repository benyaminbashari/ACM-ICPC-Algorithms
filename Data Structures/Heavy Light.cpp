vector <int> g[MAXN];
int par[MAXN],h[MAXN],sz[MAXN],up[MAXN],st[MAXN],en[MAXN],a[MAXN];
int T=0,n, seg[MAXN*4];
void dfs_make(int v,int p=0) {
  par[v]=p;
  if(v!=0) h[v]=h[p]+1;
  sz[v]=1;
  int ind=0,Max=0,pind=-1;
  for(int i=0;i<g[v].size();i++) {
      int u=g[v][i];
      if(u!=p) {
	       dfs_make(u,v);
	       sz[v]+=sz[u];
	       if(sz[u]>Max)ind=i,Max=sz[u];
	   }
      else pind=i;
  }
  if(pind!=-1) {
      swap(g[v][pind],g[v][g[v].size()-1]);
      g[v].pop_back();
    }
  if(g[v].size()) swap(g[v][0],g[v][ind]);
}
void dfs_hld(int v) {
  st[v]=T++;
  if(g[v].empty()==0) {
      up[g[v][0]]=up[v];
      dfs_hld(g[v][0]);
      for(int i=1;i<g[v].size();i++){
    	  int u=g[v][i];
    	  up[u]=u;
    	  dfs_hld(u);
	    }
  }
  en[v]=T;
}
inline bool cont(int v,int u) {
  return (st[u]>=st[v] and st[u]<en[v]);
}
int lca(int v,int u) {
  if(cont(v,u)) return v;
  if(cont(u,v)) return u;
  int ans1=par[up[v]];
  while(!cont(ans1,u)) ans1=par[up[ans1]];
  int ans2=par[up[u]];
  while(!cont(ans2,u)) ans2=par[up[ans2]];
  if(h[ans1]<h[ans2]) return ans2;
  else return ans1;
}
void add(int s,int e,int ind,int i,int val){
  if(s>i or e<=i) return;
  if(e==s+1) {
      seg[ind]+=val;
      return;
  }
  int mid=(s+e)/2;
  add(s,mid,left(ind),i,val), add(mid,e,right(ind),i,val);
  seg[ind]=seg[left(ind)]+seg[right(ind)];
}
int fin(int s,int e,int ind,int x,int y) {
  if(s>=y or e<=x) return 0;
  if(x<=s and e<=y) return seg[ind];
  int mid=(s+e)/2;
  return fin(s,mid,left(ind),x,y) +fin(mid,e,right(ind),x,y);
}
int calc(int Par,int v) {
  if(Par==v) return a[v];
  int ret=0,last=-1;
  while(st[v]>st[Par]) {
      if(st[up[v]]>st[Par]) ret+=fin(0,n,1,st[up[v]],st[v]+1);
      else break;
      v=par[up[v]];
  }
  ret+=fin(0,n,1,st[Par],st[v]+1);
  return ret;
}
int main() {
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=1;i<n;i++) {
      int v,u;
      cin>>v>>u;
      g[v].push_back(u);
      g[u].push_back(v);
    }
  dfs_make(0);
  up[0]=0;
  dfs_hld(0);
  for(int i=0;i<n;i++) add(0,n,1,st[i],a[i]);
  int m; cin>>m;
  for(int i=0;i<m;i++) {
      int v,u;
      cin>>v>>u;
      int l=lca(v,u);
      cout<<calc(l,v)+calc(l,u)-a[v]<<endl;
    }
}
