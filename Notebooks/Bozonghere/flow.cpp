#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300+10;
const int INF = 10000000;
struct Edge {
    int to,reverseIndex,cap,flow;
};


int R, C;
int MAP[MAX_N][MAX_N];
pair<int, int>castle;

vector<Edge>g[2*MAX_N*MAX_N];
//O((min(f|E|, |V||E|^2)) 1-base
int n,m,s,t,maxFlow;
pair<int, Edge*> par[2*MAX_N*MAX_N];
bool mark[2*MAX_N*MAX_N];
queue<int>q;
bool bfs() {
    memset(mark, false, sizeof mark);
    while(q.size()) q.pop();
    q.push(s);
    mark[s] = true;
    Edge tmptmp;
    par[s] = {-1, &tmptmp};

    while(q.size() > 0) {
        int a = q.front();
        q.pop();
        for(int i = 0 ; i < g[a].size() ; i++) {
          Edge* e = &g[a][i];
          if(!mark[e->to] && e->cap - e->flow > 0) {
            //cout<<a<<" "<<e.to<<" "<<e.cap-e.flow<<endl;
                par[e->to] = {a, e};
                mark[e->to] = true;
                q.push(e->to);
          }
        }
    }
    //cout<<endl<<endl;
    return mark[t];
}

void EdmondsKarp() {
  int pp = 1;
    while(bfs()) {
        
        vector<pair<int, Edge*> >path;
        int tmp = t;
        while(par[tmp].first != -1) {
            path.push_back(par[tmp]);
            tmp = par[tmp].first;
        }
        reverse(path.begin(),path.end());
        int MIN = INF;
        for(int i = 0 ; i < path.size()  ; i++) {
            Edge tmp = *path[i].second;
            MIN = min(MIN,tmp.cap - tmp.flow);
        }
        for(int i = 0 ; i < path.size() ; i++) {
          
            int u = path[i].first;
            int v = path[i].second->to;
            path[i].second->flow += MIN;
     
            g[v][path[i].second->reverseIndex].flow -= MIN;
            /*cout<<u<<" "<<v<<endl;
            cout<<path[i].second.cap - path[i].second.flow<<endl;
            cout<<g[v][path[i].second.reverseIndex].cap - g[v][path[i].second.reverseIndex].flow<<endl;*/
        }
        maxFlow += MIN;
        //return;
    }
}



void addEdge(int u, int v, int cap) {
    Edge x,y;
    x.to = v;
    y.to = u;
    x.cap = cap;
    y. cap = 0;
    x.flow = y.flow = 0;
    x.reverseIndex = g[v].size();
    y.reverseIndex = g[u].size();
    g[u].push_back(x);
    g[v].push_back(y);
}


int convert(int x, int y) {
  return x*C + y;
}

bool valid(int x, int y) {
  if(x >= 0 and x < R and y >= 0 and y < C and MAP[x][y] != 0) {
    return true;
  }
  return false;
}

void make_graph() {
  for(int i = 0 ; i < R ; i++) {
    for(int j = 0 ; j < C ; j++) {
      if(MAP[i][j] == 0)
        continue;
      addEdge(2*convert(i, j), 2*convert(i, j)+1, MAP[i][j]);

      if(valid(i+1, j)) {
        addEdge(2*convert(i, j)+1, 2*convert(i+1, j), INF);
        addEdge(2*convert(i+1, j)+1, 2*convert(i, j), INF);

      }
      if(valid(i, j+1)) {
        addEdge(2*convert(i, j)+1, 2*convert(i, j+1), INF);
        addEdge(2*convert(i, j+1)+1, 2*convert(i, j), INF);

      }
    }
  }
  n = 2*MAX_N*MAX_N-1;
  s = 2*convert(castle.first, castle.second);
  t = 2*MAX_N*MAX_N-1;
  for(int i = 0 ; i < R ; i++) {
    if(valid(i, 0)) {
      addEdge(2*convert(i, 0)+1, t, INF);
    }
    if(valid(i, C-1)) {
      addEdge(2*convert(i, C-1)+1, t, INF);
    }
  }

  for(int i = 0 ; i < C ; i++) {
    if(valid(0, i)) {
      addEdge(2*convert(0, i)+1, t, INF);
    }
    if(valid(R-1, i)) {
      addEdge(2*convert(R-1, i)+1, t, INF);
    }
  }



}

int main() {

  ios_base::sync_with_stdio(false);

  cin>>R>>C;
  for(int i = 0 ; i < R ; i++) {
    for(int j = 0 ; j < C ; j++)
      cin>>MAP[i][j];
  }

  cin>>castle.first>>castle.second;
  make_graph();

  /*for(Edge e: g[8]) {
    cout<<e.to<<endl;
  }
  return 0;*/
  EdmondsKarp();
  cout<<maxFlow<<endl;

}
