vector<int> mul(vector<int> a,vector<int> b){int n=a.size(),m=b.size(),limit=1,l=0;while(limit<=n+m){limit<<=1;++l;}a.resize(limit);b.resize(limit);vector<int>r(limit);for(int i=0;i<limit;++i)r[i]=r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));function<long long(long long,long long)>power=[&](long long b,long long n){long long s=1;while(n){if(n%2==1)s=s*b%998244353;b=b*b%998244353;n/=2;}return s;};function<void(vector<int>&,int)>NTT=[&](vector<int>&a,int type){for(int i=0;i<limit;++i)if(i<r[i])swap(a[i],a[r[i]]);for(int mid=1;mid<limit;mid<<=1){int wn=power(type==1?3:332748118,998244352/(mid<<1));for(int j=0;j<limit;j+=mid<<1){long long w=1;for(int k=0;k<mid;++k){int x=a[j+k],y=w*a[j+k+mid]%998244353;a[j+k]=x+y>=998244353?x+y-998244353:x+y;a[j+k+mid]=x<y?x-y+998244353:x-y;w=w*wn%998244353;}}}};NTT(a,1);NTT(b,1);for(int i=0;i<limit;++i)a[i]=(long long)a[i]*b[i]%998244353;NTT(a,-1);long long inv=power(limit,998244351);for(int i=0;i<=n+m;++i)a[i]=inv*a[i]%998244353;a.resize(n+m-1);return a;};