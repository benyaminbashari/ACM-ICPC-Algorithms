//IN THE NAME OF GOD

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef long double ld;


const int MAX_N = 1e5+10;
const int MAX_LOG = 20;
const int INF = 1e8;

ordered_set x;
int a[MAX_N], ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1 ; i <= n ; i++) 
		cin>>a[i];
	for(int i = n ; i >= 1 ; i--) {
		ans += x.order_of_key(a[i]);
		x.insert(a[i]);
	}
	cout<<ans<<endl;

}