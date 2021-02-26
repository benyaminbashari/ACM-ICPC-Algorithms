//O(E) no-base
//if the odd degree vertex is 2 or all degrees are even
//directional two vertex one out and one in
//edges are numbered from 1 to m
//g[i][j] = {k, l} means i-th vertex is connected with k-th vertex through l-th edge  
int n, m;
bool mark[MAX_N];
vector<pair<int, int> >g[MAX_N];
vector<int>ans;
void Euler(int v) {
  while(g[v].size() > 0) {
    pair<int, int> u = g[v].back();
    g[v].pop_back();
    if(!mark[u.second]) {
        mark[u.second] = 1;
        Euler(d);
    }
  }
  ans.push_back(u);
}