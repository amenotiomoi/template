long long isqrt(ll x){long long a=1ll<<(__lg(x+1)/2+2),b=1ll<<(__lg(x+1)/2+1);while(a>b){a=b;b=(b+x/b)/2;}return a;}
