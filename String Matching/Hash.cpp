//O(n) 0-base
//be carefull of mod ! log MOD is mutlplied 
const ll MOD = 999998727899999LL;
const ll P = 37;	
ll h[MAX_N],po[MAX_N];

ll Hash(string s) {
  h[0]=(s[0]-'a'+1);
  for(int i=1;i<s.length();i++)
    h[i]=(h[i-1]*P+(s[i]-'a'+1))%MOD;
  return h[s.length()-1];
}
ll mul(ll a, ll b) {
	if(b == 0) return 0;
	ll x = mul(a, b/2);
	if(b%2) return (x+x+a)%MOD;
	else  return (x+x)%MOD;
}
ll calc(int s,int e){
  if(s==0) return h[e];
  ll ans=h[e];
  ans-=mul(h[s-1], po[e-s+1]);
  if(ans < 0) ans += MOD;
  return ans;
}
void init() {
	po[0]=1;
  	for(int i=1;i<MAX_N;i++)
    	po[i]=(po[i-1]*P)%MOD;
}
