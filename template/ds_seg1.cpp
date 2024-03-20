#include<bits/stdc++.h>
using namespace std;
template<typename node>
class segment1 {
   private:
      int l,z;
      vector<node> t;
      struct p{segment1& segTree;int d;p(segment1& st,int i):segTree(st),d(i){}operator node()const{return segTree.t[d];}p& operator=(const node& val){segTree.change(d,val);return *this;}};
      void change(int x,node y){x+=z;t[x]=y;for(int i=x/2;i;i/=2)t[i]=node::merge(t[i*2],t[i*2+1]);}
   public:
      node query(int l,int r){node s[2]={};bool e[2]={true,true};for(l+=z-1,r+=z+1;(l^r)!=1;l>>=1,r>>=1){if(~l&1){s[0]=e[0]?t[l^1]:node::merge(s[0],t[l^1]);e[0]=false;}if(r&1){s[1]=e[1]?t[r^1]:node::merge(t[r^1],s[1]);e[1]=false;}}return e[0]?s[1]:e[1]?s[0]:node::merge(s[0],s[1]);}
      p operator[](int d){return p(*this,d);}
      segment1(int n){l=n;z=(1<<(__lg(n)+1));t.resize(z+n+2);for(int i=(l+z)/2+1;i<=z+n+1;++i)t[i]=node();for(int i=(l+z)/2;i>=1;--i)t[i]=node::merge(t[i*2],t[i*2+1]);}
};
struct node {
   long long sum,lmax,rmax,ans;
   static node merge(node a,node b) {
      return {a.sum+b.sum,max(a.lmax,a.sum+b.lmax),max(b.rmax,b.sum+a.rmax),max({a.ans,b.ans,a.rmax+b.lmax})};
   }
};

void Delta() {
   int n,m;cin >> n;
   segment1<node> Q(n);
   for(int i=1,x;i<=n;++i) {
      cin >> x;
      Q[i]={x,x,x,x};
   }
   cin >> m;
   for(int i=1,l,r;i<=m;++i) {
      cin >> l >> r;
      cout << Q.query(l,r).ans << endl;
   }
}

int main() {
   Delta();
}

// https://vjudge.net/solution/49999477
