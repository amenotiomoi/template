namespace PR {
   typedef long long ll;
   ll power(ll x,ll p,ll mod){ll answer=1;while(p){if(p&1)answer=(__int128)answer*x%mod;x=(__int128)x*x%mod;p>>=1;}return answer;}
   ll MillerRabin(ll x,ll b){ll k=x-1;while(k){ll cur=power(b,k,x);if(cur!=1&&cur!=x-1)return false;if((k&1)==1||cur==x-1)return true;k>>=1;}return true;}
   bool Prime(ll x){if(x==46856248255981ll||x<2)return false;if(x==2||x==3||x==7||x==61||x==24251)return true;return MillerRabin(x,2)&&MillerRabin(x,61);}
   ll PR(ll x){ll y=1ll*rand()*rand()%x+1,v0=1ll*rand()*rand()%(x-1)+1,v=v0,d,s=1;int t=0,k=1;while(1){v=((__int128)v*v+y)%x;s=(__int128)s*(max(v,v0)-min(v,v0))%x;if(v==v0||!s)return x;if(++t==k){if((d=__gcd(s,x))^1)return d;v0=v,k<<=1;}}}
   ll NonTrivialFact(ll x){if(Prime(x)) return -1;ll answer=1;while(answer==1||answer==x)answer=PR(x);return answer;}
   void dfs(ll x,vector<ll>& answer){if(Prime(x)){answer.push_back(x);return;}ll t=NonTrivialFact(x);dfs(t,answer);dfs(x/t,answer);}
   vector<ll> PrimeFacList(ll x){if(x==1)return{};vector<ll> answer;dfs(x,answer);return answer;}
};