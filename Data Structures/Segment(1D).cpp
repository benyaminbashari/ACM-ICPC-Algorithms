//The node which has a flag is updated
const int MAX_N = 2*(1e5+10);

int n,seg[4*MAX_N],flg[4*MAX_N];

void relax(int node, int l, int r) {
    if (!flg[x]) 
    	return;
    //give this flag to its child and update its childs based on flag
}

void update(int node, int l, int r) {
    //update cur node from its childs
    flg[x]=0;
    return;
}

void change (int node, int l, int r, int low, int high) {
    if (high<l || r<low) 
    	return 0;
    if (low<=l && r<=high) {
        //Update current node based on flag and change its flag
        return;
    }
    int mid = (l+r)/2;
    relax(node, l, r);
    change(2*node, l, mid, low, high);
    change(2*node+1, mid+1, r, low, high);
    update(node, l, r);

}

int get(int node, int l, int r, int low, int high) {
    if (high<l || r<low) 
    	return 0;
    if (low<=l && r<=high)
        return seg[x];
    relax(node, l, r);
    int mid=(l+r)/2;
    return get(2*node, l, mid, low,  high) +/*OPERATOR*/ get (2*node+1, mid+1, r, low, high);
}






