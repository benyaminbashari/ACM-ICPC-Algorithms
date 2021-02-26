//O(E log n) no-base
ll n,m,dis[MAX_N],par[MAX_N];
//weight, node
vector<pair<ll,ll> >g[MAX_N];
//weight, node
set<pair<ll,ll> >s;

void dijekstra(int start) {
    memset(dis, 31, sizeof dis);
    dis[start] = 0;
    par[start] = -1;
    s.insert({0, start});
    while(s.size() > 0) {
        pair<ll,ll>a = *s.begin();
        s.erase(*s.begin());
        ll d = a.first;
        ll v = a.second;
        for(pair<ll, ll>e:g[v]) {
            ll w = e.first;
            ll u = e.second;
            if(d + w < dis[u]) {
                s.erase({dis[u], u});
                dis[u] = d + w;
                par[u] = v;
                s.insert({dis[u], u});
            }
        }
    }
}
