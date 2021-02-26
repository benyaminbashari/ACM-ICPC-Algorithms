#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<
pair<int, int>,
null_type,
less<pair<int, int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

typedef long long ll;
typedef long double ld;
 
const int MAX_N = 3e5+10;
const int INF = 1000000000;
const ll MOD = 998244353;


ll n, k, fact[MAX_N];
vector<pair<ll, ll> > v;

ll POW(ll a, ll b) {
    if(b == 0)
        return 1;
    ll x = POW(a, b/2);
    if(b % 2 == 0) 
        return (x*x)%MOD;
    return (((x*x)%MOD)*a)%MOD;
}

ll INV(ll x) {
    return POW(x, MOD-2);
}

ll CHOOSE(ll a, ll b) {
    ll y = (fact[b] * fact[a-b])%MOD;
    ll x = fact[a];
    y = INV(y);
    return (x*y)%MOD;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    
    for(int i = 1 ; i <= n ; i++) {
        int l, r;
        cin>>l>>r;
        v.push_back({l, 1});
        v.push_back({r+1, 0});
    }
    fact[0] = 1;
    for(int i = 1 ; i <= n ; i++)
        fact[i] = (fact[i-1] * i)%MOD;

    sort(v.begin(), v.end());

    ll cur = 0;
    ll ans = 0;
    for(pair<ll, ll> x: v) {
        if(x.second == true) {
            cur++;
            if(cur >= k) {
                ans += CHOOSE(cur-1, k-1);
                ans %= MOD;
            }
        }
        else 
            cur--;
    }
    cout<<ans%MOD<<endl;
    
}

 