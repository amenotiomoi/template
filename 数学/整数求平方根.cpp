long long isqrt(long long x){long long a=x,b=(x+1)/2;while(a>b){a=b;b=(b+x/b)/2;}return a;}
