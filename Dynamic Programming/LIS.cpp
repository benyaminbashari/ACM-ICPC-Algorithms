//O(n logn) 1-base
int n,par[MAX_N],a[MAX_N];
//par[i] = j means that in the LIS .... a[j] a[i] ...
//number can be large , can be equal
//strictly increasing
//for making just increasing remove cmp

bool cmp(pair<int,int> x, pair<int,int> y) {
    if(x.first < y.first)
        return true;
    if(x.second > y.second)
        return false;
    return (x.second >= y.second);
}

vector<int> LIS() {
    vector<pair<int,int> >v;
    v.push_back(make_pair(a[1],1));
    par[1] = -1;
    for(int i = 2 ; i <= n ; i++) {
        if(a[i] > v[v.size()-1].first) {
            v.push_back(make_pair(a[i],i));
            par[i] = v[v.size()-2].second;
            continue;
        }
        int low = lower_bound(v.begin(),v.end(),make_pair(a[i],i),cmp)-v.begin();

        if(v[low].first == a[i])
            continue;
        v[low] = make_pair(a[i],i);
        if(low == 0)
            par[i] = -1;
        else
            par[i] = v[low-1].second;
    }
    vector<int>ret;
    int cur = v[v.size()-1].second;
    while(cur != -1) {
        ret.push_back(a[cur]);
        cur = par[cur];
    }
    reverse(ret.begin(),ret.end());
    return ret;
}





//O(n log n) 0-base
//number of decreasing bags is size of LIS
//CAUTION: JUST THE SIZE NOT THE ORDER FOR ORDER USE VECTOR AND PAR
multiset<int>s;
int a[MAX_N], n;
void LIS() {
    for(int i=0 ; i<n ;i++) {
        int x=a[i];
        //for increasing lower to upper
        multiset<int>::iterator it=s.lower_bound(x);
        if(it==s.end())
             s.insert(x);
        else {
            s.erase(it);
            s.insert(x);
        }
    }
}
