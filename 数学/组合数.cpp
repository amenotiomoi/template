namespace combi {
   typedef long long ll;
   ll MOD,*fac=nullptr,*inv=nullptr,*finv=nullptr;
   ll C(ll x,ll y){return(x<0||y>x)?0:fac[x]*finv[y]%MOD*finv[x-y]%MOD;}
   ll power(ll b,ll n){ll s=1;b%=MOD;while(n){if(n%2==1)s=s*b%MOD;b=b*b%MOD;n/=2;}return s;}
   void init(int n,ll mod){for(auto i:{&fac,&inv,&finv}){if(*i!=nullptr)delete *i;*i=new ll[n+1];}MOD=mod;fac[0]=fac[1]=inv[0]=inv[1]=finv[0]=finv[1]=1;for(ll i=2;i<=n;++i){fac[i]=fac[i-1]*i%MOD;inv[i]=MOD-MOD/i*inv[MOD%i]%MOD;finv[i]=finv[i-1]*inv[i]%MOD;}}
   ll Inv(int x){return power(x,MOD-2);}
};
