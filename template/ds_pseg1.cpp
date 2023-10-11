template <class node> class Psegment1 {
   private:
      struct pnode{node value;pnode *l,*r;};
      node value;pnode *l,*r;int siz;
      void build(int l,int r,pnode *&a,node& y){a=new pnode;if(l==r){a->l=a->r=nullptr,a->value=y;return;}int m=(l+r)/2;build(l,m,a->l,y);build(m+1,r,a->r,y);a->value=node::merge(a->l->value,a->r->value);}
      void build(int l,int r,pnode *&a,vector<node>&y){a=new pnode;if(l==r){a->l=a->r=nullptr,a->value=y[l];return;}int m=(l+r)/2;build(l,m,a->l,y);build(m+1,r,a->r,y);a->value=node::merge(a->l->value,a->r->value);}
      template<class T>
      node query(int L,int R,int l,int r,T*a){int mid=(L+R)/2;if(l<=L&&R<=r)return a->value;if(l<=mid&&r>mid)return node::merge(query<pnode>(L,mid,l,r,a->l),query<pnode>(mid+1,R,l,r,a->r));if(l<=mid)return query<pnode>(L,mid,l,r,a->l);return query<pnode>(mid+1,R,l,r,a->r);}
      pnode* change(int L,int R,int x,pnode*a,node& y){if(L==R) return new pnode{y,nullptr,nullptr};int m=(L+R)/2;if(x<=m){pnode* t=change(L,m,x,a->l,y);return new pnode{node::merge(t->value,a->r->value),t,a->r};}else{pnode* t=change(m+1,R,x,a->r,y);return new pnode{node::merge(a->l->value,t->value),a->l,t};}}
   public:
      Psegment1(int n,node y){build(1,(n+1)/2,l,y);build((n+1)/2+1,n,r,y);siz=n;}
      Psegment1(vector<node> y){siz=(int)y.size()-1;build(1,(siz+1)/2,l,y);build((siz+1)/2+1,siz,r,y);}
      Psegment1(){}
      node query(int l,int r){return query<Psegment1<node>>(1,siz,l,r,this);}
      Psegment1<node> change(int x,node y){Psegment1<node>s;s.l=l;s.r=r;s.siz=siz;if(x<=(siz+1)/2)s.l=change(1,(siz+1)/2,x,l,y);else s.r=change((siz+1)/2+1,siz,x,r,y);s.value=node::merge(s.l->value,s.r->value);return s;}
};
struct node {
   int value;
   static node merge(node a,node b) {
      return {-1};
   }
};