ld low = -1e4, high = 1e4;
while(low<=high) {
	if(high-low < 1e-12)
		break;
	ld lm = low+(high-low)/3;
	ld rm = high-(high-low)/3;
	ld lmm = check(lm);
	ld rmm = check(rm);
	if(lmm < rmm) 
		high = rm;
	else 
		low = lm;
}
//O(logn) no-base
//first increase then decrese
ll low = 0, high = INF;
ld ans = 0;
while(low<=high) {
	ll lm = low+(high-low)/3;
	ll rm = high-(high-low)/3;
	ld lmval = check(lm);
	ld rmval = check(rm);
	if(lmval < rmval) {
		ans = max(ans, lmval);
		low = lm+1;
	}
	else {
		ans = max(ans, rmval);
		high = rm-1;
	}
}