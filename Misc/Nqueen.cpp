#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 50+5;

int ans, n;
//diag_lr = diagonal from left to right
//zero base
int mark_col[MAX_N], mark_diag_lr[MAX_N], mark_diag_rl[MAX_N];

void place(int k) {
    if(k == n) {
        ans++;
        return;
    }
    for(int i = 0 ; i < n ; i++) {
        if(!mark_col[i] and !mark_diag_rl[k+i] and !mark_diag_lr[k-i+n]) {
            mark_col[i] = 1;
            mark_diag_rl[k+i] = 1;
            mark_diag_lr[k-i+n] = 1;
            place(k+1);
            mark_col[i] = 0;
            mark_diag_rl[k+i] = 0;
            mark_diag_lr[k-i+n] = 0;
        }
    }  
}

int main() {
    cin>>n;
    place(0);
    cout<<ans<<endl;
}