template <class node> class segment1 {
   private:
      int id(int l,int r){return (l+r)|(l!=r);}
      void change(int l,int r,int x,node &y){if(l==r){seg[id(l,r)]=y;return;}int mid=(l+r)/2;if(x<=mid)change(l,mid,x,y);else change(mid+1,r,x,y);seg[id(l,r)]=node::merge(seg[id(l,mid)],seg[id(mid+1,r)]);}
      node query(int L,int R,int l,int r){if(l<=L&&R<=r)return seg[id(L,R)];int mid=(L+R)/2;if(l<=mid&&r>mid)return node::merge(query(L,mid,l,r),query(mid+1,R,l,r));if(l<=mid)return query(L,mid,l,r);return query(mid+1,R,l,r);}
      void build(int l,int r,node &y){if(l==r){seg[id(l,r)]=y;return;}int mid=(l+r)/2;build(l,mid,y);build(mid+1,r,y);seg[id(l,r)]=node::merge(seg[id(l,mid)],seg[id(mid+1,r)]);}
   public:
      vector<node> seg;int siz;
      void init(int n,node y){siz=n;seg.resize(2*n+4);build(1,siz,y);}
      void change(int x,node y){change(1,siz,x,y);}
      node query(int l,int r){return query(1,siz,l,r);}
};
struct node {
   int sum;
   static node merge(node a,node b) {
      return node{a.sum+b.sum};
   }
};
