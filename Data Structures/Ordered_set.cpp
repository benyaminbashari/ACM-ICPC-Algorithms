#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update


using namespace std;
using namespace __gnu_pbds;


typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


int main() {
  	int n;
 	cin>>n;
  	for(int i=0;i<n;i++) {
      int x;
      cin>>x;
      t.insert(x);
    }
  	int x;
  	while(cin>>x) {
  		int index=t.order_of_key(x);
  		int value=*t.find_by_order(x);
  		cout<<index<<endl;
    }
}