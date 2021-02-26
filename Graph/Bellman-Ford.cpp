/*O(VE) 1-base
directional
we can solve 
m inequalities like : x(i) - x(j) <= c
we make one node for each x(i)
we make a source with edge weight 0 to all other nodes
we put a edge from j to i with weight c
bellman ford from source
x[i] is dis[i]*/
ll n,m,dis[MAX_N];
//first Node, second Node, weight
vector<pair<pair<ll,ll>,ll > > edges;
bool negativeCycle;
void bellmanFord() {
    memset(dis, 31, sizeof dis);
    dis[1] = 0;
    for(int i = 1 ; i <= n ; i++) 
        for(pair<pair<ll,ll>,ll > e:edges) 
            if(dis[e.first.first] +e.second < dis[e.first.second])
                dis[e.first.second] = dis[e.first.first]+e.second;
       
     for(pair<pair<ll,ll>,ll > e:edges) 
            if(dis[e.first.first] +e.second < dis[e.first.second])
            	negativeCycle = true;
}



