//O(V^3) 1-base
int n,m,dis[MAX_N][MAX_N],g[MAX_N][MAX_N];
//directional, g[i][j] = INF
void floydWarshall() {
    for(int i = 0 ; i < MAX_N ; i++)
        for(int j = 0 ; j < MAX_N ; j++)
            dis[i][j] = min(INF,g[i][j]);

    for(int i = 1 ; i <= n ; i++)
        dis[i][i] = 0;

    for(int k = 1 ; k <= n ; k++)
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                if(dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
                    //for using minimax and maximin
                    //minimax : dis[i][j] = min(dis[i][j],max(dis[i][k],dis[k][j]))
                    //maximin : dis[i][j] = max(dis[i][j],min(dis[i][k],dis[k][j]))
                    // d[i][j] + d[j][i] < 0 -> negative cycle
}
